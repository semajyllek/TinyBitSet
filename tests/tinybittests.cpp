
#include "../tinybitset.h"
#include <cassert>
#include <iostream>
#include <vector>

void testValidSize() {
	TinyBitSet<8> t;
	try {
		assert(t.getMaxElements() == 8);
		assert(t.getSetSize() == 0);
		std::cout << "passed test: testValidSize, (empty 8 bit set)" << std::endl;
	} catch (std::invalid_argument const &err) {
		std::cout << "failed test: testValidSize, " << err.what() << std::endl;
	}
	
}

void testInvalidSize() {
	try {
		TinyBitSet<65> t;
	} catch (std::invalid_argument const &err) {
		std::cout << "passed test: testInvalidSize, " << err.what() << std::endl;
		return;
	}
	std::cout << "failed test: testInvalidSize, no exception thrown" << std::endl;
}


void testInsertOne() {
	TinyBitSet<32> t;
	t.insert(5);
	try {
		assert(t.getSetSize() == 1);
	    assert(t.getIntegerElements()[0] == 5);
		std::cout << "passed test: testInsertOne, insert(5)" << std::endl;
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
		std::cout << "passed test: testInsertTwo, insert(5), insert(22)" << std::endl;
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
		std::cout << "passed test: testRemoveOne, insert(5), insert(22), remove(5)" << std::endl;
		return;
	} catch (std::invalid_argument const &err) {
		std::cout << t.getSetSize() << err.what() << std::endl;
		return;
	}
}


// test union
void testUnion() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);

	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);

	TinyBitSet<9> t3 = t1.unionb(t2);
	try {
		assert(t3.getSetSize() == 3);
	    assert(t3.getIntegerElements() == std::vector<int>({3, 5, 7}));
		std::cout << "passed test: testUnion, union({5, 7}, {3, 5})" << std::endl;
		return;
	} catch (std::invalid_argument const &err) {
		std::cout << t3.getSetSize() << err.what() << std::endl;
		return;
	}

}


void testIntersection() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);

	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);

	TinyBitSet<9> t3 = t1.intersectionb(t2);
	try {
		assert(t3.getSetSize() == 1);
	    assert(t3.getIntegerElements() == std::vector<int>({5}));
		std::cout << "passed test: testIntersection, intersection({5, 7}, {3, 5})" << std::endl;
		return;
	} catch (std::invalid_argument const &err) {
		std::cout << t3.getSetSize() << err.what() << std::endl;
		return;
	}

}







int main() {
	testValidSize();
	testInvalidSize();
	testInsertOne();
	testInsertTwo();
	testRemoveOne();
	testUnion();
	testIntersection();
	return 0;
}



