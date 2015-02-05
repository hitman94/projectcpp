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
	virtual Expression * derive(string var);
	~Exponentielle();

private:
	Expression * expr;

};
#endif