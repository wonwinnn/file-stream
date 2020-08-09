#include <iostream>
#include <fstream>
#include "tum_files.h"

string TumDepthFileProcessor::CreateFileNameByRule(int frame_num) {

	if (root_folder_.empty()) {
		cout << "Please set root folder" << endl;
		return "";
	}

	ifstream f;
	f.open(root_folder_ + depth_log_, ios::in);
	if (!f) {
		cout << "Cannot open file " << root_folder_ + depth_log_ << endl;
		return "";
	}

	string row_string = ReadRow(f, frame_num + 4); //data starts from 4th line
	string file_path = ReadColunmFromRow(row_string, ' ', 2); //use whitespace as separator
	replace(file_path.begin(), file_path.end(), '/', '\\');

	return root_folder_ + file_path;
}

Mat TumDepthFileProcessor::FileRead(string file_name) {

	return imread(file_name);
}

void TumDepthFileProcessor::SetRootFolder(string root_folder) {

	root_folder_ = root_folder;
}

string TumRgbFileProcessor::CreateFileNameByRule(int frame_num) {

	if (root_folder_.empty()) {
		cout << "Please set root folder" << endl;
		return "";
	}

	ifstream f;
	f.open(root_folder_ + rgb_log_, ios::in);
	if (!f) {
		cout << "Cannot open file " << root_folder_ + rgb_log_ << endl;
		return "";
	}

	string row_string = ReadRow(f, frame_num + 4); //data starts from 4th line
	string file_path = ReadColunmFromRow(row_string, ' ', 2);
	replace(file_path.begin(), file_path.end(), '/', '\\');

	return root_folder_ + file_path;
}

Mat TumRgbFileProcessor::FileRead(string file_name) {

	return imread(file_name);
}

void TumRgbFileProcessor::SetRootFolder(string root_folder) {

	root_folder_ = root_folder;
}