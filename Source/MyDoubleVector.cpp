// 2014707040 À¯ÁøÇõ

#include "MyDoubleVector.h"

MyDoubleVector::MyDoubleVector()
{
	// precondition: When objects are created.
	// postcondition: The memory is allocated as much as INIT_CAPACITY, member variables are initialized.
	data = new double[INIT_CAPACITY];
	space = INIT_CAPACITY;
	used = 0;
}

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v)
{
	// precondition: When an object of the class is returned by value,
	//               When an object of the class is passed (to a function) by value as an argument,
	//               When an object is constructed based on another object of the same class.
	// postcondition: The object is copied.
	data = new double[v.space];
	space = v.space;
	used = v.used;
	copy(v.data, v.data + used, data);
}

MyDoubleVector::~MyDoubleVector()
{
	// precondition: When objects are destroyed (deallocated).
	// postcondition: Frees the allocated memory.
	delete[] data;
}

MyDoubleVector& MyDoubleVector::operator=(const MyDoubleVector& source)
{
	// postcondition: RHS object is assigned to LHS object.
	double *new_data;
	if (this == &source)
		return *this;
	if (space != source.space)
	{
		new_data = new double[source.space];
		delete[] data;
		data = new_data;
		space = source.space;
	}
	used = source.used;
	copy(source.data, source.data + used, data);
	return *this;
}

void MyDoubleVector::operator+=(const MyDoubleVector& addend)
{
	// postcondition: Appends RHS object to LHS one.
	if (used + addend.used > space)
		reserve(used + addend.used);
	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
}

double& MyDoubleVector::operator[](size_t n)
{
	// precondition: n < used
	// postcondition: Returns a reference to the element at the requested position in the vector container.
	if (n >= used)
	{
		cout << "The requested position is out of range." << endl;
		exit(ERR_OUT_RANGE);
	}
	return *(data + n);
}

const MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v)
{
	// precondition: When the sizes of the two operands is the same.
	// postcondition: Returns an object that is a vector-sum of the two operand objects.
	MyDoubleVector answer;
	if (this->used != v.used)
	{
		cout << "The sizes of the two operands is not the same." << endl;
		exit(ERR_SIZES);
	}
	answer.reserve(used);
	for (size_t i = 0; i < used; i++)
	{
		answer.data[i] = data[i] + v.data[i];
		answer.used++;
	}
	return answer;
}

const MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector& v)
{
	// precondition: When the sizes of the two operands is the same.
	// postcondition: Returns an object that is a vector-difference of the two operand objects.
	MyDoubleVector answer;
	if (this->used != v.used)
	{
		cout << "The sizes of the two operands is not the same." << endl;
		exit(ERR_SIZES);
	}
	answer.reserve(used);
	for (size_t i = 0; i < used; i++)
	{
		answer.data[i] = data[i] - v.data[i];
		answer.used++;
	}
	return answer;
}

double MyDoubleVector::operator*(const MyDoubleVector& v)
{
	// precondition: When the sizes of the two operands is the same.
	// postcondition: Returns the scalar product value of the two operand objects.
	double scalar = 0.0;
	if (this->used != v.used)
	{
		cout << "The sizes of the two operands is not the same." << endl;
		exit(ERR_SIZES);
	}
	for (size_t i = 0; i < used; i++)
		scalar += data[i] * v.data[i];
	return scalar;
}

const MyDoubleVector MyDoubleVector::operator-()
{
	// postcondition: Returns an object of which each element is the unary negation.
	MyDoubleVector answer;
	answer.reserve(used);
	for (size_t i = 0; i < used; i++)
	{
		answer.data[i] = -data[i];
		answer.used++;
	}
	return answer;
}

bool MyDoubleVector::operator==(const MyDoubleVector& v)
{
	// postcondition: Returns true if sizes of two operand vectors are same and thier each element is the same.
	//                Otherwise returns false.
	size_t check = 0;
	if (used == v.used)
	{
		for (size_t i = 0; i < used; i++)
		{
			if (data[i] == v.data[i])
				check++;
		}
		return check == used;
	}
	return false;
}

void MyDoubleVector::operator()(double value)
{
	// precondition: When the vector container is not empty.
	// postcondition: Makes every element of this object be the value of the operand.
	for (size_t i = 0; i < used; i++)
		data[i] = value;
}

void MyDoubleVector::pop_back()
{
	// precondition: When the vector container is not empty.
	// postcondition: Removes the last element in the vector.
	if (!empty())
		reserve(--used);
}

void MyDoubleVector::push_back(double x)
{
	// precondition: When the memory is not full.
	// postcondition: Adds a new element at the end of the vector.
	if (used == space)
		reserve(used + CAPACITY_UP);
	data[used++] = x;
}

size_t MyDoubleVector::capacity() const
{
	// postcondition: Returns the size of the allocated storage space for the elements of the vector container.
	return space;
}

size_t MyDoubleVector::size() const
{
	// postcondition: Returns the number of elements in the vector container.
	return used;
}

void MyDoubleVector::reserve(size_t n)
{
	// postcondition: Extends the capacity of the allocated storage space for the elements of the vector container.
	double *larger_array;
	if (n == space)
		return;
	if (n < used)
		n = used;
	larger_array = new double[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	space = n;
}

bool MyDoubleVector::empty() const
{
	// postcondition: if the vector container is empty, returns true.
	//                Otherwise, returns false.
	return used == 0;
}

void MyDoubleVector::clear()
{
	// postcondition: All the elements of the vector are dropped
		delete[] data;
		used = 0;
		space = 0;
		data = new double[space];
}