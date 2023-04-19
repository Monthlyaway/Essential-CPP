#include <iostream>
#include <vector>

using namespace std;

/*
* three-level class hierarchy
* base class: LibMat
* only contain functions that are the same for all derived classes
* like print()
*
* virtual: virtual functions are intended to be overriden by derived class
*/
class LibMat {
public:
	LibMat() {
		cout << "LibMat::LibMat() default constructor!\n";
	}
	virtual ~LibMat() {
		cout << "LibMat::~LibMat() destructor!\n";
	}
	virtual void print() const
	{
		cout << "LibMat::print() -- I am a LibMat object!\n";
	}
};

class Book : public LibMat {
public:
	Book(const string& title, const string& author)
		: _title(title), _author(author) {
		cout << "Book::Book(" << _title
			<< ", " << _author << ") constructor\n";
	}
	virtual ~Book() {
		cout << "Book::~Book() destructor!\n";
	}
	// override the Libmat version of print
	virtual void print() const {
		cout << "Book::print() -- I am a Book object!\n"
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << endl;
	}
	const string& title() const { return _title; }
	const string& author() const { return _author; }
protected:
	string _title;
	string _author;
};

class AudioBook : public Book {
public:
	AudioBook(const string& title, const string& author, const string& anchor)
		: Book(title, author), _anchor(anchor) {
		cout << "AudioBook::AudioBook(" << _title
			<< ", " << _author << ", " << _anchor << ") constructor\n";
	}
	virtual void print() const {
		cout << "AudioBook::print() -- I am an AudioBook object!\n"
			// note the direct access of the inherited 
			// data members _title and _author 
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << '\n'
			<< "My anchor is: " << _anchor << endl;
	}
	virtual ~AudioBook() {
		cout << "AudioBook::~AudioBook() destructor!\n";
	}

protected:
	string _anchor;
};

class Magazine : public LibMat {
public:
	Magazine(const string& title, const string& publisher)
		: _title(title), _publisher(publisher) {
		cout << "Magazine::Magazine(" << _title
			<< ", " << _publisher << ") constructor\n";
	}
	virtual ~Magazine() {
		cout << "Magazine::~Magazine() destructor!\n";
	}
	// override the Libmat version of print
	virtual void print() const {
		cout << "Magazine::print() -- I am a Magazine object!\n"
			<< "My title is: " << _title << '\n'
			<< "My publisher is: " << _publisher << endl;
	}
	const string& title() const { return _title; }
	const string& publisher() const { return _publisher; }
protected:
	string _title;
	string _publisher;
};


void print(LibMat& mat) {
	cout << "in global print(): about to print mat.print()\n";
	// this resolves to a print() member function 
	// based on the actual object mat refers to ... 
	mat.print();
}

int main(void)
{
	//cout << "\n" << "Creating a LibMat object to print()\n";
	//LibMat libmat;
	//print(libmat);

	//cout << "\n" << "Creating a Book object to print()\n";
	//Book b("The Castle", "Franz Kafka");
	//print(b);

	/*cout << "\n" << "Creating an AudioBook object to print()\n";
	AudioBook ab("Man Without Qualities",
		"Robert Musil", "Kenneth Meyer");
	print(ab);*/

	cout << "\n" << "Creating a Magazine object to print()\n";
	Magazine mag("National Geographic", "John Doe");
	print(mag);

	return 0;
}