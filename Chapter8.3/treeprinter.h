#include <vector>
#include <iostream>
#include <string>
#include "huffman.h"
#define MAX_SIZE 100

template <typename T>
class TreePrinter {
	template <typename T> friend class HuffmanTree;
	node<T> m_tree[MAX_SIZE] = { {0, 1, 0} };
	int m_cnt;

public:
	void trans(std::vector<std::string>& x, std::string before, std::string after);
    void compress(HuffmanTree<T>& tree);
	void show(int root_cnt, std::vector<std::string> pre = std::vector<std::string>(0));
private:
    void print_(Node<T>*& p);
};

template <typename T>
void TreePrinter<T>::show(int root, std::vector<std::string> pre) {
    auto& p = m_tree[root];
    if (p.m_elem != 0) {
        std::vector<std::string> temp(pre);
        trans(temp, "©°©¤©¤", "   ");
        trans(temp, "©¸©¤©¤", "©¦  ");
        temp.push_back("©°©¤©¤");
        show(p.m_indexL, temp);
    }
    for (auto& i : pre)
        std::cout << i;
    if (p.m_elem == 0)
        std::cout << "null" << std::endl;
    else
        std::cout << p.m_elem << std::endl;
    if (p.m_elem != 0) {
        std::vector<std::string> temp(pre);
        trans(temp, "©°©¤©¤", "©¦  ");
        trans(temp, "©¸©¤©¤", "   ");
        temp.push_back("©¸©¤©¤");
        show(p.m_indexR, temp);
    }
}

template<typename T>
void TreePrinter<T>::trans(std::vector<std::string>& x, std::string before, std::string after) {
	for (auto& p : x)
		if (p == before) {
			p = after;
			break;
		}
}

template<typename T>
void TreePrinter<T>::compress(HuffmanTree<T>& tree) {
    print_(tree.root());
}

template<typename T>
void TreePrinter<T>::print_(Node<T>*& p) {
    if (p != nullptr) {
        ++m_cnt;
        m_tree[m_cnt] = { p->data() };
        print_(p->m_left);
        print_(p->m_right);
    }
    return;
}