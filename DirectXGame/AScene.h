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

	virtual void loadObjects() = 0;
	virtual void unloadObjects() = 0;
	virtual void toggleObjects(bool isActive) = 0;

public:
	bool isViewingScene = false;

private:
	std::string name;
	int index;
};

