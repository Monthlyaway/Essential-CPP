//#pragma once
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Stack {
//public:
//	// public interface
//
//	// pop and peek place the string value within elem 
//	bool push(const string& elem);
//	bool pop(string& elem);
//	bool peek(string& elem) const;
//
//	bool find(const string& elem) const;
//	int count(const string& elem) const;
//
//	// return true, if vector is empty
//	bool empty() const { return _stack.empty(); }
//	bool full() const { return _stack.size() == _stack.max_size(); }
//
//	// definition of size() is defined inside class body
//	// automatically treated as inline
//	// other functions are simply declared
//	int size() const { return _stack.size(); }
//
//private:
//	// private implementation
//	vector<string> _stack;
//};