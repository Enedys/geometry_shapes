#include "RotMatrix.hpp"

RotationMatrix::RotationMatrix() : _last_angle(0)
{
	_matrix = {{1., 0.}, {0., 1.}};
}

RotationMatrix::~RotationMatrix()
{
}

void			RotationMatrix::refreshMatrix(double angle)
{
	_matrix[0][0] = cos(angle);
    _matrix[0][1] = -sin(angle);
    _matrix[1][0] = sin(angle);
    _matrix[1][1] = cos(angle);
}

void			RotationMatrix::getRotation(AFigure &f)
{
	if (f.getRotationSpeed() != _last_angle)
	{
		refreshMatrix(f.getRotationSpeed());
		_last_angle = f.getRotationSpeed();
	}
	for (size_t i = 0; i < f.getCoordinates().size(); i++)
		f.replaceVertex(_matrix * (f.getCoordinates()[i] - f.getRotationAxis()) + f.getRotationAxis(), i);
}
