#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

//
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//phead: the pointer of head-pointer of the list
//p: the front node of the node inserted
//new_node: the node inserted
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
    if(*phead == NULL) {    //if the list is blank.
        new_node->link = NULL;
        *phead = new_node;
    } else if(p == NULL) {  //inserting to first node if the 'p' is NULL
        new_node->link = *phead;
        *phead = new_node;
    } else {    //inserting after 'p'
        new_node->link = p->link;
        p->link = new_node;
    }
}
//phead: the pointer about head-pointer
//p: the front node of the node removed
//removed: the node removed
void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
    if(p == NULL)
        *phead = (*phead)->link;
    else
        p->link = removed->link;
    free(removed);
}
//display all of the data in nodes on the list.
void display(ListNode *head) {
    ListNode *p = head;
    while(p != NULL) {
        printf("%d->", p->data);
        p = p->link;
    }
    printf("\n");
}
//Searching the data finding
ListNode *search(ListNode *head, int x) {
    ListNode *p;
    p = head;
    while(p != NULL) {
        if(p->data == x) return p;  //Searching successed!
        p = p->link;
    }
    return p;   //Searching failed. returning NULL
}
//Concatnating two Linked Lists
ListNode *concat(ListNode *head1, ListNode *head2) {
    ListNode *p;
    if(head1 == NULL) return head2;
    else if(head2 == NULL) return head1;
    else {
        p = head1;
        while(p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;
    }
}
//Reversing the List like up and down.
ListNode *reverse(ListNode *head) {
    //using 'p', 'q', 'r' for circular pointer
    ListNode *p, *q, *r;
    p = head;   //'p' is a node not processed
    q = NULL;   //'q' is a node be reversed
    while(p != NULL) {
        r = q;  //'r' is a reversed node 
        q = p;
        p = p->link;
        q->link = r;    //change the linking direction of 'q'
    }
    return q;   //'q' is a head-pointer of reversed list 
}
// application that makes nodes dynamically
ListNode *create_node(element data, ListNode *link) {
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    if( new_node == NULL ) error("메모리 할당 에러");
    new_node->data = data;
    new_node->link = link;
    return(new_node);
}
// Test application
int main(void) {
    ListNode *list1=NULL, *list2=NULL;
    ListNode *p;

    //list1 = 30->20->10
    insert_node(&list1, NULL, create_node(10, NULL));
    insert_node(&list1, NULL, create_node(20, NULL));
    insert_node(&list1, NULL, create_node(30, NULL));
    display(list1);

    //list1 = 20->10
    remove_node(&list1, NULL, list1);
    display(list1);

    //list2 = 80->70->60
    insert_node(&list2, NULL, create_node(60, NULL));
    insert_node(&list2, NULL, create_node(70, NULL));
    insert_node(&list2, NULL, create_node(80, NULL));
    display(list2);

    list1 = concat(list1, list2);
    display(list1);

    //making list1 revesed
    list1 = reverse(list1);
    display(list1);

    //search 20 in list1
    p = search(list1, 20);
    printf("탐색성공: %d\n", p->data);
}