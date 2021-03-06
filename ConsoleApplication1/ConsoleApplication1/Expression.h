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
	virtual Expression * const clone();
	virtual Type getType();
	virtual Expression * derive(string var);
	virtual Expression * simplifier();
	static void toutLiberer();
	virtual ~Expression();
	friend ostream& operator<< (ostream &out, Expression &e);
	static set<Expression *> _pool;
	
};
#endif
