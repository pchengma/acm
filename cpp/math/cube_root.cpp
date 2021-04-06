#include <iostream>
using namespace std;

int main() {
    double n = 0;
    double i;
    
    cin>>n;
    
    if (n > 0) {
      for(i = 0; i * i * i - n < 0; i = i + 0.01);
       double c = i + 0.05;
       int m = c * 10; 
       cout << double(m * 0.1) << endl;
    } else {
       n = 0 - n;
      for(i = 0; i * i * i - n < 0; i = i + 0.01);
       double c = i + 0.05;
       int m = c * 10; 
       cout << double(0 - m * 0.1) << endl;
    }
 
    return 0;
}

