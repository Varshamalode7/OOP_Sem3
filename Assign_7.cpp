/*map is an associative array
Each mapped have key and value
No two mapped values can have same key values.
*/

#include <iostream>
#include <iterator>
#include <map>
#include <string>
using namespace std;

class mapping
{
public:
    string state;
    int population;
    map<string, int> mymap;

    void createmap()
    {
        cout << "enter the state:" << endl;
        cin >> state;
        cout << "enter the population:" << endl;
        cin >> population;
        mymap.insert(pair<string, int>(state, population));
    }

    void displaymap()
    {
        cout << "map contains following element" << endl;
        // begin means pointing to starting iterator
        
        for (auto iter = mymap.begin(); iter != mymap.end(); iter++)
        {
            //*iter first will display key
            //*iter second will display value
            cout << iter->first << ": " << iter->second << endl;
        }
    }

    void findstate()
    {
        cout << "enter the state whose population is to be found:" << endl;
        string key;
        cin >> key;
        if (mymap.find(key) != mymap.end())
        {
            cout << "state found with population: " << mymap[key] << endl;
        }
        else
        {
            cout << " : Not found" << endl;
        }
    }
};
int main()
{
    mapping m1;
    int choice;
    cout << "<-------Menu------->" << endl;
    cout << "1.create the map" << endl;
    cout << "2.display map." << endl;
    cout << "3.find population." << endl;
    cout << "4.Exit" << endl;
    do
    {
        cout << "Enter the choice" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "enter the size of map" << endl;
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                m1.createmap();
            }
        }
        else if (choice == 2)
        {
            m1.displaymap();
        }
        else if (choice == 3)
        {
            m1.findstate();
        }
        else
        {
            cout << "EXIT PROGRAM" << endl;
        }
    } while (choice < 4);

    return 0;
}
