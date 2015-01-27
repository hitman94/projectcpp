#ifndef COS
#define COS
#include "Expression.h"
#include "Constante.h"
using namespace std;
class Cos :
	public Expression
{
public:
	Cos(double value);
	Cos(Constante * c);
	virtual const double eval();
	virtual string const affiche();
	~Cos();
private:
	double value;
};
#endif
