#include "IntegerArray.h"
#include <iostream>
#include <exception>
using namespace std;

IntegerArray::IntegerArray(int length) :
	m_length{ length }
{
	if (length > 0)
	{
		m_data = new int[length] {};
	}
	else
	{
		throw exception("Length by zero!");
	}
}


IntegerArray::IntegerArray(const IntegerArray& a)
{
	reallocate(a.getLength());

	for (int i = 0; i < m_length; ++i)
	{
		m_data[i] = a.m_data[i];
	}
}

IntegerArray::~IntegerArray()
{
	delete[] m_data;
}

void IntegerArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntegerArray:: operator[](int index)
{
	if (index < 0 || index >= m_length)
	{
		throw exception("Index by zero or index >= length!");
	}

	return m_data[index];
}

IntegerArray& IntegerArray:: operator=(const IntegerArray& a)
{
	if (&a == this)
	{
		return *this;
	}

	reallocate(a.getLength());

	for (int i = 0; i < m_length; ++i)
	{
		m_data[i] = a.m_data[i];
	}

	return *this;
}

void IntegerArray::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
	{
		return;
	}

	m_data = new int[newLength];
	m_length = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (newLength == m_length)
	{
		return;
	}

	if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data = new int[newLength];

	if (m_length > 0)
	{
		int elementToCopy = (newLength > m_length) ? m_length : newLength;

		for (int i = 0; i < elementToCopy; ++i)
		{
			data[i] = m_data[i];
		}
	}

	delete[] m_data;
	m_data = data;
	m_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
	if (index < 0 || index > m_length)
	{
		throw exception("Index by zero or index > length!");
	}

	int* data = new int[m_length + 1];

	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];

	data[index] = value;

	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;

}

void IntegerArray::remove(int index)
{
	if (index < 0 || index >= m_length)
	{
		throw exception("Index by zero or index > length!");
	}

	if (m_length == 1)
	{
		erase();
		return;
	}

	int* data = new int[m_length - 1];

	for (int i = 0; i < index; ++i)
	{
		data[i] = m_data[i];
	}

	for (int i = index + 1; i < m_length; ++i)
	{
		data[i - 1] = m_data[i];
	}

	delete[] m_data;
	m_data = data;
	--m_length;
}


void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}

int IntegerArray::getLength() const
{
	return m_length;
}

void IntegerArray::printArray()
{
	for (int i= 0; i < getLength(); ++i)
	{
		cout << m_data[i] << ' ';
	}
}
