#pragma once
#include "includes.hpp"
#include "AFigure.hpp"

class Triangle: public AFigure
{
public:
	Triangle(std::vector<double> const &first, std::vector<double> const &second, std::vector<double> const &third);
	~Triangle();

	virtual std::vector<double>	calcCentrMass() const override;
	virtual double				calcSquare() const override;
	virtual void				drawFigure(sf::RenderWindow &w) const override;

	Triangle const	&operator=(Triangle const &other);
	Triangle(Triangle const &other);
private:
	Triangle();
};
