#include <string>
#include <iostream>
#include <vector>
#include<typeinfo>
using namespace std;

const int& getMax(const int& a, const int& b) {
	return a > b ? a : b;
}

const string& getMax(const string& a, const string& b) {
	return a > b ? a : b;
}

template <typename T>
const T& getMax(const T& a, const T& b) {
	return a > b ? a : b;
}

template <typename T>
void Swap(T a, T b) {// 系统提供 swap 函数，所以自定义函数名首字母大写

	T c = a;
	a = b;
	b = c;

}



template <typename T>
const T& maxElem(T a) {
	T b = size * a;
	return b;
}



int main() {

	string *arr = new string[10];

	arr[0] = "a1b";
	arr[1] = "c2d";
	cout << arr[0];
	cout << arr[1];

	//int* a;
	//int* b;
	//int aa[] = { 1,2,3 };

	//int bb[] = { 33,4,55 };
	//Swap(aa,bb);
	/*cout << getMax(5.0, 2.0) << endl;*/
}
