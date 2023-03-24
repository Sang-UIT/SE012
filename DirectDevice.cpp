#include "DirectDevice.h"
LPDIRECT3D9 DirectDevice::d3d = NULL;
LPDIRECT3DDEVICE9 DirectDevice::d3ddev = NULL;
LPD3DXSPRITE DirectDevice::mSpriteHandler = NULL;

LPDIRECT3DSURFACE9 DirectDevice::backbuffer = NULL;

DirectDevice::DirectDevice()
{
}

DirectDevice::~DirectDevice()
{
}
