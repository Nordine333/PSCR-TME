#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <cstddef>
#include <string>
#include <ostream>

namespace pr {

class Chainon {
public :
	std::string data;
	Chainon * next;
	Chainon (const std::string & data, Chainon * next=nullptr);
	size_t length() ;
	void print (std::ostream & os) const;
};

class List {
public:

	Chainon * tete;

	List(): tete(nullptr)  {}

	~List();
	//ERR ? : On ne doit pas implementer la fonction dans le .hpp mais dans le .cpp

	const std::string & operator[] (size_t index) const ;

	void push_back (const std::string& val) ;

	// ERR 5 : on ne doit pas implemter la fonction directmeent dans le fichier header (.h) (redefinition erreur)
	void push_front (const std::string& val);

	bool empty() ;

	size_t size() const ;
};


std::ostream & operator<< (std::ostream & os, const List & vec) ;

} /* namespace pr */

//ERR 2 : dans #endif SRC_LIST_H_ qui suivait etait en commentaire et il fallait retirer le
//        "SRC_LIST_H"
#endif
