#include <iostream>
#include <fstream>
#include <string>
#include <map>
//#include "treeprinter.h"
#include "huffman.h"

typedef std::map<char, int> MAP_CHAR_WEIGHT;
typedef std::pair<char, int> PAIR_CHAR_WEIGHT;
int main() {
	std::fstream fin;
	fin.open("huffman.txt");
	char ch;
	MAP_CHAR_WEIGHT mapCharWeight;
	while (fin && fin.get(ch)) {
		if (mapCharWeight.find(ch) == mapCharWeight.end())
			mapCharWeight.insert(PAIR_CHAR_WEIGHT(ch, 1));
		else {
			++(mapCharWeight.find(ch)->second);
		}
	}
	fin.close();
	std::vector<Node<char>> vecNode;
	for (MAP_CHAR_WEIGHT::iterator it = mapCharWeight.begin(); it != mapCharWeight.end(); ++it) {
		Node<char> node(it->first, it->second);
		vecNode.push_back(node);
	}

	insertionsort(vecNode);

	HuffmanTree<char> huffmantree(vecNode);
	TreePrinter<char> printer;
	huffmantree.setId();
	Node<char>* p = huffmantree.root();
	visitNode<char>(p);
	huffmantree.inOrder(p, visitNode<char>);
	printer.compress(huffmantree);
	std::cout << std::endl;
	//Node<char> node_serach = *(huffmantree.root()->left()->right());
	//std::cout << std::endl;
	//Node<char>* result=	huffmantree.search(node_serach, result);
	//std::cout << (*result).left()->data() << " " << (*result).weight() << std::endl;
	printer.update(huffmantree);
	printer.show(1);
	return 0;
}