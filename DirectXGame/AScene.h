#pragma once
#include <string>
#include <vector>
#include "Vector3D.h"
#include "BNS_AGameObject.h"

class AScene
{
public:
	AScene(std::string name, int index);
	~AScene();

	virtual void loadScene() = 0;

private:
	std::string name;
	int index;
	std::vector<Vector3D> posList;
	std::vector<BNS_AGameObject> objectList;
};

