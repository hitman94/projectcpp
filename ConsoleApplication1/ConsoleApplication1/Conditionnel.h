#ifndef CONDITIONNEL
#define CONDITIONNEL
#include "Expression.h"
class Conditionnel :
	public Expression
{
public:
	Conditionnel(Expression * condition,Expression * expr1,Expression * expr2);
	~Conditionnel();
	virtual double const eval();
	virtual string const affiche();

private:
	Expression * condition;
	Expression * expr1;
	Expression * expr2;
};

#endif

