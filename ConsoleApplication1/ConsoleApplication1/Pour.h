
#include "Expression.h"
class Pour :
	public Expression
{
public:
	Pour(Expression * init,
			Expression * condition,
			Expression * actionFinBOucle,
			Expression * calcul);
	~Pour();
	virtual double const eval();
	virtual string const affiche();

private:
	Expression * init;
	Expression * condition;
	Expression * actionFinBOucle;
	Expression * calcul;
};

