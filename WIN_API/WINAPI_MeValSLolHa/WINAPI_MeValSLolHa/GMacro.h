#pragma once

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

// 선형보간
#define LERP(start, end, ratio)  start + (end - start) * ratio

#define BLACK		 RGB(0,0,0)
#define WHITE		 RGB(255,255,255)
#define RED			 RGB(255,0,0)
#define GREEN		 RGB(0,255,0)