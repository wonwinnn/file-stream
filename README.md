# file-stream
**A framework for processing a series of files/images**   

## Overview
Here's a simplified UML class diagram.  
![uml](https://img-blog.csdnimg.cn/20200817002754934.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3UwMTMyMTMxMTE=,size_16,color_FFFFFF,t_70#pic_center)
There are 4 basic components:  
1.FileToolkit, provides common functions for reading data from files.  
2.FileProcessor, provides (virtual) methods to convert files into certain format input frames (eg. cv::Mat).  
3.FrameProcessor, provides (virtual) methods to process each input frame.  
4.StreamProcess, controls the whole procedure.

## Example
Read files from TUM dataset and then output as a video.  
