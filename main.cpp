#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include "CompositeImage.h"
#include "Binarize.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
int main(int argc,char**argv)
{
	int r1,g1,b1;
	ifstream myfile;
	myfile.open(argv[1],ios::out);
	ofstream ofile;
	ofile.open("composite.ppm");
	ofstream ofile1;
	ofstream ofile2;
	ofile1.open("binarize1.ppm");
	ofile2.open("binarize2.ppm");
	int a,b,red,green,blue,range,c;
	float alpha;
	string s;
	myfile>>s>>a>>b>>range;
    Image image(a,b);
	for(int i=0;i < b;i++)											
	{	
		for(int j=0;j<a;j++)
		{
			myfile>>r1>>g1>>b1;
			Color color(r1,g1,b1);
			Pixel p(i,j,color);
			image.set_p(p,i,j);
		}
    }
	float f=0.2;
    Binarize ans1(image.get_w(),image.get_h());
     ans1.convert1(image);
    Binarize ans2(image.get_w(),image.get_h());
    ans2.convert2(image);
	CompositeImage com(ans2,ans1,f);
	ofile<<com;
	ofile1<<ans1;
	ofile2<<ans2;
	myfile.close();
	ofile.close();
}