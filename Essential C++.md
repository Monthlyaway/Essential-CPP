[TOC]

# 2 Precedural Programming

## 2.4 Using Local Static Objects

The first call calculates all the values necessary to fulfill the request of the second and third 
invocations. If a fourth invocation requested 32 elements, we really need calculate only elements 
25 through 32 — if we could cache the elements calculated between invocations. How might we 
do that? 

**<u>In general, however, file scope objects complicate the independence and understandability of individual functions.</u>** 

An alternative solution, in this case, is a <u>**local static object**</u>. With each invocation of fibon_seq(), we need calculate only those elements that are not as yet inserted into elems.

```c++
vector<int>* fibon_seq(int size)
{
    static vector<int> elems;
    // do the logic to populate it
    return &elems;  // return the pointer to vector<int>, don't copy it
}
// void push_back(const T& x):向量尾部增加一个元素X
```

Here is one possible implementation: 

```c++
vector<int>* fibon_seq(int size)
{
    int max_size = 1024;
    static vector<int> elems;
    // check the size
    if (size <= 0 || size >= max_size)
    {
        cerr << "fibon_seq(): oops: invalid size: "  // standard err output
 				<< size << " -- can't fulfill request.\n"; 
 		return 0;   // null pointer
    }
    // if size <= elems.size(), no calculations are needed
    for (int i = elems.size(); i < size; i++)
    {
        if (i == 0 || i == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[i - 2] + elems[i - 1]);
    }
   
    return &elems;  
}
```

<u>**push_back() inserts the value at the back of the vector**</u>. The memory to support this is managed automatically by the vector class itself

***

## 2.5 Declaring a Function inline

We can simplify its implementation by <u>**factoring subtasks into separate functions**</u>:

```c++
bool is_size_ok(int size)  // check if size is in range
{
    const int max_size = 1024;
    if (size <= 0 || size >= max_size)
    {
         cerr << "fibon_seq(): oops: invalid size: "  // standard err output
 				<< size << " -- can't fulfill request.\n"; 
 		return false;   // return a boolean type
    }
    else
        return true;
}

// calculate up to size elements of Fibonacci sequence 
// return address of static container holding elements 
// modify the static vector
const vector<int>* fibon_seq(int size) 
{
    static vector<int> elems;
    if (!is_size_ok(size))
        return 0;
    
    // if size <= elems.size(), no calculations are needed
    for (int i = elems.size(); i < size; i++)
    {
        if (i == 0 || i == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[i - 2] + elems[i - 1]);
    }
    return &elems;  
}

// returns the Fibonacci element at position pos 
// (we must adjust by 1 because first element is stored at 0) 
// returns false if position is unsupported 
bool fibon_elem(int pos, int &elem)
{
    // use a pointer to store the static vector
    vector<int>* pseq = fibon_seq(pos);
    if (!pseq)  // fibon_seq() returns null pointer because position is unsupported 
        {elem = 0; return false;}
    else
        elem = pseq[pos - 1];
    return true;
}
```

The drawback is that fibon_elem() now requires three function calls to complete its operation, 
whereas previously it required only one. Is this additional overhead critical? That depends on the 
context of its use. If its performance should prove unacceptable, one solution is to fold the three 
functions back into one. In C++, an alternative solution is to declare the functions as <u>**inline**</u>. 

An inline function represents a request to the compiler to **<u>expand the function at each call point</u>**. 
With an inline function, the compiler replaces the function call with a <u>**copy**</u> of the code to be executed. In effect, this allows us to benefit from the performance improvement of folding the functions back into fibon_elem() while still <u>**maintaining the three functions as independent operations.**</u>

```c++
// ok: now fibon_elem() is an inline function 
inline bool fibon_elem(int pos, int &elem)
{/* definition same as above */}
```

**<u>The definition of an inline function is usually placed within a header file.</u>**

***

## 2.6 Providing Overloaded Functions 

 Two or more functions can be given the same name if the parameter list of each function is unique 
either by <u>**the type or the number of parameters**</u>.

```c++
void display_message(char ch); 
void display_message(const string&); 
void display_message(const string&, int); 
void display_message(const string&, int, int); 
```

The <u>**return type**</u> of a function by itself does not distinguish two instances of a function that have 
the same name. The following, for example, is illegal. It results in a compile-time error: 

```c++
// error: parameter list not return type must be unique 
ostream& display_message(char ch); 
bool display_message(char ch); 

display_message('\t'); // which one? 
```



Overloading a set of functions that have unique implementations but perform a similar task **<u>simplifies the use of these functions for our users</u>**. Without overloading, we would have to provide each function with a unique name. 

**Same function name                     Different parameters**

***

## 2.7 Defining and Using Template Functions 

```c++
void display_message(const string&, const vector<int>&); 
void display_message(const string&, const vector<double>&); 
void display_message(const string&, const vector<string>&); 

void display_message(const string& msg, const vector<int>& vec)
{
    cout << msg;
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
}
```

It would certainly save us a great deal of effort if we could define a single instance of the function body rather than duplicate the code multiple times and make the <u>**necessary minor changes**</u> to each instance. To do that, however, we need a facility to bind that single instance to each vector type we wish to display. **<u>The function template mechanism</u>** provides just this facility. 

