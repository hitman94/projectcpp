#ifndef SIN
#define SIN
#include "Constante.h"

class Sin :
	public Expression
{
public:
	Sin(Expression * c);
	virtual const double eval();
	virtual string const affiche();
	virtual Expression * derive(string var);
	~Sin();

private:
	Expression *  expr;
};
#endif
