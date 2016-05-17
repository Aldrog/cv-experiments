#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/stitching.hpp>

using namespace std;
using namespace cv;

int main() {
    Stitcher stitcher = Stitcher::createDefault();
    vector<Mat> images;
    for(int i = 0; i < 3; ++i) {
        string filename = "IMG_" + to_string(i + 1) + ".jpg";
        images.push_back(imread(filename));
    }
    Mat res;
    int code = stitcher.stitch(images, res);
    imwrite("result.jpg", res);
    return code;
}