#pragma once

#include "BNS_AUIScreen.h"

class BNS_PARCMLoader_UI : public BNS_AUIScreen
{
public:
	BNS_PARCMLoader_UI(std::string name, int ID);
	~BNS_PARCMLoader_UI();
	void DrawUI() override;

	void DrawLoadingBars();
	void DrawPopUpUI();

private:
	float progress1 = 0.0f;
	float progress2 = 0.0f;
	float progress3 = 0.0f;
	float progress4 = 0.0f;
	float progress5 = 0.0f;
	float totalProgress = 0.0f;

	int completedSceneLoadingCount = 0;
	int queuedForSceneLoadingCount = 5;
};

