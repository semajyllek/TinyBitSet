/*
James Kelly
5/25/2023

C++ library for set operations on tiny sets of only the integers 1-64,
as each bit in a 64 bit integer represents a number in the set. n -> 2^(n-1)

This allows for insertion, removal, and set operations to be done in O(1) time.


*/

#include <cstdint>
#include <stdexcept>
#include <vector>
#include <string>
#include <bitset>

template <int MaxElems>
	using TinyBitRepType = typename std::conditional<MaxElems < 9, uint_fast8_t, 
					typename std::conditional<MaxElems < 17, uint_fast16_t,
					typename std::conditional<MaxElems < 33, uint_fast32_t,
					uint_fast64_t>::type>::type>::type;



template <int MaxElems>
class TinyBitSet {
	public:
		TinyBitSet();
		void insert(int i);
		void remove(int i);
		bool contains(int i);
		TinyBitSet<MaxElems> unionbitset(TinyBitSet<MaxElems> const &obj);
		void fillall();
		void removeall();
		std::vector<int> getIntegerElements();
		std::string getBitStringElements();
		int getMaxElements(); 
		int getSetSize();


	private:
		TinyBitRepType<MaxElems> tinybitrep;
		int maxElems;
};


template <int MaxElems> 
TinyBitSet<MaxElems>::TinyBitSet() {
	if (MaxElems > 64) {
        throw std::invalid_argument("TinyBitSet can only hold up to the first 64 integers");
    }	
	this->maxElems = MaxElems;	
	this->tinybitrep = 0;
}


template <int MaxElems>
TinyBitSet<MaxElems> TinyBitSet<MaxElems>::unionbitset(TinyBitSet<MaxElems> const &obj) {
	this->tinybitrep |= obj.tinybitrep;
}


template <int MaxElems>
void TinyBitSet<MaxElems>::insert(int i) {
	if ((i > this->maxElems) || (i < 1)) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and " + std::to_string(this->maxElems) + ", but " + std::to_string(i) + " was passed.");
	}
	this->tinybitrep |= (1 << (i-1));

}

template <int MaxElems>
void TinyBitSet<MaxElems>::remove(int i) {
	if ((i > this->maxElems) || (i < 1)) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and " + std::to_string(this->maxElems) + ", but " + std::to_string(i) + " was passed.");
	}
	this->tinybitrep = this->tinybitrep & ~(1 << (i-1));
}

template <int MaxElems>
bool TinyBitSet<MaxElems>::contains(int i) {
	if ((i > this->n) || (i < 1)) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and " + std::to_string(this->maxElems) + ", but " + std::to_string(i) + " was passed.");
	}
	return (this->tinybitrep & (1 << (i-1))) != 0;
}



template <int MaxElems>
void TinyBitSet<MaxElems>::fillall() {
	this->tinybitrep = ~0;
}

template <int MaxElems>
void TinyBitSet<MaxElems>::removeall() {
	this->tinybitrep = 0;
}

template <int MaxElems>
std::vector<int> TinyBitSet<MaxElems>::getIntegerElements() {
	std::vector<int> elems;
	for (int i = 0; i < this->maxElems; i++) {
		if (this->tinybitrep & (1 << i)) {
			elems.push_back(i+1);
		}
	}
	return elems;
}


template <int MaxElems>
std::string TinyBitSet<MaxElems>::getBitStringElements() {
	return std::bitset<8>(this->tinybitrep).to_string();  
}


template <int MaxElems>
int TinyBitSet<MaxElems>::getMaxElements() {
	return this->maxElems;  
}


template <int MaxElems>
int TinyBitSet<MaxElems>::getSetSize() {
	return getIntegerElements().size();  
}
