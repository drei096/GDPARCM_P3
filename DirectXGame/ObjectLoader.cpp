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

	SceneManager::Instance()->objLoadSem->acquire(1);

	IETThread::sleep(1000);

	BNS_AGameObject* tempRef = NULL;

	//LOAD OBJECTS HERE
	if (this->meshType == BNS_MeshType::TEAPOT) 
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateTeapot(pos.m_x, pos.m_y, pos.m_z);
		sceneRef->addObject(tempRef);
	}
	else if (this->meshType == BNS_MeshType::STATUE)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateStatue(pos.m_x, pos.m_y, pos.m_z);
		sceneRef->addObject(tempRef);
	}
	else if (this->meshType == BNS_MeshType::BUNNY)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateBunny(pos.m_x, pos.m_y, pos.m_z);
		sceneRef->addObject(tempRef);
	}
	else if (this->meshType == BNS_MeshType::ARMADILLO)
	{
		tempRef = BNS_PrimitiveCreation::Instance()->CreateArmadillo(pos.m_x, pos.m_y, pos.m_z);
		sceneRef->addObject(tempRef);
	}

	if (tempRef != NULL)
		tempRef->SetActive(false);

	this->execEvent->onFinishedExecution();
	//delete after being done
	delete this;
}