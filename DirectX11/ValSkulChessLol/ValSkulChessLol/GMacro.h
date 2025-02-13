#pragma once

#define PI		3.141592f

// MACRO
#define DEVICE	Device::Instance()->GetDevice()
#define DC		Device::Instance()->GetDC()

#define WIN_WIDTH		1200
#define WIN_HEIGHT		720
#define CENTER			Vector(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f)

#define SAMPLER		StateManager::Instance()->GetSampler()
#define ALPAH		StateManager::Instance()->GetAlpha()
#define ADDITIVE	StateManager::Instance()->GetAdditive()
#define BLEND		StateManager::Instance()->GetBlend()

#define KEY_DOWN(k)		InputManager::Instance()->Down(k)
#define KEY_UP(k)		InputManager::Instance()->Up(k)
#define KEY_PRESS(k)	InputManager::Instance()->Press(k)

#define DELTA_TIME		TimeManager::Instance()->DeltaTime()
#define RUN_TIME		TimeManager::Instance()->RunTime()