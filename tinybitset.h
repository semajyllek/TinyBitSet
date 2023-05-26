/*
James Kelly
5/25/2023

C++ library for set opterations on tiny sets of only the integers 1-64,
as each bit in a 64 bit integer represents a number in the set. n -> 2^(n-1)

This allows for insertion, removal, and set operations to be done in O(1) time.


*/

#include <stdexcept>
#include "bitmapping.h"




class TinyBitSet {
	public:
		TinyBitSet(int n);
		int n;
		int tinybitset;
		void insert(int i);
		void remove(int i);
		bool contains(int i);
		TinyBitSet unionbitset(TinyBitSet const &obj);
		void fill();
		void empty();
	

};


TinyBitSet::TinyBitSet(int n) {
	if (n > 64) {
		throw std::invalid_argument("TinyBitSet can only be initialized with a number between 1 and 64");
	}


	this->n = n;
}


TinyBitSet TinyBitSet::unionbitset(TinyBitSet const &obj) {
	TinyBitSet res = TinyBitSet(this->n);
	res.tinybitset = this->tinybitset | obj.tinybitset;
	return res;
}


void TinyBitSet::insert(int i) {
	if (i > this->n) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and n");
	}

	this->tinybitset |= (1 << (i-1));

}

// make remove
void TinyBitSet::remove(int i) {
	if (i > this->n) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and n");
	}
	this->tinybitset = this->tinybitset & ~(1 << (i-1));
}

bool TinyBitSet::contains(int i) {
	if (i > this->n) {
		throw std::invalid_argument("TinyBitSet can only contain numbers between 1 and n");
	}
	return (this->tinybitset & (1 << (i-1))) != 0;
}


void TinyBitSet::fill() {
	this->tinybitset = (~0 & this->n);
}


void TinyBitSet::empty() {
	this->tinybitset = 0;
}






