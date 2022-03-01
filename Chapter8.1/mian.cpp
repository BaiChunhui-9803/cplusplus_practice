#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
	int* p = new int[10];
	int* s = new int(10);
	cout << *p << " " << *s;
	return 0;


}