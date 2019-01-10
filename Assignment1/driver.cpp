#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "databases.h"
#include <limits>

int main()
{
	char x;
	bool isRunning = true;
	
	for(;isRunning;){
		std::cout << "0: Add student" << std::endl;
		std::cout << "1: Read database" << std::endl;
		std::cout << "2: Save database" << std::endl;
		std::cout << "3: Display given student data" << std::endl;
		std::cout << "4: Grade student" << std::endl;
		std::cout << "q: Quit" << std::endl;
	
		std::cin>>x;
		std::system("clear");
		if(x == 'q'){
			isRunning = false;
			break;
			}
		else if(x == '0'){
			std::cout << "GIVE NAME SURNAME STDNTNUM" << std::endl;
			std::string name;
			std::string sur;
			std::string num;
			std::string grade;
			std::cin>>name>>std::ws>>sur>>std::ws>>num;
			std::cout << "GRADES" << std::endl;
			std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			std::getline(std::cin,grade,'\n');
			BTHJAM006::AddStudent(name,sur,num,grade);
		}
		else if(x == '1'){
			std::cout << "ENTER FILE NAME. NO EXTENSIONS." << std::endl;
			std::string file;
			std::cin>>file;
			BTHJAM006::ReadDatabase(file);
		}
		else if(x == '2'){
			std::cout << "ENTER FILE> NO EXTENSION" << std::endl;
			std::string file;
			std::cin>>file;
			BTHJAM006::SaveDatabase(file);
		}
		else if(x == '3'){
			std::cout << "STUDENT NUMBER?" << std::endl;
			std::string num;
			std::cin>>num;
			BTHJAM006::Display(num);
		}
		else if(x == '4'){
			std::cout << "STUDENT NUMBER?" << std::endl;
			std::string num;
			std::cin>>num;
			BTHJAM006::Grade(num);
		}
	}

}
