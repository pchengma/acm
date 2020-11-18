#include <stdio.h>

void SelectionSort(int input[], int size) {
   // Insert your code here
   int i, j, tmp, min_idx;
   
   for (i = 0; i < size; ++i) {
     min_idx = i;
     for (j = i; j < size; ++j) {
       if (input[min_idx] > input[j]) {
         min_idx = j;
       }
     }
     tmp = input[min_idx];
     input[min_idx] = input[i];
     input[i] = tmp;
    }
}

int main(void) {

  // DO NOT CHANGE THE MAIN FUNCTION!
  int a[6] = {0};

  scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
  SelectionSort(a, 6);
  printf("%d %d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
  return 0;
}
