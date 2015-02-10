#ifndef EXPRESSION
#define EXPRESSION
#include<set>
#include <iostream>
#include "TypeEnum.h"
#include <string>
using namespace std;


class Expression
{


public:
	Expression();

	virtual const double eval()=0;
	virtual string const affiche() = 0;
	virtual Type getType();
	virtual Expression * derive(string var);
	virtual Expression * simplifier();
	static void toutLiberer();
	virtual ~Expression();
	friend ostream& operator<< (ostream &out, Expression &e);
private:
	static set<Expression *> _pool;
	
};
#endif
