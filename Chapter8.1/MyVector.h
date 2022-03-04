#include <iostream>

template <typename T>
class MyVector;

using namespace std;
template <typename T>
class MyVector {
	T* m_arr;
	int m_length = 0;
	int m_capacity = 0;
public:
	MyVector() = default;
	MyVector(const std::initializer_list<T>& list);
	MyVector(const MyVector<T>& rhs);
	MyVector<T>& operator=(const MyVector<T>& rhs);
	MyVector(MyVector<T>&& rhs);
	MyVector<T>& operator=(MyVector<T>&& rhs);
	~MyVector();

	int size();
	int capacity();
	T& operator[](const int& i);
	T& at(const int& i);
	T& front();
	T& back();
	void push_back(const T& elem);
	void pop_back();
	void insert(const int& item, const T& elem);
	void erase(const int& item);
	void clear();
};

template <typename T>
MyVector<T>::MyVector(const std::initializer_list<T>& list) {
	m_arr = list.size() > 0 ? new T[list.size()] : nullptr;
	for (int i = 0; i < list.size(); i++) {
		m_arr[i] = *(list.begin() + i);
		m_length++;
	}
	m_capacity = m_length;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& rhs) :m_length(rhs.m_length),m_capacity(rhs.m_capacity),
m_arr(m_arr = rhs.size() > 0 ? new T[rhs.size()] : nullptr) {
	for (int i = 0; i < m_length; i++) {
		m_arr[i] = rhs.m_arr[i];
	}
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs) {
	if (this != &rhs) {
		delete[]m_arr;
		m_length = rhs.m_length;
		m_capacity = rhs.m_capacity;
		m_arr = rhs.m_arr;
	}
	return *this;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& rhs) :m_length(rhs.m_length), m_capacity(rhs.m_capacity), m_arr(rhs.m_arr) {
	rhs.m_length = 0;
	rhs.m_capacity = 0;
	rhs.m_arr = nullptr;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& rhs) {
	if (this != &rhs) {
		delete[]m_arr;
		m_length = rhs.m_length;
		m_capacity = rhs.m_capacity;
		m_arr = rhs.m_arr;
		rhs.m_length = 0;
		rhs.m_arr = nullptr;
	}
	return *this;
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[]m_arr;
}

template <typename T>
int MyVector<T>::size() {
	return m_length;
}

template <typename T>
int MyVector<T>::capacity() {
	return m_capacity;
}

template <typename T>
T& MyVector<T>::operator[](const int& i) {
	if (i >= 0 && i < m_length) {
		return *(m_arr + i);
	}
	else throw "OUT_OF_RANGE";
}

template<typename T>
T& MyVector<T>::at(const int& i) {
	if (i >= 0 && i < m_length) {
		return *(m_arr + i);
	}
	else throw "OUT_OF_RANGE";
}

template<typename T>
T& MyVector<T>::front() {
	return *(m_arr[0]);
}

template<typename T>
T& MyVector<T>::back() {
	return *(m_arr[m_length - 1]);
}

template<typename T>
void MyVector<T>::push_back(const T& elem) {
	++m_length;
	if (m_capacity < m_length) {
		T* p = m_arr;
		m_capacity < 2 ? ++m_capacity : m_capacity += m_capacity / 2;
		m_arr = new T[m_capacity];
		for (int i = 0; i < m_length - 1; ++i) m_arr[i] = p[i];
		m_arr[m_length - 1] = elem;
		delete[]p;
	}
	else m_arr[m_length - 1] = elem;
}

template<typename T>
void MyVector<T>::pop_back() {
	if (m_length >= 1) --m_length;
	else cout << "´íÎó£º²»ÄÜ¶Ô¿ÕµÄÈÝÆ÷Ê¹ÓÃpop_back²Ù×÷" << endl;
}

template<typename T>
void MyVector<T>::insert(const int& item, const T& elem) {
	if (item >= 0 && item < m_length) {
		++m_length;
		if (m_capacity < m_length) {
			T* p = m_arr;
			m_capacity < 2 ? ++m_capacity : m_capacity += m_capacity / 2;
			m_arr = new T[m_capacity];
			for (int i = 0; i < item; ++i) m_arr[i] = p[i];
			m_arr[item] = elem;
			for (int i = item; i < m_length - 1; ++i) m_arr[i + 1] = p[i];
			delete[]p;
		}
		else {
			for (int i = m_length - 1; i > item; --i) m_arr[i] = m_arr[i - 1];
			m_arr[item] = elem;
		}
	}
	else cout << "´íÎó£º²åÈëÎ»ÖÃ³¬³öÈÝÆ÷·¶Î§" << endl;
}

template<typename T>
void MyVector<T>::erase(const int& item) {
	if (item >= 0 && item < m_length) {
		for (int i = item; i < m_length; ++i) m_arr[i] = m_arr[i + 1];
		--m_length;
	}
	else cout << "´íÎó£ºÊäÈëÏÂ±êÎ»ÖÃ³¬³öÈÝÆ÷·¶Î§" << endl;
}

template<typename T>
void MyVector<T>::clear() {
	m_length = 0;
}