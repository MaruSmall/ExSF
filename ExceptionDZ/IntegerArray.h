#pragma once

class IntegerArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray() = default;
    IntegerArray(int length);
    IntegerArray(const IntegerArray& a);
    ~IntegerArray();

    void erase();
    int& operator[](int index);
    IntegerArray& operator=(const IntegerArray& a);
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
    void printArray();
};

