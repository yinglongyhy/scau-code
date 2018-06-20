#include <iostream>   
#include <fstream>   
using namespace std;   
int main()   
{   
     char ch = 'x';   
    ifstream fin("test.txt" /*, ios::binary*/);   
    if (fin.eof()) {   
        cout << "file is empty." << endl;   
        return 0;   
    }   
    while (!fin.eof())  {   
        fin.get(ch);   
        cout << ch;   
    }   
    return 0;   
}
