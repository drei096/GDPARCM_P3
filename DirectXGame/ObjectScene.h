#pragma once
#include "AScene.h"
#include "BNS_GameObjectManager.h"
#include <vector>

class ObjectScene : public AScene
{
public:
	// Inherited via AScene
	virtual void loadObjects() override;

	virtual void unloadObjects() override;

public:
	void addObject(BNS_AGameObject* object);

private:
	std::vector<BNS_AGameObject*> objectList;

};

