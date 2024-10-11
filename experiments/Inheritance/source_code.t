//==================================================================================================================
//------------------------------------------------------------------------------------------------------------------
// TESTING FOR INHERITANCE: Source code for inheritance
//------------------------------------------------------------------------------------------------------------------
//
//
//------------------------------------------------------------------------------------------------------------------
// This simple file show the source code for inheritance between classes in the T language
//------------------------------------------------------------------------------------------------------------------
//
//
//------------------------------------------------------------------------------------------------------------------
// Points to keep in mind:
//  We want to support inheritance at multiple levels, but we don't want to support multiple inheritance.
// Things to define:
//  - Do we want to support concept like interface?
//  - Do we want a particular 'type' field that apply to all the classes and indicates the correct type?
//------------------------------------------------------------------------------------------------------------------
//==================================================================================================================


class A {
    int field_1;

    void function_1() {
        // Do something with this
    }
}

// The class B inheritance all the fields and function from Class A.
class B : A {
    int field_2;
}





main() {
    // We can create an instance of Class B
    A b = build B;

    b.function_1();
}