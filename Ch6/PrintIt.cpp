#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PrintIt {
public:
	PrintIt(ostream& os) : _os(os) {}
	template <typename elemType>
	void print(const elemType& val, char delimiter = '\n') {
		_os << val << delimiter;
	}
private:
	ostream& _os;
};


void prog1()
{
	PrintIt to_standard_out(cout);
	to_standard_out.print("hello");
}

int main(void)
{
	prog1();

	return 0;
}