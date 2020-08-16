#include <fstream>
#include <iostream>
#include "file_stream.h"

using namespace std;

FileToolkit& FileToolkit::get_instance() {

	static FileToolkit instance;
	return instance;
}

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

string FileToolkit::ReadColumnFromRow(string row_string, char separator, int column) {

	if (row_string.back() != separator)
		row_string = row_string + separator;

	int column_cnt = 1;
	int begin = -1;
	int last_begin = begin;
	bool column_find = false;
	while ((begin = row_string.find(separator, begin + 1)) != string::npos) {
		if (column_cnt == column) {
			column_find = true;
			break;
		}
		column_cnt++;
		last_begin = begin;
	}

	if (column_find == true)
		return row_string.substr(last_begin + 1, begin - last_begin - 1);
	else {
		cout << "Invalid column" << endl;
		return "";
	}
}

Mat FileProcessor::ReadFrame(int frame_num) {

	Mat frame;
	string file_name = CreateFileNameByRule(frame_num);
	if (!file_name.empty())
		frame = FileRead(file_name);

	return frame;
}

void StreamProcessor::AddFileProcessor(FileProcessor *file_processor) {

	file_processors_.push_back(file_processor);
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

	while (!stopped_) {
		if (!file_processors_.empty()) {
			for (vector<FileProcessor *>::iterator it = file_processors_.begin();
				it != file_processors_.end(); it++)
				frame_inputs_.push_back((*it)->ReadFrame(frame_current_));
			frame_processor_->ProcessFrame(frame_inputs_);
			frame_current_++;
			frame_inputs_.clear();
			if (frame_current_ == frame_end_)
				stopped_ = true;
		}
		else {
			cout << "Invalid frame" << endl;
			stopped_ = true;
		}
	}
}