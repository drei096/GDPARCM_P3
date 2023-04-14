#include "BNS_PARCMLoader_UI.h"

#include "BNS_FileExplorer.h"
#include "BNS_Texture.h"
#include "SceneManager.h"
#include "ObjectScene.h"
#include "IETSemaphore.h"
#include "BNS_UIManager.h"

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
			if (!dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[i])->hasLoaded) {
				ImGui::CloseCurrentPopup();
				ImGui::OpenPopup(("Loading##" + std::to_string(i)).c_str());
			}

		}

		ImGui::SameLine();
		TexturePtr icon = BNS_FileExplorer::GetInstance()->GetImageHashTable()["s" + std::to_string(i + 1)];
		static float thumbnailSize = 128.0f;
		ImGui::ImageButton((void*)icon.get()->GetShaderResourceView(),
			{ thumbnailSize, thumbnailSize }, { -1, 0 }, { 0,1 },
			-1, ImVec4(1.0f, 1.0f, 1.0f, 0.5f));


		ImGui::Spacing();
	}

	ImGui::Text("Load All Scenes");
	ImGui::Spacing();
	if (ImGui::Button("Load##5", ImVec2(150, 0)))
	{
		SceneManager::Instance()->loadAllScenes();
		if (this->queuedForSceneLoadingCount < 5) 
		{
			for (int i = this->queuedForSceneLoadingCount; i < 5; i++)
				this->queuedForSceneLoadingCount++;
		}
		
	}
	ImGui::SameLine();
	if (ImGui::Button("Toggle##5", ImVec2(150, 0)))
	{

		this->totalProgress = ((this->progress1 + this->progress2 + this->progress3 + this->progress4 + this->progress5) / (float)this->queuedForSceneLoadingCount);
		if (this-> totalProgress < 1) {
			ImGui::CloseCurrentPopup();
			ImGui::OpenPopup("Loading##5");
		}
		else 
		{
			SceneManager::Instance()->toggleAllScenes();
		}
	}
	ImGui::Spacing();



	ImGui::NextColumn();
	

	//loading bars here
	DrawLoadingBars();

	ImGui::NextColumn();

	DrawPopUpUI();

	ImGui::Text("Total Load");
	this->totalProgress = ((this->progress1 + this->progress2 + this->progress3 + this->progress4 + this->progress5) / (float)this->queuedForSceneLoadingCount);
	ImGui::ProgressBar(this->totalProgress, ImVec2(200.0f, 0.0f));

	//scene info here
	std::string sceneInfo = "Currently Viewing Scene: " + SceneManager::Instance()->getCurrentScene();
	ImGui::Text(sceneInfo.c_str());
	


	ImGui::End();
}

void BNS_PARCMLoader_UI::DrawLoadingBars()
{
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
}

void BNS_PARCMLoader_UI::DrawPopUpUI()
{
	ImGui::SetNextWindowPos(ImVec2((BNS_UIManager::WINDOW_WIDTH / 2) - 200, (BNS_UIManager::WINDOW_HEIGHT / 2) - 200));
	if (ImGui::BeginPopup("Loading##0"))
	{
		//total load progress bar
		ImGui::Text("Scene 1 Loading");
		this->progress1 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[0])->maxObjects;
		ImGui::ProgressBar(this->progress1, ImVec2(400.0f, 0.0f));
		if (this->progress1 == 1) {
			SceneManager::Instance()->toggleSceneByIndex(0);
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::SetNextWindowPos(ImVec2((BNS_UIManager::WINDOW_WIDTH / 2) - 200, (BNS_UIManager::WINDOW_HEIGHT / 2) - 200));
	if (ImGui::BeginPopup("Loading##1"))
	{
		//total load progress bar
		ImGui::Text("Scene 2 Loading");
		this->progress2 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[1])->maxObjects;
		ImGui::ProgressBar(this->progress2, ImVec2(400.0f, 0.0f));
		if (this->progress2 == 1) {
			SceneManager::Instance()->toggleSceneByIndex(1);
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::SetNextWindowPos(ImVec2((BNS_UIManager::WINDOW_WIDTH / 2) - 200, (BNS_UIManager::WINDOW_HEIGHT / 2) - 200));
	if (ImGui::BeginPopup("Loading##2"))
	{
		//total load progress bar
		ImGui::Text("Scene 3 Loading");
		this->progress3 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[2])->maxObjects;
		ImGui::ProgressBar(this->progress3, ImVec2(400.0f, 0.0f));
		if (this->progress3 == 1) {
			SceneManager::Instance()->toggleSceneByIndex(2);
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::SetNextWindowPos(ImVec2((BNS_UIManager::WINDOW_WIDTH / 2) - 200, (BNS_UIManager::WINDOW_HEIGHT / 2) - 200));
	if (ImGui::BeginPopup("Loading##3"))
	{
		//total load progress bar
		ImGui::Text("Scene 4 Loading");
		this->progress4 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[3])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[3])->maxObjects;
		ImGui::ProgressBar(this->progress4, ImVec2(400.0f, 0.0f));
		if (this->progress4 == 1) {
			SceneManager::Instance()->toggleSceneByIndex(3);
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::SetNextWindowPos(ImVec2((BNS_UIManager::WINDOW_WIDTH / 2) - 200, (BNS_UIManager::WINDOW_HEIGHT / 2) - 200));
	if (ImGui::BeginPopup("Loading##4"))
	{
		//total load progress bar
		ImGui::Text("Scene 5 Loading");
		this->progress5 = (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[4])->countLoaded / (float)dynamic_cast<ObjectScene*>(SceneManager::Instance()->getSceneList()[4])->maxObjects;
		ImGui::ProgressBar(this->progress5, ImVec2(400.0f, 0.0f));
		if (this->progress5 == 1) {
			SceneManager::Instance()->toggleSceneByIndex(4);
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::SetNextWindowPos(ImVec2((BNS_UIManager::WINDOW_WIDTH / 2) - 200, (BNS_UIManager::WINDOW_HEIGHT / 2) - 200));
	if (ImGui::BeginPopup("Loading##5"))
	{
		ImGui::Text("Total Load");
		this->totalProgress = ((this->progress1 + this->progress2 + this->progress3 + this->progress4 + this->progress5) / (float)this->queuedForSceneLoadingCount);
		ImGui::ProgressBar(this->totalProgress, ImVec2(400.0f, 0.0f));
		if (this->totalProgress >= 1) 
		{
			SceneManager::Instance()->toggleAllScenes();
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}
