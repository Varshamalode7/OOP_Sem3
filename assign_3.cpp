// /*--------------------------------------------------
// Imagine a publishing company which does marketing for book and audio cassette versions.
// Create a class publication that stores the title (a string) and price (type float) of publications.
// From this class derive two classes: book which adds a page count (type int) and tape which
// adds a playing time in minutes (type float).
// Write a program that instantiates the book and tape class, allows user to enter data and
// displays the data members. If an exception is caught, replace all the data member values with
// zero values.
// --------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

// base class publication
class publication
{
protected:
    string title;
    float prices;

public:
    // default constructor
    publication()
    {
        title = "";
        prices = 0.0;
    }
};

// derived class book from publication
class book : public publication
{
    int pages;

public:
    // default constructor
    book()
    {
        pages = 0;
    }

    void get_data_book()
    {
        cout << "Enter Title : ";
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, this->title);
        while (true)
        {
            cout << "Enter Price:";
            try
            {
                cin >> prices;
                if (prices < 0)
                {
                    throw prices;
                }
                break;
            }
            catch (float prices)
            {
                this->prices = 0;
                cout << "Price cannot be negative!" << endl;
            }
        }
    }

    void put_data_book()
    {
        while (true)
        {
            cout << "Enter no. of pages: " << endl;
            try
            {
                cin >> pages;
                if (pages < 0)
                {
                    throw pages;
                }
                break;
            }
            catch (int pages)
            {
                this->pages = 0;
                cout << "Page count cannot be negative!" << endl;
            }
        }
    }

    void displaybook()
    {
        cout << "<Book Data>" << endl;
        cout << "Title = " << this->title << endl;
        cout << "Price = " << this->prices << endl;
        cout << "Pages Count = " << this->pages << endl
             << endl;
    }
};

// derived tape class from publication base class
class tape : public publication
{

    float playtime;

public:
    // default constructor
    tape()
    {
        playtime = 0.0;
    }

    void get_data_tape()
    {
        cout << "Enter Title : ";
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, this->title);
        while (true)
        {
            cout << "Enter Price:";
            try
            {
                cin >> prices;
                if (prices < 0)
                {
                    throw prices;
                }
                break;
            }
            catch (float prices)
            {
                this->prices = 0;
                cout << "Price cannot be negative!" << endl;
            }
        }
    }
    void put_data_tape()
    {
        while (true)
        {
            cout << "Enter no. of time: " << endl;
            try
            {
                cin >> playtime;
                if (playtime < 0)
                {
                    throw playtime;
                }
                break;
            }
            catch (float playtime)
            {
                this->playtime = 0;
                cout << "Playtime count cannot be negative!" << endl;
            }
        }
    }

    void displaytape()
    {
        cout << "<tape Data>" << endl;
        cout << "Title = " << this->title << endl;
        cout << "Price = " << this->prices << endl;
        cout << "Playtime = " << this->playtime << endl
             << endl;
    }
};

int main() // main program
{
    book b; // arrray of objects
    tape t;
    int choice = 0;
    
    while(true)
    {
        cout << "\n";
        cout << "\n 1. Add book ";
        cout << "\n 2. Add tape: ";
        cout<<"\n 3.add page in book";
        cout<<"\n 4.add time in book";
        cout << "\n 5. Display book ";
        cout << "\n 6. Display tape";
        cout << "\n 7. Exit:" << endl;

        cout << "\n Enter your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Add Book: \n";
            b.get_data_book();
            break;
        }

        case 2:
        {
            cout << "Add Tape: \n";
            t.get_data_tape();
            break;
        }

        case 3:
        {
            b.put_data_book();
            break;
        }


        case 4:
        {
            t.put_data_tape();
            break;
        }


        case 5:
        {
            b.displaybook();
            break;
        }

        case 6:
        {
           
           t.displaytape();
            break;
        }

        case 7:
        {
            cout << "**********Program ExitedSuccessfully**********" << endl;
            exit(0);
        }

        default:
        {
            cout << "\n Invalid";
        }
        }
    } 
    return 0;
}
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class Publication
// {
// protected:
//     string title;
//     float price;

