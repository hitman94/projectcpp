#include "Division.h"
#include "Difference.h"
#include "Produit.h"
#include "Constante.h"

Division::Division(Expression *e1, Expression * e2) :BinOp(e1,e2)
{
}

double const Division::eval() {
	return e1->eval() / e2->eval();
}

Expression * Division::derive(string var) {
	return new Division( new Difference(new Produit(e1->derive(var),e2 ),new Produit(e1,e2->derive(var) )),new Produit(e2,e2) );
}

string Division::whoAmI() {
	return "/";
}
Expression * const Division::clone() {
	return new Division(e1->clone(), e2->clone());
}

Division::~Division()
{
}


Expression * Division::simplifier(){
	this->simplifierOperande();


	if (e1->getType() == Type::variable && e2->getType() == Type::variable){
		if (e1 == e2)
			return new Constante(1.0);
	}
	else if (e1->getType() == Type::variable && e2->getType() == Type::variable){
		if (e1 == e2)
			return new Constante(1.0);
	}
	else if (e2->getType() == Type::constant && e2->eval() == 0){
		return e1;
	}
	return this;
}
