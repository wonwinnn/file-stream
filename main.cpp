#include "file_stream.h"
#include "tum_files.h"
#include "video_play.h"

int main() {

	string folder = "F:\\SlamDatasets\\rgbd_dataset_freiburg1_desk\\rgbd_dataset_freiburg1_desk\\";

	TumRgbFileProcessor tum_rgb;
	tum_rgb.SetRootFolder(folder);

	TumDepthFileProcessor tum_depth;
	tum_depth.SetRootFolder(folder);

	VideoPlayer video;

	StreamProcessor stream;
	stream.AddFileProcessor(&tum_rgb);
	stream.AddFileProcessor(&tum_depth);
	stream.SetFrameProcessor(&video);
	stream.SetFrameBegin(0);
	stream.SetFrameEnd(100);
	stream.GetReady();
	stream.Run();

	return 0;
}