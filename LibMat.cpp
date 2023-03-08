#include <iostream>
#include <string>
using namespace std;
class LibMat {
public:
	LibMat() 
	{ cout << "LibMat::LibMat() default construcor!" << endl; }

	virtual ~LibMat() 
	{ cout << "LibMat::~LibMat() deconstructor!" << endl; }
	virtual void print() const
	{ cout << "LibMat::print() -- I am a LibMat object!" << endl;}

private:
};

class Book : public LibMat {
public:
	Book(const string& title, const string& author)
		:_title(title), _author(author) {
		cout << "Book::Book(" << _title << ", " << _author
			<< ") constructor" << endl;
	}

	virtual ~Book() {
		cout << "Book::~Book() deconstructor" << endl;
	}

	/*print() overrides the LibMat instance*/
	virtual void print() const {
		cout << "Book::print() -- I am a Book object!\n"
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << endl;
	}

	const string& title() const { return _title; }
	const string& author() const { return _author; }

protected:
	/* A member declared as protected can be directly accessed by
	 * the derived classes but cannot be directly accessed
	 * by the general program
	 */
	string _title;
	string _author;
};

class AudioBook : public Book {
public: 
	AudioBook(const string& title,
		const string& author, const string& narrator)
		: Book(title, author), _narrator(narrator) {
		cout << "AudioBook::AudioBook(" << _title
			<< ", " << _author << ", " << _narrator 
			<< ") constructor" << endl;;
	}

	virtual ~AudioBook(){
		cout << "AudioBook::~AudioBook() deconstructor" << endl;
	}

	virtual void print() const {
		cout << "AudioBook::print() -- I am an AudioBook object\n"
			// note the direct access of the inherited
			// data members _title and _author
			<< "My title is: " << _title << "\n"
			<< "My author is: " << _author << "\n"
			<< "My narrator is: " << _narrator << endl;
	}

	const string& narrator(void) const { return _narrator; }
protected:
	string _narrator;
};

/*
* a non member print function
* associated with virtual member functions
*/
void print(const LibMat& mat)
{
	cout << "in global print(): about to print mat.print()\n";
	// this resolve to a print() member function
	// based on the actual object mat refers to
	// use a pointer of reference to invoke the virtual functions
	mat.print();
}

void progm1(void)
{
	cout << "\n" << "Creating a LibMat object to print\n";
	LibMat libmat;
	print(libmat);
	/*
	* Creating a LibMat object to print
	* LibMat::LibMat() default construcor!
	* 
	* in global print(): about to print mat.print()
	* LibMat::print() -- I am a LibMat object!
	* 
	* LibMat::~LibMat() deconstructor!
	*/
}

void progm2(void)
{
	cout << "\n" << "Creating a Book object to print\n";
	Book book("Linear Algebra", "Dr.Strang");
	print(book);
	/*
	* Creating a Book object to print
    * LibMat::LibMat() default construcor!
	* Book::Book(Linear Algebra, Dr.Strang) constructor
	* 
	* in global print(): about to print mat.print()
	* Book::print() -- I am a Book object!
	* My title is: Linear Algebra
	* My author is: Dr.Strang
	* 
	* Book::~Book() deconstructor
	* LibMat::~LibMat() deconstructor!
	*/
}

void progm3(void)
{
	cout << "\n" << "Creating an AudioBook object to print\n";
	AudioBook ab("Mason and Dixon",
		"Thomas Pynchon", "Edwin Leonard");
	print(ab);
	/*
	* Creating an AudioBook object to print
	* LibMat::LibMat() default construcor!
	* Book::Book(Mason and Dixon, Thomas Pynchon) constructor
	* AudioBook::AudioBook(Mason and Dixon, Thomas Pynchon, Edwin Leonard) constructor
	* 
	* in global print(): about to print mat.print()
	* AudioBook::print() -- I am an AudioBook object
	* My title is: Mason and Dixon
	* My author is: Thomas Pynchon
	* My narrator is: Edwin Leonard
	* 
	* AudioBook::~AudioBook() deconstructor
	* Book::~Book() deconstructor
	* LibMat::~LibMat() deconstructor!
	*/
}

//int main(void)
//{
//	//progm1();
//	//progm2();
//	progm3();
//
//	return 0;
//}