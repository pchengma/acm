#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int i, j, k;
    string n;
    
    while(getline(cin,n)) {
        vector<char> v;
        // Sort in alphabet and input order:
        for(i = 0; i < 26; ++i) {
            for(j = 0; j < n.size(); ++j) {
                if(n[j] - 'a' == i || n[j] - 'A' == i)
                    v.push_back(n[j]);
            }
        }
        // Place sorted alphabet to alphabet's positions:
        for(i = 0, k = 0; i < n.size() && k < v.size(); ++i) {
            if((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z')) {
                n[i] = v[k];
                ++k;
            }
        }
        cout << n << endl;
    }
    
    return 0;
}

