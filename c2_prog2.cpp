///* see onenote->esssential c++->2.2 invoking a function*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void prog2(void);
//void bubble_sort(vector<int>& vec);
//void swap(int& val1, int& val2);
//void display(const vector<int>& vec);
//
//const int glob = 5;
//int main(void)
//{
//	prog2();
//
//	cout << glob << endl;
//	return 0;
//}
//
//void prog2(void)
//{
//	int ia[] = { 8,35,78,14,95,26,100,84,36,45,12,8,12,85,47,9,1,2,3,5,4,1,5,1,6, };
//	const int size_ia = sizeof(ia) / sizeof(ia[0]);
//	// init vector
//	vector<int> vec(ia, ia + size_ia);
//	cout << "vector before sort: "; display(vec);
//	bubble_sort(vec);
//	cout << "vector after sort: "; display(vec);
//
//}
//
//void bubble_sort(vector<int>& vec)
//{
//	for (int ix = 0; ix < vec.size() - 1; ix++)
//	{
//		for (int jx = ix + 1; jx < vec.size(); jx++)
//		{
//			if (vec[ix] > vec[jx])
//				// swap this two elements
//				swap(vec[ix], vec[jx]);
//		}
//	}
//}
//
//void swap(int& val1, int& val2)
//{
//	int temp = val1;
//	val1 = val2;
//	val2 = temp;
//}
//
//void display(const vector<int>& vec)
//{
//	for (auto i : vec)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//}