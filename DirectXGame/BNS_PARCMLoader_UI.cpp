#include "BNS_PARCMLoader_UI.h"
#include "SceneManager.h"
#include "ObjectScene.h"

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


	if (ImGui::Button("Scene 1", ImVec2(100, 0)))
	{
		SceneManager::Instance()->loadSceneByIndex(0);
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 2", ImVec2(100, 0)))
	{
		SceneManager::Instance()->loadSceneByIndex(1);
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 3", ImVec2(100, 0)))
	{
		SceneManager::Instance()->loadSceneByIndex(2);
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 4", ImVec2(100, 0)))
	{
		SceneManager::Instance()->loadSceneByIndex(3);
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 5", ImVec2(100, 0)))
	{
		SceneManager::Instance()->loadSceneByIndex(4);
	}
	ImGui::Spacing();
	if(ImGui::Button("Load All Scenes", ImVec2(100, 0)))
	{
		SceneManager::Instance()->loadAllScenes();
	}



	ImGui::NextColumn();
	//loading bars here
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[0] != NULL)
	{
		ImGui::Text("Scene 1 Loading");
		ImGui::ProgressBar((float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->maxObjects, ImVec2(200.0f, 0.0f));
	}
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[1] != NULL)
	{
		ImGui::Text("Scene 2 Loading");
		ImGui::ProgressBar((float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->maxObjects, ImVec2(200.0f, 0.0f));
	}
	if (dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->maxObjects != 0 && SceneManager::Instance()->getSceneList()[2] != NULL)
	{
		ImGui::Text("Scene 3 Loading");
		ImGui::ProgressBar((float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->maxObjects, ImVec2(200.0f, 0.0f));
	}

	ImGui::NextColumn();
	//scene info here
	ImGui::Text("Current Loaded Scene: testname\n");
	ImGui::Text("Number of objects: testnum\n");


	ImGui::End();
}
