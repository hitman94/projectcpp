#include "Conditionnel.h"


Conditionnel::Conditionnel(Expression * condition, Expression * expr1, Expression * expr2) : condition(condition), expr1(expr1), expr2(expr2)
{
}


Conditionnel::~Conditionnel()
{
}


double const Conditionnel::eval() {
	if ((bool)condition->eval()){
		return expr1->eval();
	}else{
		return expr2->eval();
	}
}

string const Conditionnel::affiche() {
	return "(" + condition->affiche() + ")?" + expr1->affiche() + ":" + expr2->affiche();
}

Expression * Conditionnel::simplifier(){
	condition = condition->simplifier();
	expr1 = expr1->simplifier();
	expr2 = expr2->simplifier();
	return this;
}