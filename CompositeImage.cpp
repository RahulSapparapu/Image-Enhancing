#include "CompositeImage.h"
#include <iostream>

CompositeImage::CompositeImage() {

}

CompositeImage::CompositeImage(Image a, Image b, float alpha):
  Image(a.get_w(), a.get_h()){
    if(a.get_w() == b.get_w() && a.get_h() == b.get_h()) {
      for(int i=0;i<_h;i++) {
        for(int j=0;j<_w;j++) {
          _p[i][j] = alpha*(a.get_pr(i,j)) + (1-alpha)*(b.get_pr(i,j));
        }
      }
    }
}

CompositeImage::~CompositeImage() {

}

// CompositeImage::CompositeImage(const CompositeImage& other):
//   Image(other.get_w(), other.get_h()) {
//       (*this)=other;
//     }
// }
