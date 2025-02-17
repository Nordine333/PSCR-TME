//ERR 3 : oublie de #include "List.h"
#include "List.hpp"

namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

List::~List()
{
	for (Chainon * c = tete ; c ; ) {
				Chainon * tmp = c->next;
				delete c;
				c = tmp;
			}
}
size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
	//ERR ? : on retourne len et pas length() qui provoque une boucle infini
	return len;
}

//ERR 4 : il manquais le const apres les parametres de la fonction
void Chainon::print (std::ostream & os)const {
	os << data ;
	if (next != nullptr) {
		os << ", ";
	}
	next->print(os);
}

// ******************  List
const std::string & List::operator[] (size_t index) const  {
	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}
	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val);
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}
}

void List::push_front (const std::string& val) {
	tete = new Chainon(val,tete);
}

//ERR 7 : il faut rajouter List:: avant le nom de la fonction
bool List::empty() {
	return tete == nullptr;
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}


std::ostream & operator<< (std::ostream & os, const pr::List & vec)
{
	os << "[";
	if (vec.tete != nullptr) {
		vec.tete->print (os) ;
	}
	os << "]";
	return os;
}

// ERR 6 : l'accolade du namespace pr empechait la declaration de la derneire fonction operator<<
} // namespace pr
