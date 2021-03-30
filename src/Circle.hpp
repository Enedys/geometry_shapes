#pragma once
#include "includes.hpp"
#include "AFigure.hpp"

class Circle: public AFigure
{
public:
	Circle(std::vector<double> const &r0, double r);
	virtual ~Circle();

	virtual std::vector<double>	calcCentrMass() const override;
	virtual double				calcSquare() const override;
	virtual void				drawFigure(sf::RenderWindow &w) const override;
	virtual double				calcPerimetr() const override;

	Circle const	&operator=(Circle const &other);
	Circle(Circle const &other);
private:
	double	_r;
	Circle();
};
