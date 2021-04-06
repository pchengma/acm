#include <iostream>
#include <string>

using namespace std;
 
int main () {
    int i;
    bool num[128] = {false};
    int cnt = 0;
    string s;
    
    cin >> s;
    
    for(i = 0; i < s.size(); ++i) {
        if(!num[s[i]]) {
            ++cnt;
            num[s[i]] = true;
        }
    }
    
    cout << cnt << endl;
     
    return 0;
}

