#include "HuffNode.h"

using namespace std;

HuffmanNode::HuffmanNode(HuffmanNode less, HuffmanNode more){
	left = make_shared<HuffmanNode>(less);
	right = make_shared<HuffmanNode>(more);
	count = less.getCount()+more.getCount();
}

HuffmanNode::HuffmanNode(char character, int count){
	character = character;
	count = count;
	left =nullptr;
	right =nullptr;
}

HuffmanNode::~HuffmanNode(){}

HuffmanNode::HuffmanNode(const HuffmanNode & other): count(other.count),character(other.character){
	left = other.left;
	right = other.right;
}

HuffmanNode & HuffmanNode::operator=(const HuffmanNode & other){
	left = other.left;
	right = other.right;
	count = other.count;
	character = other.character;
}

HuffmanNode::HuffmanNode(HuffmanNode && other): count(move(other.count)), character(move(other.character)){
	left = other.left;
	right = other.right;

	other.left = nullptr;
	other.right = nullptr;
}

HuffmanNode & HuffmanNode::operator=(HuffmanNode && other){
	count = move(other.count);
	character = move(other.character);	

	left = move(other.left);
	right = move(other.right);
}

HuffmanNode HuffmanNode::getLeft(){return *left;}

HuffmanNode HuffmanNode::getRight(){return *right;}

int HuffmanNode::getCount(){return count;}

char HuffmanNode::getChar(){return character;}


void HuffmanNode::setCount(int num){
	count = num;
}

