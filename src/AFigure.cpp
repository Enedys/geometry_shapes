#include "AFigure.hpp"

AFigure::~AFigure()
{
}

AFigure::AFigure()
{
}

AFigure::AFigure(int points) :
	_coordinates(points, std::vector<double>(_dimension, 0)), _controlPointsNum(points)
{
	_rotationSpeed = 0;
	_rotAxis = {0., 0.};
	_color[red] = 255;
	_color[green] = 255;
	_color[blue] = 255;
	_color[alpha] = 255;
}

AFigure const	&AFigure::operator=(AFigure const &other)
{
	if (&other == this)
		return (*this);
	_rotationSpeed = other._rotationSpeed;
	_color[red] = other._color[red];
	_color[green] = other._color[green];
	_color[blue] = other._color[blue];
	_color[alpha] = other._color[alpha];
	return (*this);
}

AFigure::AFigure(AFigure const &other)
{
	_rotationSpeed = other._rotationSpeed;
	_color[red] = other._color[red];
	_color[green] = other._color[green];
	_color[blue] = other._color[blue];
	_color[alpha] = other._color[alpha];
	_rotAxis = {0., 0.};
}

void	AFigure::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	_color[red] = r;
	_color[green] = g;
	_color[blue] = b;
}

void	AFigure::setRotationSpeed(double rotSpeed)
{
	_rotationSpeed = rotSpeed;
}

void	AFigure::setRotationAxis(std::vector<double> const &pos)
{
	if (pos.size() != _dimension)
		throw "RotAxis: bad axis dim.\n";
	_rotAxis = pos;
}

double	AFigure::getRotationSpeed() const
{
	return (_rotationSpeed);
}

std::vector<double> const
		&AFigure::getRotationAxis() const
{
	return (_rotAxis);
}

PointsArray const	
		&AFigure::getCoordinates() const
{
	return (_coordinates);
}

void	AFigure::replaceVertex(std::vector<double> const &v, int pos)
{
	if (v.size() != _coordinates[0].size())
		throw "Bad vector for replacement.\n";
	_coordinates[pos] = v;
}

double	AFigure::calcPerimetr() const
{
	double	p = 0;
	std::vector<double> line;
	for (int i = 0; i < _controlPointsNum; i++)
	{
		line = _coordinates[(i + 1) % _controlPointsNum] - _coordinates[i];
		p += hypot(line[x], line[y]);
	}
	return (p);
}

void	AFigure::shiftFigure(std::vector<double> const &r)
{
	for (int i = 0; i < _controlPointsNum; i++)
		_coordinates[i] = _coordinates[i] + r; 
}

void	AFigure::drawPixel(sf::RenderWindow &w, int x, int y) const
{
	sf::Vertex	point(sf::Vector2f(x, y), sf::Color(_color[red], _color[green], _color[blue], _color[alpha]));
	w.draw(&point, 1, sf::Points);
}
