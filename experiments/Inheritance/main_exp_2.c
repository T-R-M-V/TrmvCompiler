//==================================================================================================================
//------------------------------------------------------------------------------------------------------------------
// TESTING FOR LATE BIDNING METHOD AND INHERITANCE
//------------------------------------------------------------------------------------------------------------------
//
//
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
//    Undertand if this method works for more than one derivation.
//    Check if this method is guaranted to work from C standard.
//  - watch this resource to learn more about that: 
//------------------------------------------------------------------------------------------------------------------
//==================================================================================================================

// Including .h (START) 
#include <stdio.h>
// Including .h (END)





// Class that must be inherited (START)
struct A {
    int field_1;
    char* string;
};
// Class that must be inherited (END)

// Class that must inherit from A(parent class) (START)
// We can put a field of type A at the start of the struct of type B.
// Then we can directly access to the field of struct A contained in an
// istance of type struct B casting a reference of this istance to A*.
struct B {
    struct A super;

    int field_2;
};
// Class that must inherit from A(parent class) (END)

// We can directly move all the methods that are not overridable out of the struct
// like simple function where we pass a parameter that is implicit in the source code,
// the reference to the object on witch we execute the function.
// With the tric that we described above, we can easily use the function_1 even on reference
// of type B. 
void function_1(struct A* this);

void function_1(struct A* this) {
    this->field_1 = 15;
}





int main() {
    struct B b;
    b.super.field_1 = 10;
    struct A* generic_ref = (struct A*)&b;

    printf("%d", generic_ref->field_1);

    return 0;
}