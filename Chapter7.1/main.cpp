#include <string>
#include <iostream>
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

int main() {
	cout << getMax(5.0, 2.0) << endl;
}

f(int a)