```c++
template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec);
                                                 // use the template
{
    cout << string;
    for (int i = 0; i < vec.size(); i++)
    { 
        elemType t = vec[i];  // placeholder
		cout << t << ' ';
    }
    cout << endl;
}
```

We make a function a template when <u>**the body of the code remains invariant across a variety of types**</u>. 

A function template can also be an overloaded function.

```c++
// overloaded instances of a function template 
template <typename elemType> 
void display_message(const string &msg, const vector<elemType> &vec); 
template <typename elemType> 
void display_message(const string &msg, const list<elemType> &lt); 
```

***

## 2.8 Pointers to Functions Add Flexibility 

```c++
const vector<int>* *seq_ptr(int); // almost correct 
const vector<int>* (*seq_ptr)(int); // ok
/*To have seq_ptr be recognized as a pointer, we must override the default precedence of * with parentheses: 
*/
```

Here is an implementation.

```c++
bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)) 
{
    // invoke function addressed by seq_ptr 
 	const vector<int> *pseq = seq_ptr(pos); 
 	if (! pseq) 
 		{ elem = 0; return false; } 
    else
 		elem = (*pseq)[pos-1]; 
    
 	return true; 
}
```

It might be wise, however, to confirm that it does at least address some function: 

```c++
if (! seq_ptr) 
 	display_message("Internal Error: seq_ptr is set to null!");
```

What if we wish to set seq_ptr to <u>**a different sequence function with each iteration of our display loop**</u> without having to name each function explicitly? To solve this problem, we can again resort to indexing into an array. In this case, we define an array of pointers to functions: 

```c++
vector<int>* (*seq_array[])(int) = {
    fibon_seq, lucas_seq, pell_seq, 
 	triang_seq, square_seq, pent_seq 
};
```

seq_array is an array of pointers to functions holding six elements. The first element is the address of fibon_seq(), the second, lucas_seq(), and so on. We can <u>**set seq_ptr with each iteration of a while loop**</u> while the user still wishes to guess another sequence: 

```c++
int seq_index = 0;
while (next_seq == true)
{
    seq_ptr = seq_array[seq_index++];
    // ...	
}
```

Alternatively, what if we wished to access the pointer explicitly to the function generating the Pell 
sequence? It is somewhat clumsy having to remember that the Pell instance is addressed by the 
third array element. A more intuitive method of indexing is to provide a set of mnemonic constant 
values: <u>**enumerate**</u>

```c++
enum ns_type { 
 ns_fibon, ns_lucas, ns_pell, 
 ns_triang, ns_square, ns_pent 
};
// same order
seq_ptr = seq_array[ns_pell]; 
```

***

## 2.9 Setting up a header file

Before I can invoke `seq_elem()`, I must first declare it to the program. If it is invoked in five program text files, there must be five declarations available. Rather than separately declare `seq_elem()` in each of the five files, <u>**we place the function declaration in a header file**</u>. The header file is then <u>**included in each program text file**</u> that wishes to use the function. 

Using this convention, we need maintain only a single declaration of a function. If its parameter list or return type changes, only this one declaration needs to be modified. <u>**All users of the**</u>**<u>function automatically include the updated function declaration</u>**

There can be only one definition of a function in a program. However, <u>**there can be multiple declarations**</u>. We don't put definitions in a header file because the header file is included in multiple text files within a program. 

One exception to this one-definition rule is the definition of an inline function. To expand an inline function, the definition must be available to the compiler at each invocation point. This means that we must <u>**place the inline function definitions inside a header file rather than in a separate program text file**</u>. 

Objects defined at file scope are also declared in a header file if multiple files may need to access the objects. This is because an object can not be referred to until it has been declared to the program. For example, if `seq_array` were defined at file scope, we would likely provide a declaration within `NumSeq.h`. Not unexpectedly, our first try is not quite correct: 

```c++
// This is not quite right ... 
const int seq_cnt = 6; 
const vector<int>* (*seq_array[seq_cnt])(int); 
```

This is not correct because it is interpreted as the definition of seq_array and not as a declaration. Just as with a function, <u>**an object can be defined only once in a program**</u>. The definition of an object, as well as the definition of a function, <u>**must be placed in a program text file**</u>. <u>**We turn the definition of seq_array into a declaration by prefacing it with the keyword `extern`**</u>: 

```c++
// OK: this is a declaration 
extern const vector<int>* (*seq_array[seq_cnt])(int); 
```

A const object, like an inline function, is treated as an exception to the rule. <u>**The definition of a const object is not visible outside the file it is defined in**</u>. This means that we can define it in multiple program files without error.  That's to say, a const object has internal linkage.

------

## 2.10 Storage Classes

Every programming example in this book stores data in memory. There is a hardware aspect to this—each stored value occupies physical memory. C literature uses the term <u>**object for such a chunk of memory**</u>. An object can hold one or more values. An object might not yet actually have a stored value, but it will be of the right size to hold an appropriate value. (The phrase object-oriented programming uses the word object in a more developed sense to indicate class objects, whose definitions encompass both <u>**data and permissible operations**</u> on the data; C is not an object-oriented programming language.) 

```c++
int entity = 3;
```

This declaration creates an *identifier* called `entity`. An identifier is a name, in this case one that can be used to designate the contents of a particular object.

```c++
int * pt = &entity;
int ranks[10]; 
```

