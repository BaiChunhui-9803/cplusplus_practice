#include "haffman.h"
#include <iostream>
#include <fstream>

bool is_elem(const std::vector<char>& vec, const char& ch) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (*it == ch) return true;
	}
	return false;
}

int main() {

	std::fstream fin;
	fin.open("huffman.txt");
	std::vector<char> charVector;


	char ch;
	while (fin && fin.get(ch)) {
		if (is_elem(charVector, ch)) {


		}
	}
	fin.close();




	return 0;
}