#include <iostream>

using namespace std;

int gcd(int a,int b) {
  int tmp;
  
  if(a < b){
      tmp = a;
      a = b;
      b = tmp;
  }
  
  if(a % b == 0) 
      return b;
  else 
      return gcd(b, a % b);
}

int main(){
    int ans;
    int a, b;
  
    cin >> a >> b;
     
    int tmp = gcd(a, b);
    ans = a * b / tmp;
    
    cout << ans;
    
    return 0;
}

