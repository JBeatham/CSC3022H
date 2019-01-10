#ifndef _databases_H
#define _databases_H
#include <string>
#include <vector>

using namespace std;

namespace BTHJAM006{
	void AddStudent(string name,string surname, string stdntnum, string grade);
	void ReadDatabase(string file);
	void SaveDatabase(string file);
	void Display(string num);
	void Grade(string num);
	struct StudentRecord{
		string Name;
		string Surname;
		string StdNumber;
		string ClassRecord;
	};
	
	int Search(string num);
}

#endif
