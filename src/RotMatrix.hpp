#pragma once
#include "includes.hpp"
#include "AFigure.hpp"

typedef std::vector<std::vector<double> >	rotMatrix;

class RotationMatrix
{
private:
	rotMatrix		_matrix;
	double			_last_angle;
	void			refreshMatrix(double angle);

public:
	void			getRotation(AFigure &f);
	RotationMatrix();
	~RotationMatrix();
};
