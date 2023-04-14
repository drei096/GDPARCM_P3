#include "ObjectLoader.h"
#include "IETThread.h"
#include "IExecutionEvent.h"
#include "ObjectScene.h"
#include "BNS_PrimitiveCreation.h"
#include "SceneManager.h"
#include "IETSemaphore.h"

ObjectLoader::ObjectLoader(ObjectScene* sceneRef, BNS_MeshType meshType, Vector3D pos, IExecutionEvent* executionEvent) : sceneRef(sceneRef), meshType(meshType), pos(pos), execEvent(executionEvent)
{

}

ObjectLoader::~ObjectLoader()
{
	std::cout << "Destroying Object Loader" << std::endl;
}

void ObjectLoader::onStartTask()
{
	std::cout << "Running Object Loader" << std::endl;

	SceneManager::Instance()->objLoadSem->acquire();

	IETThread::sleep(1000);

	BNS_AGameObject* tempRef = nullptr;

	//LOAD OBJECTS HERE
	if (this->meshType == BNS_MeshType::TEAPOT) 
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateTeapot(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::STATUE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateStatue(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::BUNNY)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateBunny(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::ARMADILLO)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateArmadillo(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::SPHERE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateSphere(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::CAPSULE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateCapsule(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::EARTH)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateEarth(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::SAMPLE_SCENE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateScene(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::FARMHOUSE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateFarmhouse(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::SPACESHIP)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateSpaceship(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::SUZANNE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateSuzanne(pos.m_x, pos.m_y, pos.m_z);
	}
	else if (this->meshType == BNS_MeshType::TORUS)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateTorus(pos.m_x, pos.m_y, pos.m_z);
	}

	if (tempRef != nullptr) {
		sceneRef->addObject(tempRef);
		tempRef->SetActive(false);
	}

	SceneManager::Instance()->objLoadSem->release();

	this->execEvent->onFinishedExecution();
	//delete after being done
	delete this;
}