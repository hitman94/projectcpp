#ifndef SOMME
#define SOMME
#include "BinOp.h"
class Somme :
	public BinOp
{
public:
	
	Somme(Expression * e1, Expression * e2);
	virtual double const eval();
	~Somme();

protected : 
	virtual string whoAmI();


};
#endif
