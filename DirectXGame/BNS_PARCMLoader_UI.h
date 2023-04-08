#pragma once

#include "BNS_AUIScreen.h"

class BNS_PARCMLoader_UI : public BNS_AUIScreen
{
public:
	BNS_PARCMLoader_UI(std::string name, int ID);
	~BNS_PARCMLoader_UI();
	void DrawUI() override;
};

