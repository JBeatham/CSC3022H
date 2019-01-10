#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "VolImage.h"
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

//volimage <imageBase> [-d i j output_file_name] [-x i output_file_name]

int main(int argc,char * argv[])
{
	if(argc>1){
		string bName = argv[1];
		BTHJAM006::VolImage img;
		if(img.readImages(bName)){
			cout<<"Number of images: "<< img.imageNum() <<endl;
			cout<<"Number of bytes required: "<<img.volImageSize()<<endl;

			if (argc==5 && string(argv[2])=="-x"){
				img.extract(atoi(argv[3]),string(argv[4]));
			}
			else if (argc == 6 && string(argv[2])=="-d"){
				img.diffmap(atoi(argv[3]),atoi(argv[4]),string(argv[5]));
			}			
		}	
	}
}
