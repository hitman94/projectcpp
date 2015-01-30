#ifndef INFEGAL
#define INFEGAL
#include "BinOp.h"
class InferieurEgal :
	public BinOp
{
public:
	InferieurEgal(Expression * , Expression *);
	virtual double const eval();
	~InferieurEgal();
protected:
	virtual string whoAmI();
};
#endif
