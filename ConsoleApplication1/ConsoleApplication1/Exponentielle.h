#ifndef EXPONENTIELLE
#define EXPONENTIELLE
#include "Expression.h"
#include "Constante.h"
class Exponentielle :
	public Expression
{
public:
	Exponentielle(double value);
	Exponentielle(Expression * c);
	virtual double const eval();
	virtual string const affiche();
	~Exponentielle();

private:
	Expression * expr;

};
#endif
