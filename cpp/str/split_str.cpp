#include<iostream>
#include<string.h>

using namespace std;

int main () {
    string str;
    while(getline(cin,str)) {
        while(str.length() > 8) {
            for(int i = 0; i < 8; ++i)
                cout << str[i];
            cout << endl;
            str = str.substr(8);
        }
        for(int i = 0; i < 8; ++i) {
            if(i < str.length())
                cout << str[i];
            else
                cout << "0";
        }
        cout << endl;
    }
    return 0;
}
