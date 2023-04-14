#include "BNS_FileExplorer.h"

#include "BNS_UICreation.h"
#include "BNS_UIManager.h"

BNS_FileExplorer* BNS_FileExplorer::sharedInstance = nullptr;

BNS_FileExplorer* BNS_FileExplorer::GetInstance()
{
	return sharedInstance;
}

void BNS_FileExplorer::Initialize()
{
	sharedInstance = new BNS_FileExplorer();
}

void BNS_FileExplorer::Release()
{
	delete sharedInstance;
}

void BNS_FileExplorer::InitializeFiles()
{
	imageTable["dlsu_logo"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Textures\\dlsu_logo.png");
	imageTable["file_icon"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\file_icon.png");
	imageTable["folder_icon"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\folder_icon.png");
	imageTable["s1"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\s1.png");
	imageTable["s2"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\s2.png");
	imageTable["s3"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\s3.png");
	imageTable["s4"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\s4.png");
	imageTable["s5"] =
		BNS_UIManager::m_ui_creation->CreateUI_Image(L"Assets\\Icons\\s5.png");
}

BNS_FileExplorer::uiImageHashTable BNS_FileExplorer::GetImageHashTable()
{
	return imageTable;
}

BNS_FileExplorer::BNS_FileExplorer()
{
	InitializeFiles();
}

BNS_FileExplorer::~BNS_FileExplorer()
{
}
