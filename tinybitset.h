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

#include <iostream>


template <int MaxElems>
	using TinyBitRepType = typename std::conditional<MaxElems < 9, uint_fast8_t, 
					typename std::conditional<MaxElems < 17, uint_fast16_t,
					typename std::conditional<MaxElems < 33, uint_fast32_t,
					uint_fast64_t>::type>::type>::type;



template <int MaxElems>
class TinyBitSet {
	public:
		TinyBitSet();

		// overloaded object operator
		bool operator==(TinyBitSet<MaxElems> const &obj) const;
		bool operator!=(TinyBitSet<MaxElems> const &obj) const;
		TinyBitSet<MaxElems>& operator=(TinyBitSet<MaxElems> const &obj); 


		// set operations
		void insert(int i);
		void remove(int i);
		bool contains(int i);

		// set operations to return new TinyBitSet
		TinyBitSet<MaxElems> unionb(TinyBitSet<MaxElems> const &obj);
		TinyBitSet<MaxElems> intersectionb(TinyBitSet<MaxElems> const &obj);
		TinyBitSet<MaxElems> leftDifference(TinyBitSet<MaxElems> const &obj);
		TinyBitSet<MaxElems> rightDifference(TinyBitSet<MaxElems> const &obj);

		// set operations to modify this TinyBitSet
		void fillall();
		void removeall();
		void invertSet();
		int pop(bool reverse=false);

		// get functions
		std::vector<int> getIntegerElements() const;
		std::string getBitString() const;
		TinyBitRepType<MaxElems> getBitInt() const;
		int getMaxElements() const; 
		int getSetSize() const;
		bool isempty() const;

		// set functions
		void setBitRep(uint_fast8_t const newbitrep);
		void setBitRep(uint_fast16_t const newbitrep);
		void setBitRep(uint_fast32_t const newbitrep);
		void setBitRep(uint_fast64_t const newbitrep);
		

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
void TinyBitSet<MaxElems>::setBitRep(uint_fast8_t const newbitrep) {
	if (sizeof(this->tinybitrep) != sizeof(newbitrep)) {
		throw std::invalid_argument("bit representation sizes do not match");
	}
	this->tinybitrep = newbitrep;
	return;
}


template <int MaxElems> 
void TinyBitSet<MaxElems>::setBitRep(uint_fast16_t const newbitrep) {
	if (sizeof(this->tinybitrep) != sizeof(newbitrep)) {
		throw std::invalid_argument("bit representation sizes do not match");
	}
	this->tinybitrep = newbitrep;
	return;
}

template <int MaxElems> 
void TinyBitSet<MaxElems>::setBitRep(uint_fast32_t const newbitrep) {
	if (sizeof(this->tinybitrep) != sizeof(newbitrep)) {
		throw std::invalid_argument("bit representation sizes do not match");
	}
	this->tinybitrep = newbitrep;
	return;
}

template <int MaxElems> 
void TinyBitSet<MaxElems>::setBitRep(uint_fast64_t const newbitrep) {
	if (sizeof(this->tinybitrep) != sizeof(newbitrep)) {
		throw std::invalid_argument("bit representation sizes do not match");
	}
	this->tinybitrep = newbitrep;
	return;
}



template <int MaxElems> 
TinyBitSet<MaxElems>& TinyBitSet<MaxElems>::operator=(TinyBitSet<MaxElems> const &obj) {
	if (obj.getMaxElements() != this->maxElems) {
		throw std::invalid_argument("left TinyBitSet maxElems != right TinyBitSet maxElems");
	}
	this->maxElems =  obj.getMaxElements();
	this->tinybitrep = obj.tinybitrep;
	return *this;
}


template <int MaxElems> 
bool TinyBitSet<MaxElems>::operator==(TinyBitSet<MaxElems> const &obj) const {
	return this->tinybitrep == obj.tinybitrep;
}

template <int MaxElems> 
bool TinyBitSet<MaxElems>::operator!=(TinyBitSet<MaxElems> const &obj) const {
	return this->tinybitrep != obj.tinybitrep;
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
TinyBitSet<MaxElems> TinyBitSet<MaxElems>::leftDifference(TinyBitSet<MaxElems> const &obj) {
	TinyBitSet<MaxElems> t;
	t.tinybitrep = this->tinybitrep ^ (this->tinybitrep & obj.tinybitrep);
	return t;
}

template <int MaxElems>
TinyBitSet<MaxElems> TinyBitSet<MaxElems>::rightDifference(TinyBitSet<MaxElems> const &obj) {
	TinyBitSet<MaxElems> t;
	t.tinybitrep = obj.tinybitrep ^ (this->tinybitrep & obj.tinybitrep);
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
		finish = 0;
	} else {
		start = 0;
		finish = this->maxElems;
	} 

	for (int i = start; i != finish; i++) {
		if (this->tinybitrep & (1 << i)) {
			remove(i+1);
			return i+1;
		}
	}
	return 0;  
}




/*
	getters
*/

template <int MaxElems>
std::vector<int> TinyBitSet<MaxElems>::getIntegerElements() const {
	std::vector<int> elems;
	for (int i = 0; i < this->maxElems; i++) {
		if (this->tinybitrep & (1 << i)) {
			elems.push_back(i+1);
		}
	}
	return elems;
}


template <int MaxElems>
std::string TinyBitSet<MaxElems>::getBitString() const {
	return std::bitset<MaxElems>(this->tinybitrep).to_string();  
}


template <int MaxElems>
TinyBitRepType<MaxElems> TinyBitSet<MaxElems>::getBitInt() const {
	return this->tinybitrep;  
}





template <int MaxElems>
int TinyBitSet<MaxElems>::getMaxElements() const {
	return this->maxElems;  
}


template <int MaxElems>
int TinyBitSet<MaxElems>::getSetSize() const {
	return __builtin_popcount(this->tinybitrep);  
}



template <int MaxElems>
bool TinyBitSet<MaxElems>::isempty() const {
	return this->tinybitrep == 0;  
}



