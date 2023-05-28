
#include "../tinybitset.h"  // had to be installed in /usr/local/include for macOS
#include <cassert>
#include <iostream>
#include <vector>



void testEqual() {
	TinyBitSet<11> t1;
	t1.insert(5);
	t1.insert(7);
	
	TinyBitSet<11> t2;
	t2.insert(7);
	t2.insert(5);
	

	if ((t1 == t2)) {
		std::cout << "passed test: testEqual, t1.insert(5), t1.insert(7), t2.insert(7), t2.insert(5), t1==t2" << std::endl;
	} else {
		std::cout << "failed test: testEqual, size:" << t1.getBitString() <<  t2.getBitString() << std::endl;
	}
	return;
}


void testNotEqual() {
	TinyBitSet<11> t1;
	t1.insert(5);
	t1.insert(7);
	
	TinyBitSet<11> t2;
	t2.insert(7);
	t2.insert(4);
	

	if ((t1 != t2)) {
		std::cout << "passed test: testNotEqual, t1.insert(5), t1.insert(7), t2.insert(7), t2.insert(4), t1!=t2" << std::endl;
	} else {
		std::cout << "failed test: testNotEqual, size:" << t1.getBitString() << t2.getBitString() << std::endl;
	}
	return;
}






void testValidSize() {
	TinyBitSet<8> t;
	if ((t.getMaxElements() == 8) && (t.getSetSize() == 0)) {
		std::cout << "passed test: testValidSize, (empty 8 bit set)" << std::endl;
	} else {
		std::cout << "failed test: testValidSize, " << std::endl;
	}
	return;
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
	if ((t.getSetSize() == 1) && (t.getIntegerElements()[0] == 5)) {
		std::cout << "passed test: testInsertOne, insert(5)" << std::endl;
	} else {
		std::cout << "failed test: testInsertOne, size:" << t.getSetSize() << std::endl;
	}
	return;
}

void testInsertTwo() {
	TinyBitSet<32> t;
	t.insert(5);
	t.insert(22);
	if ((t.getSetSize() == 2) && (t.getIntegerElements() == std::vector<int>({5, 22}))){
		std::cout << "passed test: testInsertTwo, insert(5), insert(22)" << std::endl;
	} else {
		std::cout << "failed test: testInsertTwo, size:" << t.getSetSize() << std::endl;
	}
	return;
}

void testContains() {
	TinyBitSet<32> t;
	t.insert(5);
	if (t.contains(5)) {
		std::cout << "passed test: testContains, insert(5), t.contains(5)" << std::endl;
	} else {
		std::cout << "failed test: testContains, size:" << t.getSetSize() << std::endl;
	}
	return;
}


void testRemoveOne() {
	TinyBitSet<32> t;
	t.insert(5);
	t.insert(22);
	t.remove(5);
	if ((t.getSetSize() == 1) && (t.getIntegerElements() == std::vector<int>({22}))) {
		std::cout << "passed test: testRemoveOne, insert(5), insert(22), remove(5)" << std::endl;
	} else {
		std::cout << "failed test: testRemoveOne, size:" << t.getSetSize()  << std::endl;
	}
	return;
}


void testInvertSet() {
	TinyBitSet<11> t;
	t.insert(5);
	t.insert(7);
	t.invertSet();
	if ((t.getSetSize() == 9) && (t.getIntegerElements() == std::vector<int>({1, 2, 3, 4, 6, 8, 9, 10, 11}))) {
		std::cout << "passed test: testInvertSet, insert(5), insert(7), invertSet()" << std::endl;
	} else {
		std::cout << "failed test: testInvertSet, size:" << t.getSetSize() << std::endl;
	}
	return;
}


void testFillAll() {
	TinyBitSet<9> t;
	t.fillall();
	if ((t.getSetSize() == 9) && (t.getIntegerElements() == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}))) {
		std::cout << "passed test: testFillAll" << std::endl;
	} else {
		std::cout << "failed test: testFillAll, size:" << t.getSetSize() << std::endl;
	}
	return;
}



