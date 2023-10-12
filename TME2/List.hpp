#include <iostream>
#include <vector>
#include <cstring>

template <typename T>

class List
{
	private:

	class Chainon{
		public:
			T data;
			Chainon * suivant;
			Chainon(const T& t) : data(t), suivant(nullptr) {}
			};

	Chainon * tete;

	public:
	List()
	{
		tete = nullptr;
	}
	~List()
	{
		Chainon * tmp = tete;
		while(tmp!=nullptr)
		{
			Chainon * last = tmp;
			tmp=tmp->suivant;
			delete last;
		}
		delete tmp;
	}
	T& operator[](size_t index)
	{
		Chainon * tmp = tete;
		for(size_t i=0; i<index ; i=i+1)
		{
			tmp = tmp->suivant;
		}
		return tmp;
	}
	void push_front (const T& val)
	{
		Chainon * newTete = new Chainon(val);
		newTete->suivant = tete;
		tete = newTete;
	}
	void push_back (const T& val)
	{
		Chainon * tmp = tete;
		while(tmp->suivant!=nullptr)
		{
			tmp=tmp->suivant;
		}
		Chainon * newElem = Chainon(val);
		tmp->suivant = newElem;
		//delete newElem; je delete ou pas ?
	}

	size_t size() const
	{
		size_t taille = 0;
		Chainon * tmp = tete;
		while(tmp->suivant!=nullptr)
		{
			tmp=tmp->suivant;
			taille++;
		}
		return taille;
	}

	bool empty() const
	{
		return size()==0;
	}

	//Question 8 :
	//Ca peut etre utile selon le contexted (ex : BaseDonnee), ici vu que pour ajouter un
	//element on a pas besoin de faire de re-allocation + copie comme le vecteur pourquoi pas.

	//Question 9 :
	//Push_front est en O(1), Push_Back est en O(n) et operator[] en O(log(n))
};
