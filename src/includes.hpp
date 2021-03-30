#pragma once

#include <iostream>
#include <vector>
#include <cmath>

enum
{
	x = 0,
	y = 1,
	z = 2,
};

enum
{
	red = 0,
	green = 1,
	blue = 2,
	alpha = 3,
};

template <class T>
std::vector<T> operator+(const std::vector<T>& v, const std::vector<T>& v1)
{
	if (v.size() != v1.size())
		throw "Operator+: Bad vector size.";
	std::vector<T>	result(v.size());
	for (size_t i = 0; i < v.size(); i++)
		result[i] = v.at(i) + v1.at(i);
	return (result);
}

template <class T>
std::vector<T> operator-(const std::vector<T>& v, const std::vector<T>& v1)
{
	if (v.size() != v1.size())
		throw "Operator-: Bad vector size.";
	std::vector<T>	result(v.size());
	for (size_t i = 0; i < v.size(); i++)
		result[i] = v.at(i) - v1.at(i);
	return (result);
}

template <class T, class U>
std::vector<T> operator/(const std::vector<T>& v, U number)
{
	if (std::abs(number) < 1.0e-10)
		throw "Operator/: Division by zero.";
	std::vector<T>	result(v.size());
	for (size_t i = 0; i < v.size(); i++)
		result[i] = v.at(i) / number;
	return (result);
}

template <class T>
std::ostream	&operator<<(std::ostream &o, std::vector<T> const &v)
{
	o << "{";
	if (!v.empty())
	{
		for (size_t i = 0; i < v.size() - 1; i++)
			o << v.at(i) << ", ";
		o << v.back();
	}
	o << "}";
	return (o);
}

template <class T>
std::vector<T> operator*(const std::vector<std::vector<T> > &m,	const std::vector<T>& v)
{
	std::vector<T>	res(m.size());
	for (size_t row = 0; row < m.size(); row++)
	{
		if (m[row].size() != v.size())
			throw "Operator*: Invalid dimensions.\n";
		T	tmp = 0;
		for (size_t col = 0; col < v.size(); col++)
			tmp = tmp + m[row][col] * v[col];
		res[row] = tmp;
	}
	return (res);
}