// public:
//     Publication()
//     {
//         title = "<title>";
//         price = 0;
//     }
// };

// //derived class book
// class Book : public Publication
// {
//     int pageCount;

// public:
//     static int bookCount;
//     Book()
//     {
//         pageCount = 0;
//         Book::bookCount++;
//     }

//     void getData()
//     {
//         cout << "Enter Title : ";
//         cin.clear();
//         cin.ignore(1000, '\n');
//         getline(cin, this->title);
//         while (true)
//         {
//             cout << "Enter Price:";
//             try
//             {
//                 cin >> price;
//                 if (price < 0)
//                 {
//                     throw price;
//                 }
//                 break;
//             }
//             catch (float price)
//             {
//                 this->price = 0;
//                 cout << "Price cannot be negative!" << endl;
//             }
//         }
//         this->getPageCount();
//     }
//     void getPageCount()
//     {
//         while (true)
//         {
//             cout << "Enter no. of pages: " << endl;
//             try
//             {
//                 cin >> pageCount;
//                 if (pageCount < 0)
//                 {
//                     throw pageCount;
//                 }
//                 break;
//             }
//             catch (int pageCount)
//             {
//                 this->pageCount = 0;
//                 cout << "Page count cannot be negative!" << endl;
//             }
//         }
//     }

//     static void bookCountDisplay()
//     {
//         cout << "Current no. of books =" << Book::bookCount << endl;
//     }
//     void display()
//     {
//         cout << "<Book Data>" << endl;
//         cout << "Title = " << this->title << endl;
//         cout << "Price = " << this->price << endl;
//         cout << "Pages Count = " << this->pageCount << endl
//              << endl;
//     }
// };

// class Tape : public Publication
// {
// private:
//     float playTime;

// public:
//     static int tapeCount;
//     Tape()
//     {
//         playTime = 0;
//         Tape::tapeCount++;
//     }

//     void getData()
//     {
//         cout << "Enter Title : ";
//         cin.clear();
//         cin.ignore(1000, '\n');
//         getline(cin, this->title);
//         while (true)
//         {
//             cout << "Enter Price:";
//             try
//             {
//                 cin >> price;
//                 if (price < 0)
//                 {
//                     throw price;
//                 }
//                 break;
//             }
//             catch (float price)
//             {
//                 this->price = 0;
//                 cout << "Price cannot be negative!" << endl;
//             }
//         }
//         this->getPlayTime();
//     }
//     void getPlayTime()
//     {
//         while (true)
//         {
//             cout << "Enter play time of tape: " << endl;
//             try
//             {
//                 cin >> playTime;
//                 if (playTime < 0)
//                 {
//                     throw playTime;
//                 }
//                 break;
//             }
//             catch (float playTime)
//             {
//                 this->playTime = 0;
//                 cout << "playtime cannot be negative!" << endl
//                      << endl;
//             }
//         }
//     }

//     void display();
//     static void tapeCountDisplay()
//     {
//         cout << "Current no. of tapes =" << Tape::tapeCount << endl;
//     }

//     void display()
//     {
//         cout << "<Tape Data>" << endl;
//         cout << "Title = " << this->title << endl;
//         cout << "Price = " << this->price << endl;
//         cout << "Play Time = " << this->playTime << endl;
//     }
// };

// int Book::bookCount;
// int Tape::tapeCount;

// // driver code
// int main()
// {
//     int choice = 0;
//     vector<Book> bookDB;
//     vector<Tape> tapeDB;

//     while (choice != -1)
//     {
//         cout << "------Menu------" << endl;
//         cout << "1. New Book Entry" << endl
//              << "2. New Tape Entry" << endl
//              << "3. Display No. of Books in DB" << endl
//              << "4. Display No. of Tapes in DB" << endl
//              << "5. Display Book Data" << endl
//              << "6. Display Tape Data" << endl
//              << "-1. Exit" << endl;
//         cout << "----------------" << endl;
//         cout << "Enter your choice :";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1: // New Book Entry
//         {
//             Book B;
//             cout << "Enter Book Data: " << endl;
//             B.getData();
//             bookDB.push_back(B);
//             break;
//         }

