#pragma once
#include "AScene.h"
#include "BNS_GameObjectManager.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "IExecutionEvent.h"

class ObjectScene : public AScene, public IExecutionEvent
{
public:
	ObjectScene(std::string name, int index);
	~ObjectScene();

public:
	// Inherited via AScene
	virtual void loadObjects() = 0;
	virtual void unloadObjects() override;
	virtual void toggleObjects(bool isActive) override;

	// Inherited via IExecutionEvent
	virtual void onFinishedExecution() override;

public:
	void addObject(BNS_AGameObject* object);

public:
	int countLoaded = 0;
	int maxObjects = 0;
	bool hasLoaded = false;

protected:
	std::vector<Vector3D> posList;
	std::vector<Vector3D> occupiedList;
	std::vector<BNS_AGameObject*> objectList;
};

