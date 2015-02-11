#include "Produit.h"
#include "Constante.h"
#include "Polynome.h"
#include "Somme.h"

Produit::Produit(Expression * e1, Expression * e2) :BinOp(e1,e2){}

double const Produit::eval() {
	return e1->eval() * e2->eval();
}

Expression * Produit::derive(string var) {
	return new Somme(new Produit(e1->derive(var), e2), new Produit(e1, e2->derive(var)));
}

string Produit::whoAmI() {
	return "*";
}
Expression * const Produit::clone() {
	return new Produit(e1->clone(), e2->clone());
}
Produit::~Produit()
{
}

Expression * Produit::simplifier(){
	this->simplifierOperande();
	if (e1->getType() == Type::variable && e2->getType() == Type::variable){
		if (e1 == e2){
			std::set<std::pair<double, double>> set;
			set.insert(std::pair<double, double>(1, 2));
			Expression * poly = new Polynome(set, dynamic_cast<Variable *>(e1));
			return poly;
		}
	}
	else if (e1->getType() == Type::constant || e1->getType() == Type::variable){
		if (e1->eval() == 0){
			return new Constante(0.0);
		}else if (e1->eval() == 1){
			return e2;
		}
	}
	else if (e2->getType() == Type::constant || e2->getType() == Type::variable){
		if (e2->eval() == 0){
			return new Constante(0.0);
		}
		else if (e2->eval() == 1){
			return e1;
		}
	}
	return this;
}
