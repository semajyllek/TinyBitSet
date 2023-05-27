/*
James Kelly
5/25/2023

C++ library for set operations on tiny sets of only the integers 1-64,
as each bit in a 64 bit integer represents a number in the set. n -> 2^(n-1)

This allows for insertion, removal, and set operations to be done in O(1) time.

Q: one question you might ask is, why didn't you just use std::bitset?
A: contrary to the name, bitset didn't support any set operations, and I wanted to implement them myself,
   as well as have a more intuitive interface for the user. I thought maybe I could make it lighter weight.
   most of the functions are one-liners. I also wanted to learn more about templates and conditional types.

*/

#include <cstdint>
#include <stdexcept>
#include <vector>
#include <string>
#include <bitset>
#include <bits/stdc++.h>


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
		TinyBitSet<MaxElems> unionb(TinyBitSet<MaxElems> const &obj);
		TinyBitSet<MaxElems> intersectionb(TinyBitSet<MaxElems> const &obj);
		void fillall();
		void removeall();
		void invertSet();
		int pop(bool reverse=false);
		std::vector<int> getIntegerElements();
		std::string getBitStringElements();
		std::bitset<MaxElems> getBitSet();
		TinyBitRepType<MaxElems> getBitRep();
		int getMaxElements(); 
		int getSetSize();
		bool isempty();


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
TinyBitSet<MaxElems> TinyBitSet<MaxElems>::unionb(TinyBitSet<MaxElems> const &obj) {
	TinyBitSet<MaxElems> t;
	t.tinybitrep = this->tinybitrep | obj.tinybitrep;
	return t;
}

template <int MaxElems>
TinyBitSet<MaxElems> TinyBitSet<MaxElems>::intersectionb(TinyBitSet<MaxElems> const &obj) {
	TinyBitSet<MaxElems> t;
	t.tinybitrep = this->tinybitrep & obj.tinybitrep;
	return t;
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
	if ((i > this->maxElems) || (i < 1)) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and " + std::to_string(this->maxElems) + ", but " + std::to_string(i) + " was passed.");
	}
	return (this->tinybitrep & (1 << (i-1))) != 0;
}



template <int MaxElems>
void TinyBitSet<MaxElems>::fillall() {
	this->tinybitrep = (1 << this->maxElems) - 1;
}

template <int MaxElems>
void TinyBitSet<MaxElems>::removeall() {
	this->tinybitrep = 0;
}



template <int MaxElems>
void TinyBitSet<MaxElems>::invertSet() {
	// mask all the bits > maxElems to 0
	this->tinybitrep = ~this->tinybitrep;
	this->tinybitrep &= (1 << this->maxElems) - 1;
}




template <int MaxElems>
int TinyBitSet<MaxElems>::pop(bool reverse) {
	
	int start, finish;
	if (reverse) {
		start = this->maxElems - 1;
		finish = -1;
	} else {
		start = 0;
		finish = this->maxElems;
	} 

	for (int i = start; i != finish; i++) {
		if (this->tinybitrep & (1 << i)) {
			return i+1;
		}
	}
	return 0;  
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
	return std::bitset<MaxElems>(this->tinybitrep).to_string();  
}

template <int MaxElems>
std::bitset<MaxElems> TinyBitSet<MaxElems>::getBitSet() {
	return std::bitset<MaxElems>(this->tinybitrep);  
}

template <int MaxElems>
TinyBitRepType<MaxElems> TinyBitSet<MaxElems>::getBitRep() {
	return this->tinybitrep;  
}





template <int MaxElems>
int TinyBitSet<MaxElems>::getMaxElements() {
	return this->maxElems;  
}


template <int MaxElems>
int TinyBitSet<MaxElems>::getSetSize() {
	return __builtin_popcount(this->tinybitrep);  
}



template <int MaxElems>
bool TinyBitSet<MaxElems>::isempty() {
	return this->tinybitrep == 0;  
}



