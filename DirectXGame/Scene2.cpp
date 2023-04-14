#include "Scene2.h"
#include "ObjectLoader.h"
#include "SceneManager.h"
#include "ThreadPool.h"
#include "IETSemaphore.h"
#include "Utils.h"

Scene2::Scene2(std::string name, int index) : ObjectScene(name, index)
{
}

Scene2::~Scene2()
{
}

void Scene2::loadObjects()
{
	srand(time(NULL));

	if (hasLoaded)
		return;

	//SceneManager::Instance()->sceneLoadSem->acquire(1);

	this->maxObjects = 6;

	int randomNumber = 0;
	//Vector3D randomPos = Vector3D(Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f));

	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::SPACESHIP, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::ARMADILLO, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::ARMADILLO, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f), Utils::randomFloat(-20.0f, 20.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

}