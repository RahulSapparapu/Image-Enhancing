#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Histogram_5.h"
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

using namespace std;

Histogram_5::Histogram_5(){}

Histogram_5::~Histogram_5(){}

Histogram_5::Histogram_5(Image i):brightness(i.get_h(),vector <int> (i.get_w())){
  int h=i.get_h();
  int w=i.get_w();

  // vector< vector <int> > brightness(h,vector <int> (w));

  for(int k=0;k<h;k++){
    for(int j=0;j<w;j++){
      Color c;
      c=i.get_p(k,j).get_c();
      brightness[k][j]=(c.get_r()+c.get_b()+c.get_g())/3;
    }
  }
  vector <int> histogram_5(256,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      histogram_5[brightness[i][j]]++;
    }
  }

  for(int i=1;i<255;i++){
    if(histogram_5[i]<histogram_5[i-1] && histogram_5[i+1]>histogram_5[i] && histogram_5[i]!=0 && histogram_5[i+1]!=0 && histogram_5[i-1]!=0 )
      threshold.push_back(i);
  }

}

vector<int> Histogram_5::getThreshold(){
  return threshold;
}

vector< vector<int> > Histogram_5::getBrightness(){
  return brightness;
}
