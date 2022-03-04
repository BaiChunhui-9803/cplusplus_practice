#include "MySet.h"
#include <vector>
#include <iostream>

int main() {
	std::vector<char> Vec_A = { 'a','b','c' };
	std::vector<char> Vec_B = { 'x','y','z' };
	Set<char> Set_A(Vec_A), Set_B(Vec_B);
	Set_A.erase('a');
	Set_A.erase('b');
	Set_A.insert('x');
	Set_A.insert('z');
	std::cout << Set_A << std::endl;
	Set<char> Set_C = sum(Set_A, Set_B);
	std::cout << Set_C << std::endl;
	Set<char> Set_D = common(Set_A, Set_B);
	std::cout << Set_D << std::endl;
	std::cout << Set_B.find('y') << std::endl;
	std::cout << Set_A << std::endl;
	std::cout << Set_B << std::endl;
	swap(Set_A, Set_B);
	std::cout << Set_A << std::endl;
	std::cout << Set_B << std::endl;
}
