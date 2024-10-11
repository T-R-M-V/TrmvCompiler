//==================================================================================================================
//------------------------------------------------------------------------------------------------------------------
// This simple file is a test to understand what we need to create binding at runtime of method
// with the C code
//------------------------------------------------------------------------------------------------------------------
//
//
//------------------------------------------------------------------------------------------------------------------
// Points to reason about:
//  - probably is useful that a virtual method takes a void* in place of a struct Type*, with that we make a more
//    generic code. We can perform the casting to the right type in the context of the function.
//  - reason better on the language we want to create, make a better defined syntax (for now make the more simple
//    you can do, only to understand what you need)
//  - watch "type punning" techinque: https://en.wikipedia.org/wiki/Type_punning. This thread speak on stack 
//    overflow on this subject: https://stackoverflow.com/questions/1237266/how-can-inheritance-be-modelled-using-c
//------------------------------------------------------------------------------------------------------------------
//==================================================================================================================

// Including .h (START) 
#include <stdio.h>
// Including .h (END)





// Class that must be inherited (START)
struct A {
    int a;

    void (*f_ptr)(struct A*);    // This is the equivalent to a virtual function in C++ with this signature: virtual void f();
};
// Class that must be inherited (END)

// Class that must inherit from A(parent class) (START)
struct B {
    int a;  // This must be copied from the class A
    int b;

    void (*f_ptr)(struct B*);
};
// Class that must inherit from A(parent class) (END)

// Function to bind like methods for the classes (START)
void f_a(struct A* a);
void f_b(struct B* b);

void f_a(struct A* a) {
    a->a = 10;
    printf("Called implementation for A\n");
}

void f_b(struct B* b) {
    b->b = 10;
    b->a = 11;
    printf("Called implementation for B\n");
}
// Function to bind like methods for the classes (END)





int main() {
    struct A a;
    struct B b;
    
    a.f_ptr = &f_a;
    b.f_ptr = &f_b;
    
    (*a.f_ptr)(&a);
    (*b.f_ptr)(&b);

    return 0;
}