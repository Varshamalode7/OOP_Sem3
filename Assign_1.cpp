/*
    ----
Create class of complex numbers and overload +, *, << and >> operators
to perform operations on complex numbers
    ----
*/

#include <iostream>
using namespace std;

class complex
{
private:
    float real, imag;

public:
    // default constructor
    complex()
    {
        real = 0;
        imag = 0;
    }

    // overload + operator
    complex operator+(complex  &c2)
    {
        c2.real = c2.real + real;
        c2.imag = c2.imag + imag;
        return c2;
    }

    // overload * operator
    complex operator*(complex &c2)
    {
        // (a+ib) * (c+id) = (ac - bd) + (ad + cb)i
        // complex ans;
        c2.real = (real * c2.real) - (imag * c2.imag);
        c2.imag = (real * c2.imag)+(imag * c2.real) ;
        return c2;
    }

    // overload << operator
    friend ostream &operator<<(ostream &out, const complex &c2);

    // overload >> operator
    friend istream &operator>>(istream &in, complex &c2);
};

// overload << operator
ostream &operator<<(ostream &out, const complex &c2)
{
    out<< "("<<c2.real << "+" << c2.imag << "i"<<")";
    return out;
}

// overload >> operator
istream &operator>>(istream &in, complex &c2)
{
    in >> c2.real ;
    in >> c2.imag;
    return in;
}

int main()
{
    int choice;
    complex z1, z2;

    cout << "Welcome to Complex Calculator!";
    while (true)
    {
        cout << "\n1 - Addition"
             << "\n2 - Multiplication"
             << "\n\nEnter your choice :";
        cin >> choice;

        switch (choice)
        {
        case 1: // addition

            cout << "\nEnter real and imaginary part of complex number z1 :\n";
            cin >> z1;
            cout << "\nEnter real and imaginary part of complex number z2 :\n";
            cin >> z2;
            cout<<"("<<z1<<"+"<<z2<<")"<<endl;
            cout << "Addition of complex numbers = ";
            cout << z1 + z2;
            break;

        case 2: // multiplication

            cout << "\nEnter real and imaginary part of complex number z1 :\n";
            cin >> z1;
            cout << "\nEnter real and imaginary part of complex number z2 :\n";
            cin >> z2;
            cout<<"("<<z1<<"*"<<z2<<")"<<endl;
            cout << "Product of complex numbers = ";
            cout << z1 * z2;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
            break;
        }
    }
    return 0;
}

// #include <iostream> //it is implemented by object of classes
// using namespace std;

// class Complex
// { // creation of class

//     double real, img;

// public:         // access specifer
//     Complex() {// default constructor
//                 real=0;
//                 img=0;
    
//     }
//     void setdata()
//     { // real and img values : input from user
//         cin >> real >> img;
//     }

//     void get()
//     { // it is defined to display complex number
//         cout << real << "+(" << img << ")i" << endl;
//     }

//     Complex operator+(Complex c2)
//     {                 //+ operator overloading
//         Complex temp; // creation of object
//         temp.real = real + c2.real;
//         temp.img = img + c2.img;
//         return temp;
//     }

//     Complex operator*(Complex c2)
//     {                  //* operator overloading
//         Complex temp1; // creation of object
//         temp1.real = (real * c2.real) - (img * c2.img);
//         temp1.img = (img * c2.real) + (c2.img * real);
//         return temp1;
//     }
//     // friend func is used to access private and protected member in class
//     //&=pass by reference and used to assign address of variable
//     //*pointer is used to assign the value of variable
//     friend ostream &operator<<(ostream &out, Complex &c);
//     friend istream &operator>>(istream &in, Complex &c);
// };

// // Always outside the class because it is the one base class derived from iostream class
// //<<------>insertion
// ostream &operator<<(ostream &out, Complex &c)
// {
//     if (c.img < 0)
//         out << c.real << signed (c.img) << "i" << endl;
//     else
//         out << c.real << "+" << c.img << "i" << endl;
//     return out;
// }

// //>>-------extraction opoerators
// istream &operator>>(istream &in, Complex &c)
// {
//     in >> c.real;
//     in >> c.img;
//     return in;
// }

// int main()
// {
//     Complex c1, c2, c3; // creation of object
//     Complex c6;         // creation of object
//     c6.get();

//     cout << " Enter real and imaginary part of first number: " << endl;
//     c1.setdata();

//     cout << "The First complex number is :" << endl;
//     c1.get();

//     cout << "Enter real and imaginary part of second number:" << endl;
//     c2.setdata();

//     cout << "The second complex number is :" << endl;
//     c2.get();

//     cout << "Addition of two complex numbers are:" << endl;
//     c3 = c1 + c2;
//     c3.get();

//     cout << "Product of two complex numbers is:" << endl;
//     Complex c5 = c1 * (c2);
//     c5.get();

//     return 0;
// }