In general, as you may recall from Chapter 3 , “Data and C,” an expression that designates an object is called an <u>**lvalue**</u>. So `entity` is an identifier that is an lvalue, and *pt is an expression that is an lvalue. Along the same lines, the expression `ranks + 2 * entity` is neither an <u>**identifier (not a name)**</u> nor an <u>**lvalue**</u> (<u>**doesn’t designate the contents of a memory location**</u>).

```c++
const char * pc = "Behold a string literal!";
```

`*pc`, which designates the data object holding the 'B' character, is an lvalue, but <u>**not a modifiable lvalue.**</u> Similarly, the string literal itself, because it designates (指定) the object holding the character string, is an lvalue, but not a modifiable one. 

You can describe an object in terms of its <u>**storage duration**</u>, which is how long it stays in memory. You can describe an identifier used to access the object by its <u>**scope**</u> and its <u>**linkage**</u> , which together indicate which parts of a program can use it.

***

### 2.10.1 Scope

A *block*, as you’ll recall, is a region of code contained within an opening brace and the matching closing brace. For instance, the entire body of a function is a block. <u>**Any compound statement within a function also is a block**</u>.

A variable defined inside a block has block scope, and it is visible from the point it is defined until the end of the block containing the definition. Also, <u>**formal function parameters**</u>, even though they occur before the opening brace of a function, have block scope and belong to the block containing the function body.

Variables declared in an inner block have scope restricted just to that block: 

```c++
double blocky(double cleo) 
{
 	double patrick = 0.0;
 	int i;
 	for (i = 0; i < 10; i++)
	{
 		double q = cleo * i; // start of scope for q
 		// ...
 		patrick *= q;
 	} // end of scope for q
    return patrick;
 } 
```

*Function scope* applies just to <u>**labels**</u> used with `goto` statements. This means that even if a label first appears inside an inner block in a function, <u>**its scope extends to the whole function**</u>. It would be confusing if you could use the same label inside two separate blocks, and function scope for labels prevents this from happening. 

<u>**A variable with its definition placed outside of any function has file scope**</u>. <u>**A variable with file scope is visible from the point it is defined to the end of the file containing the definition.**</u>

```c++
#include <stdio.h>
int units = 0; /* a variable with file scope */
```

**Note**

What you view as several files may <u>**appear to the compiler as a single file**</u>. For example, suppose that, as often is the case, you include one or more header files ( .h extension) in a source code file ( `.c` sextension). A header file, in turn, may include other header files. So several separate physical files may be involved. However, C preprocessing essentially replaces an `#include` directive with the contents of the header file. Thus the compiler sees a single file containing information from your source code file and all the header files. This single file is called a <u>**translation unit**</u>. When we describe a variable as having file scope, it’s actually visible to the whole translation unit. If your program consists of several source code files, then it will consist of several translation units, with <u>**each translation unit corresponding to a source code file and its included files.**</u> 

***

### 2.10.2 Linkage

- A variable with <u>**file scope**</u> can have either internal or external linkage. 
- A variable with <u>**external linkage**</u> can be used anywhere in a multifile program. 
- A variable with <u>**internal linkage**</u> can be used anywhere in a single translation unit. 

**Note**   **Formal and Informal Terms**

The C Standard uses “file scope with internal linkage” to describe scope limited to one translation unit (a source code file plus its included header files) and “file scope with external linkage” to describe scope that, at least potentially, extends to other translation units. But programmers don’t always have the time or patience to use those terms. Some common short cuts are to use “<u>**file scope**</u>” for “file scope with internal linkage” and “<u>**global scope**</u>” or “<u>**program scope**</u>” for “file scope with external linkage.” 

So how can you tell whether a file scope variable has internal or external linkage? You look to see if the storage class specifier `static` is used in the external definition: 

```c++
int giants = 5; // file scope, external linkage, static storage duration
static int dodgers = 3; // file scope, internal linkage, static storage duration
int main() {
	// ...
}
```

You cannot define `giants` twice in another file unless you add `static` before your next declaration.

The variable giants can be used by other files that are part of the same program. The dodgers variable is private to this particular file, but can be used by any function in the file. 

***

### 2.10.3 Storage Duration

- If an object has <u>**static storage duration**</u>, it exists throughout program execution.

  Note that for file scope variables, the keyword `static` indicates the linkage type, not the storage duration. A file scope variable declared using `static` has internal linkage, but <u>**all file scope variables, using internal linkage or external linkage, have static storage duration.**</u> 

- Variables with block scope normally have <u>**automatic storage duration**</u>.

  It is possible, however, for a variable to have block scope but static storage duration.

  ```c++
  void more(int number) {
   int index;
   static int ct = 0;  // static storage duration, block scope
   ...
   return 0;
   }
  ```

But its scope is confined to the `more()` function block. Only while this function executes can the program use `ct` to access the object it designates. *(However, one can allow indirect access by enabling the function to provide the address of the storage to other functions, for example, by a pointer parameter or return value.*) 

  <img src="${md_image}/image-20230117161126184.png"  />

***

### 2.10.4 Static Variables with External Linkage

