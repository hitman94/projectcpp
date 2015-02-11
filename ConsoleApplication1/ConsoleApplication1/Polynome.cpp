#include "Polynome.h"
#include "Constante.h"

Polynome::Polynome(std::set<std::pair<double, double>> * set, Variable * nomVar) :coeff(set), variable(nomVar)
{
}

string const Polynome::affiche() {
	string s;
	for (std::set < std::pair<double, double> >::iterator it = coeff->begin(); it != coeff->end(); it++) {
		s += (to_string(it->second) + "*" + variable->affiche() + "^" + to_string(it->first));
		if (++it != coeff->end()) {
			s += " + ";
		}
		it--;
	}
	return s;
}

Expression * Polynome::derive(string var) {
	if (var != variable->affiche())
		return new Constante(0);

	std::set<std::pair<double, double>> * set = new std::set < std::pair<double, double> >;

	for (std::set < std::pair<double, double> >::iterator it = coeff->begin(); it != coeff->end(); it++) {
		double puissance = it->first;
		double coefficient = 0;
		if (puissance > 0) {
			coefficient = puissance * it->second;
			puissance--;
		}
		set->insert(std::pair<double, double>(puissance, coefficient));
	}

	return new Polynome(set, variable);
		
}

double const Polynome::eval() {
	if (variable->eval() == 0)
		return 0;
	std::set < std::pair<double, double> >::iterator it = coeff->end();
	it--;
	double i = it->first;
	double result = it->second;
	it--;
	for (; it != coeff->begin(); it--) {
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
	return new Polynome(new std::set<std::pair<double, double>>(*coeff),variable ) ;
}

Polynome * const Polynome::operator+(const Polynome &polynom) {
	std::set<std::pair<double, double>> * set = new std::set < std::pair<double, double> >;
	std::set<std::pair<double, double>>::iterator it1 = coeff->begin();
	std::set<std::pair<double, double>>::iterator it2 = polynom.coeff->begin();
	while (it1 != coeff->end() && it2 != polynom.coeff->end()) {
		if (it1->first < it2->first) {
			set->insert(*it1);
			it1++;
		}
		else if (it1->first > it2->first) {
			set->insert(*it2);
			it2++;
		}
		else {
			set->insert(std::pair<double, double>(it1->first, it1->second + it2->second));
			it1++;
			it2++;
		}
	}
	while (it1 != coeff->end()) {
		set->insert(*it1);
		it1++;
	}
	while (it2 != polynom.coeff->end()) {
		set->insert(*it2);
		it2++;
	}
	return new Polynome(set,variable);
}

Polynome * const Polynome::operator-(const Polynome &polynom) {
	std::set<std::pair<double, double>> * set = new std::set < std::pair<double, double> > ;
	std::set<std::pair<double, double>>::iterator it1 = coeff->begin();
	std::set<std::pair<double, double>>::iterator it2 = polynom.coeff->begin();
	while (it1 != coeff->end() && it2 != polynom.coeff->end()) {
		if (it1->first < it2->first) {
			set->insert(*it1);
			it1++;
		}
		else if (it1->first > it2->first) {
			set->insert(std::pair<double, double>(it2->first,  -1* it2->second));
			it2++;
		}
		else {
			set->insert(std::pair<double, double>(it1->first, it1->second - it2->second));
			it1++;
			it2++;
		}
	}
	while (it1 != coeff->end()) {
		set->insert(*it1);
		it1++;
	}
	while (it2 != polynom.coeff->end()) {
		set->insert(std::pair<double, double>(it2->first, -1 * it2->second));
		it2++;
	}
	return new Polynome(set, variable);
}

Polynome * const Polynome::operator*(const Polynome &polynom) {
	std::set<std::pair<double, double>> * set = new std::set < std::pair<double, double> >;
	std::set<std::pair<double, double>>::iterator it1 = coeff->begin();
	
	while (it1 != coeff->end()) {
		std::set<std::pair<double, double>>::iterator it2 = polynom.coeff->begin();
		while (it2 != polynom.coeff->end()) {
			set->insert(std::pair<double, double>(it1->first*it2->first, it1->second*it2->second));
			it2++;
		}
		it1++;
	}
	
	return new Polynome(set, variable);
}


Polynome * const Polynome::operator=(const Polynome &polynom) {
	if (this != &polynom)
		return new Polynome(new std::set<std::pair<double, double>>(*coeff), variable);
	else
		return this;
}

Polynome::~Polynome()
{
	delete coeff;
}
