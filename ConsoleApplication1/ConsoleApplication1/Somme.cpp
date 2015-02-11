#include "Somme.h"
#include "Constante.h"
#include "Produit.h"


Somme::Somme(Expression * e1, Expression *e2) :BinOp(e1,e2)
{
}

double const Somme::eval() {
	return e1->eval() + e2->eval();
}
Expression * Somme::derive(string var) {
	return new Somme(e1->derive(var), e2->derive(var));
}

string Somme::whoAmI() {
	return "+";
}

Expression * const Somme::clone() {
	return new Somme(e1->clone(), e2->clone());
}

Somme::~Somme()
{
}

Expression * Somme::simplifier(){
	this->simplifierOperande();
	if (e1->getType() == Type::variable && e2->getType() == Type::variable){
		if (e1 == e2)
			return new Produit(new Constante(2.0),e1);
	}
	else if (e1->getType() == Type::constant && e2->getType() == Type::constant){
		if (e1->eval() == e2->eval())
			return new Produit(new Constante(2.0), e1);
	}
	else if (e1->getType() == Type::constant || e1->getType() == Type::variable){
		if (e1->eval() == 0){
			return e2;
		}
	}
	else if (e2->getType() == Type::constant || e2->getType() == Type::variable){
		if (e2->eval() == 0){
			return e1;
		}
	}
	return this;
}
