#include <ctime>
#include <iostream>
#include "../../../src/vector.hpp"

#include <vector>
#include <string.h>
#include "vector_test.hpp"

#define MAX_TEST 1000000

void	printOk() {
	std::cout << "\033[0;32m" << "V" << "\033[0;37m";
}

void	printError(std::string message) {
	std::cout << "\033[0;31m" << message << "\033[0;37m" << std::endl;
}

void	printVector(NAMESPACE::vector<int> vector) {
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

void	simpleCreation() {
	std::cout << "SimpleCreation" << std::endl;
	NAMESPACE::vector<int> NAMESPACE_vct(10, 5);
	std::cout << NAMESPACE_vct.size() << std::endl;
	std::cout << NAMESPACE_vct.max_size() << std::endl;
	std::cout << "\n\t===" << std::endl;
	std::cout << "=== RangeConstructor ===" << std::endl;
	NAMESPACE::vector<int> vector(18, 5);
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	NAMESPACE::vector<int> vectorIterator(vector.begin(), vector.end());
	for (unsigned long i = 0; i < vectorIterator.size(); i++)
		std::cout << vectorIterator[i] << " ";
	NAMESPACE::vector<int> a(5, 10);
	NAMESPACE::vector<int> b(a);
	for (unsigned long i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			printError("False");
	}
	a.clear();
	for (unsigned long i = 0; i < a.size(); i++) {
		std::cout << b[i] << std::endl;
	}
	std::cout << b.size() << " " << b.max_size() << std::endl;
	NAMESPACE::vector<int> empty;
	NAMESPACE::vector<int> empty_copy(empty);
	std::cout << empty.size() << std::endl;
	std::cout << "\n===" << std::endl;
}

void	vectorExpansion() {
	std::cout << "VectorExpansion" << std::endl;
	{
		// Default constructor
		std::cout << "=== Default constructor ===" << std::endl;;
		NAMESPACE::vector<int> vector;
		for (std::size_t i = 0; i < MAX_TEST; ++i) {
      		vector.push_back(i);
			std::cout << vector.size() << std::endl;
    	}
		printOk();
	}
	{
		// Fill constructor
		std::cout << "\nFill constructor" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		std::cout << vector.size() << std::endl;
    for (std::size_t i = 0; i < MAX_TEST; ++i) {
      vector.push_back(i);
			std::cout << vector[vector.size() - 1] << std::endl;
    }
		printOk();
		printOk();
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorOperatorEqual() {
	std::cout << "Vector operator=" << std::endl;
	{
		std::cout << "=== _capacity >= rhs.size ===" << std::endl;
    NAMESPACE::vector<int> vector(3, 8);
    NAMESPACE::vector<int> st_vector(3, 4);

    vector = st_vector;
    std::cout << vector.size() << std::endl;
    NAMESPACE::vector<int>::iterator it = vector.begin();
    while (it != vector.end()) {
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
  }
  {
    std::cout << "\n=== _capacity < rhs.size ===" << std::endl;
		NAMESPACE::vector<int> vector(3, 8);
    NAMESPACE::vector<int> st_vector(10, 4);

    vector = st_vector;
    NAMESPACE::vector<int>::iterator it = vector.begin();
    std::cout << vector.size() << std::endl;
		while (it != vector.end()) {
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;
  }
	std::cout << "\n\t===" << std::endl;
}

void	vectorBeginEnd() {
	std::cout << "Vector Begin/End" << std::endl;
	NAMESPACE::vector<int> vector;
	for (int i = 0; i < 10; i++)
		vector.push_back((i + 1) * 2);
	{
		std::cout << "=== With regular iterator ===" << std::endl;
		NAMESPACE::vector<int>::iterator start = vector.begin();
		NAMESPACE::vector<int>::iterator end = vector.end() - 1;
		while (start != end) {
			std::cout << *start << " " << *end << std::endl;
			start++;
		}
		start = vector.begin();
		*start = 42;
	}
	{
		std::cout << "=== With const iterator ===" << std::endl;
		NAMESPACE::vector<int>::const_iterator start = vector.begin();
		NAMESPACE::vector<int>::const_iterator end = vector.end() - 1;
		while (start != end) {
			std::cout << *start << " " << *end << std::endl;
			start++;
		}
		start = vector.begin();
		// Impossible bc const
		//*start = 24;
	}
}

void vectorRbeginRend() {
	std::cout << "Vector Rbegin/Rend" << std::endl;
	NAMESPACE::vector<int> vector;
	for (int i = 0; i < 10; i++)
		vector.push_back((i + 1) * 2);
	{
		std::cout << "=== With regular rev_iterator ===" << std::endl;
		NAMESPACE::vector<int>::reverse_iterator rev_start = vector.rend() - 1;
		NAMESPACE::vector<int>::reverse_iterator rev_end = vector.rbegin() + 1;
		std::cout << *rev_start << std::endl;
		std::cout << *rev_end << std::endl;
		while (rev_start != rev_end)
			std::cout << *(rev_end)++ << " ";
		std::cout << std::endl;
		rev_end = vector.rbegin() + 1;
		while (rev_start != rev_end)
			std::cout << *(rev_start)-- << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== With const_reverse_iterator ===" << std::endl;
		NAMESPACE::vector<int>::const_reverse_iterator rev_start = vector.rend() - 1;
		NAMESPACE::vector<int>::const_reverse_iterator rev_end = vector.rbegin() + 1;
		std::cout << *rev_start << std::endl;
		std::cout << *rev_end << std::endl;
		while (rev_start != rev_end)
			std::cout << *(rev_end)++ << " ";
		std::cout << std::endl;
		rev_end = vector.rbegin() + 1;
		while (rev_start != rev_end)
			std::cout << *(rev_start)-- << " ";
		std::cout << std::endl;
	}
}

void	vectorResize() {
	std::cout << "VectorResize" << std::endl;
	NAMESPACE::vector<int> vector(10, 8);

	{
		std::cout << "=== Size/max_size/capacity of empty vector ===" << std::endl;
		NAMESPACE::vector<int> empty;
		std::cout << empty.size() << " " << empty.max_size() << " " << empty.empty() << std::endl;
	}
	{
		std::cout << vector.empty() << std::endl;
		std::cout << vector.max_size() << std::endl;
	}
	{
		// resize (n < _size)
		std::cout << "\nResize (n < _size)" << std::endl;
    NAMESPACE::vector<int>::iterator first_it = vector.begin();
    vector.resize(5);

		std::cout << vector.size() << std::endl;
    /*  Iterator still must be valid a resize */
    NAMESPACE::vector<int>::iterator second_it = vector.begin();
    while (second_it != vector.end()) {
			if (first_it++ == second_it++)
				std::cout << "TRUE" << std::endl;
		}
  }

  {
		// resize (n < _size && n < _capacity)
		std::cout << "\n=== Resize (n > _size && n < _capactity) ===" << std::endl;
    // To increase _capacity from 10 to 20
    vector.push_back(1);
    vector.resize(15);

		std::cout << vector.size() << std::endl;
    NAMESPACE::vector<int>::iterator it = vector.begin();
		std::cout << *(it + 12) << std::endl;
	}
	{
		std::cout << "\nresize (n > _size && n > _capacity)" << std::endl;
		// To increase _capacity from 10 to 20
    vector.push_back(1);
    vector.resize(22);
		std::cout << vector.size() << std::endl;
    NAMESPACE::vector<int>::iterator it = vector.begin();
		std::cout << *(it + 12) << std::endl;
    for (int i = 0; i < 20; ++i) {
      vector.push_back(i);
    }
		printOk();
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorReserve() {
	std::cout << "VectorReserve" << std::endl;
	NAMESPACE::vector<int> vector(10, 8);

  {
		std::cout << "\n=== n < _capacity ===" << std::endl;
    vector.reserve(5);
		std::cout << vector.size() << std::endl;
	}
  {
    std::cout << "\nn == _capacity" << std::endl;
		vector.reserve(10);
		std::cout << vector.size() << std::endl;
	}
	{
    std::cout << "\nn > _capacity" << std::endl;
		vector.reserve(15);
		std::cout << vector.size() << std::endl;
	}
	{
		std::cout << "\nTest that exception is thrown" << std::endl;
    NAMESPACE::vector<int>::size_type max = vector.max_size();

		std::cout << max << std::endl;
		try {
			vector.reserve(max + 1);
			printError("vector.reserve(NAMESPACE_max + 15) should throw an error");
		} catch (std::exception& e) {
			// std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\t===" << std::endl;
}

void	vectorOperatorBrackets() {
	std::cout << "Operator Brackets" << std::endl;
	NAMESPACE::vector<int> vector(10);
	for (int i = 0; i < 10; i++)
		vector[i] = (i+1) * 2;
	std::cout << vector[3] << std::endl;
	const int a = vector[7];
	std::cout << a << std::endl;
	const NAMESPACE::vector<int> vector_const(10, 8);
	int b = vector_const[3];
	std::cout << b << std::endl;
}

void	vectorAt() {
	std::cout << "VectorAt" << std::endl;
	NAMESPACE::vector<int> vector(10, 8);
  std::vector<int> st_vector(10, 8);

  vector.push_back(100);
	std::cout << vector.at(10) << std::endl;
	try {
		vector.at(11);
		printError("\nNAMESPACE_vector.at(11) should throw an error");
	} catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
	}
	{
		std::cout << "\n=== On empty vector ===" << std::endl;
		NAMESPACE::vector<int> empty;
		vector.clear();
		try {
			std::cout << vector.at(0);
			std::cout << "a on empty vector SHOULD THROW AN ERROR" << std::endl;
		} catch (std::exception& e) {
			// std::cout << e.what() << std::endl;
		}
		std::cout << vector.size() << std::endl;
	}
	std::cout << "\n\t===" << std::endl;
}


void vectorFrontBack() {
	std::cout << "VectorFrontBack" << std::endl;
	NAMESPACE::vector<int> vector;

	/*
	**	You can call front/back on an empty vector but trying to do stuff if returned reference will segfault, both for NAMESPACE or std
	*/

	vector.push_back(15);
  vector.push_back(40);
  vector.push_back(1);

	std::cout << vector.front() << " " << vector.back() << std::endl;
	vector.back() -= vector.front();
	std::cout << vector.front() << " " << vector.back() << std::endl;

	while (!vector.empty()) {
		vector.clear();
	}
	std::cout << vector.size() << std::endl;
	std::cout << "\n\t===" << std::endl;
}

void	vectorAssign() {
	std::cout << "VectorAssign" << std::endl;
	NAMESPACE::vector<int> vector;
	for (int i = 0; i < 30; i++)
		vector.push_back(i);
	std::cout << vector.size() << " " << vector.max_size() << std::endl;
	{
		std::cout << "=== n <= _size ===" << std::endl;
		for (int j = 0; j <= 30; j++) {
			NAMESPACE::vector<int> v;
			for (int i = 0; i < 30; i++)
				v.push_back(i);
			v.assign(j, 42);
			for (unsigned long i = 0; i < v.size(); i++)
				std::cout << v.at(i) << " ";
			std::cout << std::endl;
			std::cout << v.size() << " " << v.max_size() << std::endl;
		}
	}
	{
		std::cout << "=== n > _size ===" << std::endl;
		for (int j = 1000; j < 2000; j++) {
			vector.assign(j, 42);
			for (unsigned long i = 0; i < vector.size(); i++)
				std::cout << vector.at(i) << " ";
			std::cout << std::endl;
			std::cout << vector.size() << " " << vector.max_size() << std::endl;
		}
	}
	{
		std::cout << "=== from Empty vector ===" << std::endl;
		NAMESPACE::vector<int> v;
		std::cout << v.size() << v.max_size() << std::endl;
		for (int i = 0; i < 100; i++) {
			v.assign(i, i);
			for (unsigned long j = 0; j < v.size(); j++)
				std::cout << v.at(j) << " ";
			std::cout << std::endl;
			std::cout << v.size() << " " << v.max_size() << std::endl;
		}
	}
	{
		std::cout << "=== from vector to emptyVector ===" << std::endl;
		NAMESPACE::vector<int> v(10, 8);
		std::cout << v.size() << " " << v.max_size() << std::endl;
		printVector(v);
		v.assign(0, 10);
		for (unsigned long j = 0; j < v.size(); j++)
			std::cout << v[j] << " ";
		std::cout << std::endl;
		std::cout << v.size() << " " << v.max_size() << std::endl;
		std::cout << v.empty() << std::endl;
		v.assign(5, 2);
		std::cout << std::endl;
		std::cout << v.size() << " " << v.max_size() << std::endl;
		std::cout << v.empty() << std::endl;
	}
	std::cout << "=== Assign range ===" << std::endl;
	{
		NAMESPACE::vector<int> vectorToAssign(10, 7);
		NAMESPACE::vector<int> vectorBase(1000, 42);
		vectorToAssign.assign(vectorBase.begin(), vectorBase.end() - 1);
		NAMESPACE::vector<int>::iterator it = vectorToAssign.begin();
		while (it != vectorToAssign.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		vectorToAssign.assign(vectorBase.begin() + 4, vectorBase.end() - 77);
		it = vectorToAssign.begin();
		while (it != vectorToAssign.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
	}
}

void	vectorPushPopBack() {
	std::cout << "VectorPushPopBack" << std::endl;
	{
		std::cout << "=== Classic ===" << std::endl;
		NAMESPACE::vector<int> vector;
		int sum = 0;
		vector.push_back(100);
		std::cout << vector.size() << std::endl;
		vector.push_back(200);
		std::cout << vector.size() << std::endl;
		vector.push_back(300);
		std::cout << vector.size() << std::endl;

		while (!vector.empty())
		{
			std::cout << vector.size() << " X " << std::endl;
			sum += vector.back();
			vector.pop_back();
		}
		std::cout << sum << std::endl;
	}
	{
		std::cout << "=== Push_back 1 million times ===" << std::endl;
		NAMESPACE::vector<int> vector;
		for (int i = 0; i < 1000000; i++) {
			vector.push_back(i * 2);
			std::cout << vector.size() << " ";
		}
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		std::cout << "=== Pop_back until empty ===" << std::endl;
		while (!vector.empty()) {
			vector.pop_back();
			std::cout << vector.size() << std::endl;
		}
		std::cout << vector.size() << std::endl;
		it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
	}
}

void	vectorInsert() {
	std::cout << "VectorInsert" << std::endl;
	/*
	**	Fill insert
	*/
	{
		std::cout << "=== Fill insert (One Element) size + 1 < _capacity ===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		vector.pop_back();
		vector.pop_back();
		std::cout << "capacity: " << std::endl;
		vector.insert(vector.begin() + 2, 1, 42);
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
		std::cout << std::endl;
		vector.insert(vector.begin() + 1, 5, 78);
		it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
		vector.insert(vector.end(), 5, 21);
		it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Fill insert size + 1 == _capacity ===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		vector.pop_back();
		vector.insert(vector.begin() + 2, 1, 78);
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		v1.pop_back();
		v1.insert(v1.begin(), 1, 42);
		it = v1.begin();
		while (++it != v1.end())
			std::cout << *it << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int> v2(10, 8);
		v2.pop_back();
		v2.insert(v2.begin(), 1, 42);
		it = v2.begin();
		while (++it != v2.end())
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Fill Insert size + n > _capacity ===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		vector.insert(vector.begin() + 2, 3, 42);
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Fill Insert to end ===" << std::endl;
		NAMESPACE::vector<int> vector(1000, 8);
		NAMESPACE::vector<int>::iterator ret;
		for (unsigned long i = 0; i < 10; i++) {
			ret = vector.insert(vector.end(), i * 10);
			std::cout << vector.size() << std::endl;
			while (ret != vector.end())
				std::cout << *(ret++) << " ";
			std::cout << std::endl;
		}
			NAMESPACE::vector<int>::iterator it = vector.begin();
			while (it != vector.end())
				std::cout << *(it++) << " ";
			std::cout << std::endl;
	}
	{
		std::cout << "=== big insert begin + 2 ===" << std::endl;
		NAMESPACE::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		printVector(vector);
		vector.insert(vector.begin() + 2, MAX_TEST, 42);
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== big insert begin ===" << std::endl;
		NAMESPACE::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		printVector(vector);
		vector.insert(vector.begin(), 10000, 42);
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== big insert end ===" << std::endl;
		NAMESPACE::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		printVector(vector);
		vector.insert(vector.end(), MAX_TEST, 42);
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	/*
	**	Simple insert
	*/
	{
		std::cout << "=== n + size() < _capacity ===" << std::endl;
		NAMESPACE::vector<int> vector(15, 8);
		vector.reserve(30);
		for (unsigned long i = 0; i < 15; i++)
			vector[i] = i * 2;
		printVector(vector);
		std::cout << vector.size() << std::endl;
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.begin() + 2, 42);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
		ret = vector.insert(vector.begin(), 34);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
		ret = vector.insert(vector.end(), 34);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== n + size == _capacity ===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		vector.pop_back();
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.begin() + 2, 78);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
	}
	{
		std::cout << "=== n + size == _capacity (begin)===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		vector.pop_back();
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.begin(), 78);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
	}
	{
		std::cout << "=== n + size == _capacity (end)===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		vector.pop_back();
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.end(), 78);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (++it != vector.end())
			std::cout << *it << " ";
	}
	{
		std::cout << "=== size() + 1 > _capacity ===" << std::endl;
		NAMESPACE::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.begin() + 2, 42);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== size() + 1 > _capacity begin ===" << std::endl;
		NAMESPACE::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.begin(), 42);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== size() + 1 > _capacity end ===" << std::endl;
		NAMESPACE::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		NAMESPACE::vector<int>::iterator ret = vector.insert(vector.end(), 42);
		while (ret != vector.end())
			std::cout << *(ret++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	{
		/*
			Bottleneck here.
		*/
		std::cout << "=== Big Simple Insert ===" << std::endl;
		NAMESPACE::vector<int> vector;
		for (int i = 0; i < 10000; i++) {
			NAMESPACE::vector<int>::iterator ret = vector.insert(vector.begin(), i);
			//while (ret != vector.end())
			std::cout << *(ret) << " ";
			std::cout << std::endl;
		}
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;
	}
	std::cout << "Insert with range" << std::endl;
	{
		NAMESPACE::vector<int> vector(10, 8);
		NAMESPACE::vector<int> vectorToAdd(4, 42);
		vector.insert(vector.begin(), vectorToAdd.begin(), vectorToAdd.end());
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it_add = vectorToAdd.begin();
		while (it_add != vectorToAdd.end())
			std::cout << *(it_add++) << " ";
		std::cout << std::endl;
		vector.insert(vector.end(), vectorToAdd.begin() + 1, vectorToAdd.end() - 1);
		it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		it_add = vectorToAdd.begin();
		while (it_add != vectorToAdd.end())
			std::cout << *(it_add++) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Big Insert Range ===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		NAMESPACE::vector<int> vectorToAdd(1000, 42);
		vector.insert(vector.begin(), vectorToAdd.begin(), vectorToAdd.end());
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		NAMESPACE::vector<int>::iterator it_add = vectorToAdd.begin();
		while (it_add != vectorToAdd.end())
			std::cout << *(it_add++) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Big Insert Range middle ===" << std::endl;
		NAMESPACE::vector<int> vector(10, 8);
		for (unsigned long i = 0; i < 10000; i++) {
			NAMESPACE::vector<int> vectorToAdd(5, i * 2);
			std::cout << "I: " << i << std::endl;
			vector.insert(vector.begin(), vectorToAdd.begin() + 2, vectorToAdd.end() - 1);
		}
		NAMESPACE::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
	}
}

void	vectorErase() {
	std::cout << "VectorErase" << std::endl;
	NAMESPACE::vector<int> vector(7);
		for (unsigned long i = 0; i < vector.size(); i++) {
		vector[i] = i;
	}
	{
		std::cout << "\n=== Simple erase ===" << std::endl;
		printVector(vector);
		NAMESPACE::vector<int>::iterator b = vector.begin();
		NAMESPACE::vector<int>::iterator it = vector.erase(b + 2);
		printVector(vector);
		std::cout << "value: " << *it << std::endl;
		std::cout << "size: " << vector.size() << std::endl;
		std::cout << "capacity: " << std::endl;
	}
	{
		//	Provoke segfault for both.
		//std::cout << "\n=== Erase with end() as input ===" << std::endl;
		//NAMESPACE::vector<int>::iterator it = vector.erase(vector.end());
		//std::cout << *it << std::endl;
		//printVector(vector);
	}
	{
		std::cout << "\n=== Erase last element ===" << std::endl;
		NAMESPACE::vector<int>::iterator it = vector.end() - 1;
		it = vector.erase(vector.end() - 1);
		if (it != vector.end())
			std::cout << *it << std::endl;
		std::cout << vector.size() << std::endl;
	}
	{
		std::cout << "\n=== Erase while i > 0 ===" << std::endl;
		NAMESPACE::vector<int>:: iterator b = vector.begin();
		for (unsigned long i = vector.size(); i > 0; i = vector.size()) {
			b = vector.erase(b);
			printVector(vector);
		}
		//std::vector<int>::iterator it;
		//std::vector<int> v;
		//ft::vector<int>::iterator itf;
		//ft::vector<int> vf;
		//while (it++ < v.end());
		//while (itf++ < vf.end());
	}
	for (unsigned long i = 10; i < 20; i++)
		vector.push_back(i * 2);
	{
		std::cout << "\n=== Erase with range ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin() + 4, vector_copy.end() - 2);
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		std::cout << "From begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::vector<int> v;
		// Come to this line later to fix capacity (maybe use insert)
		//std::cout << vector_copy.size() << " " << vector_copy.capacity() << std::endl;
	}
	{
		std::cout << "\n=== Erase with begin and end ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin(), vector_copy.end());
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		std::cout << "From begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
	}
	{
		std::cout << "\n=== Erase with end ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin() + 4, vector_copy.end());
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "From begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\n=== Erase with end - 1 ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin() + 4, vector_copy.end() - 1);
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "\nFrom begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\n=== Erase with start + 3 ===" << std::endl;
		NAMESPACE::vector<int> vector_copy(vector);
		NAMESPACE::vector<int>::iterator it = vector_copy.erase(vector_copy.begin(), vector_copy.begin() + 3);
		std::cout << "From returned iterator" << std::endl;
		while (it != vector_copy.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << "\nFrom begin iterator" << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== With big vector ===" << std::endl;
		NAMESPACE::vector<int> v(1000, 8);
		NAMESPACE::vector<int>::iterator it = v.erase(v.begin() + 2, v.end() - 4);
		while (it != v.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		it = v.begin();
		while (it != v.end())
			std::cout <<  *(it++) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	vectorSwap() {
	std::cout << "VectorSwap" << std::endl;

	NAMESPACE::vector<int> vector(3, 100);
	NAMESPACE::vector<int> vector2(5, 200);

	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (unsigned long i = 0; i < vector2.size(); i++)
		std::cout << vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "AFTER" << std::endl;
	vector.swap(vector2);
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (unsigned long i = 0; i < vector2.size(); i++)
		std::cout << vector2[i] << " ";
	std::cout << std::endl;
	std::cout << "Allocate on swapped vector" << std::endl;
	for (unsigned long i = 0; i < 50; i++)
		vector.push_back(i * 2);
	std::cout << "\nBACK" << std::endl;
	vector2.swap(vector);
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (unsigned long i = 0; i < vector2.size(); i++)
		std::cout << vector2[i] << " ";
	std::cout << "\n=== On empty vector ===" << std::endl;
	NAMESPACE::vector<int> empty;
	empty.swap(vector);
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (unsigned long i = 0; i < empty.size(); i++)
		std::cout << empty[i] << " ";
	std::cout << std::endl;
	empty.swap(vector);
	std::cout << "\n=== Swap two empty vector ===" << std::endl;
	std::cout << empty.empty() << std::endl;
	NAMESPACE::vector<int> empty2;
	empty.swap(empty2);
	for (unsigned long i = 0; i < empty.size(); i++)
		std::cout << empty[i] << " ";
	std::cout << std::endl;
	for (unsigned long i = 0; i < empty2.size(); i++)
		std::cout << empty2[i] << " ";
	std::cout << std::endl;
	std::cout << "Swap Big vector" << std::endl;
	NAMESPACE::vector<int> a(100, 3);
	NAMESPACE::vector<int> b(100, 4);
	a.swap(b);
	NAMESPACE::vector<int>::iterator a_it = a.begin();
	NAMESPACE::vector<int>::iterator b_it = b.begin();
	while (a_it != a.end())
		std::cout << *(a_it++) << " ";
	std::cout << std::endl;
	while (b_it != b.end())
		std::cout << *(b_it++) << " ";
	std::cout << std::endl;
	a.swap(b);
	a_it = a.begin();
	b_it = b.begin();
	while (a_it != a.end())
		std::cout << *(a_it++) << " ";
	std::cout << std::endl;
	while (b_it != b.end())
		std::cout << *(b_it++) << " ";
	std::cout << "\n\t===" << std::endl;
}

void	vectorClear() {
	std::cout << "VectorClear" << std::endl;
	NAMESPACE::vector<int> vector(1000, 8);
  vector.clear();
	std::cout << vector.size() << std::endl;
	std::cout << "\n=== On empty Vector ===" << std::endl;
	NAMESPACE::vector<int> empty;
	empty.clear();
	std::cout << empty.size() << " " << empty.capacity() << std::endl;
	std::cout << "\n\t===" << std::endl;
}

void	vectorGetAllocator() {
	std::cout << "VectorGetAllocator" << std::endl;
	ft::vector<int> vector(10, 8);
	std::vector<int> st_vector(10, 8);
	vector.get_allocator() == st_vector.get_allocator() ? printOk() : printError("\nget_allocation !=");
	std::cout << "\n\t===" << std::endl;
}

void isIntegralTest() {
	std::cout << "is_integral Test" << std::endl;
	std::cout << std::boolalpha;
	std::cout << NAMESPACE::is_integral<bool>::value << std::endl;
	std::cout << NAMESPACE::is_integral<char>::value << std::endl;
	std::cout << NAMESPACE::is_integral<wchar_t>::value << std::endl;
	std::cout << NAMESPACE::is_integral<signed char>::value << std::endl;
	std::cout << NAMESPACE::is_integral<short int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<long int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<long long int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<unsigned char>::value << std::endl;
	std::cout << NAMESPACE::is_integral<unsigned short int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<unsigned int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<unsigned long int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<unsigned long long int>::value << std::endl;
	std::cout << NAMESPACE::is_integral<struct fooStruct>::value << std::endl;
}

bool	fooComp(int a, int b) {
	return (a < b);
}

void	vectorComparison() {
	std::cout << "Vector Comparison" << std::endl;
	std::cout << std::boolalpha;
	{
		std::cout << "=== Same Size ===" << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(10, 8);
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
		v1[7] = 9;
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
		v2[3] = 9;
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
	}
	{
		std::cout << "=== v1.size() < v2.size() ===" << std::endl;
		NAMESPACE::vector<int> v1(8, 8);
		NAMESPACE::vector<int> v2(10, 8);
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
		v1[7] = 9;
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
		v2[3] = 9;
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
	}
	{
		std::cout << "=== v1.size() > v2.size() ===" << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(6, 8);
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
		v1[7] = 9;
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
		v2[3] = 9;
		std::cout << (v1 == v2) << std::endl;
		std::cout << (v1 != v2) << std::endl;
		std::cout << (v1 < v2) << std::endl;
		std::cout << (v1 <= v2) << std::endl;
		std::cout << (v1 > v2) << std::endl;
		std::cout << (v1 >= v2) << std::endl;
	}
}

void	vectorEqual() {
	std::cout << "NAMESPACE::equal" << std::endl;
	/*
	**	Equal isn't protected.
	*/
	{	NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(10, 8);
		v2[9] = 15;
		std::cout << std::boolalpha;
		//std::cout << NAMESPACE::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
		//std::cout << NAMESPACE::equal(v1.begin(), v1.end(), v2.begin(), fooComp) << std::endl;
	}
 		std::cout << "=== NAMESPACE::lexicographical_compare ===" << std::endl;
	{
		std::cout << "=== Same Size vector ===" << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(10, 8);
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v1[9] = 42;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[9] = 78;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[9] = 78;
		v2[3] = 9;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	}
	{
		std::cout << "=== v1 < v2 ===" << std::endl;
		NAMESPACE::vector<int> v1(5, 8);
		NAMESPACE::vector<int> v2(10, 8);
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v1[3] = 3;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[9] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[3] = 8;
		v2[4] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	}
	{
		std::cout << "=== v1 > v2 ===" << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(5, 8);
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v2[3] = 3;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v1[9] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v1[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v1[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
		v1[3] = 8;
		v1[4] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	}
 		std::cout << "=== NAMESPACE::lexicographical_compare with comp ===" << std::endl;
	{
		std::cout << "=== Same Size vector ===" << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(10, 8);
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v1[9] = 42;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[9] = 78;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[9] = 78;
		v2[3] = 9;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
	}
	{
		std::cout << "=== v1 < v2 ===" << std::endl;
		NAMESPACE::vector<int> v1(5, 8);
		NAMESPACE::vector<int> v2(10, 8);
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v1[3] = 3;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[9] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[3] = 8;
		v2[4] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
	}
	{
		std::cout << "=== v1 > v2 ===" << std::endl;
		NAMESPACE::vector<int> v1(10, 8);
		NAMESPACE::vector<int> v2(5, 8);
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v2[3] = 3;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v1[9] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v1[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v1[3] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
		v1[3] = 8;
		v1[4] = 1;
		std::cout << NAMESPACE::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), fooComp) << std::endl;
	}
}

void	vector_test() {
	simpleCreation();	// DONE
	vectorExpansion(); // DONE
	vectorOperatorEqual(); // DONE
	vectorBeginEnd(); // DONE
	vectorRbeginRend(); // DONE
	vectorResize(); // DONE
	vectorReserve(); // DONE
	vectorOperatorBrackets(); // DONE
	vectorAt(); // DONE
	vectorFrontBack(); // DONE
	vectorAssign(); // DONE
	vectorPushPopBack(); // DONE
	vectorInsert(); // DONE
	vectorErase(); // DONE
	vectorSwap(); // DONE
	vectorClear(); // DONE
	vectorGetAllocator(); // DONE
	vectorConstIterator(); // DONE
	vectorIterator(); // DONE
	vectorConstReverseIterator(); // DONE
	vectorReverseIterator(); // DONE
	isIntegralTest(); // DONE
	vectorComparison(); // DONE
	vectorEqual(); // DONE
}
