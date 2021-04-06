#include<iostream>

using namespace std;

int main() {
    int num;
    
    cin >> num;
    while (num) {
        cout << num % 10;
        num /= 10;
    }
    return 0;
}

