/*Write a C++ program that creates an output file, writes
information to it, closes the file, open it again as an input file
and read the information from the file.*/

#include <iostream>
#include <fstream> //is is a base class for ofstream and if stream
#include <string>
using namespace std;

class Student
{
    string name;
    int Roll_No;

public:
    ofstream obj1;
    ifstream obj2;
    fstream obj3;

    void create_file()
    {
        obj1.open("cs.txt");
        cout << " Your File created successfully." << endl;
        obj1.close();
    }

    void write_file()
    {
        obj1.open("cs.txt",ios::out |ios::app);
        cout << "Enter your name:" << endl;
        cin >> name;
        cout << "Enter your Roll_No:" << endl;
        cin >> Roll_No;
        obj1 << "Name of Student is : " << name << endl;
        obj1 << "Roll_No of Student is : " << Roll_No << endl;
        cout << "Write operation performed successfully." << endl;
        obj1.close();
    }

    void read_file()
    {
        obj2.open("cs.txt");
        cout << "Contents of the file are:" << endl;
        char ch;
        while (true)
        {
            ch = obj2.get();
            if (obj2.eof())
            {
                break;
            }
            cout << ch;
        }

        cout << "Read operation performed successfully." << endl;
        obj2.close();
    }

    void edit_file()
    {
        obj3.open("cs.txt");

        int n;
        cout << "Enter the location of cursor" << endl;
        cin >> n;

        obj3.seekg(n, ios::beg);

        int c;
        cout << "Enter the number of characters to replace and new string" << endl;
        cin >> c;
        char str[c];
        for (int i = 0; i < c; i++)
        {
            cin >> str[i];
        }

        obj3.write(str, c);

        obj3.close();
    }
};

