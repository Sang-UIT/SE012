#pragma once

#ifndef _INPUT_H
#define _INPUT_H 1


#include <d3d9.h>
#include <dinput.h>
class Input
{
public:
	Input();
	~Input();

	static int Init_DirectInput(HWND);
	static int Init_Keyboard(HWND);
	static void Poll_Keyboard();
	static int KeyDown(int);
	static void Kill_Keyboard();
	static int Init_Mouse(HWND);
	static void Poll_Mouse();
	static int Mouse_Button(int);
	static int Mouse_X();
	static int Mouse_Y();
	static void Kill_Mouse();
};
#endif

