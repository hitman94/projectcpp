#ifndef SOMME
#define SOMME
#include "BinOp.h"
class Somme :
	public BinOp
{
public:
	
	Somme(Expression * e1, Expression * e2);
	virtual double const eval();
	virtual Expression * derive(string var);
	virtual Expression * const clone();
	~Somme();

protected : 
	virtual string whoAmI();


};
#endif
