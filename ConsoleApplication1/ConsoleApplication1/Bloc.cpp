#include "Bloc.h"


Bloc::Bloc(string name, Expression * expr) : name(name)
{
	listExpr.push_back(expr);
}


Bloc::~Bloc()
{
}


void Bloc::add(Expression  * expr){
	listExpr.push_back(expr);
}


double const Bloc::eval() {
	double value;
	for (std::list<Expression *>::iterator it = listExpr.begin(); it != listExpr.end(); it++){
		value = (*it)->eval();
	}
	return value;
}

string const Bloc::affiche() {
	string returnString = "{\n";
	for (std::list<Expression *>::iterator it = listExpr.begin(); it != listExpr.end(); it++){
		returnString += "\t" + (*it)->affiche() + "\n";
	}
	return (returnString += "}");

}
