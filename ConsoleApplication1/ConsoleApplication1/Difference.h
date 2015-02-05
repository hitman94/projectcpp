#ifndef DIFF
#define DIFF
#include "BinOp.h"
class Difference :
	public BinOp
{
public:
	Difference(Expression *e1, Expression *e2);
	virtual double const eval();
	virtual Expression * derive(string var);
	~Difference();
private:
	virtual string whoAmI();
};
#endif