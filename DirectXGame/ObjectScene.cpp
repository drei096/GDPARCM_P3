#include "ObjectScene.h"
#include "SceneManager.h"
#include "IETSemaphore.h"
#include "BNS_GameObjectManager.h"

ObjectScene::ObjectScene(std::string name, int index) : AScene(name, index)
{
	
}

ObjectScene::~ObjectScene()
{
}

void ObjectScene::unloadObjects()
{
	if (!hasLoaded)
		return;

	SceneManager::Instance()->sceneLoadSem->acquire();

	this->countLoaded = 0;

	for (auto object : this->objectList) 
	{
		SceneManager::Instance()->objmutex->acquire();
		BNS_GameObjectManager::get()->DeleteObject(object);
		SceneManager::Instance()->objmutex->release();
	}

	this->objectList.clear();
	this->objectList.shrink_to_fit();

	std::cout << this->objectList.size() << std::endl;

	for (auto occupiedPos : SceneManager::Instance()->occupiedList)
		SceneManager::Instance()->posList.push_back(occupiedPos);

	SceneManager::Instance()->occupiedList.clear();

	this->hasLoaded = false;

	SceneManager::Instance()->sceneLoadSem->release();
}

void ObjectScene::toggleObjects(bool isActive)
{
	for (auto object : this->objectList)
		object->SetActive(isActive);
}

void ObjectScene::onFinishedExecution()
{
	//SceneManager::Instance()->objLoadSem->release();
	this->countLoaded++;

	if (this->countLoaded == this->maxObjects && this->maxObjects != 0)
		for (auto objects : this->objectList)
			objects->SetActive(isViewingScene); //initially set to false for startup load
	
}

void ObjectScene::addObject(BNS_AGameObject* object)
{
	this->objectList.push_back(object);
}
