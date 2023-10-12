#include <iostream>
#include <vector>
#include <cstring>

template <typename T>

class Vector
{
	private:
	size_t sz;
	size_t taille_alloc;
	T * espace;

	public:
	Vector(int sz_=10)
	{
		taille_alloc=sz_;
		espace = new T[taille_alloc];
	}
	~Vector()
	{
		delete[] espace;
	}
	T& operator[](size_t index)
	{
		if(index >=taille_alloc) return nullptr;
		T * tmp = espace;
		for(size_t i=0; i<index ; i=i+1)
		{
			tmp += sizeof(T);
		}
		return tmp;
	}
	const T& operator[](size_t index) const
	{
		if(index >=taille_alloc) return nullptr;
		T * tmp = espace;
		for(size_t i=0; i<index ; i=i+1)
		{
			tmp += sizeof(T);
		}
		return tmp;
	}
	void push_back (const T& val)
	{
		if(sz+1 >=taille_alloc)
		{
			T * newEspace = new T[taille_alloc*2];
			for(size_t i = 0 ; i<sz ; i=i+1)
			{
				newEspace[i] = espace[i];
			}
			T * tmp = espace;
			espace = newEspace;
			delete[] tmp;
		}
		this[sz] = val;
		sz++;
	}

	size_t size() const
	{
		return sz;
	}

	bool empty() const
	{
		return sz==0;
	}

	//Question 5 :
		//C'est toujours utile si on gere plusieurs vecteurs en meme temps, mais ce n'est pas
		//necessaire car le constructeur par copie/operateur affectation devra parcourir
		//tout le vecteur en O(n) et devra refaire de la re-allocation a chaque fois
		//Sauf si necessaire pour le contexte précis mais deconseillé

	//Question 6 :
	//Push_front est en O(1), Push_Back est en O(n) et operator[] en O(log(n))
};
