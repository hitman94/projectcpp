#ifndef BLOC
#define BLOC
#include "Expression.h"
#include <list>
class Bloc :
	public Expression
{
public:
	Bloc(string name, Expression * expr);
	~Bloc();
	virtual const double eval();
	virtual string const affiche();
	void add(Expression  * expr);

private:
	string name;
	list<Expression *> listExpr;
};

#endif
