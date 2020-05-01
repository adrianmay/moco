/**
  @file videowriter_basic.cpp
  @brief A very basic sample for using VideoWriter and VideoCapture
  @author PkLab.net
  @date Aug 24, 2016
*/

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace cv;
using namespace std;

string input="http://192.168.1.120/action/stream?subject=mjpeg&user=admin&pwd=12345";
string output="/out/moco.avi";
int preview=0;

int setOpts(int argc, char** argv)
{
  opterr = 0;
  int c;
  while ((c = getopt (argc, argv, "pdi:o:")) != -1)
  switch (c)
    {
    case 'p':
      preview = 1;
      break;
    case 'i':
      input = optarg;
      break;
    case 'd':
      input = "";
      break;
    case 'o':
      output = optarg;
      break;
    case '?':
      if (optopt == 'i')
        fprintf (stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint (optopt))
        fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
      return 1;
    default:
      abort ();
    }
  return 0;
}

int main(int argc, char** argv)
{
  int res = setOpts(argc, argv);
  if (res) return res;

  Mat frame;
  VideoCapture cap;
  if (input!="")
    cap.open(input);
  else 
    cap.open(0);
  if (!cap.isOpened()) {
    cerr << "ERROR! Unable to open camera\n";
    return -1;
  }

  cap >> frame;
  if (frame.empty()) { cerr << "ERROR! blank frame grabbed\n"; return -1; }

  VideoWriter writer;
  int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
  double fps = 25.0;
  writer.open(string(output), codec, fps, frame.size(), true);
  if (!writer.isOpened()) { cerr << "Could not open the output video file for write\n"; return -1; }

  cout << "Writing videofile: " << output << endl
       << "Press any key to terminate" << endl;

  for (;;)
  {
    if (!cap.read(frame)) { cerr << "ERROR! blank frame grabbed\n"; continue; }

    writer.write(frame);
    if (preview) {
      imshow("Live", frame);
      if (waitKey(5) >= 0)
        break;
    }
  }
  // the videofile will be closed and released automatically in VideoWriter destructor
  return 0;
}


