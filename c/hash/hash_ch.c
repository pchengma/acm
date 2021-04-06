#include <stdio.h>
#include <string.h>

int main() {
    int n, i, len, j, k, temp, s;
    char str[10000];
    
    while(scanf("%d", &n) != EOF) {
        for(k = 0; k < n; k++){
            scanf("%s", &str);
            int hash[26]={0};
            len = strlen(str);
            for(i = 0; i < len; i++){
                if(str[i] >= 'A' && str[i] <= 'Z') {
                    hash[str[i]-'A']++;
                } else {
                    hash[str[i]-'a']++;
                }
            }
            for(i = 0; i < 25; i++){
                for(j = 25; j > i; j--){
                    if(hash[j] > hash[j - 1]){
                        temp = hash[j];
                        hash[j] = hash[j - 1];
                        hash[j - 1] = temp;
                    }
                }
            }
            s=0;
            for(i = 0; i < 26; i++){
                s += (hash[i] *(26-i));
            }
            printf("%d\n", s);
        }
    }
}
