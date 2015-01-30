#include "Pour.h"


Pour::Pour(Expression * init,
	Expression * condition,
	Expression * actionFinBOucle,
	Expression * calcul) : init(init), condition(condition), actionFinBOucle(actionFinBOucle), calcul(calcul)
{
}


Pour::~Pour()
{
}


double const Pour::eval() {
	init->eval();
	while (condition->eval()){
		calcul->eval();
		actionFinBOucle->eval();
	}
	return 1.0;
}

string const Pour::affiche() {
	return "for(" + init->affiche() + ";" + condition->affiche() + ";" + actionFinBOucle->affiche() + ")" + calcul->affiche();
}

