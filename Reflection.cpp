#include "Reflection.h"
#include <iostream>
using namespace std;
Reflection::Reflection(){}

Reflection::~Reflection(){}

Reflection::Reflection(Image i):Image(i){
  int h=i.get_h();
  int w=i.get_w();
  for(int k=0;k<h/2;k++){
      for(int j=0;j<w;j++){
        Pixel a;
        a=i.get_p(k,j);
        Pixel b;
        b=i.get_p(h-k-1,j);
        (*this).set_p(b,k,j);
        (*this).set_p(a,h-k-1,j);
      }
  }
}
