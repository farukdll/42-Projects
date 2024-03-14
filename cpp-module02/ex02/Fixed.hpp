#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int fractionalBits = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &number);
		bool operator>(const Fixed &number);
		bool operator<(const Fixed &number);
		bool operator>=(const Fixed &number);
		bool operator<=(const Fixed &number);
		bool operator==(const Fixed &number);
		bool operator!=(const Fixed &number);
		Fixed operator+(const Fixed &number);
		Fixed operator-(const Fixed &number);
		Fixed operator*(const Fixed &number);
		Fixed operator/(const Fixed &number);
		Fixed operator++(int);
		Fixed &operator++();
		Fixed operator--(int);
		Fixed &operator--();
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		Fixed(const int intVal);
		Fixed(const float floatVal);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
