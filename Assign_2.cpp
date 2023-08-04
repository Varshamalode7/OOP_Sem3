/* PROBLEM STATEMENT
 * Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/


#include <iostream>
#include <string.h>                        
using namespace std;

//to make class as friend
class StudData;                            

//creation of student class
class Student                              
{
    string name;
    int roll_no;
    string cls;
    char *division;
    string dob;
    char *bloodgroup;
   
//creation of static data variable
static int count;                          

public:
// Default Constructor
Student(){
        division = new char;
        bloodgroup = new char[4];
        }
 
//Destructor destroy the obj
~Student(){                              
        delete division;
        delete bloodgroup;
        }
       
//static member function        
static int getCount(){
    return count;
    }
   
//member functions
void getData(StudData *);              
void dispData(StudData *);

friend class StudData;
};

//creation of studentdata class
class StudData{
        string caddress;
        long long int *Phno;
        long long int *License_Number;

public:
//default constructor
StudData(){
        caddress = "";
        Phno = new long long;
        License_Number = new long long;
    }

//destructor
~StudData(){
        delete Phno;
        delete License_Number;
    }
   
//member function    
void getStudData(){
        cout << "Enter Address : ";
        cin.get();
        getline(cin, caddress);
        cout << "Enter Phone Number : ";
        cin >> *Phno;
        cout << "Enter Driving License Number: ";
        cin >> *License_Number;
    }
   
void dispStudData(){
        cout << " Address : " << caddress << endl;
        cout << "Phone Number : " << *Phno << endl;
        cout << "Driving License Number : " << *License_Number<< endl;
    }
};

// Inline function
inline void Student::getData(StudData *st){
        cout << "Enter Student Name : ";
        getline(cin, name);
        cout << "Enter Roll Number : ";
        cin >> roll_no;
        cout << "Enter Class : ";
        cin.get();
        getline(cin, cls);
        cout << "Enter Division : ";
        cin >> division;
        cout << "Enter Date of Birth : ";
        cin.get();
        getline(cin, dob);
        cout << "Enter Blood Group : ";
        cin >> bloodgroup;
        st->getStudData();
        count++;
    }  

//inline function
inline void Student::dispData(StudData *st1){
        cout << "Student Name : " << name << endl;
        cout << "Roll Number : " << roll_no << endl;
        cout << "Class : " << cls << endl;
        cout << "Division : " << division << endl;
        cout << "Date of Birth : " << dob << endl;
        cout << "Blood Group : " << bloodgroup << endl;
        st1->dispStudData();
    }
   
int Student::count;

int main(){
    //obj creation
    Student *stud1[100];                
    StudData *stud2[100];
    int n = 0;
    char ch;
   
do{
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        Student::getCount();
        cout << "Do you want to add another student(y / n) : ";
        cin >> ch;
        cin.get();
    }while (ch == 'y' || ch == 'Y'); 
   
for (int i = 0; i < n; i++){
        cout << " Student Details" << endl;
        stud1[i]->dispData(stud2[i]);
    }

cout << "Total Students : " << Student::getCount();

for (int i = 0; i < n; i++){
        delete stud1[i];
        delete stud2[i];
    }

return 0;
}






// #include<iostream>
// #include<string.h>

// using namespace std;
// class data{
//     public:
//     string name[50];
//     static int roll;
//     string  cls[5];
//     int div;
//     string dob[10];
//     char bg[5];
//     long int tel_num;
//     long int lic_num;

//     void getdata();
//     void inline in();
//     friend class Teacher;

//     data(){
//         //constructor called
//     }
//     ~data(){
//         //destructor called
//     }

//     static int set(){
//         return roll;
//     }
//     data(data &d){
//         strcpy(name,d.name);
//         strcpy(cls,d.cls);
//         this->div=d.div;
//         strcpy(dob,d.dob);
//         strcpy(bg,d.bg);
//         this->tel_num=d.tel_num;
//         this->lic_num=d.lic_num;
//         roll++;
//     }
// };
// int data::roll=00;
// void data::in(){
//     cout<<"Enter the name"<<endl;
//     cin>>name;
// }
// void data::getdata(){
//     in();
//     cout<<"Enter class"<<endl;
//     cin>>cls;
//     cout<<"Enter div"<<endl;
//     cin>>div;
//     cout<<"Enter dob"<<endl;
//     cin>>dob;
//     cout<<"Enter bg"<<endl;
//     cin>>bg;
//     cout<<"Enter telephone num"<<endl;
//     cin>>tel_num;
//     cout<<"Enter licence num"<<endl;
//     cin>>lic_num;
// }

// class Teacher{
//     public:
//     void display(data &s){
//         cout<<"Name: "<<s.name<<endl;
//         cout<<"Roll Number: "<<s.set()<<endl;
//         cout<<"Class: "<<s.cls<<endl;
//         cout<<"Divison: "<<s.div<<endl;
// 		cout<<"Date of Birth: "<<s.dob<<endl;
// 		cout<<"Blood Group:"<<s.bg<<endl;
// 		cout<<"Telephone Number: "<<s.tel_num<<endl;
//         cout<<"License Number: "<<s.lic_num<<endl;
//     }
// };
// int main(){
//     data d1;
//     Teacher t;

//     int n;
//     cout<<"Enter the number of students to be added"<<endl;
//     cin>>n;
//     data *db[n];
//     for(int i=0;i<n;i++){
//         db[i]=new data();
//         db[i]->getdata();
//         t.display(*db[i]);
//         delete(db[i]);
//     }
//     return 0;

// }

// //Assignment _No_02_OPP
// // #include <iostream>
// // #include<string.h>
// // using namespace std;

// // class Student{					//creation of class
// // public:							//access specifier
// // 	int Roll_No;
// // 	int Sr_No;
// // 	char Greet[10];
// // 	char Name[20];
// // 	char Div;
// // 	char Blood_grp;
// // 	char DOB[10];
// // 	long int Tele_No;
// // 	static int count;			//static data member
	
// // 	void getdata();				//Function decleration
// // 	friend void display(Student &obj);		//friend function used
	
// // 	Student()					//Default constructor
// // 	{
// // 		Roll_No=0;
// // 		cout<<"Constructor"<<endl;
// // 		Roll_No=count;
// // 		count++;
// // 	}
	
// // 	~Student()					//Destructor
// // 	{
// // 		cout<<"Destructor-Destroying the object"<<endl;
// // 		count--;
		
// // 	}
	
// // 	Student(int Roll_No)			//parameterized constructor
// // 	{
// // 		this->Roll_No=Roll_No;		//this 
// // 	}
	
// // 	Student(Student &obj)			//copy constructor
// // 	{
// // 		Roll_No=obj.Roll_No;
// // 		strcpy(Name,obj.Name);
// // 				strcpy(DOB,obj.DOB);
// // 				strcpy(Greet,obj.Greet);
// // 				Blood_grp=obj.Blood_grp;
// // 				Div=obj.Div;
// // 				Tele_No=obj.Tele_No;
// // 				Sr_No=count;
// // 				count++;
// // 	}
// // };


	

// // int Student :: count=0;
// // void Student:: getdata()				//Define of function
// // 	{
// // 		cout<<"Enter the roll number of the student:"<<endl;
// // 		cin>>Roll_No;

// // 		cout<<"Enter the name of the student:"<<endl;
// // 		cin>>Name;

// // 		cout<<"Enter the date of birth of the student:"<<endl;
// // 		cin>>DOB;

// // 		cout<<"Enter the blood group of the student:"<<endl;
// // 		cin>>Blood_grp;

// // 		cout<<"Enter the class of the student:"<<endl;
// // 		cin>>Greet;

// // 		cout<<"Enter the division of the student:"<<endl;
// // 		cin>>Div;

// // 		cout<<"Enter the contact of the student:"<<endl;
// // 		cin>>Tele_No;
// // 	}
// // void display(Student & obj)
// // 	{
// // 		cout<<obj.Roll_No<<endl;
// // 		cout<<obj.Name<<endl;
// // 		cout<<obj.DOB<<endl;
// // 		cout<<obj.Blood_grp<<endl;
// // 		cout<<obj.Greet<<endl;
// // 		cout<<obj.Div<<endl;
// // 		cout<<obj.Tele_No<<endl;
		
// // 	}
		
// // int main()
// // {

// // 	Student s1;						//creation of object
// // 	Student s2(s1);					//creation of obj for copy constructor
// // 	cout<<"Enter the details of a student:"<<endl;
// // 	s1.getdata();

// // 	cout<<"All data is as displayed below:"<<endl;
// // 	cout<<"\n---------------------------------------------------------------------";
// // 	cout<<"\nROLL No.\tNAME\t\tDOB\t\tBLOOD GRP\tCLASS\tDIV\tCONTACT No,";
// // 	display(s1);
// // cout<<"\n---------------------------------------------------------------------";

// // 	int i,n;

// // 	Student *s[50];
// // 	cout<<"\nEnter how many student object do you want us to create?"<<endl;
// // 	cin>>n;

// // 	for(i=0;i<n;i++)
// // 	{
// // 		s[i]= new Student(); //new operator use to dynamic memory(run time) allocation
// // 	}

// // 	for(i=0;i<n;i++)
// // 	{
// // 		s[i]->getdata();
// // 	}
	
	
// // 	for(i=0;i<n;i++)
// // 	{
// // 		display(*s[i]);
// // 	}
	
// // 	for(i=0;i<n;i++)
// // 	{
// // 		delete (s[i]);
// // 	}
// // 	return 0;
// // }


