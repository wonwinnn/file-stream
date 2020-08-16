#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class FileToolkit {
private:
	FileToolkit() = default;
public:
	FileToolkit(const FileToolkit&) = delete;
	FileToolkit& operator = (const FileToolkit&) = delete;
	static FileToolkit& get_instance();
	~FileToolkit() = default;
	string ReadRow(ifstream & in, int row);
	string ReadColumnFromRow(string row_string, char separator, int column);
};

class FileProcessor {	
public:
	FileToolkit &file_toolkit_ = FileToolkit::get_instance();
	Mat ReadFrame(int frame_num);
	virtual string CreateFileNameByRule(int frame_num) = 0;
	virtual Mat FileRead(string file_name) = 0;
};

// The frame processor interface
class FrameProcessor {
public:
	virtual void ProcessFrame(vector<Mat> &input) = 0;
};

class StreamProcessor {
private:
	bool ready_;
	bool stopped_ = false;
	int frame_begin_ = 0;
	int frame_end_ = 0;
	int frame_current_ = 0;
	vector<Mat> frame_inputs_;
	vector<FileProcessor *>file_processors_;
	FrameProcessor *frame_processor_;
public:
	void AddFileProcessor(FileProcessor *file_processor);
	void SetFrameProcessor(FrameProcessor *frame_processor);
	void SetFrameBegin(int frame_begin);
	void SetFrameEnd(int frame_end);
	void GetReady();
	void Run();
};

#endif // !FILE_STREAM_H
#pragma once
