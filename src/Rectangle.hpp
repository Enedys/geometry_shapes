#pragma once
#include "includes.hpp"
#include "AFigure.hpp"
#include "Triangle.hpp"

class Rectangle: public AFigure
{
public:
	Rectangle(std::vector<double> const &upperLeft, std::vector<double> const &bottomRight);
	~Rectangle();

	virtual std::vector<double>	calcCentrMass() const override;
	virtual double				calcSquare() const override;
	virtual void				drawFigure(sf::RenderWindow &w) const override;

	Rectangle const	&operator=(Rectangle const &other);
	Rectangle(Rectangle const &other);
private:
	Rectangle();
	std::vector<Triangle>		triangulate() const;
};
