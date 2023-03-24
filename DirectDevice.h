#pragma once
#include <d3dx9.h>
#include <d3d9.h>
class DirectDevice
{
public:
	DirectDevice();
	~DirectDevice();
	static LPDIRECT3D9 d3d;
	static LPDIRECT3DDEVICE9 d3ddev; //device directX hiện tại
	static LPD3DXSPRITE mSpriteHandler; //spriteHanlder hiện tại

	static LPDIRECT3DSURFACE9 backbuffer;
};

