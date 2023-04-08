#include "BNS_PARCMLoader_UI.h"

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
		
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 2", ImVec2(100, 0)))
	{
		
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 3", ImVec2(100, 0)))
	{
		
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 4", ImVec2(100, 0)))
	{
		
	}
	ImGui::Spacing();
	if(ImGui::Button("Scene 5", ImVec2(100, 0)))
	{
		
	}
	ImGui::Spacing();
	if(ImGui::Button("Load All Scenes", ImVec2(100, 0)))
	{
		
	}



	ImGui::NextColumn();
	//loading bars here



	ImGui::NextColumn();
	//scene info here
	ImGui::Text("Current Loaded Scene: testname\n");
	ImGui::Text("Number of objects: testnum\n");


	ImGui::End();
}
