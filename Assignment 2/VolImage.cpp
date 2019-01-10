#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "VolImage.h"
#include <limits>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

BTHJAM006::VolImage::VolImage(){
	height = 0;
	width = 0;
}

BTHJAM006::VolImage::~VolImage(){
	for(int i=0;i<slices.size();i++){
		for(int j=0;j<height;j++){
			delete[] slices[i][j];
		}
		delete[] slices[i];
	}

}

bool BTHJAM006::VolImage::readImages(string baseName){
	string line;	
	int num;
	string swidth;
	string sheight;
	string snum;	

	ifstream in ("brain_mri_raws/MRI.data");
	getline(in,line);
	istringstream iss(line);
	iss>>swidth>>ws>>sheight>>ws>>snum;
	
	width = stoi(swidth);
	height = stoi(sheight);
	num = stoi(snum);
	try{
		int count = 0;
		for(int i=0;i<num;i++){
			
			ifstream file ("brain_mri_raws/MRI"+to_string(i)+".raw", ios::in|ios::binary);
			
			if (file.is_open()){
				//cout<<"Hello"<<endl;
				unsigned char ** tImage = new unsigned char*[height];
				for(int j=0;j<height;j++){
					char * tRow = new char[width];
				
					//cout<<"Hello"<<endl;
					file.read(tRow, width);
					//cout<<"Hello"<<endl;
					tImage[j]= (unsigned char *)tRow;
				
				}
				//cout<<"Hello"<<endl;
				
				slices.push_back(tImage);
				file.close();
			}
		}
	}
	catch(exception e){
		cout<<"readImages failed"<<endl;
		return false;
	}
	return true;
}

void BTHJAM006::VolImage::diffmap(int i, int j, string output_prefix){
	ofstream outfile (output_prefix+".raw",ios::out|ios::binary|ios::trunc);
	ofstream datafile(output_prefix+".dat",ios::out);
	
	datafile << width <<" "<< height<<" "<<1;
	datafile.close();
	
	for(int h=0;h<height;h++){
		for(int w=0;w<width;w++){
			outfile << (unsigned char)(abs((float)slices[i][h][w] - (float)slices[j][h][w])/2);
		}
	}
	outfile.close();
	cout<<"diffmap success"<<endl;

}


void BTHJAM006::VolImage::extract(int sliceId, std::string output_prefix){
	ofstream outfile(output_prefix+".raw",ios::out|ios::binary|ios::trunc);
	ofstream datafile(output_prefix+".dat",ios::out);
	
	datafile << width <<" "<< height<<" "<<1;
	datafile.close();
	for(int h=0;h<height;h++){
		for(int w=0;w<width;w++){
			outfile << slices[sliceId][h][w];
		}
		
	}
	outfile.close();
	cout<<"extract success"<<endl;
}

int BTHJAM006::VolImage::volImageSize(void){
	int size = width*height*slices.size();
	size = size + slices.size()*height*sizeof(unsigned char*);
	size = size + slices.size()*sizeof(unsigned char**);

	return size;

}

int BTHJAM006::VolImage::imageNum(void){
	return slices.size();
}