//         case 2: // New Tape Entry
//         {
//             Tape T;
//             cout << "Enter Tape Data: " << endl;
//             T.getData();
//             tapeDB.push_back(T);
//             break;
//         }

//         case 3: // Display No. of Books in DB
//         {
//             Book::bookCountDisplay();
//             break;
//         }

//         case 4: // Display No. of Tapes in DB
//         {
//             Tape::tapeCountDisplay();
//             break;
//         }

//         case 5: // Display Book Data
//         {
//             for (auto B : bookDB)
//             {
//                 B.display();
//                 cout << endl;
//             }
//             break;
//         }

//         case 6: // Display Tape Data
//         {
//             for (auto T : tapeDB)
//             {
//                 T.display();
//                 cout << endl;
//             }
//             break;
//         }

//         case -1: // Exit
//         {
//             cout << "----Exit from Database----" << endl;
//             choice = -1;
//             break;
//         }

//         default: // Exit
//         {
//             cout << "----Exit from Database----" << endl;
//             choice = -1;
//             break;
//         }
//         }
//     }

//     return 0;
// }

// // #include <iostream>
// // using namespace std;
// // class publication
// // {
// // protected:
// //     string title;
// //     float price;

// // public:
// //     publication()
// //     {
// //         title = "publication name:";
// //     }
// //     ~publication()
// //     {
// //         cout << "Destructor for base class" << endl;
// //     }
// // };

// // class book : public publication
// // {
// // protected:
// //     int pages;

// // public:
// //     book()
// //     {
// //     }
// //     ~book()
// //     {
// //         cout << "Destructor for book" << endl;
// //     }
// //     void getdata()
// //     {
// //         cout << "Enter the following data:" << endl;
// //         cout << "Title: ";
// //         cin >> title;
// //         cout << "Price: ";
// //         cin >> price;
// //         try
// //         {
// //             cout << "Pages : ";
// //             cin >> pages;
// //             if (pages < 0)
// //             {
// //                 throw pages;
// //             }
// //         }
// //         catch (int pages)
// //         {
// //             cout << "Exception Caught " << endl;
// //             title = "0";
// //             price = 0;
// //             this->pages = 0;
// //         }
// //     }
// //     void displaydata()
// //     {
// //         cout << "The Book details are as follows: " << endl;
// //         cout << "Title: " << title << endl;
// //         cout << "price: " << price << endl;
// //         cout << "pages: " << pages << endl;
// //     }
// // };
// // class tape : public publication
// // {
// // protected:
// //     float time;

// // public:
// //     tape()
// //     {
// //     }
// //     ~tape()
// //     {
// //         cout << "Destructor for tape" << endl;
// //     }
// //     void getdata()
// //     {
// //         cout << "Enter the following data:" << endl;
// //         cout << "Title: ";
// //         cin >> title;
// //         cout << "Price: ";
// //         cin >> price;
// //         try
// //         {
// //             cout << "time : ";
// //             cin >> time;
// //             if (time < 0)
// //             {
// //                 throw time;
// //             }
// //         }
// //         catch (float time)
// //         {
// //             cout << "Exception Caught " << endl;
// //             title = "0";
// //             price = 0;
// //             this->time = 0;
// //         }
// //     }
// //     void displaydata()
// //     {
// //         cout << "The audio cassette details are as follows: " << endl;
// //         cout << "Title: " << title << endl;
// //         cout << "price: " << price << endl;
// //         cout << "Time: " << time << endl;
// //     }
// // };
// // int main()
// // {

// //     book b1;
// //     b1.getdata();
// //     b1.displaydata();
// //     tape t1;
// //     t1.getdata();
// //     t1.displaydata();
// //     return 0;
// // }
