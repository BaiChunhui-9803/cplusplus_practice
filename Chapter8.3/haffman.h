#include <vector>
#include <iostream>
template <typename T> class HaffmanTree;
template <typename T>
class Node {
	friend class HaffmanTree<T>;
private:
	T m_data;
	int m_weight = 0;
	Node* m_left = nullptr;
	Node* m_right = nullptr;
public:
	Node(const T& data) :m_data(data) {}
	Node(const T& data, const int& weight) :m_data(data), m_weight(weight) {}
	T& data() { return m_data; }
	const T& data() const { return m_data; }
	int weight() { return m_weight; }
	const int weight() const { return m_weight; }
	Node* left() { return m_left; }
	Node* right() { return m_right; }
};

template <typename T>
class HaffmanTree {
private:
	Node<T>* m_root = nullptr;
	int m_number = 0;
	std::vector<int> m_vector;
public:
	HaffmanTree() = default;
	HaffmanTree(const HaffmanTree&) = delete;
	HaffmanTree& operator=(const HaffmanTree&) = delete;
	~HaffmanTree() { destroy(m_root); }
	void setNumber(const int& number) { m_number = number; }
	int getNumber() { return m_number; }
	Node<T>* root() const { return m_root; }
	Node<T>* insert(const T& value) { return insert_(m_root, value); }
	Node<T>* search(const T& value) const { return search_(m_root, value); }
	void preOrder(Node<T>* p, void(*visit)(T&));
	void inOrder(Node<T>* p, void(*visit)(T&));
	void postOrder(Node<T>* p, void(*visit)(T&));
private:
	Node<T>* insert_(Node<T>*& p, const T& value);
	Node<T>* search_(Node<T>* p, const T& value) const;
	void destroy(Node<T>* p);
};


template <typename T>
void HaffmanTree<T>::destroy(Node<T>* p) {
	if (p != nullptr) {
		destroy(p->m_left);
		destroy(p->m_right);
		delete p;
	}
	m_vector.clear();
}

template <typename T>
Node<T>* HaffmanTree<T>::insert_(Node<T>*& p, const T& value) {
	if (p == nullptr)
		return p = new(std::nothrow) Node<T>(value);
	else if (value < p->m_data)
		return insert_(p->m_left, value);
	else
		return insert_(p->m_right, value);
}

template <typename T>
Node<T>* HaffmanTree<T>::search_(Node<T>* p, const T& value) const {
	while (p != nullptr && p->m_data != value) {
		if (value < p->m_data) p = p->left;
		else p = p->m_right;
	}
	return p;
}

template <typename T>
void HaffmanTree<T>::preOrder(Node<T>* p, void(*visit)(T&)) {
	if (p != nullptr) {
		visit(p->m_data);
		inOrder(p->left, visit);
		inOrder(p->right, visit);
	}
}

template <typename T>
void HaffmanTree<T>::inOrder(Node<T>* p, void(*visit)(T&)) {
	if (p != nullptr) {
		inOrder(p->left, visit);
		visit(p->m_data);
		inOrder(p->right, visit);
	}
}

template <typename T>
void HaffmanTree<T>::postOrder(Node<T>* p, void(*visit)(T&)) {
	if (p != nullptr) {
		inOrder(p->left, visit);
		inOrder(p->right, visit);
		visit(p->m_data);
	}
}

template <typename T>
void visit(T& value) {
	std::cout << value << " ";
}