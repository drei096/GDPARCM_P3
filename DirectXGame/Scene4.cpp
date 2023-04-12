#include "Scene4.h"
#include "ObjectLoader.h"
#include "SceneManager.h"
#include "ThreadPool.h"
#include "IETSemaphore.h"
#include "Utils.h"

Scene4::Scene4(std::string name, int index) : ObjectScene(name, index)
{
}

Scene4::~Scene4()
{
}

void Scene4::loadObjects()
{
	srand(time(NULL));

	if (hasLoaded)
		return;

	//SceneManager::Instance()->sceneLoadSem->acquire(1);

	this->maxObjects = 6;

	int randomNumber = 0;
	Vector3D randomPos = Vector3D(Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f));

	randomNumber = rand() % this->posList.size();
	//ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::ARMADILLO, randomPos, this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	//this->occupiedList.push_back(this->posList[randomNumber]);
	//this->posList.erase(this->posList.begin() + randomNumber);
	//this->posList.shrink_to_fit();

	randomPos = Vector3D(Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f));
	randomNumber = rand() % this->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::EARTH, randomPos, this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	//this->occupiedList.push_back(this->posList[randomNumber]);
	//this->posList.erase(this->posList.begin() + randomNumber);
	//this->posList.shrink_to_fit();

	randomPos = Vector3D(Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f));
	randomNumber = rand() % this->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::ARMADILLO, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, randomPos, this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	//this->occupiedList.push_back(this->posList[randomNumber]);
	//this->posList.erase(this->posList.begin() + randomNumber);
	//this->posList.shrink_to_fit();

	randomPos = Vector3D(Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f));
	randomNumber = rand() % this->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, randomPos, this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	//this->occupiedList.push_back(this->posList[randomNumber]);
	//this->posList.erase(this->posList.begin() + randomNumber);
	//this->posList.shrink_to_fit();

	randomPos = Vector3D(Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f));
	randomNumber = rand() % this->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, randomPos, this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	//this->occupiedList.push_back(this->posList[randomNumber]);
	//this->posList.erase(this->posList.begin() + randomNumber);
	//this->posList.shrink_to_fit();

	randomPos = Vector3D(Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f), Utils::randomFloat(-30.0f, 30.0f));
	randomNumber = rand() % this->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::SAMPLE_SCENE, randomPos, this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	//this->occupiedList.push_back(this->posList[randomNumber]);
	//this->posList.erase(this->posList.begin() + randomNumber);
	//this->posList.shrink_to_fit();
}