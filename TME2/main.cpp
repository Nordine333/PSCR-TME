#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include <cstring>
#include "HashMap.hpp"

int main () {
	using namespace std;
	using namespace std::chrono;
	//EX 2 :
	//vector<string> v;
	//EX 3 :
	vector<pair<string,int>> v;
	//EX 4 :
	HashMap<string,int> Hmap(3);

	ifstream input = ifstream("WarAndPeace.txt");

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);

		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": "<< word << endl;
		nombre_lu++;

		/*
		 * EX2 :
		bool uniq = true;
		for(size_t i=0; i< v.size() ; i=i+1)
		{
			if(word==v[i])
				{
					uniq = false;
					break;
				}

		}

		if(uniq) v.push_back(word);
		uniq=true;

		cout<<"le vecteur fait : "<<v.size()<<endl;
		*/

		/*
		 * EX3 :
		bool uniq = true;
				for(size_t i=0; i< v.size() ; i=i+1)
				{

					if(word==v[i].first)
						{
							uniq = false;
							v[i].second++;
							break;
						}
				}

		if(uniq) v.push_back(std::make_pair(word,1));
		uniq=true;
		*/

		//EX4 :

		Hmap.put(word,1);
		cout<<"taille : " << Hmap.size() << endl;

	}


	/*
			 * EX3 :
	for(size_t i=0; i< v.size() ; i=i+1)

	{
		if(v[i].first == "war" || v[i].first == "peace" || v[i].first=="toto"){
			cout<<v[i].first<<", occurence : "<<v[i].second<<endl;
		}
	}
	*/

	//Pas optimiser, Complexité en O(n²)



	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;


    return 0;
}


