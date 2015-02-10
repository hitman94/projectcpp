#include "Variable.h"
#include "Constante.h"
map<string, double> Variable::varMap;

Variable::Variable(string name, double value) :name(name)
{
	Variable::varMap.insert(std::pair<string,double>(name,value));
}

double const Variable::eval() {
	if (Variable::varMap.find(this->name) == Variable::varMap.end())
		varMap.insert(std::pair<string, double>(this->name, 0.0));
	return Variable::varMap.find(this->name)->second;
}

void Variable::set(double value) {
	Variable::varMap[this->name]= value;
}

string const Variable::affiche() {
	return this->name;
}


Expression * Variable::derive(string var) {
	if (var == this->name)
		return new Constante(1);
	return new Constante(0);
}

void Variable::effacerMemoire() {
	Variable::varMap.clear();
}
Type Variable::getType(){
	return Type::variable;
}


Variable::~Variable()
{
	//Variable::varMap.erase(this->name);
}
