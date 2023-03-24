#pragma once
// Anim_sprite program header file 
#define _GAME_H

#include <d3d9.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graphics.h"




// application title
#define APPTITLE "DirectX Game"

// screen setup
#define FULLSCREEN 0 // 1=fullscreen, 0=windowed
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// macros to read the keyboard asynchronously
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)& 0x8000)?1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code)& 0x8000)?1:0)

class Game
{
public:
	Game();
	~Game();
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;
	// function prototypes
	static int Game_Init(HWND);
	static void Game_Run(HWND);
	static void Game_End(HWND);
};

