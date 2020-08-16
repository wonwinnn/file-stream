#ifndef VIDEO_PLAY_H
#define VIDEO_PLAY_H

#include "file_stream.h"

class VideoPlayer : public FrameProcessor {
public:
	void ProcessFrame(vector<Mat> &input);
};

#endif // !VIDEO_PLAY_H
#pragma once
