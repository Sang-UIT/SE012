#include "Game.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "Sprite.h"
// timming variable 
long start = GetTickCount();
Sprite* Kitty = NULL;
int _left = 0;
// initialize the game
HRESULT result;
Game::Game()
{
}

Game::~Game()
{
}


int Game::Game_Init(HWND hwnd)
{

	// set ramdom number seed
	srand(time(NULL));
	D3DXCreateSprite(DirectDevice::d3ddev, &DirectDevice::mSpriteHandler);
	Kitty = new Sprite(DirectDevice::mSpriteHandler, "kitty.bmp", 92, 60, 6, 3);

	
	
	// return okay
	return 1;
}

// the main game loop
void Game::Game_Run(HWND hwnd)
{

	// make sure the direct3d device is valid
	if (DirectDevice::d3d == NULL)
	{
		return;
	}

	// after short delay , ready for next frame
	// this keeps the game runnning at a steady frame rate	
	if (GetTickCount() - start >= 30)
	{
		start = GetTickCount();
	}
	LPDIRECT3DSURFACE9 surface = NULL;


	// đánh dấu bắt đầu vẽ 1 frame(start rendering)

	DirectDevice::d3ddev->BeginScene();


	if (TRUE)
	{
		DirectDevice::d3ddev->ColorFill(DirectDevice::backbuffer, NULL, D3DCOLOR_XRGB(255, 0, 0));
	
		Kitty->Render(DirectDevice::backbuffer, _left, 100);
		Kitty->Next();
		_left = (_left + 10) % SCREEN_WIDTH;
		// stop rendering
		int y=DirectDevice::d3ddev->EndScene();
		if (y == 1)
			MessageBox(NULL, "123", "321", MB_OK);
		else if (y == 0)
			MessageBox(NULL, "sdsada", "dsadas", MB_OK);

	}


	// display the backbuffer on the screen
	DirectDevice::d3ddev->Present(NULL, NULL, NULL, NULL);
	// check for escape key(to exit program)
	if (KEY_DOWN(VK_ESCAPE))
		PostMessage(hwnd, WM_DESTROY, 0, 0);
}

void Game::Game_End(HWND hwnd)
{
	if (DirectDevice::d3d != NULL)
		DirectDevice::d3d->Release();
	if (DirectDevice::d3ddev != NULL)
		DirectDevice::d3ddev->Release();
}