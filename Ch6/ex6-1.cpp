/*Rewrite the following class definition to make it a class template: */
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename elemType>
class example {
public:
    example(const elemType& min, const elemType& max)
        : _min(min), _max(max) {}

    example(const elemType* array, int size)
        : _min(), _max() {
        _parray = new elemType[size];
        for (int i = 0; i < size; ++i) {
            _parray[i] = array[i];
        }
        this->_size = size;
    }

    elemType& operator[](int index) {
        if (index >= 0 && index < _size) {
            return _parray[index];
        }
        else {
            // Handle out-of-bounds access or throw an exception
            // depending on your requirements.
            throw std::out_of_range("Invalid index");
        }
    }

    bool operator==(const example& other) const {
        if (_size != other._size) {
            return false;
        }
        for (int i = 0; i < _size; ++i) {
            if (_parray[i] != other._parray[i]) {
                return false;
            }
        }
        return true;
    }

    bool insert(const elemType* array, int arraySize) {
        int newSize = _size + arraySize;
        elemType* newArray = new elemType[newSize];
        for (int i = 0; i < _size; ++i) {
            newArray[i] = _parray[i];
        }
        for (int i = 0; i < arraySize; ++i) {
            newArray[_size + i] = array[i];
        }
        delete[] _parray;
        _parray = newArray;
        _size = newSize;
        return true;
    }

    bool insert(elemType value) {
        /* 
        * construct a new array
        * move the original array to the new location
        * push new value to the end of narray
        * delete the original array
        * modify private member data: _size, _parray
        */
        elemType* newArray = new elemType[_size + 1];  // construct a new array
        for (int i = 0; i < _size; ++i) {
            newArray[i] = _parray[i];  // parray is the old array
        }
        newArray[_size] = value;  // value is pushed back
        delete[] _parray;
        _parray = newArray;
        ++_size;
        return true;
    }

    elemType min() const {
        return _min;
    }

    elemType max() const {
        return _max;
    }

    int size() const {
        return _size;
    }

    void min(const elemType& newMin) {
        _min = newMin;
    }

    void max(const elemType& newMax) {
        _max = newMax;
    }

    int count(elemType value) const {
        int count = 0;
        for (int i = 0; i < _size; ++i) {
            if (_parray[i] == value) {
                ++count;
            }
        }
        return count;
    }

    ~example() {
        delete[] _parray;
    }

private:
    int _size = 0;
    elemType* _parray = 0;
    elemType _min;
    elemType _max;
};

int main() {
    // Example with integers
    example<int> intExample(1, 10);

    intExample.insert(5);
    intExample.insert(8);
    intExample.insert(3);
    intExample.insert(6);

    std::cout << "Min: " << intExample.min() << std::endl;
    std::cout << "Max: " << intExample.max() << std::endl;

    std::cout << "Values in the example: ";
    for (int i = 0; i < intExample.size(); ++i) {
        std::cout << intExample[i] << " ";
    }
    std::cout << std::endl;

    int searchValue = 5;
    std::cout << "Count of " << searchValue << ": " << intExample.count(searchValue) << std::endl;

    // Example with doubles
    double doubleArray[] = { 1.2, 3.4, 5.6 };
    int doubleSize = sizeof(doubleArray) / sizeof(double);

    example<double> doubleExample(doubleArray, doubleSize);

    doubleExample.min(0.5);
    doubleExample.max(6.7);

    std::cout << "Min: " << doubleExample.min() << std::endl;
    std::cout << "Max: " << doubleExample.max() << std::endl;

    std::cout << "Values in the example: ";
    for (int i = 0; i < doubleExample.size(); ++i) {
        std::cout << doubleExample[i] << " ";
    }
    std::cout << std::endl;

    double searchValue2 = 3.4;
    std::cout << "Count of " << searchValue2 << ": " << doubleExample.count(searchValue2) << std::endl;

    return 0;
}