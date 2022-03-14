#include <vector>
#include <iostream>

#define MAX_SIZE 100
template <typename T>
struct node {
	T m_elem;
	int m_wt;
	int m_id = 0;
	int m_indexL, m_indexR;
};

template <typename T>
class Node;
template <typename T>
class HuffmanTree;
template <typename T>
class TreePrinter {
	friend class Node<T>;
	friend class HuffmanTree<T>;
	node<T> m_tree[MAX_SIZE] = { {0, 0, 0, 1, 0} };
	int m_cnt = 0;

public:
	void trans(std::vector<std::string>& x, std::string before, std::string after);
	void compress(HuffmanTree<T>& tree);
	void show(int root_cnt, std::vector<std::string> pre = std::vector<std::string>(0));
	int find(Node<T>& node);
	void update(HuffmanTree<T>& tree);
private:
	void print_(Node<T>* p);
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
	Node<T>* root = tree.root();
	print_(root);

}

template<typename T>
int TreePrinter<T>::find(Node<T>& node) {
	for (int i = 1; i < MAX_SIZE; i++) {
		if (m_tree[i].m_elem == node.data() && m_tree[i].m_wt == node.weight()) {
			return i;
		}
	}
	return 0;
}

template<typename T>
void TreePrinter<T>::update(HuffmanTree<T>& tree) {
	for (int i = 1; i < MAX_SIZE; i++) {
		Node<T> search(m_tree[i].m_elem, m_tree[i].m_wt, m_tree[i].m_id);
		Node<T>* result = tree.search(search, result);
		if (result->left() != nullptr) {
			m_tree[i].m_indexL = find(*(result->left()));
			m_tree[i].m_id = result->left()->id();
		}
		else m_tree[i].m_indexL = 0;
		if (result->right() != nullptr) {
			m_tree[i].m_indexR = find(*(result->right()));
			m_tree[i].m_id = result->right()->id();
		}
		else m_tree[i].m_indexR = 0;
		/*result->left() != nullptr ? m_tree[i].m_indexL = find(*(result->left())) : m_tree[i].m_indexL = 0;
		result->right() != nullptr ? m_tree[i].m_indexR = find(*(result->right())) : m_tree[i].m_indexR = 0;*/
		//if (result->left() != nullptr) m_tree[i].m_indexL = find(*(result->left()));
		//else m_tree[i].m_indexL = 0;
		//m_tree[i].m_indexR = find(*(result->right()));
	}
}

template<typename T>
void TreePrinter<T>::print_(Node<T>* p) {
	if (p != nullptr) {
		++m_cnt;
		m_tree[m_cnt] = { p->data(), p->weight() };
		print_(p->left());
		print_(p->right());
	}
	return;
}

template <typename T> class HuffmanTree;
template <typename T>
class Node {
	friend class HuffmanTree<T>;
private:
	T m_data;
	int m_weight = 0;
	int m_id = 0;
	Node* m_left = nullptr;
	Node* m_right = nullptr;
public:
	Node() = default;
	Node(const T& data) :m_data(data) {}
	Node(const T& data, const int& weight, const int& id) :m_data(data), m_weight(weight), m_id(id) {}
	Node(const T& data, const int& weight) :m_data(data), m_weight(weight) {}
	T& data() { return m_data; }
	const T& data() const { return m_data; }
	int weight() { return m_weight; }
	const int weight() const { return m_weight; }
	int id() { return m_id; }
	const int id() const { return m_id; }
	Node* left() { return m_left; }
	Node* right() { return m_right; }
	Node<T>& operator=(const Node<T>& node) {
		if (this != &node) {
			this->m_data = node.m_data;
			this->m_weight = node.m_weight;
			this->m_left = node.m_left;
			this->m_right = node.m_right;
		}
		return *this;
	}
	bool operator==(const Node<T>& node) const {
		if (node.data() == this->data() && node.weight() == this->weight()) return true;
		else return false;
	}
};
template <typename T>
void visitNode(Node<T>*& node);
template <typename T>
void visit(T& value);

struct Less {
	bool operator () (const int& a, const int& b) {
		return a < b;
	}
};

template <typename F = Less>
void insertionsort(std::vector<Node<char>>& vec, F f = F()) {
	for (int i = 1, j = 1; i < vec.size(); ++i) {
		Node<char> t = vec[i];
		for (j = i; j > 0; --j) {
			if (f(vec[j - 1].weight(), t.weight()))
				break;
			vec[j] = vec[j - 1];
		}
		vec[j] = t;
	}
}

