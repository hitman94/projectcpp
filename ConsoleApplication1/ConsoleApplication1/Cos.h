#ifndef COS
#define COS
#include "UnaireOp.h"
#include "Constante.h"
using namespace std;
class Cos :
	public UnaireOp
{
public:
	Cos(Expression * c);
	virtual const double eval();
	virtual Expression * derive(string var);
	virtual string const affiche();
	virtual Expression * simplifier();
	virtual Expression * const clone();
	~Cos();
};
#endif
