#include "Polynome.h"
#include "Constante.h"

Polynome::Polynome(std::set<std::pair<double, double>> set, Variable * nomVar) :coeff(set), variable(nomVar)
{
}

string const Polynome::affiche() {
	string s;
	for (std::set < std::pair<double, double> >::iterator it = coeff.begin(); it != coeff.end(); it++) {
		s += (to_string(it->second) + "*" + variable->affiche() + "^" + to_string(it->first));
		if (++it != coeff.end()) {
			s += " + ";
		}
		it--;
	}
	return s;
}

Expression * Polynome::derive(string var) {
	if (var != variable->affiche())
		return new Constante(0);

	std::set<std::pair<double, double>> set;

	for (std::set < std::pair<double, double> >::iterator it = coeff.begin(); it != coeff.end(); it++) {
		double puissance = it->first;
		double coefficient = 0;
		if (puissance > 0) {
			coefficient = puissance * it->second;
			puissance--;
		}
		set.insert(std::pair<double, double>(puissance, coefficient));
	}

	return new Polynome(set, variable);
		
}

double const Polynome::eval() {
	if (variable->eval() == 0)
		return 0;
	std::set < std::pair<double, double> >::iterator it = coeff.end();
	it--;
	double i = it->first;
	double result = it->second;
	it--;
	for (; it != coeff.begin(); it--) {
		double puissance = it->first;
		double coefficient = it->second;
		while (i > puissance) {
			result *= variable->eval();
			i--;
		}
		result = result * variable->eval() + coefficient;
		i--;
	}
	return result;
}

Expression * const Polynome::clone() {
	return new Polynome(std::set<std::pair<double, double>>(coeff),variable ) ;
}

Polynome::~Polynome()
{
}
