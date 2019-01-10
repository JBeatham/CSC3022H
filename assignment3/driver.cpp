#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "HuffTree.h"


using namespace std;

int main(int argc,char * argv[]){
	unordered_map<char, int> unMap;
	string input;
	string output;
	char character;


	if(argc>=3){
		input = argv[1];
		output = argv[2];
		ifstream in (input);
		//getline(in,line);
		
		while(in>>noskipws>>character){
			if(unMap.count(character)>0){
				unMap.insert(make_pair(character,1));				
			}
			else{
				++unMap[character];
			}
		}
		in.close();

		HuffmanTree manTree = HuffmanTree(unMap);
		string buffer = "";
		ifstream inTwo (input);
		while(in>>noskipws>>character){
			buffer = buffer + manTree.getBitString(character);
		}
		inTwo.close();

		ofstream out(output, ofstream::binary);

		out<<buffer;
		out.close();
		unordered_map<char, string> codeTable = manTree.getTable();
		ofstream outTwo (output +".hdr");
		out<<codeTable.size()<< "\n";
		for(auto i : codeTable){
			out<<i.first<<" "<<i.second<<"\n";
		}
		outTwo.close();	
	}
}

