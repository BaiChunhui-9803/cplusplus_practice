#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
class Set;
template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& s);
template <typename T>
Set<T> common(const Set<T>& a, const Set<T>& b);
template <typename T>
Set<T> sum(const Set<T>& a, const Set<T>& b);
template <typename T>
Set<T> swap(const Set<T>& a, const Set<T>& b);

template <typename T>
class Set {
	std::vector<T> m_elems;
public:
	Set() = default;
	Set(const std::vector<T>& l);
	bool is_elem(T);
	void insert(T);
	void erase(T);
	int find(T);
	void clear();
	int size();
	Set<T>& operator=(const Set<T>& s);
	Set<T>(const Set<T>& s);
	friend std::ostream& operator<<<>(std::ostream& os, const Set<T>& s);
	friend Set<T> common<>(const Set<T>& a, const Set<T>& b);
	friend Set<T> sum<>(const Set<T>& a, const Set<T>& b);
	friend void swap<>(Set<T>& a, Set<T>& b);
};

template <typename T>
Set<T>::Set(const std::vector<T>& list) {
	for (auto &it : list) {
		m_elems.push_back(it);
	}
}

template <typename T>
bool Set<T>::is_elem(T elem) {
	for (auto it = m_elems.begin(); it != m_elems.end(); it++)
		if (*it == elem) return true;
	return false;
}

template <typename T>
void Set<T>::insert(T elem) {
	this->m_elems.insert(this->m_elems.begin(), elem);
	//m_elems.push_back(elem);
}

template <typename T>
void Set<T>::erase(T elem) {
	for (auto it = m_elems.begin(); it != m_elems.end();) {
		if (*it == elem) it = m_elems.erase(it);
		else ++it;
	}
};

template <typename T>
int Set<T>::find(T elem) {
	if (!is_elem(elem)) return -1;
	else {
		int temp = 0;
		for (auto it = m_elems.begin(); it != m_elems.end(); it++)
			if (*it == elem) return temp;
			else temp++;
	}
}

template <typename T>
void Set<T>::clear() {
	m_elems.clear();
}

template <typename T>
int Set<T>::size() {
	return m_elems.size();
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& s) {
	if (this != &s) this->m_elems = s.m_elems;
	return *this;
}

template<typename T>
Set<T>::Set(const Set<T>& s) {
	this->m_elems = s.m_elems;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& s) {
	os << "{";
	for (int i = 0; i < s.m_elems.size(); i++) {
		os << s.m_elems[i];
		if (i != s.m_elems.size() - 1) {
			std::cout << ",";
		}
	}
	os << "}";
	return os;
}

template<typename T>
Set<T> common(const Set<T>& a, const Set<T>& b) {
	Set<T> set_common;
	for (auto it = b.m_elems.begin(); it != b.m_elems.end(); it++) {
		if (find(a.m_elems.begin(), a.m_elems.end(), *it) != a.m_elems.end()) set_common.insert(*it);
	}
	return set_common;
}

template<typename T>
Set<T> sum(const Set<T>& a, const Set<T>& b) {
	Set<T> set_sum(a);
	for (auto it = b.m_elems.begin(); it != b.m_elems.end(); it++) {
		if (find(a.m_elems.begin(), a.m_elems.end(), *it) == a.m_elems.end()) set_sum.insert(*it);
	}
	return set_sum;
}

template<typename T>
void swap(Set<T>& a, Set<T>& b) {
	Set<T> c(a);
	a = b;
	b = c;
}