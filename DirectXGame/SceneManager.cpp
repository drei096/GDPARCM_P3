#include "SceneManager.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "Scene5.h"
#include "ThreadPool.h"
#include "IETSemaphore.h"
#include "IMGUI/imgui.h"

SceneManager* SceneManager::sharedInstance = nullptr;

SceneManager::SceneManager()
{
	this->threadPool = new ThreadPool("MeshLoaderPool", 12);
	this->threadPool->startScheduler();

	this->sceneLoadSem = new IETSemaphore(1);
	this->objLoadSem = new IETSemaphore(1);
	this->objmutex = new IETSemaphore(1);

	this->posList.push_back(Vector3D(0, 0, 0));
	this->posList.push_back(Vector3D(2.5, 2.5, 2.5));
	this->posList.push_back(Vector3D(-2.5, -2.5, -2.5));
	this->posList.push_back(Vector3D(5, 5, 5));
	this->posList.push_back(Vector3D(-5, -5, -5));
	this->posList.push_back(Vector3D(7.5, 7.5, 7.5));
	this->posList.push_back(Vector3D(-7.5, -7.5, -7.5));
	this->posList.push_back(Vector3D(10, 10, 10));
	this->posList.push_back(Vector3D(-10, -10, -10));
	this->posList.push_back(Vector3D(12.5, 12.5, 12.5));
	this->posList.push_back(Vector3D(-12.5, -12.5, -12.5));
	this->posList.push_back(Vector3D(15, 15, 15));
	this->posList.push_back(Vector3D(-15, -15, -15));
	this->posList.push_back(Vector3D(10, 0, 10));
	this->posList.push_back(Vector3D(-10, 0, 10));
	this->posList.push_back(Vector3D(-10, 0, -10));
	this->posList.push_back(Vector3D(10, 0, -10));
	this->posList.push_back(Vector3D(0, -20, 0));
	this->posList.push_back(Vector3D(20, 20, 0));
	this->posList.push_back(Vector3D(0, 20, 20));
	this->posList.push_back(Vector3D(-20, 10, 10));
	this->posList.push_back(Vector3D(30, -10, 10));
	this->posList.push_back(Vector3D(15.5, -15.5, 12.5));
	this->posList.push_back(Vector3D(-15, 20, -2));
	this->posList.push_back(Vector3D(7, -8, 28));
	this->posList.push_back(Vector3D(-27, -12, -18));
	this->posList.push_back(Vector3D(22, -26, 10));
	this->posList.push_back(Vector3D(4, 17, 14));
	this->posList.push_back(Vector3D(-28, 9, -29));
	this->posList.push_back(Vector3D(13, 27, -6));
	this->posList.push_back(Vector3D(26, -28, 23));
	this->posList.push_back(Vector3D(-10, -20, -27));
	this->posList.push_back(Vector3D(-6, 13, 22));
	this->posList.push_back(Vector3D(11, 25, 18));
	this->posList.push_back(Vector3D(-21, -7, -8));
	this->posList.push_back(Vector3D(19, -17, -19));
	this->posList.push_back(Vector3D(-24, 4, 26));
	this->posList.push_back(Vector3D(3, 30, 9));
	this->posList.push_back(Vector3D(28, -23, -12));
}

SceneManager::~SceneManager()
{
}

void SceneManager::addScene(AScene* scene)
{
	this->sceneList.push_back(scene);
}

void SceneManager::initializeScenes()
{
	AScene* sceneTemp;

	sceneTemp = new Scene1("Scene1", this->sceneList.size());
	this->addScene(sceneTemp); 
	sceneTemp = new Scene2("Scene2", this->sceneList.size());
	this->addScene(sceneTemp);
	sceneTemp = new Scene3("Scene3", this->sceneList.size());
	this->addScene(sceneTemp);
	sceneTemp = new Scene4("Scene4", this->sceneList.size());
	this->addScene(sceneTemp);
	sceneTemp = new Scene5("Scene5", this->sceneList.size());
	this->addScene(sceneTemp);

	//pre-load all scenes
	loadAllScenes();
}

std::vector<AScene*> &SceneManager::getSceneList()
{
	return this->sceneList;
}

ThreadPool* SceneManager::getThreadPool()
{
	return this->threadPool;
}

void SceneManager::loadSceneByIndex(int index)
{
	if (this->sceneList[index] == NULL)
		return;

	this->sceneList[index]->loadObjects();
}

void SceneManager::loadAllScenes()
{
	if (this->sceneList.empty())
		return;

	for (auto scene : this->sceneList) 
	{
		if (!dynamic_cast<ObjectScene*>(scene)->hasLoaded)
			scene->loadObjects();
	}
}

void SceneManager::unloadSceneByIndex(int index)
{
	if (this->sceneList[index] == NULL)
		return;

	this->sceneList[index]->unloadObjects();
}

void SceneManager::unloadAllScenes()
{
	if (this->sceneList.empty())
		return;

	for (auto scene : this->sceneList)
		scene->unloadObjects();
}

void SceneManager::toggleSceneByIndex(int index)
{
	if (this->sceneList[index] == NULL)
		return;

	isViewingAllScenes = false;
	for(int i = 0; i < sceneList.size(); i++)
	{
		if (i != index)
		{
			this->sceneList[i]->isViewingScene = false;
			this->sceneList[i]->toggleObjects(this->sceneList[i]->isViewingScene);
		}
		else
		{
			this->sceneList[i]->isViewingScene = true;
			this->sceneList[i]->toggleObjects(this->sceneList[i]->isViewingScene);
		}
	}

	currentScene = "Scene" + std::to_string((index + 1));
}

void SceneManager::toggleAllScenes()
{
	if (this->sceneList.empty())
		return;

	if(isViewingAllScenes == false)
	{
		for (auto scene : this->sceneList)
		{
			scene->isViewingScene = true;
			scene->toggleObjects(scene->isViewingScene);
		}
		isViewingAllScenes = true;
		currentScene = "All Scenes";
	}
	else
	{
		for (auto scene : this->sceneList)
		{
			scene->isViewingScene = false;
			scene->toggleObjects(scene->isViewingScene);
		}
		isViewingAllScenes = false;
		currentScene = "None";
	}
	
		
}

std::string SceneManager::getCurrentScene()
{
	return currentScene;
}

void SceneManager::setCurrentScene()
{
	
}

void SceneManager::create()
{
	if (SceneManager::sharedInstance)
		throw std::exception("Scene Manager already created");
	else
	{
		SceneManager::sharedInstance = new SceneManager();
	}
}

void SceneManager::release()
{
	if (!SceneManager::sharedInstance)
		return;
	delete SceneManager::sharedInstance;
}

SceneManager* SceneManager::Instance()
{
	return sharedInstance;
}
