#include "IfThenElse.h"


IfThenElse::IfThenElse(Expression * condition, Expression * expr1, Expression * expr2) : condition(condition), expr1(expr1), expr2(expr2)
{
}


IfThenElse::~IfThenElse()
{
}


double const IfThenElse::eval() {
	if ((bool)condition->eval){
		return expr1->eval();
	}
	else{
		return expr2->eval();
	}
}

string const IfThenElse::affiche() {
	return "if(" + condition->affiche() + ")" + expr1->affiche() + "else" + expr2->affiche();
}