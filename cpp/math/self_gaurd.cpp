#include<iostream>

using namespace std;
 
bool selfguard(int n) {
    int size = 0;
    int ten = 10;
    int x = n;
    while(x) {
        x /= 10;
        size++;
    }
    for(int i = 0; i < size - 1; ++i) {
        ten *= 10;
    }
    if((n*n-n)%ten == 0) 
        return true;
    else 
        return false;
}
 
int main() {
    int n;
    while(cin >> n) {
        int sum=1;
        for(int i=1;i<=n;i++) {
            if(selfguard(i)) {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
}