int main()
{
    Student s1;
    while (true)
    {
        cout << "1. Create a file." << endl;
        cout << "2. Write operation." << endl;
        cout << "3. Read operation." << endl;
        cout << "4. Edit operation." << endl;
        cout << "5. Exit." << endl;

        int choice;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            s1.create_file();
        }

        else if (choice == 2)
        {
            s1.write_file();
        }

        else if (choice == 3)
        {
            s1.read_file();
        }

        else if (choice == 4)
        {
            s1.edit_file();
        }

        else if (choice == 5)
        {
            break;
        }

        else
        {
            cout << " Your choice is Invalid . Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}

// //*****Assignment ******//
// /*Write a C++ program that creates an output file, writes
// information to it, closes the file, open it again as an input file
// and read the information from the file.*/

// #include<iostream>
// #include<fstream>
// using namespace std;

// class Employee
// {
//     char Name[20];
//     int Age;

//     public:
//         void getdata()
//         {
//             cin>>Name;
//             cin>>Age;

//         }
//         void display()
//         {
//             cout<<"\n Enter Name:"<<Name;
//             cout<<"\n Enter Id:"<<Age;

//         }
// };

// int main()
// {
//     Employee o[5];
//     fstream f;
//     int i,n;

//     f.open("it.txt");
//     cout<<"\n How many employee information do you need to store?";
//     cin>>n;
//     cout<<"\n Enter information of employee in this format(NAME/ID/SALARY)";
//     for(i=0;i<n;i++)
//     {
//         cout<<"\n Enter information of:"<<i<<"\n Employee";
//         o[i].getdata();
//         f.write((char*)&o[i],sizeof o[i]);
//     }

//     f.close();

//     f.open("it.txt",ios::in);
//     cout<<"\n Information of Employees is as follows:";
//     for(i=0;i<n;i++)
//     {
//         f.read((char*)&o[i],sizeof o[i]);
//         o[i].display();
//     }
//     f.close();

//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;
// string exitCondition = "^C";

// void createFile() {

//     fstream file;
//     file.open("sample_4.txt", ios::out);

//     if (file) {
//         cout<<"File created successfully"<<endl;
//     } else {
//         cout<<"Error while creating file"<<endl;
//     }

//     file.close();
// }

// void readFile() {
//     fstream file;
//     file.open("sample_4.txt", ios::in);

//     if (file) {
//         char x;
//         while (1) {
//             x = file.get();
//             if (file.eof()) {
//                 break;
//             }
//             cout<<x;
//         }
//     } else {
//         cout<<"File does not exist"<<endl;
//     }
//     cout<<endl;

//     file.close();
// }

// void writeText() {
//     ofstream file;
//     file.open("sample_4.txt", ios::trunc);
//     string line;

//     cout<<"Keep on writing data to the files! To exit press "<<exitCondition<<endl;
//     bool append = true;
//     cin.ignore();

//     while(append) {
//         getline(cin, line);
//         if(exitCondition.compare(0, 2, line) == 0){
//             cout<<"Breaking"<<endl;
//             append = false;
//             break;
//         }
//         file<<line;
//     }
//     cout<<endl;
//     file.close();
// }

// void appendText() {
//     ofstream file;
//     file.open("sample_4.txt", ios::app);
//     string line;

//     cout<<"Keep on writing data to the files! To exit press "<<exitCondition<<endl;
//     bool append = true;
//     cin.ignore();

//     while(append) {
//         getline(cin, line);
//         if(exitCondition.compare(0, 2, line) == 0){
//             cout<<"Breaking"<<endl;
//             append = false;
//             break;
//         }
//         file<<line;
//     }
//     cout<<endl;
//     file.close();
// }

// void editText() {
//     fstream file;
//     file.open("sample_4.txt");

//     int n;
//     cout<<"Enter the location of cursor"<<endl;
//     cin>>n;

//     file.seekg(n, ios::beg);

//     int c;
//     cout<<"Enter the number of characters to replace and new string"<<endl;
//     cin>>c;
//     char str[c];
//     for(int i = 0; i < c; i++) {
//         cin>>str[i];
//     }

//     file.write(str, c);

//     file.close();
// }

// int main() {
//     while(true) {
//         cout<<"Choose your option"<<endl;
//         cout<<"1.Create a file"<<endl;
//         cout<<"2.Write text"<<endl;
//         cout<<"3.Append text"<<endl;
//         cout<<"4.Read text"<<endl;
//         cout<<"5.Edit text"<<endl;
//         cout<<"6.Exit"<<endl;
//         int c;
//         cin>>c;

//         switch(c) {
//         case 1: {
//             createFile();
//             break;
//         }
//         case 2: {
//             writeText();
//             break;
//         }
//         case 3: {
//             appendText();
//             break;
//         }
//         case 4: {
//             readFile();
//             break;
//         }
//         case 5: {
//             editText();
//             break;
//         }
//         default: {
//             cout<<"Wrong choice"<<endl;
//             break;
//         }
//         }
//     }
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// class Student
// {
//     string name;
//     int age;

// public:
//     ofstream obj1;
//     ifstream obj2;
//     fstream obj3;

//     void create_file()
//     {
//         obj1.open("OOP.txt");
//         cout << "File created successfully." << endl;
//         obj1.close();
//     }

//     void write_file()
//     {
//         obj1.open("OOP.txt");
//         cout << "Enter your name:" << endl;
//         cin >> name;
//         cout << "Enter your age:" << endl;
//         cin >> age;
//         obj1 << "Name: " << name << endl;
//         obj1 << "Age: " << age << endl;
//         cout << "Write operation performed successfully." << endl;
//         obj1.close();
//     }

//     void read_file()
//     {
//         obj2.open("OOP.txt");
//         cout << "Contents of the file are:" << endl;
//         char ch;
//         while (1)
//         {
//             ch = obj2.get();
//             if (obj2.eof())
//             {
//                 break;
//             }
//             cout << ch;
//         }
//         cout << "Read operation performed successfully." << endl;
//         obj2.close();
//     }

//     void editText() {
//     fstream file;
//     file.open("OOP.txt");

//     int n;
//     cout<<"Enter the location of cursor"<<endl;
//     cin>>n;

//     file.seekg(n, ios::beg);

//     int c;
//     cout<<"Enter the number of characters to replace and new string"<<endl;
//     cin>>c;
//     char str[c];
//     for(int i = 0; i < c; i++) {
//         cin>>str[i];
//     }

//     file.write(str, c);

//     file.close();
//     }
// };

// int main()
// {
//     Student s1;
//     while (true)
//     {
//         cout << "1. Create a file." << endl;
//         cout << "2. Write operation." << endl;
//         cout << "3. Read operation." << endl;
//         cout << "4. Edit operation." << endl;
//         cout << "5. Exit." << endl;
//         int choice;
//         cout << "Enter your choice:" << endl;
//         cin >> choice;
//         if (choice == 1)
//         {
//             s1.create_file();
//         }
//         else if (choice == 2)
//         {
//             s1.write_file();
//         }
//         else if (choice == 3)
//         {
//             s1.read_file();
//         }
//         else if (choice == 4)
//         {
//             s1.editText();
//         }
//         else if (choice == 5)
//         {
//             break;
//         }
//         else
//         {
//             cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
//         }
//     }

//     return 0;
// }

// #include<iostream>
// #include<fstream>
// #include<string>
// using namespace std;
// int main()

// {
//     while(true)
//     {
//         cout<<"****************************"<<endl;
//          cout <<"1. Write operation." << endl;
//         cout << "2. Read operation." << endl;
//         cout << "3. Edit operation." << endl;
//         cout << "4. Exit." << endl;
        
//     int choice;
//     cout<<"enter here : ";
//     cin>>choice;
//     cout<<"****************************"<<endl;
    
//     if(choice==1){
//     ofstream h1;
//     h1.open("f1.txt");
//      string st;
//      cout<<"enter string here : ";
//      std::getline(std::cin >> ws , st);
//      cout<<endl;
//     h1<<st;
   
//     h1.close();
//     }
    
//     if(choice==2)
//     {
//     ifstream h2;
//     h2.open("f1.txt");

//     // input file
//     string st1;
//     cout<<"content is : "<<endl;   
//     while (h2.eof()==0)
//     {
//         getline(h2,st1); 
//         cout<<st1<<endl;   //reading file
//     }
//     h2.close();
//     }
    
//     if(choice==3){
//     ofstream h1;
//     h1.open("f1.txt",ios::app);
//      string st;
//      cout<<"enter string here : ";
//      std::getline(std::cin >> ws , st);
//      cout<<endl;
//     h1<<st;
   
//     h1.close();
//     }


//     if(choice==4)
//     {
//         cout<<"exited";
//         break;
//     }
    
//     }
//     return 0;
    
// }