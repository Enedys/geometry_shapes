#include "Circle.hpp"

Circle::Circle(std::vector<double> const &r0, double r) try : AFigure(1)
{
	if (r0.size() != _dimension)
		throw ("Bad init vector size.");
	if (r <= 0)
		throw ("Bad circle radius.");
	_coordinates.at(0) = r0;
	_r = r;
}
catch (...)
{
	throw;
};

std::vector<double>		
				Circle::calcCentrMass() const
{
	return (_coordinates[0]);
}

double			Circle::calcPerimetr() const
{
	return (2. * M_PI * _r);
}

double			Circle::calcSquare() const
{
	return (M_PI * _r * _r);
}

void				Circle::drawFigure(sf::RenderWindow &w) const
{
	//Bresenham algorithm
	int x_ = 0;
	int y_ = _r;
	int delta = 1 - 2 * _r;
	int error = 0;
	while(y_ >= 0)
	{
		for (int j = _coordinates[0][x] - x_; j < _coordinates[0][x] + x_; j++)
		{
			drawPixel(w, j, _coordinates[0][y] + y_);
			drawPixel(w, j, _coordinates[0][y] - y_);
		}
		error = 2 * (delta + y_) - 1;
		if(delta < 0 && error <= 0)
		{
			++x_;
			delta += 2 * x_ + 1;
			continue;
		}
		error = 2 * (delta - x_) - 1;
		if(delta > 0 && error > 0)
		{
			--y_;
			delta += 1 - 2 * y_;
			continue;
		}
		++x_;
		delta += 2 * (x_ - y_);
		--y_;
	}
}

Circle::~Circle()
{
}

Circle const	&Circle::operator=(Circle const &other)
{
	if (this == &other)
		return (*this);
	AFigure::operator=(other);
	_controlPointsNum = other._controlPointsNum;
	_coordinates = other._coordinates;
	_r = other._r;
	return (*this);
}

Circle::Circle(Circle const &other) : 
	AFigure(other)
{
	_controlPointsNum = other._controlPointsNum;
	_coordinates = other._coordinates;
	_r = other._r;
}