#include "Framerate.h"

void Framerate::Update(float frameRate)
{
	std::string frameRateText = "Frame Rate: " + std::to_string((int)frameRate);
	componentText.setString(frameRateText);
}