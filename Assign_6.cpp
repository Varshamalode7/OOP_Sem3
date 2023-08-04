#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person{
    public:
    string name;
    string dob;
     long int tel_no;
    Person(string n,string d,int t){
        name=n;
        dob=d;
        tel_no=t;
    }
    void display(){
        cout<<name<<" "<<dob<<" "<<tel_no<<endl;
    }
};
vector<Person> r1;

bool compare(const Person &p1, const Person &p2)
{
 return p1.name < p2.name;
}

void insert(){
    string n,dob;
    long int tel;
    cout<<"Enter name ,date of bitrh,tel no of a person"<<endl;
    cin>>n>>dob>>tel;
    Person p(n,dob,tel);
    r1.push_back(p);
    cout<<"Record Added successfully"<<endl;
}

void print(){
    for(auto i:r1){
        i.display();
    }
}

void sorting(){
    sort(r1.begin(),r1.end(),compare);
    print();
}

void search(){
    string nm;
    cout<<"Enter name of person"<<endl;
    cin>>nm;
    for( auto i:r1){
        if(i.name==nm){
            i.display();
            return;
        }
    }
    cout<<"Person not found"<<endl;
}

int main() {
    while(true){
        cout<<endl;
        cout<<"Enter 1 to insert new person"<<endl;
        cout<<"Enter 2 to print sorted records by name"<<endl;
        cout<<"Enter 3 to search a record by name"<<endl;
        cout<<"Enter 4 to exit"<<endl;
        int res;
        cout<<"Enter your choice : ";
        cin>>res;
        if(res==1) insert();
        else if(res==2) sorting();
        else if(res==3) search();
        else if(res==4) break;
        else continue;
    }
    return 0;
}