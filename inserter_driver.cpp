//// C++ program to demonstrate std::inserter
//#include <iostream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	// Declaring first container
//	vector<int> d1 = { 1,5,2,3,4,1,2,6,5,4,1,3,2,4 };
//
//	// Declaring second container for
//	// copying values
//	vector<int> d2 = { 4,5,6 };
//
//	vector<int>::iterator it;
//	it = d2.begin() + 1;
//	// i1 points to next element of 4 in d2
//
//	std::sort(d1.begin(), d1.end());
//	// Using std::inserter inside std::copy
//	std::unique_copy(d1.begin(), d1.end(), inserter(d2, it));
//
//	// Displaying v1 and v2
//	cout << "d1: ";
//	for (auto u : d1)
//		cout << u << ' ';
//	cout << endl;
//	cout << "d2: ";
//	for (auto u : d2)
//		cout << u << ' ';
//	cout << endl;
//
//	return 0;
//}