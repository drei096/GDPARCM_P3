#include "Scene5.h"
#include "ObjectLoader.h"
#include "SceneManager.h"
#include "ThreadPool.h"
#include "IETSemaphore.h"
#include "Utils.h"

Scene5::Scene5(std::string name, int index) : ObjectScene(name, index)
{
}

Scene5::~Scene5()
{
}

void Scene5::loadObjects()
{
	srand(time(NULL));

	if (hasLoaded)
		return;

	//SceneManager::Instance()->sceneLoadSem->acquire(1);

	this->maxObjects = 6;

	int randomNumber = 0;
	//Vector3D randomPos = Vector3D(Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f));

	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	ObjectLoader* objectLoader = new ObjectLoader(this, BNS_MeshType::SPHERE, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::EARTH, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::ARMADILLO, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::SAMPLE_SCENE, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::BUNNY, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::ARMADILLO, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

	//randomPos = Vector3D(Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f), Utils::randomFloat(-35.0f, 35.0f));
	randomNumber = rand() % SceneManager::Instance()->posList.size();
	//objectLoader = new ObjectLoader(this, BNS_MeshType::TEAPOT, this->posList[randomNumber], this);
	objectLoader = new ObjectLoader(this, BNS_MeshType::STATUE, SceneManager::Instance()->posList[randomNumber], this);
	SceneManager::Instance()->getThreadPool()->scheduleTask(objectLoader);
	SceneManager::Instance()->occupiedList.push_back(SceneManager::Instance()->posList[randomNumber]);
	SceneManager::Instance()->posList.erase(SceneManager::Instance()->posList.begin() + randomNumber);
	SceneManager::Instance()->posList.shrink_to_fit();

}