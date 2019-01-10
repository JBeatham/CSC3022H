#include "image.h"


using namespace std;

image::image(){
	width = 0;
	height = 0;
}
image::~image(){}

image::image(string filename){
	load(filename);
}
image & image::operator=(image & other){
	height = other.height;
	width = other.width;
	
	data = move(other.data);
	
	return *this;
}

image::image(image & other){
	height = other.height;
	width = other.width;

	data = move(other.data);
}

image::image(image && other): width(move(other.width)), height(move(other.height)){
	data = unique_ptr<unsigned char[]>(other.data.get());
}
image & image::operator=(image && other){
	height = move(other.height);
	width = move(other.width);	

	data = move(other.data);
	
	return *this;
}

image image::operator+(image & rhs){
	image::iterator y = this->begin();
	image temp = image(rhs);
	for(int i=0;i<(height*width);i++){
		int entry =(int)*(y) + (int)temp.data.get()[i];
	
		if(entry>255){
			entry = 255;
		}

		temp.data[i] = (unsigned char)entry;
		y++;
	}
		
	return temp;
}
image image::operator-(image & rhs){
	image::iterator y = this->begin();
	image temp = image(rhs);

	for(int i=0;i<(height*width);i++){
		int entry =(int)*(y) - (int)temp.data.get()[i];
	
		if(entry<0){
			entry = 0;
		}

		temp.data[i] = (unsigned char)entry;
		y++;
	}
		
	return temp;
}
image image::operator!(void){
	image temp = image(*this);
	cout<< height<< " "<<width<<endl;
	for(int i=0;i<(height*width);i++){

		int entry =255- (int)temp.data.get()[i];
		temp.data.get()[i] = (unsigned char)entry;

	}
	return temp;
}
image image::operator/(image & rhs){
	image::iterator y = this->begin();
	image temp = image(*this);

	for(int i=0;i<(height*width);i++){
		unsigned char x = rhs.data.get()[i];

		if((int)x!=255){
			temp.data[i]=0;
		}
		y++;
	}
		
	return temp;
}
image image::operator*(int f){
	image::iterator y = this->begin();
	image temp = image(*this);

	for(int i=0;i<(height*width);i++){
		if((int)*y>=f){
			temp.data[i]=255;
		}
		else{
			temp.data[i]=0;
		}
		y++;
	}
		
	return temp;
}

image::iterator::iterator(u_char *p) : ptr(p) {}

image::iterator::iterator(const image::iterator & rhs): ptr(rhs.ptr) {}

image::iterator image::begin(){
	return image::iterator(data.get());
}

image::iterator image::end(){
	return image::iterator(data.get()+height*width);
}

void image::iterator::operator++(int){
	ptr++;
}

void image::iterator::operator--(int){
	ptr--;
}

unsigned char& image::iterator::operator*(){
	return *ptr;
}

void operator<<(std::ostream & o, image & rhs){
	string stuff ="";
	for(int i=0;i<rhs.height*rhs.width;i++){
		stuff = rhs.data.get()[i];
		o<<stuff;
	}
}

void operator>>(std::istream & p, image & rhs){
	unsigned char uChar [rhs.height*rhs.width];
	rhs.data = unique_ptr<unsigned char[]>(new unsigned char [rhs.height*rhs.width]);
	p.read((char*)uChar, rhs.height*rhs.width);
	image::iterator iter = rhs.begin();

	for(int i=0;i<rhs.width*rhs.height;i++){
		*iter = uChar[i];
		iter++;
	}
	
	
}

void image::load(std::string filename){
	ifstream infile(filename,ios::binary);
	string str;
	stringstream sstream;
	
	getline(infile,str);

	str="#";

	while(str[0]=='#'){
		getline(infile,str);
	}

	sstream << str;
	sstream >> height >> ws >> width;

	getline(infile,str);

	infile >> *this;
	infile.close();
}

void image::save(std::string filename){
	ofstream outfile(filename);

	outfile<< "P5"<<endl;
	outfile<<"#Did you ever hear the tragedy of Darth Plagueis the Wise?"<<endl;
	outfile<<"#I thought not. It's not a story the Jedi would tell you. It's a Sith legend."<<endl;
	outfile<<"#Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life... "<<endl;
	outfile<<"#He had such a knowledge of the dark side that he could even keep the ones he cared about from dying."<<endl;
	outfile<<"#The dark side of the Force is a pathway to many abilities some consider to be unnatural."<<endl;
	outfile<<"#He became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did."<<endl;
	outfile<<"#Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. It's ironic he could save others from death, but not himself."<<endl;

	outfile<<height<<" "<<width<<endl;
	outfile<<"255"<<endl;
	outfile<<*this;
	
	outfile.close();

}

bool image::operator==(image & rhs){
	return(height==rhs.height && width==rhs.width);
}
