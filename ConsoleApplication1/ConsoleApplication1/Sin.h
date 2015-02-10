#ifndef SIN
#define SIN
#include "Constante.h"
#include "UnaireOp.h"
class Sin :
	public UnaireOp
{
public:
	Sin(Expression * c);
	virtual const double eval();
	virtual string const affiche();
	virtual Expression * simplifier();
	virtual Expression * const clone();
	virtual Expression * derive(string var);
	~Sin();

};
#endif
