#include <fstream>
#include <iostream>
#include "file_stream.h"

using namespace std;

String FileToolkit::ReadRow(ifstream &in, int row) {

	string buf;
	int line_cnt = 0;
	in.seekg(0, ios::beg);
	while (getline(in, buf)) {
		line_cnt++;
		if (line_cnt == row)
			break;
	}
	return buf;
}

string FileToolkit::ReadColunmFromRow(string row_string, char separator, int colunm) {

	if (row_string.back() != separator)
		row_string = row_string + separator;

	int colunm_cnt = 1;
	string colunm_string;
	int begin = -1;
	int last_begin = begin;
	bool colunm_find = false;
	while ((begin = row_string.find(separator, begin + 1)) != string::npos) {
		if (colunm_cnt == colunm) {
			colunm_find = true;
			break;
		}
		colunm_cnt++;
		last_begin = begin;
	}

	if (colunm_find == true)
		return row_string.substr(last_begin + 1, begin - last_begin - 1);
	else {
		cout << "Invalid column" << endl;
		return colunm_string;
	}
}

bool FileProcessor::ReadFrame(int frame_num, Mat &output) {

	string file_name = CreateFileNameByRule(frame_num);
	if (!file_name.empty()) {
		Mat frame = FileRead(file_name);
		frame.copyTo(output);
	}
	else
		return 0;

	return 1;
}

void StreamProcessor::SetFileProcessor(FileProcessor *file_processor) {

	file_processor_ = file_processor;
}

void StreamProcessor::SetFrameProcessor(FrameProcessor *frame_processor) {

	frame_processor_ = frame_processor;
}

void StreamProcessor::SetFrameBegin(int frame_begin) {

	frame_begin_ = frame_begin;
}

void StreamProcessor::SetFrameEnd(int frame_end) {

	frame_end_ = frame_end;
}


void StreamProcessor::GetReady() {

	frame_current_ = frame_begin_;
}

void StreamProcessor::Run(){

	Mat frame;
	while (!stopped_) {
		if (file_processor_->ReadFrame(frame_current_, frame)) {
			frame_processor_->ProcessFrame(frame);
			frame_current_++;
			if (frame_current_ == frame_end_)
				stopped_ = true;
		}
		else {
			cout << "Invalid frame" << endl;
			stopped_ = true;
		}
	}
}