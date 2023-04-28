# Essential-CPP

Essential C++ by Stanley B. Lippman

# Chapter 5

## virtual destructor

When a class has virtual functions, it is intended to be used as a base class, which means that it will be inherited by other classes. In this case, if the base class does not define a virtual destructor, it can lead to memory leaks and undefined behavior.

When a derived class is deleted, its destructor is called automatically. However, if the base class destructor is not virtual, the derived class destructor may not properly release all the resources allocated by the base class. This is because, when the derived class is destroyed, only the derived class destructor is called, not the base class destructor.

For example, consider the following code:

```c++
class Base {
public:
    virtual void foo() {}
    // no virtual destructor
};

class Derived : public Base {
public:
    ~Derived() {
        // derived class destructor
    }
};

int main() {
    Base* b = new Derived();
    delete b;
    return 0;
}
```

In this code, the base class `Base` defines a virtual function `foo()`, but does not define a virtual destructor. The derived class `Derived` has a destructor, but it does not call the base class destructor explicitly.

When the `delete` statement is executed, the `Derived` destructor is called, but the `Base` destructor is not called. As a result, any resources allocated by the `Base` constructor are not properly released, which can lead to memory leaks and undefined behavior.

**To avoid this issue, it is a good practice to always define a virtual destructor in a base class that has virtual functions.** This ensures that the destructor of the most derived class in the inheritance hierarchy is called, which in turn ensures that all resources allocated by the base class are properly released.

Therefore, a base class that defines one or more virtual functions should always define a virtual destructor to avoid memory leaks and undefined behavior.