void testRemoveAll() {
	TinyBitSet<37> t;
	t.insert(10);
	t.insert(2);
	t.insert(35);
	t.removeall();

	if ((t.getSetSize() == 0) && (t.getIntegerElements() == std::vector<int>({}))) {
		std::cout << "passed test: testRemoveAll" << std::endl;
	} else {
		std::cout << "failed test: testRemoveAll, size:" << t.getSetSize() << std::endl;
	}
	return;
}




void testUnion() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);
	t1.insert(1);
	t1.insert(3);


	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);
	t2.insert(8);

	TinyBitSet<9> t3 = t1.unionb(t2);
	if ((t3.getSetSize() == 5) && (t3.getIntegerElements() == std::vector<int>({1, 3, 5, 7, 8}))){
		std::cout << "passed test: testIntersection, intersection({5, 7, 1, 3}, {3, 5, 8})" << std::endl;
	} else {
		std::cout << "failed test: testIntersection, " << t3.getSetSize() << std::endl;
	}
	return;

}


void testIntersection() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);
	t1.insert(1);
	t1.insert(3);


	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);
	t2.insert(8);

	TinyBitSet<9> t3 = t1.intersectionb(t2);
	if ((t3.getSetSize() == 2) && (t3.getIntegerElements() == std::vector<int>({3, 5}))){
		std::cout << "passed test: testIntersection, intersection({5, 7, 1, 3}, {3, 5, 8})" << std::endl;
	} else {
		std::cout << "failed test: testIntersection, " << t3.getSetSize() << std::endl;
	}
	return;

}



void testLeftDiff() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);
	t1.insert(1);
	t1.insert(3);


	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);
	t2.insert(8);

	TinyBitSet<9> t3 = t1.leftDifference(t2);
	if ((t3.getSetSize() == 2) && (t3.getIntegerElements() == std::vector<int>({1, 7}))){
		std::cout << "passed test: testLeftDiff, leftDifference({5, 7, 1, 3}, {3, 5, 8})" << std::endl;
	} else {
		std::cout << "failed test: testLeftDiff, " << t3.getSetSize() << std::endl;
	}
	return;

}


void testRightDiff() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);
	t1.insert(1);
	t1.insert(3);


	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);
	t2.insert(8);

	TinyBitSet<9> t3 = t1.rightDifference(t2);
	if ((t3.getSetSize() == 1) && (t3.getIntegerElements() == std::vector<int>({8}))){
		std::cout << "passed test: testRightDiff, rightDifference({5, 7, 1, 3}, {3, 5, 8})" << std::endl;
	} else {
		std::cout << "failed test: testRightDiff, " << t3.getSetSize() << std::endl;
	}
	return;

}



void testPopFirst() {
	TinyBitSet<17> t;
	t.insert(5);
	t.insert(7);
	int res = t.pop();

	if((res == 5) && (t.getSetSize() == 1)) {
		std::cout << "passed test: testPopFirst, insert(5), insert(7), pop()" << std::endl;
	} else {
		std::cout << "failed test: testPopFirst, " << res << t.getSetSize() <<  std::endl;
	}
	return;

}


void testPopLast() {
	TinyBitSet<17> t;
	t.insert(5);
	t.insert(7);
	t.insert(17);
	bool reverse = true;
	int res = t.pop(reverse);

	if((res == 17) && (t.getSetSize() == 2)) {
		std::cout << "passed test: testPopLast, insert(5), insert(7), insert(17), pop()" << std::endl;
	} else {
		std::cout << "failed test: testPopLast, " << res << t.getSetSize() << std::endl;
	}
	return;
}





int main() {
	testEqual();
	testNotEqual();
	testContains();
	testValidSize();
	testInvalidSize();
	testInsertOne();
	testInsertTwo();
	testRemoveOne();
	testInvertSet();
	testUnion();
	testIntersection();
	testFillAll();
	testRemoveAll();
	testPopFirst();
	testPopLast();
	testLeftDiff();
	testRightDiff();
	return 0;
}



