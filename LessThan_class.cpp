//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class LessThan {
//public:
//	LessThan(int val) : _val(val) {}
//	int comp_val()	const { return _val; }
//	void comp_val(int nval) { _val = nval; }
//
//	bool operator()(int value) const;
//private:
//	int _val;
//};
//
//inline bool LessThan::
//operator()(int value) const { return value < _val; }
//
//
//int count_less_than(const vector<int>& vec, int comp)
//{
//	LessThan lt(comp);
//	int count = 0;
//
//	for (int ix = 0; ix < vec.size(); ix++)
//		if (lt(vec[ix]))
//			count++;
//	return count;
//}
//
//void print_less_than(const vector<int>& vec, int comp, ostream& os = cout)
//{
//	LessThan lt(comp);
//	vector<int>::const_iterator find_it = vec.begin();
//	vector<int>::const_iterator end_it = vec.end();
//
//	while ((find_it = find_if(find_it, end_it, lt)) != end_it)
//	{
//		os << *find_it << " ";
//		++find_it;
//	}
//	os << endl;
//}
//
//int main(void)
//{
//	LessThan lt10(10);
//	int ia[5] = { 11,9,7,6,15 };  // 9,7,6 are less than 10
//	vector<int> ivec(ia, ia + 5);
//	cout << "count less than 10: " << count_less_than(ivec, 10) << endl;
//
//	cout << "print less than 10 elements: ";
//	print_less_than(ivec, 10);
//
//	return 0;
//}