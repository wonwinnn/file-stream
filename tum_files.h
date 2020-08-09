#ifndef TUM_FILES_H
#define TUM_FILES_H

#include "file_stream.h"

class TumDepthFileProcessor : public FileToolkit {
private:
	string root_folder_;
	string depth_log_ = "depth.txt";
public:
	string CreateFileNameByRule(int frame_num);
	Mat FileRead(string file_name);
	void SetRootFolder(string root_folder);
};

class TumRgbFileProcessor : public FileToolkit {
private:
	string root_folder_;
	string rgb_log_ = "rgb.txt";
public:
	string CreateFileNameByRule(int frame_num);
	Mat FileRead(string file_name);
	void SetRootFolder(string root_folder);
};

#endif // !TUM_FILES_H
#pragma once
