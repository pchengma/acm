#include <iostream>
#include <string>

using namespace std;

int main(){
    int i;
    char ch;
    string str;
    
    getline(cin, str);
  
    for(i = str.size() - 1; i > str.size() / 2; --i) {
        ch = str[i];
        str[i] = str[str.size() - i];
        str[str.size() - i] = ch;
    }
}

