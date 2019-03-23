#include "Binarize.h"
#include "Histogram_5.h"
#include "Reflection.h"
#include "Reflection_y.h"

#include <iostream>
using namespace std;


Binarize:: Binarize(){}
Binarize::~Binarize(){}
Binarize::Binarize(int w,int h):Image(w,h)
{}
Binarize Binarize::convert1(Image image)
{
    Histogram_5 h(image);
    vector<int >v=h.getThreshold();
        int mean=0;
        cout<<v.size()<<endl;
        if(v.size()>=2)
        {
            Color white(255,255,255);
            Color blue(0,0,255);
            cout<<v[0]<< " "<<v[1]<<endl;
            for(int i=0;i<_h;i++)
            {
                for(int j=0;j<_w;j++)
                {
                    mean=(image.get_p(i,j).get_c().get_r()+image.get_p(i,j).get_c().get_b()+image.get_p(i,j).get_c().get_g())/3;
                    if(mean>v[0])
                    {
                        Pixel p(i,j,white);
                        set_p(p,i,j);
                    }
                    else
                    {
                        Pixel p1(i,j,blue);
                        set_p(p1,i,j);
                    }
                }
            }
        }
        else
        {
            cout<<"REFLECTION"<<endl;
            Reflection r(image);
            for(int i=0;i<image.get_h();i++ )
            {
                for(int j=0;j<image.get_w();j++)
                {
                    Pixel p(i,j,r.get_p(i,j).get_c());
                    set_p(p,i,j);
                }
            }
        }
    }
Binarize Binarize::convert2(Image image)
{
    Histogram_5 h(image);
    vector<int >v=h.getThreshold();
        int a[256];
        int mean=0;
        if(v.size()>=2)
        {
           Color white(255,255,255);
		   Color blue(255,255,0);
            for(int i=0;i<_h;i++)
            {
                for(int j=0;j<_w;j++)
                {
                    mean=(image.get_p(i,j).get_c().get_r()+image.get_p(i,j).get_c().get_b()+image.get_p(i,j).get_c().get_g())/3;
                    if(mean>v[1])
                    {
                        Pixel p(i,j,white);
                        set_p(p,i,j);
                    }
                    else
                    {
                        Pixel p1(i,j,blue);
                        set_p(p1,i,j);
                    }
                }
            }
            return (*this);
        }
        else
        {
            cout<<"REFLECTION"<<endl;
            Reflection_y  r(image);
            for(int i=0;i<image.get_h();i++ )
            {
                for(int j=0;j<image.get_w();j++)
                {
                    Pixel p(i,j,r.get_p(i,j).get_c());
                    set_p(p,i,j);
                }
            }
        }
}