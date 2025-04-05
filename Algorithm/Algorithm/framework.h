// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <memory>
#include <string>
#include <wrl/client.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"dxguid.lib")

using namespace std;
using namespace DirectX;

#include "Core/Device/Device.h"

// MATH
#include "Core/Math/Vector.h"
#include "Core/Math/Transform.h"

// RENDER
#include "Core/Render/VertexLayout.h"
#include "Core/Render/VertexBuffer.h"
#include "Core/Render/IndexBuffer.h"
#include "Core/Render/VertexShader.h"
#include "Core/Render/PixelShader.h"

// BUFFER
#include "Core/Buffers/ConstantBuffer.h"
#include "Core/Buffers/BufferLayout.h"

// Utility
#include "Core/Utility/InputManager.h"
#include "Core/Utility/TimeManager.h"

// Collider
#include "Core/Math/Collider/RectCollider.h"
#include "Core/Math/Collider/CircleCollider.h"

// OBJECTS - bagic
#include "Objects/Bagic/Quad.h"

// SCENE
#include "Scene/Scene.h"

// PROGRAM
#include "Program/Program.h"

#include "GMacro.h"

extern HWND hWnd;
extern Vector mousePos;
