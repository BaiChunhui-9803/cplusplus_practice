#include <iostream>
#include <vector>
#include <string>
#include "MyVector.h"

using namespace std;


int main() {

	//MyVector<int> MyVec_A = { 1,2,3,4,5 };
	MyVector<int> MyVec_A;

	for (int i = 0; i < 20; i++) {
		MyVec_A.push_back(0);
		cout << MyVec_A.size() << " " << MyVec_A.capacity() << endl;
	}


}