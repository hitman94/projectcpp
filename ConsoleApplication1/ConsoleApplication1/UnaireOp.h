#ifndef UNAIRE
#define UNAIRE
#include "Expression.h"
class UnaireOp :
	public Expression
{
public:
	UnaireOp(Expression * c);
	~UnaireOp();
protected:
	Expression * expr;
};
#endif
