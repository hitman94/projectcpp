#ifndef AFFECTATION
#define	AFFACTATION
#include "Expression.h"
#include "Variable.h"
class Affectation :
	public Expression
{
public:
	Affectation(Variable * v, Expression * expr);
	double const eval();
	string const affiche();
	Expression * const clone();
	~Affectation();
private:
	Variable * var;
	Expression * expr;
};
#endif
