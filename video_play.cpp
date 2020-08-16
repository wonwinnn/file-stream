#include <string>
#include "video_play.h"

void VideoPlayer::ProcessFrame(vector<Mat> &input) {

	vector<Mat>::iterator it;
	int cnt = 0;
	for (it = input.begin(); it != input.end(); it++) {
		imshow("video" + to_string(cnt), *it);
		cnt++;
	}
	waitKey(100);
}