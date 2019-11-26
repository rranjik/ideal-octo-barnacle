// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>

class foo {
public:
	static int count;
	int id;
	foo() {
		id = count;
		std::cout << "creating " << id << std::endl;
		count++;
	}
	~foo() {
		std::cout << "deleting " << id << std::endl;
	}
	friend std::ostream& operator<<(std::ostream& out, const foo f) {
		out << f.id;
		return out;
	}
};

int foo::count = 0;

template <typename T>
class vector {
	T* alloc;
	size_t cap;
	size_t len;
public:
	vector() {
		len = 0;
		cap = 1;
		alloc = new T[cap];
	}
	void push(T t) {
		if (len < cap) {
			alloc[len] = t;
			len++;
		}
		else {
			auto new_alloc = new T[2 * cap];
			for (size_t i = 0; i < cap; i++) {
				new_alloc[i] = alloc[i];
			}
			cap *= 2;
			new_alloc[len] = t;
			len++;
			delete[] alloc;
			alloc = new_alloc;
		}
	}
	T& operator[](size_t i) {
		if (i < len) {
			return alloc[i];
		}
		else throw std::exception("out of range");
	}
	size_t size() {
		return len;
	}
	~vector() {
		delete[] alloc;
	}
};

int main()
{
	vector<foo> v;
	v.push(foo());
	v.push(foo());
	v.push(foo());
	v.push(foo());
	v.push(foo());
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " " << std::endl;
	}
	getchar();
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
