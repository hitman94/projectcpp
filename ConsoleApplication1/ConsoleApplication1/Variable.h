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
	virtual Type getType();
	virtual string const affiche();
	virtual Expression * derive(string var);
	void set(double value);
	static void effacerMemoire();
	~Variable();
	bool operator==(Variable const &var);
	
private:
	static map<string, double> varMap;
	string name;
};
#endif
