#include "Triangle.hpp"
#include "unistd.h"

Triangle::Triangle(std::vector<double> const &first, std::vector<double> const &second, std::vector<double> const &third) try : AFigure(3)
{
	if (first.size() != _dimension || second.size() != _dimension || third.size() != _dimension)
		throw ("Bad vector size.");
	_coordinates.at(0) = first;
	_coordinates.at(1) = second;
	_coordinates.at(2) = third;

}
catch (...)
{
	throw;
};

std::vector<double>	
				Triangle::calcCentrMass() const
{
	return ((_coordinates[0] + _coordinates[1] + _coordinates[2]) / 3.);
}

double			Triangle::calcSquare() const
{
	//vector multiplication
	std::vector<double>	side1 = _coordinates[0] - _coordinates[1];
	std::vector<double>	side2 = _coordinates[0] - _coordinates[2];
	return (std::abs(side1[x] * side2[y] - side1[y] * side2[x]) / 2.);
}

void			Triangle::drawFigure(sf::RenderWindow &w) const
{
	//sort by y-direction
	std::vector<double>	const *upper = &_coordinates[0];
	std::vector<double>	const *middle = &_coordinates[1];
	std::vector<double>	const *bottom = &_coordinates[2];
	if (middle->at(y) < upper->at(y))
		std::swap(upper, middle);
	if (bottom->at(y) < upper->at(y))
		std::swap(upper, bottom);
	if (bottom->at(y) < middle->at(y))
		std::swap(bottom, middle);
	double	dx_ub = 0, dx_um = 0, dx_mb = 0;
	if (bottom->at(y) != upper->at(y))
		dx_ub = (bottom->at(x) - upper->at(x)) / ((bottom->at(y) - upper->at(y)));
	if (middle->at(y) != upper->at(y))
		dx_um = (middle->at(x) - upper->at(x)) / ((middle->at(y) - upper->at(y)));
	if (bottom->at(y) != middle->at(y))
		dx_mb = (bottom->at(x) - middle->at(x)) / ((bottom->at(y) - middle->at(y)));
	double x_left, x_right;
	double dx_max = std::max(dx_ub, dx_um);
	double dx_min = std::min(dx_ub, dx_um); 
	for (int i = upper->at(y); i < middle->at(y) - 1; i++)
	{
		x_left = upper->at(x) + dx_min * (i + 1 - upper->at(y));
		x_right = upper->at(x) + dx_max * (i + 1 - upper->at(y));
		for (int j = x_left; j < x_right; j++)
			drawPixel(w, j, i);
	}
	dx_max = std::max(dx_ub, dx_mb);
	dx_min = std::min(dx_ub, dx_mb);
	if ((int)bottom->at(y) == (int)middle->at(y))
		return ;
	for (int i = bottom->at(y); i >= middle->at(y); i--)
	{
		x_left = bottom->at(x) + dx_max * (i - bottom->at(y));
		x_right = bottom->at(x) + dx_min * (i - bottom->at(y));
		for (int j = x_left; j < x_right; j++)
			drawPixel(w, j, i);
    }
	for (int j = x_left; j < x_right; j++)
		drawPixel(w, j, middle->at(y) - 1);		
	for (int j = x_left; j < x_right; j++)
		drawPixel(w, j, middle->at(y));		
}

Triangle::~Triangle()
{
}

Triangle const	&Triangle::operator=(Triangle const &other)
{
	if (this == &other)
		return (*this);
	AFigure::operator=(other);
	_controlPointsNum = other._controlPointsNum;
	_coordinates = other._coordinates;
	return (*this);
}

Triangle::Triangle(Triangle const &other) : 
	AFigure(other)
{
	_controlPointsNum = other._controlPointsNum;
	_coordinates = other._coordinates;
}