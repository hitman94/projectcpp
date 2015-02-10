#ifndef EXPONENTIELLE
#define EXPONENTIELLE
#include "UnaireOp.h"
#include "Constante.h"
class Exponentielle :
	public UnaireOp
{
public:
	Exponentielle(double value);
	Exponentielle(Expression * c);
	virtual double const eval();
	virtual string const affiche();
	virtual Expression * derive(string var);
	virtual Expression * simplifier();
	virtual Expression * const clone();
	~Exponentielle();

};
#endif