A static variable with external linkage has file scope, external linkage, and static storage duration. This class is sometimes termed the <u>**external storage class**</u>, and variables of this type are called <u>**external variables**</u>. You create an external variable by *placing a defining declaration* outside of any function. As a matter of documentation, an external variable can additionally be declared inside a function that uses it by using the extern keyword(Just for documentaton). If a particular external variable is defined in one source code file and is used in a second source code file, <u>**declaring the variable in the second file with `extern` is mandatory**</u>. Declarations look like this:

```c++
int Errupt;         /* externally defined variable */
double Up[100];     /* externally defined array */
extern char Coal;   /* mandatory declaration if */
                    /* Coal defined in another file */
void next(void);
int main(void) 
{
	extern int Errupt; /* optional declaration */
	extern double Up[]; /* optional declaration, no need to specify size, already                                done before*/
}
```

Note that <u>**you don’t have to give the array size in the optional declaration of `double Up`**</u> . That’s because the original declaration already supplied that information. The group of `extern` declarations inside `main()` can be omitted entirely because <u>**external variables have file scope**</u>, so they are known from the point of declaration to the end of the file. They do serve, however, to document your intention that `main()` use these variables. 

```c++
// replacing 
extern int Errupt; 
// with 
int Errupt; 
```

in `main()` causes the compiler to create an automatic variable named `Errupt`. <u>**It would be a separate, local variable, distinct from the original**</u> `Errupt`. The local variable would be in scope while the program executes `main()`, but the external Errupt would be in scope for other functions, such as `next()`, in the same file. Inshort, a variable in block scope “hides” a variable of the same name in file scope while the program executes statements in the block. If, for some improbable reason, you actually need to use a local variable with the same name as a global variable, **you might opt to use the `auto` storage-specifier in the local declaration to document your choice**. 

In <u>**Example 3**</u>, four separate variables are created. The Hocus variable in `main()` is automatic by default and is local to main. The `Hocus` variable in magic() is automatic explicitly and is known only to `magic()`. The external Hocus variable is not known to `main()` or `magic()` but would be known to any other function in the file that did not have its own local `Hocus` . Finally, `Pocus` is an external variable known to `magic()` but not to `main()` because `Pocus` follows `main()` . 

```c++
/* Example 3 */
int Hocus;  // external linkage
int magic();  // external linkage
int main(void) 
{
	int Hocus; // Hocus declared, is auto by default
 // or `auto int Hocus`
}

int Pocus;  // external to the rest file
int magic()
{
	auto int Hocus; // local Hocus declared automatic
    // ...
} 
```

***

### 2.10.5 Initializing External Variables 

Like automatic variables, external variables can be initialized explicitly. Unlike automatic variables, <u>**external variables are initialized automatically to zero if you don’t initialize them**</u>. This rule applies to elements of an externally defined array, too. Unlike the case for automatic variables, <u>**you can use only constant expressions to initialize file scope variables**</u>: 

```c++
int x = 10; // ok, 10 is constant
int y = 3 + 20; // ok, a constant expression
size_t z = sizeof(int); // ok, a constant expression

/* ATTENTION */
int x2 = 2 * x; // not ok, x is a variable 
```

Suppose you do this.

```c++
extern int tern;
int main(void)
{ /**/ }
```

The compiler will assume that the actual definition of tern is somewhere else in your program, perhaps in another file. This declaration does not cause space to be allocated. Therefore, <u>**don’t use the keyword extern to create an external definition; use it only to refer to an existing external definition.**</u> 

<u>**An external variable can be initialized only once, and that must occur when the variable is defined**</u>. Suppose you have this: 

```c++
// file one.c
 char permis = 'N';
 ...
 // file two.c
 extern char permis = 'Y'; /* error */ 
```

***

### 2.10.6 Multiple Files

Complex C programs often use several separate files of source code. Sometimes these files might need to share an external variable. The C way to do this is to <u>**have a defining declaration in one file and referencing declarations in the other files**</u>. That is, <u>**all but one declaration (the defining declaration) should use the extern keyword**</u>, and <u>**only the defining declaration should be used to initialize the variable.**</u> 

***

# 3 Generic Programming

<u>**Standard Template Library (STL)**</u>

- a set of container classes, including the `vector`, `list`, `set`, and `map` classes
- a set of generic algorithms to operate over these containers, including `find()`, `sort()`, `replace()`, and `merge()`. 

The vector and list container classes represent sequential containers. A <u>**sequential container**</u> maintains a first element, a second element, and so on through a last element. We primarily iterate over a sequential container. The map and set classes represent <u>**associative containers**</u>. An associative container supports fast lookup of a value.

A <u>**map**</u> is a key/value pair: The key is used for lookup, and the value represents the data we store and retrieve. A telephone directory, for example, is easily represented by a map. The <u>**key**</u> is the individual's name. The value is the associated phone number. 

A <u>**set**</u> contains only key values. We query it as to whether a value is present. For example, if we were to build an index of words that occur in news stories, we would want to exclude neutral words such as the, an, but, and so on. Before a word is entered into the index, we query an `excluded_word` set. If the word is present, we discard it; otherwise, we include the word in our index. 

The <u>**generic algorithms**</u> provide a large number of operations that can be applied both to the container classes and to the built-in array. The algorithms are called generic because they are <u>**independent of both the type of element**</u> they are operating on (for example, whether it is an int, double, or string) and <u>**the type of container**</u> within which the elements are held (whether it is a vector, list, or built-in array). 

