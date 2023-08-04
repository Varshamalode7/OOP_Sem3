/*Write a function template for selection sort that inputs, sorts
and outputs an integer array and a float array.*/


/*template is generic class or a function.You can use templates to define functions as well as classes,
 syntax :-template <class type>
 syntax for class template:-template <class type> class class-name
type is a placeholder name for a data type used by the function.
*/
#include <iostream>
using namespace std;

// T type parameter is used to represent a placeholder name,
// to be replaced by the compiler, for a data type, within the class definition.
template <class T>

class sort
{
public:
    T a[50]; // creation of t type array
    int n;
    void accept()
    {
        cout << "Enter no. of elements:" << endl;
        cin >> n;
        cout << "enter a elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void selection_sort()
    {
        T temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                   temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i]<<" ";
        }
    }
};

int main()
{
    
    sort<int> s1;   // calls template function i.e calls sort<int>
    sort<float> s2; // calls template function i.e calls sort<float>

    cout << "*****SELECTION SORT*******\n";

    while(true){
        cout<<endl;
        cout << "sorting of integer and float array" << endl;
        cout << "1.for int array" << endl;
        cout << "2.for float array" << endl;
        
        int choice;
        cout << "enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.accept();
            cout << "\nElements are:\n";
            s1.display();
            s1.selection_sort();
            cout << "\nSorted elements are:\n";
            s1.display();
            break;

        case 2:
            s2.accept();
            cout << "\nElements are:\n";
            s2.display();
            s2.selection_sort();
            cout << "\nSorted elements are:\n";
            s2.display();
            break;
            cout << endl;
        }
    }
    return 0;
}