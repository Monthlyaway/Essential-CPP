//#include "Stack.h"
//#include <algorithm>
//using namespace std;
//
//bool Stack::push(const string& elem)
//{
//	// don't write _stack.full() determine the object is full or not, not the 
//	// implementation is 
//	if (full())
//		return false;
//	_stack.push_back(elem);
//	return true;
//}
//
//bool Stack::pop(string& elem)
//{
//	if (empty())
//		return false;
//	// pop and peek place the string value within elem
//	elem = _stack.back();
//	_stack.pop_back();
//	return true;
//}
//
//bool Stack::peek(string& elem) const
//{
//	if (empty())
//		return false;
//	elem = _stack.back();
//	return true;
//}
//
//bool Stack::find(const string& elem) const
//{
//	if (empty())
//		return false;
//	// global scope oprerator is necessary
//	// otherwise, recursive invokes the member instance of find()!
//	return std::find(_stack.begin(), _stack.end(), elem) != _stack.end();
//}
//
//int Stack::count(const string& elem) const
//{
//	return std::count(_stack.begin(), _stack.end(), elem);
//}
//
///*drive simple Stack class for c4_1*/
////int main(void)
////{
////	Stack st;
////	string str;
////
////	while (cin >> str && !st.full())
////		st.push(str);
////
////	if (st.empty())
////	{
////		cerr << "Oops! No strings were read -- bailing out." << endl;
////		return -1;
////	}
////
////	cout << "Read in " << st.size() << " strings. "
////		<< "The stirngs in reverse order: " << endl;
////	// clear end of file set
////	cin.clear();
////
////	//while (st.size())
////	//	if (st.pop(str))
////	//		cout << str << " ";
////	//cout << endl;
////
////	//cout << "There are now " << st.size() << " elements in the stack." << endl;
////
////	cout << "Please input some strings to search, or q to quit" << endl;
////	string search_word;
////	while (cin >> search_word && search_word != "q")
////	{
////		if (st.find(search_word))
////			cout << "Find " << search_word
////			<< "£¬appear " << st.count(search_word)
////			<< " times." << endl;
////		else
////			cout << "Can not find " << search_word << endl;
////		cout << "Please input some strings to search, or q to quit" << endl;
////	}
////
////
////		return 0;
////}