The generic algorithms achieve type independence by being implemented as <u>**function templates**</u>. <u>**They achieve container independence by not operating directly on the container**</u>. Rather, they are passed an iterator pair (`first`,`last`), marking the range of elements over which to iterate. While first is unequal to last, the algorithm operates on the element addressed by `first`, increments `first` to address the next element, and then recompares `first` and `last` for equality. A good first question is, what is an <u>**iterator**</u>? The next two sections try to answer that. 

***

## 3.1 The Arithmetic of Pointers 

If the value is contained within the vector, we must return a pointer to it; otherwise, we return 0, indicating that the value is not present.

```c++
int* find(const vector<int> &vec, int value) 
{ 
 	for (int ix = 0; ix < vec.size(); ++ix) 
 		if (vec[ix] == value) 
 			return &vec[ix];  // return the address of the present int
	return 0; 
} 
```

We are next assigned the task of having the function work not only with integers but also with <u>**any type in which the equality operator is defined**</u>. If you have read *Section 2.7*, you should recognize this task as requiring us to transform `find()` into a <u>**function template**</u>: 

```c++
template <typename elemType>
elemType* find(const vector<elemType>& vec, 
               const elemType& value)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];
	return 0;
}
```

Our next assignment is to have `find()` work both for a vector and an array of elements of any type for which an equality operator is defined. Our first thought is to overload the function, providing an instance that takes a vector and an instance that takes an array. 

***

### 3.1.1 **Array Invokation**

<u>**We are advised against overloading in this case.**</u> With a little thought, we're told, we can implement `find()` so that <u>**a single instance can handle**</u> the elements of either a vector or a built￾in array. Gosh, but that seems hard. 

```c++
int min(int array[24]) { ... } 
// is passed by pointer
int min(int* array) { ... } 
```

Somehow, we must indicate to `min()` when the reading of the array should stop.

```c++
template <typename elemType>
elemType* find(const elemType* array, int size,  // pass the size
	const elemType& value);
```

Or, we pass a <u>***sentinel*（哨兵，守卫**</u>）,indicates that we have completed reading the elements of the array. 

```c++
template <typename elemType>
elemType* find(const elemType* first, const elemType* sentinel,
	const elemType& value);
```

One interesting aspect of this solution is that we have <u>**eliminated the declaration of the array from the parameter list**</u> — solving the first of our smaller problems. <u>**Even though we are accessing the array through a pointer, we can still apply the subscript operator**</u> exactly as we did before: 

<u>**Pointer arithmetic adds increments of the size of the type being addressed.**</u> Let's say that array contains integer elements. array+2, then, adds the size of two integer elements to the address of array. Under pointer arithmetic, on a machine in which an integer is 4 bytes, the answer is 1008. When we have the address of the element, we must then dereference the address to get the value of the elements. When we write array[2], <u>**the pointer arithmetic and address dereferencing are done automatically**</u>. 

```c++
template <typename elemType>
elemType* find(const elemType* first,
	const elemType* last, const elemType& value)
{
	if (!first || !last)  // if first == 0 or last == 0
		return 0;
	// while first does not equal last, 
	// compare value with element addressed by first 
	// if the two are equal, return first 
	// otherwise, increment first to address next element 
    for (; first != last; first++)   // last is one past the end
        if (*first == value)
            return first;
    
    return 0;
}
```

<u>**The second address marks 1 past the last element of the array**</u>. Is that legal? Yes. If we should ever try to read or write to that address, however, all bets are off. But if all we do with that address is to compare it against other element addresses, we're fine. The address 1 past the last element of the array serves as a <u>**sentinel**</u> indicating that we have completed our iteration. 

How might `find()` be invoked? The following code uses the pointer arithmetic we illustrated earlier: 

```c++
int ia[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
double da[6] = { 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };
string sa[4] = { "pooh", "piglet", "eeyore", "tigger" };

int* pi = find(ia, ia + 8, ia[3]);
double* pd = find(da, da + 6, da[3]);
string* ps = find(sa, sa + 4, sa[3]);
```

***

### 3.1.2 **Vector Invokation**

How might we implement the second programming subtask, that of accessing each element of a vector independent of the vector object the elements are contained within? <u>**A vector also holds its elements in a contiguous area of memory**</u>, so we can pass `find()` a begin/end pair of addresses in the same way as we do for the built-in array, except in one case. Unlike an array, <u>**a vector can be empty**</u>. For example, 

```c++
vector<string> svec;  // vector is empty
```

A safer implementation is first to confirm that svec is not empty. 

```c++
if (! svec.empty()) // true if the container size is 0, false otherwise.
                    // ... ok, call find() 
```

Although this is safer, it is somewhat cumbersome for the user. A more uniform way of accessing the address of the first element is to wrap the operation into a function, something like the <u>**inline funtion**</u>: 

```c++
// vec.begin()
template <typename elemType>
inline elemType* begin(const vector<elemType>& vec)
{ return vec.empty() ? 0 : &vec[0];}
```

A second function,` end()`, <u>**returns either 0 or a pointer to 1 past the last element of the vector**</u>. In 
this way, we can safely and uniformly invoke `find()` for any vector: 

```c++
find(begin(svec), end(svec), search_value);
// if svec is empty, begin == end == 0
```

***

### 3.1.3 **List Class Invokation**

