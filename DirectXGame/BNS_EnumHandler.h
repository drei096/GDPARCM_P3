#pragma once

enum class BNS_ObjectTypes
{
	CUBE = 0,
	MESH,
	PLANE,
	CAMERA,
	SKYBOX,
	SPHERE,
	CAPSULE,
	CYLINDER
};

enum class BNS_VertexShaderType
{
	TEXTURE = 0,
	MESH,
	COLOR,
	COLOR_LERP,
	LIGHTING,
	POINT_LIGHT
};

enum class BNS_PixelShaderType
{
	TEXTURE = 0,
	MESH,
	COLOR,
	COLOR_LERP,
	LIGHTING,
	SKYBOX,
	EARTH,
	POINT_LIGHT
};

enum class BNS_InputLayoutType
{
	TEXTURE = 0,
	MESH,
	COLOR,
	COLOR_LERP
};

enum class BNS_UINames
{
	PROFILER_SCREEN,
	MENU_SCREEN,
	INSPECTOR_SCREEN,
	HIERARCHY_SCREEN,
	SCENEVIEW_SCREEN,
	CONTENT_BROWSER_SCREEN,
	GAMEOBJECT_SCREEN,
	CONSOLE_SCREEN,
	STATE_SCREEN,
	VIEW_MODE,
	PARCM_LOADER_WINDOW
};

enum class ComponentType
{
	NotSet = -1,
	Script,
	Renderer,
	Input,
	Physics,
	Transform
};

//DEPRECATED
enum class LogType
{
	Display = 0,
	Warning,
	Error
};

enum class BNS_MeshType
{
	TEAPOT = 0,
	STATUE,
	BUNNY,
	ARMADILLO,
	SPHERE,
	CUBE,
	EARTH,
	CAPSULE,
	SAMPLE_SCENE,
};

class BNS_EnumHandler
{
	
};