#include "Rectangle.hpp"

Rectangle::Rectangle(std::vector<double> const &upperLeft, std::vector<double> const &bottomRight) try : AFigure(4)
{
	if (upperLeft.size() != _dimension || bottomRight.size() != _dimension)
		throw ("Bad vector size.");
	_coordinates.at(0) = upperLeft;
	_coordinates.at(1) = {bottomRight[x], upperLeft[y]};
	_coordinates.at(2) = bottomRight;
	_coordinates.at(3) = {upperLeft[x], bottomRight[y]};
}
catch (...)
{
	throw;
};

std::vector<double>	
				Rectangle::calcCentrMass() const
{
	return ((_coordinates[0] + _coordinates[2]) / 2.);
}

double			Rectangle::calcSquare() const
{
	//vector multiplication
	std::vector<double>	side1 = _coordinates[1] - _coordinates[0];
	std::vector<double>	side2 = _coordinates[3] - _coordinates[0];
	return (std::abs(side1[x] * side2[y] - side1[y] * side2[x]));
}

std::vector<Triangle>
				Rectangle::triangulate() const
{
	std::vector<Triangle>	trs = {Triangle(_coordinates[0],_coordinates[1], _coordinates[2]),
									Triangle(_coordinates[2],_coordinates[3], _coordinates[0])};
	trs[0].setColor(_color[0], _color[1], _color[2]);
	trs[1].setColor(_color[0], _color[1], _color[2]);
	return (trs);
}

void			Rectangle::drawFigure(sf::RenderWindow &w) const
{
	std::vector<Triangle>	triangulated = triangulate();
	for (auto tr: triangulated)
		tr.drawFigure(w);
}

Rectangle::~Rectangle()
{
}

Rectangle const	&Rectangle::operator=(Rectangle const &other)
{
	if (this == &other)
		return (*this);
	AFigure::operator=(other);
	_controlPointsNum = other._controlPointsNum;
	_coordinates = other._coordinates;
	return (*this);
}

Rectangle::Rectangle(Rectangle const &other) : 
	AFigure(other)
{
	_controlPointsNum = other._controlPointsNum;
	_coordinates = other._coordinates;
}
