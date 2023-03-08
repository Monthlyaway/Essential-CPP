///* Because we wish 
// * only a single instance of each global object, we declare each one to be a static class member as 
// * well as the member functions that access them.
//*/
//#include <string>
//using namespace std;
//
//class globalWrapper {
//public:
//	static int tests_passed() { return _tests_passed; }
//	static int tests_run() { return _tests_run; }
//	static int version_number() { return _version_number; }
//	static string version_stamp() { return _version_stamp; }
//	static string program_name() { return _program_name; }
//
//	static void tests_passed(int nval) { _tests_passed = nval; }
//	static void tests_run(int nval) { _tests_run = nval; }
//
//private:
//	static string _program_name;
//	static string _version_stamp;
//	static int _version_number;
//	static int _tests_run;
//	static int _tests_passed;
//};
///*definition of static member variable*/
//string globalWrapper::_program_name;
//string globalWrapper::_version_stamp;
//int globalWrapper::_version_number;
//int globalWrapper::_tests_run;
//int globalWrapper::_tests_passed;
