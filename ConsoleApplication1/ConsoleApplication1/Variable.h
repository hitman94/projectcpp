#ifndef VAR
#define VAR
#include "Expression.h"
#include <map>
class Variable :
	public Expression
{
public:
	Variable(string name, double value=0.0);
	virtual double const eval();
	virtual string const affiche();
	void set(double value);
	static void effacerMemoire();
	~Variable();
private:
	static map<string, double> varMap;
	string name;
};
#endif
