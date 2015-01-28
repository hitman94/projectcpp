#ifndef BINOP
#define BINOP
#include "Expression.h"
class BinOp :
	public Expression
{
public:
	BinOp(Expression *e1, Expression *e2);
	virtual string const affiche();
	~BinOp();

protected:
	virtual string whoAmI()=0;
	Expression *e1;
	Expression *e2;
};


#endif