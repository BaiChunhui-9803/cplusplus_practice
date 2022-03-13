#include "MySet.h"
#include "Complex.h"
#include <vector>
#include <iostream>

int main() {
	std::vector<char> Vec_A = { 'a','b','c' };
	std::vector<char> Vec_B = { 'x','y','z' };
	Set<char> Set_A(Vec_A), Set_B(Vec_B);
	Set<char> Set_AA;
	Set<char> Set_BB(Set_AA);
	Set_AA = Set_A;
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

	std::vector<Complex> Vec_X = { Complex(1,2), Complex(3,4), Complex(5,6) };
	std::vector<Complex> Vec_Y = { Complex(0,2), Complex(2,4), Complex(4,6) };
	Set<Complex> Set_X(Vec_X);
	Set<Complex> Set_Y(Vec_Y);
	Set<Complex> Set_XYS = sum(Set_X, Set_Y);
	std::cout << Set_XYS << std::endl;
	Set<Complex> Set_XYC = common(Set_X, Set_Y);
	std::cout << Set_XYC << std::endl;
	Complex com_A(1, 6);
	std::cout << com_A << std::endl;
	std::cout << Set_X << std::endl;
}