template <typename T>
class HuffmanTree {
private:
	Node<T>* m_root = nullptr;
	int m_number = 0;
	int m_cnt = 0;
public:
	HuffmanTree() = default;
	HuffmanTree(const HuffmanTree&) = delete;
	HuffmanTree& operator=(const HuffmanTree&) = delete;
	~HuffmanTree() { destroy(m_root); }
	HuffmanTree(std::vector<Node<char>>& vec);
	Node<T>& build2Nodes(Node<T> &left, Node<T> &right);
	void setNumber(const int& number) { m_number = number; }
	int getNumber() { return m_number; }
	Node<T>* root() const { return m_root; }
	void build(Node<T>& node) { Node<T>* q = &node; build_(m_root, q); }
	void setId() { setID_(m_root); }
	Node<T>* insert(const T& value) { return insert_(m_root, value); }//ËÑË÷Ê÷
	Node<T>* search(const T& value) const { return search_(m_root, value); }//ËÑË÷Ê÷
	Node<T>* search(const Node<T>& node, Node<T>*& result) { return search_(m_root, node, result); }//ËÑË÷Ê÷
	void preOrder(Node<T>* p, void(*visitNode)(Node<T>*&));
	void preOrder(Node<T>* p, void(*visit)(T&));
	void inOrder(Node<T>* p, void(*visitNode)(Node<T>*&));
	void inOrder(Node<T>* p, void(*visit)(T&));
	void postOrder(Node<T>* p, void(*visit)(T&));//ËÑË÷Ê÷;
private:
	void build_(Node<T>*& p, Node<T>* q);
	void setID_(Node<T>*& p);
	Node<T>* insert_(Node<T>*& p, const T& value);//ËÑË÷Ê÷
	Node<T>* search_(Node<T>* p, const T& value) const;//ËÑË÷Ê÷
	Node<T>* search_(Node<T>* p, const Node<T>& node, Node<T>*& result);
	void destroy(Node<T>* p);
};

template <typename T>
HuffmanTree<T>::HuffmanTree(std::vector<Node<char>>& vec) {
	m_number = vec.size();
	std::vector<Node<char>> vec_erase(2 * m_number);
	int loop = 0;
	while (vec.size() > 1) {
		vec_erase.at(2 * loop) = vec.at(0);
		vec_erase.at(2 * loop + 1) = vec.at(1);
		vec.erase(vec.begin());
		vec.erase(vec.begin());
		Node<T> new_node(build2Nodes(vec_erase.at(2 * loop), vec_erase.at(2 * loop + 1)));
		vec.push_back(new_node);
		insertionsort(vec);
		++loop;
	}
	//inOrder(&(vec.at(0)), visitNode<T>);
	//std::cout << std::endl;
	build(vec.at(0));

}

template<typename T>
void HuffmanTree<T>::setID_(Node<T>*& p) {
	if (p != nullptr) {
		p->m_id = ++m_cnt;
		setID_(p->m_left);
		setID_(p->m_right);
	}
	return;
}

template <typename T>
void HuffmanTree<T>::build_(Node<T>*& p, Node<T>* q) {
	if (p == nullptr && q != nullptr) {
		p = new(std::nothrow) Node<T>(q->m_data, q->m_weight);
		//std::cout << p->m_data << " " << p->m_weight << " " << p->m_id << std::endl;
		build_(p->m_left, q->m_left);
		build_(p->m_right, q->m_right);
	}
	return;
}

template <typename T>
Node<T>& HuffmanTree<T>::build2Nodes(Node<T> &left, Node<T> &right) {
	Node<T> new_node('@', left.weight() + right.weight());
	new_node.m_left = &left;
	new_node.m_right = &right;
	return new_node;
}

template <typename T>
void HuffmanTree<T>::destroy(Node<T>* p) {
	if (p != nullptr) {
		destroy(p->m_left);
		destroy(p->m_right);
		delete p;
	}
}

template <typename T>
Node<T>* HuffmanTree<T>::insert_(Node<T>*& p, const T& value) {
	if (p == nullptr)
		return p = new(std::nothrow) Node<T>(value);
	else if (value < p->m_data)
		return insert_(p->m_left, value);
	else
		return insert_(p->m_right, value);
}

template <typename T>
Node<T>* HuffmanTree<T>::search_(Node<T>* p, const T& value) const {
	while (p != nullptr && p->m_data != value) {
		if (value < p->m_data) p = p->left;
		else p = p->m_right;
	}
	return p;
}

template<typename T>
Node<T>* HuffmanTree<T>::search_(Node<T>* p, const Node<T>& node, Node<T>*& result) {
	if (p != nullptr) {
		if (*p == node) {
			result = p;
		}
		search_(p->left(), node, result);
		search_(p->right(), node, result);
	}
	return result;
}

template <typename T>
void HuffmanTree<T>::preOrder(Node<T>* p, void(*visitNode)(Node<T>*&)) {
	if (p != nullptr) {
		visitNode(p);
		inOrder(p->m_left, visitNode);
		inOrder(p->m_right, visitNode);
	}
}

template <typename T>
void HuffmanTree<T>::preOrder(Node<T>* p, void(*visit)(T&)) {
	if (p != nullptr) {
		visit(p->m_data);
		preOrder(p->m_left, visit);
		preOrder(p->m_right, visit);
	}
}

template <typename T>
void HuffmanTree<T>::inOrder(Node<T>* p, void(*visitNode)(Node<T>*&)) {
	if (p != nullptr) {
		inOrder(p->m_left, visitNode);
		visitNode(p);
		inOrder(p->m_right, visitNode);
	}
}

template <typename T>
void HuffmanTree<T>::inOrder(Node<T>* p, void(*visit)(T&)) {
	if (p != nullptr) {
		inOrder(p->m_left, visit);
		visit(p->m_data);
		inOrder(p->m_right, visit);
	}
}

template <typename T>
void HuffmanTree<T>::postOrder(Node<T>* p, void(*visit)(T&)) {
	if (p != nullptr) {
		postOrder(p->m_left, visit);
		postOrder(p->m_right, visit);
		visit(p->m_data);
	}
}

template <typename T>
void visit(T& value) {
	std::cout << value << " ";
}

template <typename T>
void visitNode(Node<T>*& node) {
	std::cout << node->data() << " " << node->weight() << " " << node->id() << std::endl;
}