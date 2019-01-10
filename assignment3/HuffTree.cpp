#include "HuffTree.h"

using namespace std;

struct compare{
	bool operator()(const HuffmanNode& a, const HuffmanNode& b){
		return (a.count < b.count);
	}
};


HuffmanTree::HuffmanTree(unordered_map<char, int> unMap){
	build(unMap);
	makeCodeTable(*rootNode,"");
}

HuffmanTree::~HuffmanTree(){}

HuffmanTree::HuffmanTree(const HuffmanTree & other){
	rootNode = other.rootNode;
}

HuffmanTree & HuffmanTree::operator=(const HuffmanTree & other){
	rootNode = other.rootNode;
}

HuffmanTree::HuffmanTree(HuffmanTree && other){
	rootNode = other.rootNode;

	other.rootNode = nullptr;
}

HuffmanTree & HuffmanTree::operator=(HuffmanTree && other){
	rootNode = move(other.rootNode);
}



void HuffmanTree::build(unordered_map<char, int> unMap){
	priority_queue<HuffmanNode, vector<HuffmanNode>,compare> queue;		

	for(auto i:unMap){
		queue.emplace(i.first,i.second);
	}
	while(queue.size()>1){
		HuffmanNode tmp = HuffmanNode(queue.top(),queue.top());
		queue.pop();
		queue.pop();
		queue.push(tmp);
		
	}
	rootNode = make_shared<HuffmanNode>(queue.top());
	queue.pop();
}

void HuffmanTree::makeCodeTable(HuffmanNode node, string code){
	if(node.left){
		makeCodeTable(node.getLeft(),(code + "0"));
		makeCodeTable(node.getRight(),(code + "1"));
	}
	else{
		cTable.insert(make_pair(node.character,code));
	}
	return;
}

string HuffmanTree::getBitString(char a){
	return cTable[a];
}

unordered_map<char, string> HuffmanTree::getTable(){
	return cTable;
}
