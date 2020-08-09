#include "file_stream.h"
#include "tum_files.h"
#include "video_play.h"

int main() {

	TumRgbFileProcessor tum;
	string folder = "F:\\SlamDatasets\\rgbd_dataset_freiburg1_desk\\rgbd_dataset_freiburg1_desk\\";
	tum.SetRootFolder(folder);

	VideoPlayer video;

	StreamProcessor stream;
	stream.SetFileProcessor(&tum);
	stream.SetFrameProcessor(&video);
	stream.SetFrameBegin(0);
	stream.SetFrameEnd(100);
	stream.GetReady();
	stream.Run();

	return 0;
}