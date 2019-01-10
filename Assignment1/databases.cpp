#include "databases.h"
#include <fstream>
#include <iostream>
#include <sstream>
 

using namespace std;
//BTHJAM006::
vector<BTHJAM006::StudentRecord> vec;


int BTHJAM006::Search(string num){
	for (int i=0; i<vec.size();i++){
		if(vec[i].StdNumber == num){
			return i;
		}
	}
	return -1;
}

void BTHJAM006::AddStudent(string name,string surname, string stdntnum, string grade){
	StudentRecord tmp;
	tmp.Name = name;
	tmp.Surname = surname;
	tmp.StdNumber = stdntnum;
	tmp.ClassRecord = grade;
	
	int x = BTHJAM006::Search(stdntnum);
	if(x>=0){
		vec[x]=tmp;
	}
	else{
		vec.push_back(tmp);
	}

}

void BTHJAM006::ReadDatabase(string file){
	string filename = file+".txt";

	ifstream data(filename.c_str());

	if(!data){
		cout << "Couldn't open " << filename << endl;
		return; 
		}
	vec.clear();
	while(!data.eof()){
		string line;
		string notGrades;
		string grades;
		StudentRecord temp;

		getline(data,line);
		if(line.length()==0) break;
		int i = line.find_first_of(' ');

		notGrades.assign(line,0,i);
		temp.ClassRecord.assign(line,i+1,line.length()-1);
		
		int x = notGrades.find_first_of('#');
		temp.Name.assign(notGrades,0,x);
		notGrades.erase(0,x + 1);
		
		x = notGrades.find_first_of('#');
		temp.Surname.assign(notGrades,0,x);
		notGrades.erase(0,x + 1);

		temp.StdNumber.assign(notGrades,0,notGrades.length());
		int q = BTHJAM006::Search(temp.StdNumber);
		if(q>=0){
			vec[q]=temp;
		}
			vec.push_back(temp);
		
	}

	data.close();
}

void BTHJAM006::SaveDatabase(string file){
	string filename = file+".txt";

	ofstream outfile (file+".txt");

	for(int i=0;i<vec.size();i++){
		string out = vec[i].Name+'#'+vec[i].Surname+'#'+vec[i].StdNumber+' '+vec[i].ClassRecord;
		outfile << out << std::endl;
	}

	outfile.close();
}

void BTHJAM006::Display(string studentNum){
	int i = BTHJAM006::Search(studentNum);
	if(i>=0){
		cout << vec[i].Name<<' '<<vec[i].Surname<<' '<<vec[i].StdNumber<<' '<<vec[i].ClassRecord << endl;
	}
	else{cout<<"Damn, that guy doesn't exist"<<endl;}
}
void BTHJAM006::Grade(string num){
	int x = BTHJAM006::Search(num);
	if(x<0){
		cout<<"Damn, that guy doesn't exist"<<endl;
		return;
	}
	StudentRecord temp = vec[x];
	int total=0, tn =0;
	int count=0;
	stringstream stream(temp.ClassRecord);

	while(!stream.eof()){
		stream>>tn;
		count++;
		total += tn;
		
	}
	cout <<"GRADE AVERAGE = "<< total/count << endl;

}




















































