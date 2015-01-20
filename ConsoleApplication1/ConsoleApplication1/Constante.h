#include <iostream>
#include "Expression.h"
class Constante :
	public Expression
{
public:
	Constante(double value);
	double eval();
	friend ostream& operator<< (ostream &out, Constante &c);
	~Constante();
private:
	double value;
};

