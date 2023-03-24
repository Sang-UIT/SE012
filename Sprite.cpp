#include "Sprite.h"

Sprite::Sprite(LPD3DXSPRITE SpriteHandler,const char* Path, int Width, int Height, int Count, int SpritePerRow)
{
	D3DXIMAGE_INFO info;
	HRESULT result;

	_Image = NULL;
	DirectDevice::mSpriteHandler = SpriteHandler;

	_Width = Width;
	_Height = Height;
	_Count = Count;
	_SpritePerRow = SpritePerRow;
	_Index = 0;

	result = D3DXGetImageInfoFromFile(Path, &info);
	LPDIRECT3DDEVICE9 d3ddv; SpriteHandler->GetDevice(&d3ddv);
	result = D3DXCreateTextureFromFileEx(
		d3ddv, Path,
		info.Width, info.Height,
		1,				//Mipmap levels
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),		// Transparent color
		&info,				// Image information
		NULL,
		&_Image);
}

Sprite::Sprite(const Sprite& rhs)
{	
}

void Sprite::Next()
{
}

void Sprite::Render(LPDIRECT3DSURFACE9 Target, int X, int Y)
{
	RECT srect;

	srect.left = (_Index % _SpritePerRow) * (_Width);
	srect.top = (_Index / _SpritePerRow) * (_Height);
	srect.right = srect.left + _Width - 1;
	srect.bottom = srect.top + _Height - 1;

	DirectDevice::mSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXVECTOR3 position((float)X, (float)Y, 0);
	DirectDevice::mSpriteHandler->Draw(
		_Image,
		&srect,
		NULL,
		&position,
		D3DCOLOR_XRGB(255, 255, 255)	// Hardcode!
	);
	DirectDevice::mSpriteHandler->End();
}

Sprite::~Sprite()
{
}
