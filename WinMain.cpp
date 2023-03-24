#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <stdio.h>
#include "Graphics.h"
#include "Game.h"
#include <string>



// window call back function 
LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:

		//call the "front-end" shutdown function
		Game::Game_End(hWnd);

		// tell windows to kill this program

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// helper function to set up the window properties
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	// create the window class structure
	WNDCLASSEX wc;
	// fill the struct with info 
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APPTITLE;
	wc.hIconSm = NULL;

	// set up the window with class info
	return RegisterClassEx(&wc);
}

// entry point Winmain for a window program
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	MSG msg;
	HWND hWnd;

	// register the class 
	MyRegisterClass(hInstance);

	
	// create new window 
	hWnd = CreateWindow(
		APPTITLE,
		APPTITLE,
		WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// was there an error creating the window ?
	if (!hWnd)
	{
		return FALSE;
	}

	// display the window 
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	
	if (!Graphics::Init_Direct3D(hWnd, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN))
	{
		return 0;
	}

	// initialize the game
	if (!Game::Game_Init(hWnd))
	{
		MessageBox(hWnd, ":((", "Error", MB_OK);
		return 0;
	}
	// main message loop
	int done = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// look for quit message
			if (msg.message == WM_QUIT)
			{
				done = 1;
			}

			// decode and pass message on to WndProc
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		else {
			// process game loop(else prevents running after window is closed )
			Game::Game_Run(hWnd);
		}

	}
	return msg.wParam;
	return 0;

}
