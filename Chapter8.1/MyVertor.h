#include <iostream>

template <typename T>
class MyVector {
	T* m_arr;
	int m_length = 0;
public:
	MyVector() = default;
	MyVector(const std::initializer_list<T>& list);
	MyVector(const MyVector<T>& rhs);
	MyVector<T>& operator=(const MyVector<T>& rhs);




};

template <typename T>
MyVector<T>::MyVector(const std::initializer_list<T>& list) {
	m_arr = list.size() > 0 ? new T[list.size()] : nullptr;
	for (int i = 0; i < list.size(); i++) {
		m_arr[i] = *(list.begin() + i);
		m_length++;
	}
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& rhs) :m_length(rhs.m_length), m_arr(m_arr = list.size() > 0 ? new T[list.size()] : nullptr) {
	for (int i = 0; i < m_length; i++) {
		m_arr[i] = rhs.m_arr[i];
	}
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs) {
	if (this != &rhs) {
		m_length = rhs.m_length;
		delete[]arr;
		m_arr = rhs.m_arr;
		return *this;
	}
}