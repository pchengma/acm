#include <stdio.h>

struct link {
    int val;
    struct link *next;
};

link * head_reverse(link * head) {
    link * new_head = NULL;
    link * tmp = NULL;
  
    if (head == NULL || head->next == NULL) {
        return head;
    }
   
    while (head != NULL) {
        tmp = head;
        head = head->next;

        tmp->next = new_head;
        new_head = tmp;
    }
  
    return new_head;
}