A *list* class is also a container. The difference is that the elements of a list are linked through a pair of pointers: <u>**a forward pointer addressing the next element and a backward pointer addressing the preceding element.**</u> 

Pointer arithmetic doesn't work with a list. <u>**Pointer arithmetic presumes that the elements are contiguous**</u>. By adding the size of one element to the current pointer, we reset the pointer to address the next element. This is the underlying assumption of our implementation of `find()`. Unfortunately, that assumption doesn't hold when we access the next element of a list. 

The solution is to provide <u>**a layer of abstraction over the behavior of the underlying pointers**</u>. Rather than program the underlying pointers directly, we program the layer of abstraction. We place the unique handling of the underlying pointers within that layer, shielding it from our users. This technique allows us to handle any of the standard library container classes with a single instance of `find()`. 

***

## 3.2 Making Sense of Iterators

We need a collection of objects that support the same set of operators as the built-in pointer (++, , !=) but allow us to <u>**provide a unique implementation of those operators**</u>. We can do exactly this with the *C++ class mechanism*. We'll design a set of iterator classes that are programmed using the same syntax as that of a pointer. For example, if `first` and `last` are `list` class iterators, we can write 

```c++
// first and last are iterator class objects 
while (first != last)
{
	cout << *first << ' ';
	++first;
}
```

- For the list class iterator, for example, the associated increment function advances to the next element <u>**by following the list pointer**</u>. 
- For the vector class iterator, the increment function advances to the next element by adding the size of one element to the current address. 

Where do we get iterators? <u>**Each container class**</u> provides a `begin()` operation that returns an iterator that addresses the first element of the container and an` end()` operation that returns an iterator that addresses 1 past the last element of the container. For example, disregarding how we define an iterator object for the moment, we <u>**assign**</u>, <u>**compare**</u>, <u>**increment**</u>, and <u>**dereference**</u> an iterator as follows: 

```c++
for (iter = svec.begin();
	iter != svec.end(); ++iter)
		cout << *iter << ' ';
```

Before we look at <u>**how to define an iterator**</u>, let's think for a moment about <u>**the information its definition must provide**</u>: 

- *The type of the container* over which it iterates, which determines how it accesses the next element;
- *The type of the element* being addressed, which determines the value returned from a dereference of the iterator. 

```c++
vector<string> svec;
// the standard library iterator syntax 
// iter addresses vector elements of type string 
// it is initialized to the first element of svec 
vector<string>::iterator iter = svec.begin();

for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
```

