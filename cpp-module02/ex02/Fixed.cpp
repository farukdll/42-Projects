#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

Fixed::Fixed(const int intVal) {
	_value = intVal * pow(2, fractionalBits);
}

Fixed::Fixed(const float floatVal) {
	_value = roundf(floatVal * pow(2, fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &number) {
	this->_value = number._value;
	return (*this);
}

int Fixed::toInt() const {
	return (_value / pow(2, fractionalBits));
}

float Fixed::toFloat() const {
	return (float(_value) / pow(2, fractionalBits));
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed) {
	output << fixed.toFloat();
	return (output);
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

bool Fixed::operator>(const Fixed &number) {
	return (this->_value > number._value);
}

bool Fixed::operator<(const Fixed &number) {
	return (this->_value < number._value);
}

bool Fixed::operator>=(const Fixed &number) {
	return (this->_value >= number._value);
}

bool Fixed::operator<=(const Fixed &number) {
	return (this->_value <= number._value);
}

bool Fixed::operator==(const Fixed &number) {
	return (this->_value == number._value);
}

bool Fixed::operator!=(const Fixed &number) {
	return (this->_value != number._value);
}

Fixed Fixed::operator+(const Fixed &number) {
	Fixed rtn(this->toFloat() + number.toFloat());
	return (rtn);
}

Fixed Fixed::operator-(const Fixed &number) {
	Fixed rtn(this->toFloat() - number.toFloat());
	return (rtn);
}

Fixed Fixed::operator*(const Fixed &number) {
	Fixed rtn(this->toFloat() * number.toFloat());
	return (rtn);
}

Fixed Fixed::operator/(const Fixed &number) {
	Fixed rtn(this->toFloat() / number.toFloat());
	return (rtn);
}

Fixed Fixed::operator++(int) {
	Fixed result = *this;
	this->_value++;
	return (result);
}

Fixed &Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed result = *this;
	this->_value--;
	return (result);
}

Fixed &Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1._value < f2._value)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1._value > f2._value)
		return (f1);
	return (f2);
}
