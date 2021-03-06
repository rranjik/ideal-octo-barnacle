// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>

template <typename T>
class Array {
public:
	T* alloc{ nullptr };
	size_t size{ 0 };
	Array() = default;
	Array(size_t s) {
		if (s) {
			alloc = new T[s];
			size = s;
		}
	}

	T& operator[](const size_t i) {
		if (i < size) {
			return alloc[i];
		}
		else throw exception("out of range");
	}
	
	~Array() {
		if (alloc) {
			delete[] alloc;
			size = 0;
		}
	}

	Array(const Array& other) {
		if (!other.empty()) {
			size = other.size;
			alloc = new T[size]{};
			for (int i = 0; i < size; i++) {
				alloc[i] = other.alloc[i];
			}
		}
	}

	Array& operator==(Array source) {
		swap(*this, source);
		return *this;
	}

	friend void swap(Array& a, Array& b) {
		using std::swap;
		swap(a.alloc, b.alloc);
		swap(a.size, b.size);
	}

	bool empty() {
		return size == 0;
	}
};

using namespace std;
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

class Base {
public:
	virtual void speak() {
		cout << "I'm base" << endl;
	}
	virtual ~Base(){
		cout << "Base's destructor" << endl;
	}
};

class Derived : public Base {
public:
	void speak() {
		cout << "I'm dervied" << endl;
	}
	~Derived(){
		cout << "Derived's destructor" << endl;
	}
};

int main()
{
	Base* b;
	b = new Derived();
	b->speak();
	delete b;
    std::cout << "Hello World!\n"; 
	char c;
	std::getchar();
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
