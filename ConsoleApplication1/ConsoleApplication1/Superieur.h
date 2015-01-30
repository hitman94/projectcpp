#ifndef SUP
#define SUP
#include "BinOp.h"
class Superieur :
	public BinOp
{
public:
	Superieur(Expression *, Expression *);
	virtual double const eval();
	~Superieur();

protected:
	virtual string whoAmI();
};
#endif

