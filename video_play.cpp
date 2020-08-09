#include "video_play.h"

void VideoPlayer::ProcessFrame(Mat &input) {

	imshow("video", input);
	waitKey(100);
}