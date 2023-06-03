
#include "../tinybitset.h"  // had to be installed in /usr/local/include for macOS
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
		std::cout << "passed test: testEqual" << std::endl;
	} else {
		std::cout << "failed test: testEqual, fill:" << t1.getBitString() <<  t2.getBitString() << std::endl;
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
		std::cout << "passed test: testNotEqual" << std::endl;
	} else {
		std::cout << "failed test: testNotEqual, fill:" << t1.getBitString() << t2.getBitString() << std::endl;
	}
	return;
}


void testAssignmentObject() {
	TinyBitSet<11> t1;
	t1.insert(5);
	t1.insert(7);

	TinyBitSet<11> t2;
	t2 = t1;
	if ((t1 == t2)) {
		std::cout << "passed test: testAssignmentObject" << std::endl;
	} else {
		std::cout << "failed test: testAssignmentObject, bit strings:" << t1.getBitString() << t2.getBitString() << std::endl;
	}
}


void testAssignmentBitRep() {
	TinyBitSet<9> t1;
	t1.insert(1);
	t1.insert(8);

	TinyBitSet<9> t2(t1.getBitInt());
	
	if ((t1 == t2)) {
		std::cout << "passed test: testAssignmentBitRep" << std::endl;
	} else {
		std::cout << "failed test: testAssignmentBitRep, bit strings:" << t1.getBitString() << "      " << t2.getBitString() << std::endl;
	}
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

void testInvalidSizeError() {
	try {
		TinyBitSet<65> t;
	} catch (std::invalid_argument const &err) {
		std::cout << "passed test: testInvalidSizeError, " << err.what() << std::endl;
		return;
	}
	std::cout << "failed test: testInvalidSizeError, no exception thrown" << std::endl;
}


void testInsertOne() {
	TinyBitSet<32> t;
	t.insert(5);
	if ((t.getSetSize() == 1) && (t.getIntegerElements()[0] == 5)) {
		std::cout << "passed test: testInsertOne" << std::endl;
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
		std::cout << "passed test: testInsertTwo" << std::endl;
	} else {
		std::cout << "failed test: testInsertTwo, size:" << t.getSetSize() << std::endl;
	}
	return;
}

void testContains() {
	TinyBitSet<32> t;
	t.insert(5);
	if (t.contains(5)) {
		std::cout << "passed test: testContains" << std::endl;
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
		std::cout << "passed test: testRemoveOne" << std::endl;
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
		std::cout << "passed test: testInvertSet" << std::endl;
	} else {
		std::cout << "failed test: testInvertSet, size:" << t.getSetSize() << std::endl;
	}
	return;
}


void testFill() {
	TinyBitSet<9> t;
	t.fill();
	if ((t.getSetSize() == 9) && (t.getIntegerElements() == std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}))) {
		std::cout << "passed test: testFill" << std::endl;
	} else {
		std::cout << "failed test: testFill, size:" << t.getSetSize() << std::endl;
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
		std::cout << "passed test: testUnion" << std::endl;
	} else {
		std::cout << "failed test: testUnion, " << t3.getSetSize() << std::endl;
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
		std::cout << "passed test: testIntersection" << std::endl;
	} else {
		std::cout << "failed test: testIntersection, " << t3.getSetSize() << std::endl;
	}
	return;

}





void testPopSmallest() {
	TinyBitSet<17> t;
	t.insert(5);
	t.insert(7);
	int res = t.popSmallest();

	if((res == 5) && (t.getSetSize() == 1)) {
		std::cout << "passed test: testPopSmallest" << std::endl;
	} else {
		std::cout << "failed test: testPopSmallest, " << res << t.getSetSize() <<  std::endl;
	}
	return;

}


void testPopLargest() {
	TinyBitSet<17> t;
	t.insert(5);
	t.insert(7);
	t.insert(17);
	int res = t.popLargest();

	if((res == 17) && (t.getSetSize() == 2)) {
		std::cout << "passed test: testPopLargest" << std::endl;
	} else {
		std::cout << "failed test: testPopLargest, " << res << t.getSetSize() << std::endl;
	}
	return;
}

void testPopInt() {
	TinyBitSet<17> t;
	t.insert(5);
	t.insert(7);
	t.insert(11);
	t.insert(17);
	int res = t.popInt(11);

	if((t.getSetSize() == 3) && (res == 11)) {
		std::cout << "passed test: testPopInt" << std::endl;
	} else {
		std::cout << "failed test: testPopInt, res: " << res << ", size: " << t.getSetSize() << std::endl;
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
		std::cout << "passed test: testLeftDiff" << std::endl;
	} else {
		std::cout << "failed test: testLeftDiff, " << t3.getSetSize() << std::endl;
	}
	return;

}





void testLeftDiffBits() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);
	t1.insert(1);
	t1.insert(3);


	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);
	t2.insert(8);

	TinyBitSet<9> t3 = t1.leftDifference(t2.getBitInt());
	if ((t3.getSetSize() == 2) && (t3.getIntegerElements() == std::vector<int>({1, 7}))){
		std::cout << "passed test: testLeftDiffBits" << std::endl;
	} else {
		std::cout << "failed test: testLeftDiffBits, " << t3.getSetSize() << std::endl;
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
		std::cout << "passed test: testRightDiff" << std::endl;
	} else {
		std::cout << "failed test: testRightDiff, " << t3.getSetSize() << std::endl;
	}
	return;

}


void testRightDiffBits() {
	TinyBitSet<9> t1;
	t1.insert(5);
	t1.insert(7);
	t1.insert(1);
	t1.insert(3);


	TinyBitSet<9> t2;
	t2.insert(3);
	t2.insert(5);
	t2.insert(8);

	TinyBitSet<9> t3 = t1.rightDifference(t2.getBitInt());
	if ((t3.getSetSize() == 1) && (t3.getIntegerElements() == std::vector<int>({8}))){
		std::cout << "passed test: testRightDiffBits" << std::endl;
	} else {
		std::cout << "failed test: testRightDiffBits, " << t3.getSetSize() << std::endl;
	}
	return;

}







int main() {
	testEqual();
	testNotEqual();
	testAssignmentObject();
	testAssignmentBitRep();
	testContains();
	testValidSize();
	testInvalidSizeError();
	testInsertOne();
	testInsertTwo();
	testRemoveOne();
	testInvertSet();
	testUnion();
	testIntersection();
	testFill();
	testRemoveAll();
	testPopSmallest();
	testPopLargest();
	testPopInt();
	testLeftDiff();
	testRightDiff();
	testLeftDiffBits();
	testRightDiffBits();
	return 0;
}



