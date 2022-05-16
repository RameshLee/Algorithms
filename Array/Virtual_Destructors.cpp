// Link: https://leetcode.com/playground/KwqPpGPjn

class A {
    public: A() { printf("A class constructor!\n"); }
    public: ~A() { printf("A class destructor!\n"); }
    public: virtual void func() = 0;// { printf("A class function\n"); }
};

class B : public A {
    public: B() { printf("B class constructor!\n"); }
    public: ~B() { printf("B class destructor!\n"); }
    public: void func() override { printf("B class function\n"); }
};

class PvtClass {
    private: PvtClass() { printf("PvtClass constructor!\n"); }
    private: ~PvtClass() { printf("PvtClass destructor!\n"); }
    public: friend void friendFunc();
};

void friendFunc() {
    PvtClass *obj = new PvtClass;
    delete obj;
}

int main() {
   // 1) virtual destructor
    /* A *obj = new B;
     obj->func();
     delete obj;
   */

    // 2) private destructor
    friendFunc();
    // PvtClass p; => gives error, because constructor/destructor is private.
}

// Concepts:
// 1.1) virtual destructor: helps to avoid memory leaks when a Base points to Derived class.
// 1.2) it is not necessary to override virtual function unless it's a pure virtual func. Moreover, abstract class (with pure virtual func) cannot be instantiated.
// 1.3) protected destructor: prevents deletion of derived class via base class pointer.
// 2.1) private constructor/destructor: to ensure an instance of this obj is never created. Only, friend func can access private; therefore, can be used for white-box testing.