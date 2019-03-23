#ifndef HISTOGRAM_5_H
#define HISTOGRAM_5_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

using namespace std;

class Histogram_5{
private:
  vector<int> histogram_5;
  vector<int> threshold;
  vector< vector<int> > brightness;

public:
  Histogram_5();
  ~Histogram_5();
  Histogram_5(Image i);
  vector<int> getThreshold();
  vector< vector<int> > getBrightness();
};

#endif
