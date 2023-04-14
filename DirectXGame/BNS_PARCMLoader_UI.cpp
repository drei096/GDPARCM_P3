#include "BNS_PARCMLoader_UI.h"
#include "SceneManager.h"
#include "ObjectScene.h"
#include "IETSemaphore.h"

BNS_PARCMLoader_UI::BNS_PARCMLoader_UI(std::string name, int ID) : BNS_AUIScreen(name, ID)
{

}

BNS_PARCMLoader_UI::~BNS_PARCMLoader_UI()
{
}

void BNS_PARCMLoader_UI::DrawUI()
{
	ImGui::Begin("PARCM Scene Loader");
	ImGui::Columns(3);

	for (int i = 0; i < 5; i++)
	{
		std::string stringName = "Scene" + std::to_string(i + 1);
		ImGui::Text(stringName.c_str());
		ImGui::Spacing();
		if (ImGui::Button(("Load##" + std::to_string(i)).c_str(), ImVec2(100, 0)))
		{
			SceneManager::Instance()->loadSceneByIndex(i);
			this->queuedForSceneLoadingCount++;
		}
		ImGui::SameLine();
		if (ImGui::Button(("Unload##" + std::to_string(i)).c_str(), ImVec2(100, 0)))
		{
			SceneManager::Instance()->unloadSceneByIndex(i);
			this->completedSceneLoadingCount--;
			this->queuedForSceneLoadingCount--;
		}
		ImGui::SameLine();
		if (ImGui::Button(("Toggle##" + std::to_string(i)).c_str(), ImVec2(100, 0)))
		{
			SceneManager::Instance()->toggleSceneByIndex(i);
		}
		ImGui::Spacing();
	}

	ImGui::Text("Load All Scenes");
	ImGui::Spacing();
	if (ImGui::Button("Load##5", ImVec2(150, 0)))
	{
		SceneManager::Instance()->loadAllScenes();
	}
	ImGui::SameLine();
	if (ImGui::Button("Toggle##5", ImVec2(150, 0)))
	{
		SceneManager::Instance()->toggleAllScenes();
	}
	ImGui::Spacing();



	ImGui::NextColumn();
	//loading bars here
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[0] != NULL)
	{
		ImGui::Text("Scene 1 Loading");
		this->progress1 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->maxObjects;
		ImGui::ProgressBar(this->progress1, ImVec2(200.0f, 0.0f));
		if (this->progress1 == 1) {
			this->completedSceneLoadingCount++;
			dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->hasLoaded = true;
		}
	}
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[1] != NULL)
	{
		ImGui::Text("Scene 2 Loading");
		this->progress2 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->maxObjects;
		ImGui::ProgressBar(this->progress2, ImVec2(200.0f, 0.0f));
		if (this->progress2 == 1) {
			this->completedSceneLoadingCount++;
			dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->hasLoaded = true;
		}
	}
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[2] != NULL)
	{
		ImGui::Text("Scene 3 Loading");
		this->progress3 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->maxObjects;
		ImGui::ProgressBar(this->progress3, ImVec2(200.0f, 0.0f));
		if (this->progress3 == 1) {
			this->completedSceneLoadingCount++;
			dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->hasLoaded = true;
		}
	}
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[3])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[3] != NULL)
	{
		ImGui::Text("Scene 4 Loading");
		this->progress4 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[3])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[3])->maxObjects;
		ImGui::ProgressBar(this->progress4, ImVec2(200.0f, 0.0f));
		if (this->progress4 == 1) {
			this->completedSceneLoadingCount++;
			dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[3])->hasLoaded = true;
		}
	}
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[4])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[4] != NULL)
	{
		ImGui::Text("Scene 5 Loading");
		this->progress5 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[4])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[4])->maxObjects;
		ImGui::ProgressBar(this->progress5, ImVec2(200.0f, 0.0f));
		if (this->progress5 == 1) {
			this->completedSceneLoadingCount++;
			dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[4])->hasLoaded = true;
		}
	}

	ImGui::NextColumn();

	//total load progress bar
	ImGui::Text("Total Load");
	this->totalProgress = ((this->progress1 + this->progress2 + this->progress3 + this->progress4 + this->progress5) / (float)this->queuedForSceneLoadingCount);
	ImGui::ProgressBar(this->totalProgress, ImVec2(200.0f, 0.0f));

	ImGui::Spacing();

	//scene info here
	std::string sceneInfo = "Currently Viewing Scene: " + SceneManager::Instance()->getCurrentScene();
	ImGui::Text(sceneInfo.c_str());
	


	ImGui::End();
}
