#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "image.h"

using namespace std;

int main(int argc,char * argv[]){
	image im1;
	image im2;
	image im3;

	if(argc == 5){
		char* argChar = argv[1];
		string arg(argChar);
		//cout<<"1"<<endl;
		if(arg=="-a"){
			//cout<<"2"<<endl;
			im1.load(argv[2]);
			//cout<<"3"<<endl;
			im2.load(argv[3]);
			//cout<<"4"<<endl;
			if(im1==im2){
				im3 = im1+im2;
				im3.save(argv[4]);
			}
		}
		else if(arg=="-s"){
			im1.load(argv[2]);
			im2.load(argv[3]);
			if(im1==im2){
				im3 = im1-im2;
				im3.save(argv[4]);
			}
		}
		else if(arg=="-l"){
			im1.load(argv[2]);
			im2.load(argv[3]);
			if(im1==im2){
				im3 = im1/im2;
				im3.save(argv[4]);
			}
		}
		else if(arg=="-t"){
			im1.load(argv[2]);
			im3 = im1*atoi(argv[3]);
			im3.save(argv[4]);
		}
	}
	
	else if(argc == 4){
		im1.load(argv[2]);
		im3 = !im1;
		im3.save(argv[3]);
	}
	
	else{
		cout<< "Wrong parameters"<<endl;
	}
	

}
