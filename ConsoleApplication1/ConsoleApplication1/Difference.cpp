#include "Difference.h"

#include "Constante.h"
Difference::Difference(Expression *e1, Expression * e2) :BinOp(e1,e2) {

}

double const Difference::eval() {
	return e1->eval() - e2->eval();
}

Expression * Difference::derive(string var) {
	return new Difference(e1->derive(var), e2->derive(var));
}

string Difference::whoAmI() {
	return "-";
}

Expression * Difference::simplifier(){
	this->simplifierOperande();
	

	if (e1->getType() == Type::variable && e2->getType() == Type::variable){
		 if (e1 == e2)
			return new Constante(0.0);
	}
	else if (e2->getType() == Type::constant && e2->eval() == 0){
		return e1;
	}
	return this;
}

Difference::~Difference()
{
}
