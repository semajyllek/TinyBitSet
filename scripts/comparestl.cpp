
/*

	time each of these operations for N random integer elements using 1. tinybitset and 2. std::set
	a. insertion
	b. removal
	c. membership
	d. union
	e. intersection
	f. left difference
	g. right difference
	h. pop smallest
	i. pop largest

*/

#include <iostream>
#include <chrono>
#include <unordered_set>
#include "../tinybitset.h"

const int MAX_ELEMS = 64;


float timeInsertionTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		t.insert(randInts[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeInsertionSTL(int N, int* randInts) {
	std::unordered_set<int> s;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		s.insert(randInts[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeRemovalTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t;

	for (int i = 0; i < N; i++) {
		t.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		t.remove(randInts[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeRemovalSTL(int N, int* randInts) {
	std::unordered_set<int> s;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		s.erase(randInts[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}





float timeMembershipTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t;

	for (int i = 0; i < N; i++) {
		t.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		t.contains(randInts[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeMembershipSTL(int N, int* randInts) {
	std::unordered_set<int> s;

	for (int i = 0; i < N; i++) {
		s.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		s.count(randInts[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeUnionTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t1;
	TinyBitSet<MAX_ELEMS> t2;

	for (int i = 0; i < N; i++) {
		t1.insert(randInts[i]);
	}

	for (int i = 0; i < N; i++) {
		t2.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	t1.unionb(t2);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}



float timeUnionSTL(int N, int* randInts) {
	std::unordered_set<int> s1;
	std::unordered_set<int> s2;

	for (int i = 0; i < N; i++) {
		s1.insert(randInts[i]);
	}

	for (int i = 0; i < N; i++) {
		s2.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	s1.insert(s2.begin(), s2.end());
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeIntersectionTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t1;
	TinyBitSet<MAX_ELEMS> t2;

	for (int i = 0; i < N; i++) {
		t1.insert(randInts[i]);
	}

	for (int i = 0; i < N; i++) {
		t2.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	t1.intersectionb(t2);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}

float timeIntersectionSTL(int N, int* randInts) {
	std::unordered_set<int> s1;
	std::unordered_set<int> s2;

	for (int i = 0; i < N; i++) {
		s1.insert(randInts[i]);
	}

	for (int i = 0; i < N; i++) {
		s2.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	std::unordered_set<int> s3;
	for (auto it = s1.begin(); it != s1.end(); it++) {
		if (s2.count(*it) > 0) {
			s3.insert(*it);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}



float timeMaxTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t;

	for (int i = 0; i < N; i++) {
		t.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	t.popLargest();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}

float timeMaxSTL(int N, int* randInts) {
	std::unordered_set<int> s;

	for (int i = 0; i < N; i++) {
		s.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	int max = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it > max) {
			max = *it;
		}
	}
	s.erase(max);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeMinTBS(int N, int* randInts) {
	TinyBitSet<MAX_ELEMS> t;
	for (int i = 0; i < N; i++) {
		t.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	t.popSmallest();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


float timeMinSTL(int N, int*randInts) {
	std::unordered_set<int> s;
	for (int i = 0; i < N; i++) {
		s.insert(randInts[i]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	int min = MAX_ELEMS;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it < min) {
			min = *it;
		}
	}
	s.erase(min);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}


int main() {
	
	int N = 1000000;

	int randInts[N];
	for (int i = 0; i < N; i++) {
		randInts[i] = (rand() % MAX_ELEMS) + 1;
	}

	float t1, t2;

	std::cout << "N = " << N << ", MAX_ELEMS = " << MAX_ELEMS << std::endl;

	// time insertion
	t1 = timeInsertionTBS(N, randInts);
	t2 = timeInsertionSTL(N, randInts);

	std::cout << "time for insertion of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for insertion of " << N << " elements in std::set: " << t2 << std::endl;


	// time removal
	t1 = timeRemovalTBS(N, randInts);
	t2 = timeRemovalSTL(N, randInts);

	std::cout << "time for removal of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for removal of " << N << " elements in std::set: " << t2 << std::endl;


	// time membership
	t1 = timeMembershipTBS(N, randInts);
	t2 = timeMembershipSTL(N, randInts);

	std::cout << "time for membership of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for membership of " << N << " elements in std::set: " << t2 << std::endl;


	// time union
	t1 = timeUnionTBS(N, randInts);
	t2 = timeUnionSTL(N, randInts);

	std::cout << "time for union of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for union of " << N << " elements in std::set: " << t2 << std::endl;

	// time intersection
	t1 = timeIntersectionTBS(N, randInts);
	t2 = timeIntersectionSTL(N, randInts);

	std::cout << "time for intersection of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for intersection of " << N << " elements in std::set: " << t2 << std::endl;

	// time min
	t1 = timeMinTBS(N, randInts);
	t2 = timeMinSTL(N, randInts);

	std::cout << "time for min of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for min of " << N << " elements in std::set: " << t2 << std::endl;


	// time max
	t1 = timeMaxTBS(N, randInts);
	t2 = timeMaxSTL(N, randInts);

	std::cout << "time for max of " << N << " elements in TinyBitSet: " << t1 << std::endl;
	std::cout << "time for max of " << N << " elements in std::set: " << t2 << std::endl;


	return 0;

}


/*
N = 1000000, MAX_ELEMS = 64
time for insertion of 1000000 elements in TinyBitSet: 0.00558562
time for insertion of 1000000 elements in std::set: 0.0870218
time for removal of 1000000 elements in TinyBitSet: 0.00315625
time for removal of 1000000 elements in std::set: 0.0367294
time for membership of 1000000 elements in TinyBitSet: 0.00291933
time for membership of 1000000 elements in std::set: 0.0575827
time for union of 1000000 elements in TinyBitSet: 1.125e-06
time for union of 1000000 elements in std::set: 5.792e-06
time for intersection of 1000000 elements in TinyBitSet: 1.417e-06
time for intersection of 1000000 elements in std::set: 3.8417e-05
time for max of 1000000 elements in TinyBitSet: 1.834e-06
time for max of 1000000 elements in std::set: 1.1958e-05



N = 1000000, MAX_ELEMS = 35
time for insertion of 1000000 elements in TinyBitSet: 0.00552667
time for insertion of 1000000 elements in std::set: 0.0869244
time for removal of 1000000 elements in TinyBitSet: 0.00319171
time for removal of 1000000 elements in std::set: 0.0365375
time for membership of 1000000 elements in TinyBitSet: 0.00294442
time for membership of 1000000 elements in std::set: 0.0579016
time for union of 1000000 elements in TinyBitSet: 3.542e-06
time for union of 1000000 elements in std::set: 2.667e-06
time for intersection of 1000000 elements in TinyBitSet: 3.042e-06
time for intersection of 1000000 elements in std::set: 2.3833e-05
time for max of 1000000 elements in TinyBitSet: 2.125e-06
time for max of 1000000 elements in std::set: 8.166e-06




N = 1000000, MAX_ELEMS = 9
time for insertion of 1000000 elements in TinyBitSet: 0.00544487
time for insertion of 1000000 elements in std::set: 0.0868513
time for removal of 1000000 elements in TinyBitSet: 0.00335342
time for removal of 1000000 elements in std::set: 0.0364481
time for membership of 1000000 elements in TinyBitSet: 0.00295092
time for membership of 1000000 elements in std::set: 0.0571621
time for union of 1000000 elements in TinyBitSet: 4.584e-06
time for union of 1000000 elements in std::set: 1.25e-06
time for intersection of 1000000 elements in TinyBitSet: 5.916e-06
time for intersection of 1000000 elements in std::set: 9e-06
time for max of 1000000 elements in TinyBitSet: 5.125e-06
time for max of 1000000 elements in std::set: 7.834e-06



N = 1000000, MAX_ELEMS = 5
time for insertion of 1000000 elements in TinyBitSet: 0.005366
time for insertion of 1000000 elements in std::set: 0.088149
time for removal of 1000000 elements in TinyBitSet: 0.00313167
time for removal of 1000000 elements in std::set: 0.0367437
time for membership of 1000000 elements in TinyBitSet: 0.00287008
time for membership of 1000000 elements in std::set: 0.0589925
time for union of 1000000 elements in TinyBitSet: 1.083e-06
time for union of 1000000 elements in std::set: 1.209e-06
time for intersection of 1000000 elements in TinyBitSet: 2.083e-06
time for intersection of 1000000 elements in std::set: 8.667e-06
time for max of 1000000 elements in TinyBitSet: 2.5e-06
time for max of 1000000 elements in std::set: 6e-06


*/




