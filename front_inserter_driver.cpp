//#include <iostream>
//#include <iterator>
//#include <deque>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	// Declaring first container
//	deque<int> v1 = { 1, 2, 3 ,1,3,2,4,2,3,1,2,4 };
//
//	// Declaring second container for
//	// copying values
//	deque<int> v2 = { 4, 4 , 5, 6 };
//
//	std::sort(v1.begin(), v1.end());
//	// Using std::front_inserter inside std::copy
//	std::unique_copy(v1.begin(), v1.end(), std::front_inserter(v1));  // support push_front method
//	
//	auto ip = std::unique_copy(v2.begin(), v2.end(), v2.begin());
//	v2.resize(std::distance(v2.begin(), ip));
//
//	// Displaying v1 and v2
//	// Displaying v1 and v2
//	cout << "v1: ";
//	for (auto u : v1)
//		cout << u << ' ';
//	cout << endl;
//	cout << "v2: ";
//	for (auto u : v2)
//		cout << u << ' ';
//	cout << endl;
//
//	return 0;
//}