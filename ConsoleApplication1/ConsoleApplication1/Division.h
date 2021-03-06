#ifndef DIVISION
#define DIVISION
#include "BinOp.h"
class Division :
	public BinOp
{
public:
	Division(Expression * e1, Expression * e2);
	virtual double const eval();
	virtual Expression * simplifier();
	virtual Expression * derive(string var);
	virtual Expression * const clone();
	~Division();
protected:
	virtual string whoAmI();
};
#endif
