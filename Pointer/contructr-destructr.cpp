#include "../std_lib_facilities.h"

struct X { 
    int val;
    // simple test class int val; 
    void out(const string& s, int nv) { 
        cerr << this << " – >" << s << ": " << val << " (" << nv << ")\n"; 
    }

    X(){ out("X()",0); val=0; } // default constructor
    
    X(int v) { 
        val=v; 
        out( "X(int)",v); 
    } 
    
    X(const X& x){ 
        val=x.val; 
        out("X(X&) ",x.val); 
    } // copy constructor 

    X& operator=(const X& a) { 
        out("X::operator=()",a.val); 
        val=a.val; return *this; 
    } 
    
    ~X() { out("~X()",0); } // destructor 
};

X glob(2); // a global variable 

X copy(X a) { return a; } 

X copy2(X a) { X aa = a; return aa; } 

X& ref_to(X& a) { return a; } 

X* make(int i) { X a(i); return new X(a); } 

struct XX { X a; X b; }; 

int main() { 
    cout << "\n";
    cout << "X loc {4};\n";
    X loc {4}; // local variable 
    cout << "\n";

    cout << "X loc2 {loc};\n";
    X loc2 {loc}; // copy construction 
    cout << "\n";
    
    cout << "loc = X{5};\n";
    loc = X{5}; // copy assignment 
    cout << "\n";

    cout << "loc2 = copy(loc);\n";
    loc2 = copy(loc); // call by value and return 
    cout << "\n";

    cout << "loc2 = copy2(loc);\n";
    loc2 = copy2(loc); 
    cout << "\n";

    cout << "X loc3 {6};\n";
    X loc3 {6}; 
    cout << "\n";

    cout << "X& r = ref_to(loc);\n";
    X& r = ref_to(loc); // call by reference and return 
    cout << "\n";

    cout << "delete make(7);\n";
    delete make(7); 
    cout << "\n";

    cout << "delete make(8);\n";
    delete make(8); 
    cout << "\n";

    cout << "vector<X> v(4);\n";
    vector<X> v(4); // default values 
    cout << "\n";

    cout << "XX loc4;\n";
    XX loc4; 
    cout << "\n";

    cout << "X* p = new X{9};\n";
    X* p = new X{9}; // an X on the free store 
    cout << "\n";

    cout << "delete p;\n";
    delete p; 
    cout << "\n";

    cout << "X* pp = new X[5];\n";
    X* pp = new X[5]; // an array of Xs on the free store 
    cout << "\n";

    cout << "delete [] pp;\n";
    delete [] pp; 
    cout << "\n";
    cout << "Global clean up:\n";
}