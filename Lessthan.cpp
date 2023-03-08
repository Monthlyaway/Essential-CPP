#include <iostream>
#include <vector>
using namespace std;
class LessThan {
public:
	LessThan(int val) : _val(val) {}
	int comp_val() const { return _val; }
	void comp_val(int nval) { _val = nval; }

	bool operator() (int value) const;

private:
	int _val;
};

inline bool LessThan::operator() (int value) const
{
	return value < _val;
}

LessThan lt10(10);
int count_less_than(const vector<int>& vec, int comp)
{
	LessThan lt(comp);
	int count = 0;
	for (int ix = 0; ix < vec.size(); ix++)
		if (lt(vec[ix]))
			++count;
	return count;
}

void print_less_than(const vector<int>& vec, int comp,
	ostream& os = cout)
{
	LessThan lt(comp);
	vector<int>::const_iterator iter = vec.begin();
	vector<int>::const_iterator it_end = vec.end();

	os << "elements less than " << lt.comp_val() << endl;
	// return _val
	while ((iter = find_if(iter, it_end, lt)) != it_end)
	{
		os << *iter << " ";
		iter++;
	}
}

int main(void)
{
	int ia[10] = { 9,5,6,3,2,1,4,7,0, 8 };
	vector<int> ivec(ia, ia + 10);
	int comp_val = 5;

	cout << "Number of elements less than "
		<< comp_val << " are "
		<< count_less_than(ivec, comp_val) << endl;
	print_less_than(ivec, comp_val);

	return 0;
}
