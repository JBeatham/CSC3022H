#ifndef _HuffNode_H
#define _HuffNode_H
#include <memory>
#include <string>
class HuffmanTree;
struct compare;
class HuffmanNode{
	friend class HuffmanTree;
	friend struct compare;
	private:
		char character;
		int count;
		std::shared_ptr<HuffmanNode> right, left;
	
	public:
		HuffmanNode(HuffmanNode left, HuffmanNode right);
		HuffmanNode(char character, int count);
		HuffmanNode();
		~HuffmanNode();
		HuffmanNode & operator=(const HuffmanNode & other);
		HuffmanNode(HuffmanNode && other);
		HuffmanNode & operator=(HuffmanNode && other);
		HuffmanNode(const HuffmanNode & other);
		

		HuffmanNode getLeft();
		HuffmanNode getRight();
		int getCount();
		char getChar();

		void setCount(int num);
};
#endif