`iter` is defined to be an iterator for vectors of string elements. It is <u>**initialized to address the first element of `svec`**</u>. (The double colon <u>**[: :]**</u> indicates that iterator is a type <u>**nested within the string vector definition**</u>. This will make more sense when you read *Chapter 4* and we implement our own iterator class. For now, we'll just use the iterator.) For a `const` vector, such as 

```c++
const vector<string> cs_vec; 
```

we traverse the elements using a `const_iterator`

```c++
vector<string>::const_iterator = cs_vec.begin(); 
```

A` const_iterator` allows us to <u>**read the vector elements but not write to them**</u>. 

To access the element through the iterator, we <u>**dereference**</u> it just as we do a built-in pointer: 

```c++
cout << "String value of element: " << *iter;
```

Similarly, to invoke an operation of the underlying string element through iter, we use the <u>**member selection arrow syntax**</u>: 

```c++
cout << "(" << iter->size() << "): " << *iter << endl;
```

Here is a reimplementation of `display()` as a function template using iterators rather than the subscript operator: 	

```c++
template <elemType>
void display(const vector<elemType> &vec, ostream &os)
{  // only support display vector elements
    // initialzie iterator
    vector<elemType>::const_iterator iter = vec.begin();
    // begin() return type iterator
    vector<elemType>::const_iterator end_it = vec.end();
    
    for (; iter != end_it; iter++)
        os << *iter << endl;
    os << endl;
}
```

Our reimplementation of `find()` supports either a pair of built-in pointers, or a pair of iterators to a container of a particular type:

```c++
template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, IteratorType last,
                  const elemType &value)  // make elemType const
{
    for (; first != last; first++)
        if (value == *first)
            return first;
    return last;  //  return last, notice how to check found or not
}
```

Let's see how we might use this reimplementation of `find()` with a <u>**built-in array, a vector, and a list**</u>: 

```c++
const int asize = 8;
int ia[asize] = { 1, 1, 2, 3, 5, 8, 13, 21 };
// initialzie the list and vector with 8 elements of ia
// first is the pointer to ia[0], last is one element past the last element
vector<int> ivec(ia, ia + asize);
list<int> ilist(ia, ia + asize);

int *pia = find(ia, ia + asize, 1024);
if (pis != ia + asize)  // if not found, return last
{/*found*/}

vector<int>::iterator iter;  // ATTENTION: how to initialize iterator
iter = find(ivec.begin(), ivec.end(), 1024);
if (iter != ivec.end())
{/*found*/}

list<int>:: iterator iter;
iter = find(ilist.begin(), ilist.end(), 1024);
if (iter != ilist.end())
{/*found*/}
```

wait to see <u>**function object**</u>

***

## 3.3 Operations Common to All Containers

The following operations are common to all the container classes (as well as the string class): 

- The equality (`==`) and inequality (`!=`) operators return true or false. 
- The assignment (`=`) operator copies one container into another.
- `empty()` returns true if the container holds no elements. 
- `size()` returns a count of the elements currently held within the container. 
- `clear()` deletes all the elements. 

The following function exercises each of these operations: 

```c++
void comp(vector<int> &v1, vector<int> &v2)
{
    // are the two vectors equal?
    if (v1 == v2)
        return;
   // is either vector empty?
    if (v1.empty() || v2.empty())
        return;
    
    // no point defining it unless we are going to use it
    vector<int> t;
    // assign t the largest vector
    t = v1.size() > v2.size() ? v1 : v2;  // assign the vector directly
    // use t...
    
    // ok. empty t of its elements 
	// t.empty() will now return true 
	// t.size() will now return 0 
	t.clear(); 
    // ... ok, fill up t and use it some more ...    
}
```

Each container supports a `begin()` and an `end()` operation to return, respectively, an iterator to the first element of the container, and 1 past the last valid element: 

- `begin()` returns an iterator to the first element. 
- `end()` returns an iterator that addresses 1 past the last element. 

All containers support an `insert()` operation to add elements and an `erase()` operation to delete elements. 

- `insert() `adds one or a range of elements to a container.

  ```c++
  std::vector<int> myvector(3, 100);
  std::vector<int>::iterator it;
  
  it = myvector.begin();
  it = myvector.insert(it, 200);
  
  myvector.insert(it, 2, 300);
  
  // "it" no longer valid, get a new one:
  it = myvector.begin();
  
  std::vector<int> anothervector(2, 400);
  myvector.insert(it + 2, anothervector.begin(), anothervector.end());
  ```

- `erase()` deletes one or a range of elements from a container.

***

## 3.4 Using the Sequential Containers 

- Pros and cons of sequential container

  <u>**Random access**</u> is efficient;

  <u>**Insertion of an element at any position**</u> is inefficient.

- Pros and cons of noncontiguous memory double-linked

  <u>**Random access**</u> is efficient;

  <u>**Insertion of an element at any position**</u> is inefficient.

When is a list more appropriate? If we were reading test scores from a file and wished to store each score in ascending order, we are likely to be <u>**randomly inserting into the container with each score we read**</u>. In this case, the list container is preferred. 

A third sequential container is a <u>**deque**</u> (pronouced deck). A deque behaves pretty much like a vector — the elements are stored contiguously. Unlike a vector, however, <u>**a deque supports efficient insertion and deletion of its front element**</u> (as well as its back element). If, for example, we need to insert elements at the front of the container and delete them from the back, a deque is the most appropriate container type. (The standard library queue class is implemented using a deque to hold the queue's elements.) 

To sum up:

- vector
- list
- deque

```c++
// include header file
#include <vector> 
#include <list> 
#include <deque> 
```

There are <u>**five ways**</u> to define a sequential container object: 

```c++
// creat an empty container
list<string> slist;
vector<int> ivec;

/*Create a container of some size. Each element is initialized to its default value.    (Recall that the default value for the built-in arithmetic types such as int and double is zero.) */
list<int> ilist(1024);
vector<string> svec(32);

/*Create a container of a given size and specify an initial value for each element:*/
vector<int> ivec(10, -1);
list<string> slist(32, "unassigned");

/*Create a container, providing an iterator pair marking a range of elements with which to initialize the container: */
int ia[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
vector<int> fib(ia, ia + 8);  // iterator pairs

/*Create a container, providing a second container object. The new container is initialized by copying the second: */
list<string> slist;
// fill slist...
list<string> slist2(slist);  // copy of slist
```

`push_back()` inserts an element at the back. `pop_back()` deletes the element.

In addition, the <u>**list and deque containers**</u> (but not the vector) support` push_front()`and `pop_front()`. The `pop_back()` and `pop_front()` operations do not return the deleted value. To read the front value, we use `front()`, and to read the back value, we use `back()`.

```c++
#include <deque>
deque<int> a_line;  // now empty
int ival;
while (cin >> ival)
{
    // insert ival at the back of a line
    a_line.push_back(ival);
    
    // ok; read the value at the front of a line
    int curr_value = a_line.front();
    
    // do something...
    
    // delete the value at the front of a line
    a_line.pop_front();
}
```

## 3.9 Using Iterator Inserters

```c++
#include <algorithm>
// In the last section, we assign each element of the source container that matches the predicate 
// test into the target container
while ((first = find_if(first, last, bind2(pred, val))) != last)
    *at++ = *first++;

// This require the target container to be big enough to hold the value
// It is up to the programmer to decide whether target is big enough
// You can define them to be the same size
int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
vector<int> ivec(ia, ia + elem_size);
int ia2[elem_size]; 
vector<int> ivec2(elem_size); 

// But the target container may be too large
// filter() is currently implemented to assign into a fixed container slot
// If we reinplement it, what happens to the program that use the assignment implementation 
// filter() to do insertion
```

### **`unique_copy()`** **version 1**

```c++
template< class InputIt, class OutputIt >
OutputIt unique_copy( InputIt first, InputIt last, OutputIt d_first );
// In this, only the first element from every consecutive group of equivalent elements in the range // [first, last) is copied.
// Return Value: An iterator pointing to the end of the copied range, which contains no consecutive // duplicates.
vector<int> v = { 10, 10, 30, 30, 30, 100, 10,
                      300, 300, 70, 70, 80 };
 
    // Declaring a vector to store the copied value
    vector<int> v1(10);
 
    vector<int>::iterator ip;
 
    // Using std::unique_copy
    ip = std::unique_copy(v.begin(), v.begin() + 12, v1.begin());
    // Now v1 contains {10 30 100 10 30 70 80 0 0 0}
 
    // Resizing vector v1
    v1.resize(std::distance(v1.begin(), ip));
 
    cout << "Before: ";
    for (ip = v.begin(); ip != v.end(); ++ip)
    {
        cout << *ip << " ";
    }

 // Displaying the vector after applying std::unique_copy
    cout << "\nAfter: ";
    for (ip = v1.begin(); ip != v1.end(); ++ip)
    {
        cout << *ip << " ";
    }
 
```

### **`unique_copy()`** **version 2**  

back_inserter used

```c++
// By comparing using a pre-defined function: Syntax:
template 
  OutputIterator unique_copy (InputIterator first, InputIterator last,
                              OutputIterator result, BinaryPredicate pred);

/*Here, first, last and result are the same as previous case.

Pred: Binary function that accepts two elements 
in the range as argument, and returns a value convertible to bool. 
The value returned indicates whether both arguments are considered equivalent
(if true, they are equivalent and one of them is removed).
The function shall not modify any of its arguments.
This can either be a function pointer or a function object.

Return Value: It returns an iterator pointing to the 
end of the copied range, which contains no consecutive duplicates.*/

// C++ program to demonstrate the
// use of std::unique_copy
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
// Defining the BinaryFunction
bool Pred(char a, char b)
{
    // Checking if both the arguments are same and equal
    // to 'v' then only they are considered same
    // and duplicates are removed
    if (a == b && a == 'v')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    // Declaring a string
    string s = "You arre vvvisiting GFG", s1;
 
    // Using std::unique_copy to remove the consecutive
    // v in the word and copy it to s1
    auto ip = std::unique_copy(s.begin(), s.end(), back_inserter(s1), Pred);
 
    cout << "Before: " << s;
 
    // Displaying the corrected string
    cout << "\nAfter: " << s1;
    return 0;
}
```

### **`back_inserter()`** 

That's hardly in the spirit of the STL. Rather, the standard library provides three insertion adapters. These adapters allow us to **override a container's assignment operator**. 

`unique_copy()` is explaned above

```c++
// A back-insert iterator is a special type of output iterator designed to allow algorithms that 
// usually overwrite elements (such as copy) to instead insert new elements automatically // at the end of the container.
// back_inserter() causes the container's push_back() operator to be invoked in 
// place of the assignment operator. This is the preferred inserter for vectors. The 
// argument to back_inserter is the container: 

// Syntax:
std::back_inserter (Container& x);

/*
x: Container in which new elements will 
be inserted at the end.

Returns: A back_insert_iterator that inserts 
elements at the end of container x.
*/

vector<int> result_vec; 
unique_copy(ivec.begin(), ivec.end(), back_inserter(result_vec)); 
// if pass result_vec.begin(), then every time unique_copy()
// is invoked, result_vec is overwritten

```

### `insert()`

1. Syntax

```c++
vector_name.insert (position, val)
```

- *position –* It specifies the iterator which points to the position where the insertion is to be done.
- *val –* It specifies the value to be inserted.

```c++
// A program to illustrate the function of
// vector_name.insert(position,val)
#include <bits/stdc++.h>
using namespace std;
  
int main()
{
  
    // Initialising the vector
    vector<int> vector_name{ 1, 2, 3, 4, 5 };
  
    // Printing out the original vector
    cout << "Original vector :\n";
    for (auto x : vector_name)
        cout << x << " ";
    cout << "\n";
  
    // Inserting the value 100 at position 3(0-based
    // indexing) in the vector
    vector_name.insert(vector_name.begin() + 3, 100);
  
    // Printing the modified vector
    cout << "Vector after inserting 100 at position 3 :\n";
    for (auto x : vector_name)
        cout << x << " ";
    cout << "\n";
  
    // Inserting the value 500 at position 1(0-based
    // indexing) in the vector
    vector_name.insert(vector_name.begin() + 1, 500);
  
    // Printing the modified vector
    cout << "Vector after inserting 500 at position 1 :\n";
    for (auto x : vector_name)
        cout << x << " ";
    return 0;
}
  
// This code is contributed by Abhijeet Kumar(abhijeet19403)
```

2. Syntax

   ```c++
   vector_name.insert(position, size, val)
   ```

3. Syntax

   ```c++
   vector_name.insert(position, iterator1, iterator2)
   ```

### `inserter()`

see inserter_driver.cpp

```c++
std::inserter(Container& x, typename Container::iterator it);
x: Container in which new elements will 
be inserted.
it: Iterator pointing to the insertion point.

Returns: An insert_iterator that inserts elements into 
x at the position indicated by it.
```

### `front_inserter()`

```c++
// front_inserter() causes the container's push_front() operator to be invoked. This 
// inserter can be used only with the list and deque containers: 
std::front_inserter (Container& x);

x: Container in which new elements will 
be inserted at the beginning.

Returns: A front_insert_iterator that inserts 
elements at the beginning of container x.
```

