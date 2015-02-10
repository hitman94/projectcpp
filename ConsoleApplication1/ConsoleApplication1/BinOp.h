#ifndef BINOP
#define BINOP
#include "Expression.h"
class BinOp :
	public Expression
{
public:
	BinOp(Expression *e1, Expression *e2);
	virtual string const affiche();
	virtual Expression * const clone();
	~BinOp();

protected:
	virtual string whoAmI()=0;
	Expression *e1;
	Expression *e2;
	void simplifierOperande();

	
};


#endif