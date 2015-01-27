#ifndef SIN
#define SIN
#include "Constante.h"

class Sin :
	public Expression
{
public:
	Sin(double value);
	Sin(Constante * c);
	virtual const double eval();
	virtual string const affiche();
	~Sin();

private:
	double value;
};
#endif
