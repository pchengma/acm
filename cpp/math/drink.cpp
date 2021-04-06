#include<iostream>
 
using namespace std;

int myfun(int my_input) {
    if(my_input <= 1)
        return 0;
    if(my_input == 2)
        return 1;
    return my_input / 3 + myfun(my_input / 3 + my_input % 3);
}
 
int main() {
    int my_input;
    
    while(cin >> my_input) {
        if(my_input == 0)
            break;
        cout << myfun(my_input) << endl;
    }
    return 0;
}
