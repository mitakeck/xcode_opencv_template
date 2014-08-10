//
//  main.cpp
//  opencv_test
//
//  Created by mitake on 8/9/14.
//  Copyright (c) 2014 三井 健史. All rights reserved.
//

#include <iostream>
#include <opencv/highgui.h>

int main(int argc, const char * argv[])
{
    CvCapture *capture;
    IplImage *frame;
    int c;
    
    capture = cvCreateCameraCapture(0);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);
    
    cvNamedWindow("camera");
    
    while (1) {
        frame = cvQueryFrame (capture);
        cvShowImage ("Capture", frame);
        c = cvWaitKey (2);
        if (c == '\x1b')
            break;
    }
    
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
    cvDestroyWindow("capture");

    return 0;
}

