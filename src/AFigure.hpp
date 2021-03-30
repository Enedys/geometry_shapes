#pragma once
#include "includes.hpp"
#include <SFML/Graphics.hpp>

typedef std::vector<std::vector<double> > PointsArray;

class AFigure
{
public:
	AFigure(int cornesNum);

	virtual std::vector<double>	calcCentrMass() const = 0;
	virtual double				calcSquare() const = 0;
	virtual void				drawFigure(sf::RenderWindow &w) const = 0;

	PointsArray const			&getCoordinates() const;
	std::vector<double> const	&getRotationAxis() const;
	double						getRotationSpeed() const;
	void						setColor(uint8_t r, uint8_t g, uint8_t b);
	void						setRotationSpeed(double speed);
	void						setRotationAxis(std::vector<double> const &pos);
	void						replaceVertex(std::vector<double> const &v, int pos);
	virtual	void				shiftFigure(std::vector<double> const &r);
	virtual double				calcPerimetr() const;
	void						drawPixel(sf::RenderWindow &w, int x, int y) const;

	virtual ~AFigure();
protected:
	PointsArray	_coordinates;
	uint8_t		_color[4];
	double		_rotationSpeed;
	int			_controlPointsNum;
	std::vector<double>
				_rotAxis;
	static int	const
				_dimension = 2;

	AFigure const	&operator=(AFigure const &other);
	AFigure(AFigure const &other);
private:
	AFigure();
};
