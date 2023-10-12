#include <iostream>
#include <vector>
#include <cstring>
#include <forward_list>

template <typename K,typename V>

class HashMap
{
	private:

	class Entry{
		public:
			K key;
			V value;

	        Entry(const K& k, const V& v) : key(k), value(v) {}

		};

	std::vector<std::forward_list<Entry>> buckets;
	size_t sz;



	public:
	HashMap(size_t s) :  buckets(s),sz(s) {}
	~HashMap()
	{
		sz = 0;
	}

	V* get(const K & key)
	{
		size_t h = std::hash<K>()(key);
		for (Entry& entry : buckets[h%sz]) //sz :len : conforme formule : hash(k) % buckets.size()
		{
			if(key==entry.key) return &entry.value;
		}

		return nullptr; //on a pas trouvé
	}

	bool put(const K & key, const V & value)
	{
		if(get(key)!=nullptr) return true;

		size_t h = std::hash<K>()(key);
		buckets[h].push_front(Entry(key,value));
		//sz++; je veut que ce soit le nb de bucket pas d'eleme totaux

		return false;
	}
	size_t size() const
	{
		size_t nbBucketNonVide = 0;

		for (size_t i = 0; i<sz; i=i+1)
		{
			if(buckets[i].empty()) nbBucketNonVide++;
		}
		return nbBucketNonVide;
	}

	void grow()
	{
		size_t tailleActuel = size();
		if(tailleActuel>=0.8*sz)
		{
			std::vector<std::forward_list<Entry>> newBuckets(sz*2);
			for(size_t i = 0; i<tailleActuel ; i=i+1)
			{
				newBuckets[i] = buckets[i];
			}

			buckets = newBuckets; //pas de delete car buckets n'est pas pointeur
			sz=sz*2;
		}
	}

};
