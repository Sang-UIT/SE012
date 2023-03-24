#include "Animation.h"

Animation::Animation(int count, int begin, int end, int delay)
{
	totalFrameCount = count;
	animcount = 0;
	animdelay = delay;
	beginframe = begin;
	endframe = end;
	curframe = beginframe;

	sprite = new Sprite * [count];
	
}
Animation::~Animation()
{
	for (int i = 0; i < totalFrameCount; i++) {
		delete sprite[i];
	}
	delete[] sprite;
}