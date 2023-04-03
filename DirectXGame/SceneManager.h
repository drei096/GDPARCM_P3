#pragma once
#include "AScene.h"
#include <vector>

class SceneManager
{
private:
	SceneManager();
	~SceneManager();
	SceneManager(SceneManager const&) {}; // copy constructor is private
	SceneManager& operator=(SceneManager const&) {}; // assignment operator is private

public:
	void addScene(AScene* scene);
	void initializeScenes();
	std::vector<AScene*>* getSceneList();

private:
	std::vector<AScene*> sceneList;
};

