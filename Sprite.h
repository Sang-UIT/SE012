#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "DirectDevice.h"

class Sprite
{
protected:
	LPDIRECT3DTEXTURE9 _Image;		// The “container”

	int _Index; 		// Current sprite index
	int _Width;   	// Sprite width
	int _Height;		// Sprite height
	int _Count;		// Number of sprites in the container
	int _SpritePerRow;	// Number of sprites per row
public:
	Sprite(LPD3DXSPRITE SpriteHandler, const char *Path, int Width, int Height, int Count, int SpritePerRow);
	Sprite(const Sprite&);
	// Advance to next sprite in the list
	void Next();

	// Render current sprite at location (X,Y) at the target surface
	void Render(LPDIRECT3DSURFACE9 Target, int X, int Y);
	~Sprite();

};

