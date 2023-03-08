//#pragma once
//class Triangular_iterator {
//public:
//	// set _index to index-1 in order not to subtract 1 with 
//	// each element access ... 
//	Triangular_iterator(int index) : _index(index - 1) {}
//	// overload operator ==, this pointer is omitted
//	bool operator==(const Triangular_iterator&) const;
//	// overload operator !=
//	bool operator!=(const Triangular_iterator&) const;
//	int operator*() const;
//	int& operator++(); // prefix version 
//	int operator++(int); // postfix version 
//
//private:
//	void check_integrity() const;
//	int _index;  // The Triangular_iterator class maintains an index 
//	// into the Triangular class static data member, 
//};
