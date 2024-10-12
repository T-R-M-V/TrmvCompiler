//==================================================================================================================
//------------------------------------------------------------------------------------------------------------------
// TESTING FOR INTERFACES(AKA: virtual classes)
//------------------------------------------------------------------------------------------------------------------
//
//
//------------------------------------------------------------------------------------------------------------------
// This simple file show the source code interfaces in for classes.
// It shows how you can inherit from multiple 
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





// Create interfaces for the classes (START)
interface I {
    void function_1();
    void function_4();
}

interface I2 {
    void function_2();
}
// Create interfaces for the classes (END)

// Create base class to inherits (START)
class A {
    int field_1;

    void function_3() {
        this.field_1 = 32;
    }
}
// Create base class to inherits (END)

// Create class that inherits from base class (START)
class B : A, I, I2 {
    void function_1() {
        this.field_1 = 64;
    }

    void function_2() {
        this.field_1 = 32;
    }

    void function_4() {
    }
}
// Create class that inherits from base class (END)





main() {
    B b = build B;
    I i = b;
    I2 i2 = b;

    i.function_1();
    i.function_4();

    i2.function_2();
}