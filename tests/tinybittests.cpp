
#include "../tinybitset.h"
#include <cassert>
#include <iostream>
#include <vector>

void testValidSize() {
	TinyBitSet<8> t;
	try {
		assert(t.getMaxElements() == 8);
		assert(t.getSetSize() == 0);
		std::cout << "Test: testValidSize passed: (empty 8 bit set)" << std::endl;
	} catch (std::invalid_argument const &err) {
		std::cout << "Test: testValidSize failed: " << err.what() << std::endl;
	}
	
}

void testInvalidSize() {
	try {
		TinyBitSet<65> t;
	} catch (std::invalid_argument const &err) {
		std::cout << "Test: testInvalidSize passed: " << err.what() << std::endl;
		return;
	}
	std::cout << "Test testInvalidSize failed: no exception thrown" << std::endl;
}


void testInsertOne() {
	TinyBitSet<32> t;
	t.insert(5);
	try {
		assert(t.getSetSize() == 1);
	    assert(t.getIntegerElements()[0] == 5);
		std::cout << "Test testInsertOne passed: insert(5)" << std::endl;
		return;
	} catch (std::invalid_argument const &err) {
		std::cout << t.getSetSize() << err.what() << std::endl;
		return;
	}
}

void testInsertTwo() {
	TinyBitSet<32> t;
	t.insert(5);
	t.insert(22);
	try {
		assert(t.getSetSize() == 2);
	    assert(t.getIntegerElements() == std::vector<int>({5, 22}));
		std::cout << "Test testInsertTwo passed: insert(5), insert(22)" << std::endl;
		return;
	} catch (std::invalid_argument const &err) {
		std::cout << t.getSetSize() << err.what() << std::endl;
		return;
	}
}


void testRemoveOne() {
	TinyBitSet<32> t;
	t.insert(5);
	t.insert(22);
	t.remove(5);
	try {
		assert(t.getSetSize() == 1);
	    assert(t.getIntegerElements() == std::vector<int>({22}));
		std::cout << "Test testRemoveOne passed: insert(5), insert(22), remove(5)" << std::endl;
		return;
	} catch (std::invalid_argument const &err) {
		std::cout << t.getSetSize() << err.what() << std::endl;
		return;
	}
}







int main() {
	testValidSize();
	testInvalidSize();
	testInsertOne();
	testInsertTwo();
	testRemoveOne();
	return 0;
}



