

class A {
    int field_1;
    virtual void f() {
        // Do something
    }
}

class B : A {
    int field_2;
    virtual void f() {
        // Do something else rispect to f method of class A
    }
}


main() {
    A a = A();
    A b = B();
    a.f();
    b.f();
}