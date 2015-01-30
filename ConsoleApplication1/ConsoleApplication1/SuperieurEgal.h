#ifndef SUPEGAL
#define SUPEGAL
#include "BinOp.h"
class SuperieurEgal :
	public BinOp
{
public:
	SuperieurEgal(Expression *, Expression *);
	virtual double const eval();
	~SuperieurEgal();
protected:
	virtual string whoAmI();
};
#endif
