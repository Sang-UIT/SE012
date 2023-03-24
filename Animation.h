#pragma once
#include "Sprite.h"
class Animation
{
public:
	Animation(int count = 1, int begin = 0, int end = 0, int delay = 1);
	~Animation();

	int totalFrameCount;
	int beginframe; // chỉ số frame đầu của animation hiện tại
	int curframe;	// chỉ số frame hiện tại
	int endframe;	// chỉ số frame cuối của animation hiện tại
	int animdelay;
	int animcount;
	Sprite** sprite;
};

