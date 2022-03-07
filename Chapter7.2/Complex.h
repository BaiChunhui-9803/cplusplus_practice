#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Complex {
	double m_real = 0;
	double m_imag = 0;

public:
	Complex(double real = 0, double imag = 0) :m_real(real), m_imag(imag) {}
	Complex(const Complex& rhs);
	~Complex() = default;
	void set(double real, double imag);
	double real() { return m_real; }
	double imag() { return m_imag; }

	bool operator==(const Complex& right) const;
	bool operator!=(const Complex& right) const;
	Complex& operator+(const Complex& right);
	Complex& operator-(const Complex& right);
	Complex& operator*(const Complex& right);
	Complex& operator/(const Complex& right);
	Complex& operator=(const Complex& right);

	friend std::ostream& operator<<(std::ostream& os, const Complex& rhs);
};

Complex::Complex(const Complex& rhs) {
	m_real = rhs.m_real;
	m_imag = rhs.m_imag;
}

void Complex::set(double real, double imag) {
	m_real = real;
	m_imag = imag;
}

bool Complex::operator==(const Complex& right) const{
	return this->m_real == right.m_real && this->m_imag == right.m_imag;
}

bool Complex::operator!=(const Complex& right) const {
	return this->m_real != right.m_real || this->m_imag != right.m_imag;
}

Complex& Complex::operator+(const Complex& right) {
	Complex rtn(this->m_real + right.m_real, this->m_imag + right.m_imag);
	return rtn;
}

Complex& Complex::operator-(const Complex& right) {
	Complex rtn(this->m_real - right.m_real, this->m_imag - right.m_imag);
	return rtn;
}

Complex& Complex::operator/(const Complex& right) {
	Complex rtn((this->m_real * right.m_real + this->m_imag * right.m_imag) / (right.m_real * right.m_real + right.m_imag * right.m_imag)
		, (this->m_imag * right.m_real - this->m_real * right.m_imag) / (right.m_real * right.m_real + right.m_imag * right.m_imag));
	return rtn;
}

Complex& Complex::operator=(const Complex& right) {
	if (&right == this) return *this;
	m_real = right.m_real;
	m_imag = right.m_imag;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
	os << rhs.m_real << "+" << rhs.m_imag << "i";
	return os;
}
