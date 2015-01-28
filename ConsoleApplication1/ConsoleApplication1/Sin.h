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
	~Sin();

private:
	Expression *  expr;
};
#endif
