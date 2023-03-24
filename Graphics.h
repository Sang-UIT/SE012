#pragma once

// Chapter 3 graphics.h v1.0
#ifndef _GRAPHICS_H // Prevent multiple definitions if this
#define _GRAPHICS_H // file is included in more than one place
#include <d3d9.h>
#include "Game.h"
#include "DirectDevice.h"


class Graphics
{
public:
	Graphics();// Constructor	
	~Graphics();// Destructor
	
	static int Init_Direct3D(HWND hw, int width, int height, bool fullscreen);
	static LPDIRECT3DSURFACE9 LoadSurface(char*);
	static LPDIRECT3DTEXTURE9 LoadTexture(char*, D3DCOLOR);
};
#endif
