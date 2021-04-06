#include <iostream>

using namespace std;

int main(){
    int neg_cnt = 0, pos_cnt = 0, sum = 0;
    double avg = 0.0;
    int input;
    
    while (cin >> input){
        if (input < 0){
            ++neg_cnt;
        } else {
            sum += input;
            ++pos_cnt;
        }
    }
    
    if (pos_cnt > 0){
        avg = sum / double(pos_cnt);
    }
    
    cout << neg_cnt << endl;
    printf("%.1f\n", avg);
    
    return 0;
}

