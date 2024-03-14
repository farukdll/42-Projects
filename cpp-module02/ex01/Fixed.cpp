#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &c_asg) {
	std::cout << "Copy constructor called" << std::endl;
	*this = c_asg;
}

Fixed::Fixed(const int i_x) {
	std::cout << "Int constructor called" << std::endl;
	_value = i_x * pow(2, fractionalBits);
}

Fixed::Fixed(const float f_i) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f_i * pow(2, fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &c_asg) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = c_asg._value;
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
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
