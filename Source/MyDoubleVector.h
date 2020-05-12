// 2014707040 À¯ÁøÇõ

#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class MyDoubleVector
{
public:
	static const int INIT_CAPACITY = 1;
	static const int CAPACITY_UP = 3;
	static const int ERR_OUT_RANGE = 1;
	static const int ERR_SIZES = 2;
	MyDoubleVector();
	MyDoubleVector(const MyDoubleVector& v);
	~MyDoubleVector();
	MyDoubleVector& operator=(const MyDoubleVector& source);
	void operator+=(const MyDoubleVector& addend);
	double& operator[](size_t n);
	const MyDoubleVector operator+(const MyDoubleVector& v);
	const MyDoubleVector operator-(const MyDoubleVector& v);
	double operator*(const MyDoubleVector& v);
	const MyDoubleVector operator-();
	bool operator==(const MyDoubleVector& v);
	void operator()(double value);
	void pop_back();
	void push_back(double x);
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	bool empty() const;
	void clear();

private:
	double *data;
	size_t used;
	size_t space;
};