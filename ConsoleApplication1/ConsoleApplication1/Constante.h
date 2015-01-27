#ifndef CONSTANTE
#define CONSTANTE
#include <iostream>
#include "Expression.h"
class Constante :
	public Expression
{
public:
	Constante(double value);
	virtual string const affiche();
	virtual const double eval();
	~Constante();
private:
	double value;
};
#endif
