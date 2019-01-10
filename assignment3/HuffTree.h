#ifndef _HuffTree_H
#define _HuffTree_H


#include "HuffNode.h"
#include <queue>
#include <cstdlib>
#include <unordered_map>



class HuffmanTree{
	private:
		std::shared_ptr<HuffmanNode> rootNode;
		std::unordered_map<char, std::string> cTable;		

	public:
		HuffmanTree(std::unordered_map<char,int> unMap);
		~HuffmanTree();
		
		HuffmanTree(const HuffmanTree & other);
		HuffmanTree(HuffmanTree && other);		
		HuffmanTree & operator=(const HuffmanTree & other);
		HuffmanTree & operator=(HuffmanTree && other);

		//bool operator()(const HuffmanNode& a,const HuffmanNode& b);
		void build(std::unordered_map<char, int> unMap);
		void makeCodeTable(HuffmanNode node, std::string code);
		std::string getBitString(char a);
		std::unordered_map<char, std::string> getTable();
		
};
#endif
