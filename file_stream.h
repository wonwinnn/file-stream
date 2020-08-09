#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// The file processor interface
class FileProcessor {
public:
	bool ReadFrame(int frame_num, Mat &output);
	virtual string CreateFileNameByRule(int frame_num) = 0;
	virtual Mat FileRead(string file_name) = 0;
};

class FileToolkit : public FileProcessor {
public:
	string ReadRow(ifstream & in, int row);
	string ReadColunmFromRow(string row_string, char separator, int colunm);
};

// The frame processor interface
class FrameProcessor {
public:
	virtual void ProcessFrame(Mat &input) = 0;
};

class StreamProcessor {
private:
	bool ready_;
	bool stopped_ = false;
	int frame_begin_ = 0;
	int frame_end_ = 0;
	int frame_current_ = 0;
	FileProcessor *file_processor_;
	FrameProcessor *frame_processor_;
public:
	void SetFileProcessor(FileProcessor *file_processor);
	void SetFrameProcessor(FrameProcessor *frame_processor);
	void SetFrameBegin(int frame_begin);
	void SetFrameEnd(int frame_end);
	void GetReady();
	void Run();
};

#endif // !FILE_STREAM_H
#pragma once
