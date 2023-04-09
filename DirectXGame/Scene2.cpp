#include "Scene2.h"
#include "ObjectLoader.h"
#include "SceneManager.h"
#include "ThreadPool.h"
#include "IETSemaphore.h"

Scene2::Scene2(std::string name, int index) : ObjectScene(name, index)
{
}

Scene2::~Scene2()
{
}

void Scene2::loadObjects()
{
	SceneManager::Instance()->sceneLoadSem->acquire(1);

	this->maxObjects = 3;

	int randomNumber = 0;

	randomNumber = rand() % this->posList.size();
	ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	this->occupiedList.push_back(this->posList[randomNumber]);
	this->posList.erase(this->posList.begin() + randomNumber);
	this->posList.shrink_to_fit();

	randomNumber = rand() % this->posList.size();
	objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	this->occupiedList.push_back(this->posList[randomNumber]);
	this->posList.erase(this->posList.begin() + randomNumber);
	this->posList.shrink_to_fit();

	randomNumber = rand() % this->posList.size();
	objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, this->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	this->occupiedList.push_back(this->posList[randomNumber]);
	this->posList.erase(this->posList.begin() + randomNumber);
	this->posList.shrink_to_fit();

	SceneManager::Instance()->sceneLoadSem->release(1);
}