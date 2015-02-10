#ifndef IFTHENELSE
#define	IFTHENELSE
#include "Expression.h"
class IfThenElse :
	public Expression
{
public:
	IfThenElse(Expression * condition, Expression * expr1, Expression * expr2);
	~IfThenElse();
	virtual double const eval();
	virtual string const affiche();
	virtual Expression * simplifier();

private:
	Expression * condition;
	Expression * expr1;
	Expression * expr2;
};

#endif