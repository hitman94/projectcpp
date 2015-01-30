#ifndef INF
#define INF
#include "BinOp.h"
class Inferieur :
	public BinOp
{
public:
	Inferieur(Expression *, Expression *);
	virtual double const eval();
	~Inferieur();
protected:
	virtual string whoAmI();
};

#endif

