#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include <SFML/Graphics.hpp>
#include "RotMatrix.hpp"

int main()
{
	sf::RenderWindow	window(sf::VideoMode(750, 250), "Figures");
	
	Circle		c({65., 80.}, 50);
	c.setColor(10, 55, 200);
	
	Rectangle	r({165., 45.}, {265., 170.});
	r.setRotationSpeed(-2 / 180. * M_PI);
	r.setRotationAxis(r.calcCentrMass());
	r.setColor(180, 0, 200);
	
	Triangle	t({330., 25.}, {445., 100.}, {380., 170.});
	t.setRotationSpeed(1 / 180. * M_PI);
	t.setRotationAxis(t.calcCentrMass());
	t.setColor(0, 175, 200);

	Triangle	t_star({500., 125.}, {575., 100.}, {575., 150.});
	t_star.setColor(255, 255, 255);
	Rectangle	r_star({575., 75.}, {650., 175.});
	r_star.setColor(255, 0, 0);
	Triangle	t_star2({650., 100.}, {650., 150.}, {725., 125.});
	t_star2.setColor(255, 255, 255);
	t_star.setRotationAxis(r_star.calcCentrMass());
	r_star.setRotationAxis(r_star.calcCentrMass());
	t_star2.setRotationAxis(r_star.calcCentrMass());
	r_star.setRotationSpeed(3 / 180. * M_PI);
	t_star.setRotationSpeed(3 / 180. * M_PI);
	t_star2.setRotationSpeed(3 / 180. * M_PI);

	std::cout << "1.Circle. " << "Center of Mass: " << c.calcCentrMass() << ", Square: "\
				<< c.calcSquare() << ", Perimetr: " << c.calcPerimetr() << std::endl;
	std::cout << "2.Rectangle. "<< "Center of Mass: " << r.calcCentrMass() << ", Square: "\
				<< r.calcSquare() << ", Perimetr: " << r.calcPerimetr() << std::endl;
	std::cout << "3.Triangle. "<< "Center of Mass: " << t.calcCentrMass() << ", Square: "\
				<< t.calcSquare() << ", Perimetr: " << t.calcPerimetr() << std::endl;

	window.setFramerateLimit(30);
	RotationMatrix	rotator;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
		}
		window.clear();

		rotator.getRotation(t);
		rotator.getRotation(r);
		r.drawFigure(window);
		t.drawFigure(window);
		c.drawFigure(window);

		rotator.getRotation(r_star);
		rotator.getRotation(t_star);
		rotator.getRotation(t_star2);
		r_star.drawFigure(window);
		t_star.drawFigure(window);
		t_star2.drawFigure(window);	

		window.display();
	}
	return (0);
}