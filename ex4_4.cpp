///* A user profile consists of a login, the actual user name,
// * the number of times logged on, the
// * number of guesses made, the number of correct guesses,
// * the current level ¡ª one of beginner,
// * intermediate, advanced, guru ¡ª and the percentage correct
// * (this latter may be computed or
// * stored). Provide a UserProfile class. Support input and output,
// * equality and inequality. The
// * constructors should allow for a default user level and default
// *  login name of "guest." How
// * might you guarantee that each guest login for a particular session is unique?*/
//#include <iostream>
//#include <string>
//#include <map>
//#include <cstdlib>  // for itoa()
//
//using namespace std;
//
//class UserProfile {
//public:
//	enum uLevel { Beginner, Intermediate, Advanced, Guru };
//
//	// default memberwise initialization
//	UserProfile(string login, uLevel level = Beginner);
//	// default constructor 
//	UserProfile(void);
//	// no explicit copy constructor or copy assignment operator 
//	// no destructor necessary...
//
//	bool operator==(const UserProfile& rhs);
//	bool operator!=(const UserProfile& rhs);
//
//	// read access functions
//	string user_name(void) const { return _user_name; }
//	string login(void) const { return _login; }
//	int times_logged(void) const { return _times_logged; }
//	int guesses(void) const { return _guesses; }
//	int correct_guesses(void) const { return _correct_guesses; }
//	double correctness_percent(void) const;
//	string level(void) const;
//
//	// write access functions
//	void reset_login(const string& sval) { _login = sval; }
//	void reset_user_name(const string& sval) { _user_name = sval; }
//
//	void reset_level(uLevel newlevel) { _user_level = newlevel; }
//	void reset_level(const string& sval);
//
//	void reset_login_count(int newcount) { _times_logged = newcount; }
//	void reset_login_count(void) { _times_logged = 0; }
//
//	void reset_guess_count(int newcount) { _guesses = newcount; }
//	void reset_guess_count(void) { _guesses = 0; }
//
//	void reset_correct_guesses(int nval) { _correct_guesses = nval; }
//	void reset_correct_guesses(void) { _correct_guesses = 0; }
//
//	void bump_login_count(int cnt = 1) { _times_logged += cnt; }
//	void bump_guess_count(int cnt = 1) { _guesses += cnt; }
//	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }
//
//private:
//	string _user_name;
//	string _login;
//	int _times_logged;
//	int _guesses;
//	int _correct_guesses;
//	uLevel _user_level;
//
//	static map<string, uLevel> _level_map; // use string outside class
//	static void init_level_map(void);
//	static string guest_login(void);
//};
//
//inline double UserProfile::correctness_percent(void) const
//{
//	return _guesses
//		? (double)_correct_guesses / _guesses * 100
//		: 0.0;
//}
//
//inline UserProfile::UserProfile(string login, uLevel level)
//	:_user_name("Not Initialized"), _user_level(level), _login(login),
//	_times_logged(1), _guesses(0), _correct_guesses(0){}
//
//inline UserProfile::UserProfile(void)
//	: _user_name("Not Initialized"), _user_level(Beginner), _login("guest"),
//	_times_logged(1), _guesses(0), _correct_guesses(0)
//{
//	static int id = 0;
//	char buffer[16];
//
//	// _itoa() is a Standard C library function 
//	// turns an integer into a null-terminated string
//	_itoa_s(id++, buffer, 16, 10);
//
//	// add a unique id during session to guest login 
//	// sample login: guest1234
//	_login += buffer;
//
//}
//
//inline bool UserProfile::operator==(const UserProfile& rhs)
//{
//	if (_login == rhs._login &&
//		_user_name == rhs._user_name)
//		return true;
//	else
//		return false;
//}
//
//inline bool UserProfile::operator!=(const UserProfile& rhs)
//{
//	// use the overloaded operator == above
//	// together with this pointer
//	return !(*this == rhs);
//}
//
//string UserProfile::level(void) const
//{
//	static string _level_table[] = {
//		"Beginner", "Intermediate", "Advanced", "Guru"
//	};
//	return _level_table[_user_level];
//}
//
///*non member functions: return reference to ostream and istream*/
//ostream& operator<<(ostream& os, const UserProfile& rhs)
//{
//	// output of the form: stanl Beginner 12 100 10 10%
//	os << "login: " << rhs.login() << ", "
//		<< "level: " << rhs.level() << ", "
//		<< "login count: " << rhs.times_logged() << ", "
//		<< "guess count: " << rhs.guesses() << ", "
//		<< "guess correct: " << rhs.correct_guesses() << ", "
//		<< "correctness percentage: " << rhs.correctness_percent();
//	return os;
//}
//
//
///* static part
// * overkill ... but it allows a demonstration ...
// */
//map<string, UserProfile::uLevel> UserProfile::_level_map;
//void UserProfile::init_level_map(void)
//{
//	_level_map["Beginner"] = Beginner;
//	_level_map["Intermediate"] = Intermediate;
//	_level_map["Advanced"] = Advanced;
//	_level_map["Guru"] = Guru;
//}
//
//inline void UserProfile::reset_level(const string& nlevel)
//{
//	if (_level_map.empty())
//		init_level_map();
//
//	// confirm level is a recognized user level
//	// use map member function find(), not the find algorithm
//	map<string, uLevel>::iterator iter = _level_map.begin();
//	_user_level = (iter = _level_map.find(nlevel))
//		== _level_map.end() ? _level_map["Beginner"] : iter->second;
//}
//
//istream& operator>>(istream& is, UserProfile& rhs)
//{
//	// assume the input is valid...
//	string login, level;
//	is >> login >> level;
//
//	int login_count, guess_count, correct_guesses;
//	is >> login_count >> guess_count >> correct_guesses;
//
//	rhs.reset_login(login);
//	rhs.reset_level(level);
//	rhs.reset_login_count(login_count);
//	rhs.reset_guess_count(guess_count);
//	rhs.reset_correct_guesses(correct_guesses);
//
//	return is;
//}
//
///*main function*/
////int main(void)
////{
////	UserProfile Will;
////	cout << Will << endl;  // test output operator
////
////	UserProfile Will_too;
////	cout << Will_too << endl;
////
////	UserProfile Laurence("Laurence", UserProfile::Guru);	
////	cout << Laurence << endl;
////
////	UserProfile Laurence_too("Laurence", UserProfile::Beginner);
////	cout << Laurence_too << endl;
////
////	Will.bump_guess_count(27);
////	Will.bump_guess_correct(25);
////	Will.bump_login_count();
////	cout << Will << endl;
////
////	/*cin >> Will;
////	cout << Will << endl;*/
////
////	return 0;
////}