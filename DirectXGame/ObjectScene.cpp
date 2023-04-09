#include "ObjectScene.h"
#include "SceneManager.h"
#include "IETSemaphore.h"

ObjectScene::ObjectScene(std::string name, int index) : AScene(name, index)
{
	//1
	this->posList.push_back(Vector3D(0, 0, 0));
	//2
	this->posList.push_back(Vector3D(2.5, 2.5, 2.5));
	//3
	this->posList.push_back(Vector3D(-2.5, -2.5, -2.5));
	//4
	this->posList.push_back(Vector3D(5, 5, 5));
	//5
	this->posList.push_back(Vector3D(-5, -5, -5));
	//6
	this->posList.push_back(Vector3D(7.5, 7.5, 7.5));
	//7
	this->posList.push_back(Vector3D(-7.5, -7.5, -7.5));
	//8
	this->posList.push_back(Vector3D(10, 10, 10));
	//9
	this->posList.push_back(Vector3D(-10, -10, -10));
	//10
	this->posList.push_back(Vector3D(12.5, 12.5, 12.5));
	//11
	this->posList.push_back(Vector3D(-12.5, -12.5, -12.5));
	//12
	this->posList.push_back(Vector3D(15, 15, 15));
	//13
	this->posList.push_back(Vector3D(-15, -15, -15));
}

ObjectScene::~ObjectScene()
{
}

void ObjectScene::unloadObjects()
{
}

void ObjectScene::onFinishedExecution()
{
	SceneManager::Instance()->objLoadSem->release(1);
	this->countLoaded++;

	if (this->countLoaded == this->maxObjects && this->maxObjects != 0)
		for (auto objects : this->objectList)
			objects->SetActive(true);
}

void ObjectScene::addObject(BNS_AGameObject* object)
{
	this->objectList.push_back(object);
}
