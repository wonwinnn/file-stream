# file-stream
**A framework for processing a series of files/images**   

## Overview
Here's a simplified UML class diagram.  
![uml](https://img-blog.csdnimg.cn/20200817002754934.png)
There are 4 basic components:  
1.FileToolkit, provides common functions for reading data from files.  
2.FileProcessor, provides (virtual) methods to convert files into certain format input frames (eg. cv::Mat).  
3.FrameProcessor, provides (virtual) methods to process each input frame.  
4.StreamProcess, controls the whole procedure.

## Example
Read files from TUM dataset and then output as a video.  
