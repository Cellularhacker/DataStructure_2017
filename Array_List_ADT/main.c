/*
* Date : 2017-04-04
* Written by : Cellularhacker
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100   //Maximum size of the array

typedef int element;
typedef struct {
    element list[MAX_LIST_SIZE];    //Define Array
    int length;     //Length of current array
} ArrayListType;

//Error Handling function
void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}
//Resetting Address
void init(ArrayListType *L) {
    L->length = 0;
}
// If it is empty, return 1
// or return 0
int is_empty(ArrayListType *L) {
    return L->length == 0;
}
// If it is full, return 1
// or return 0
int is_full(ArrayListType *L) {
    return L->length == MAX_LIST_SIZE;
}
// Print the ArrayListType
void display(ArrayListType *L) {
    int i;
    for(i=0;i<L->length;i++)
        printf("%d\n", L->list[i]);
}
// position: location to add
// item: item to add
void add(ArrayListType *L, int position, element item) {
    if( !is_full(L) && (position >= 0) && (position <= L->length) ) {
        int i;
        for(i=(L->length-1); i>=position; i--)
            L->list[i+1] = L->list[i];
        L->list[position] = item;
        L->length++;
    }
}
// position: location to delete
// return : item be deleteted
element delete(ArrayListType *L, int position) {
    int i;
    element item;

    if( position < 0 || position >= L->length )
        error("Location Error");
    item = L->list[position];
    for(i=position; i<(L->length-1);i++)
        L->list[i] = L->list[i+1];
    L->length--;
    return item;
}
//
main() {
    ArrayListType list1;
    ArrayListType *plist;

    // Create a ArrayListType stucture with static allocation
    // and returning pointer by parameter to function
    init(&list1);
    add(&list1, 0, 10);
    add(&list1, 0, 20);
    add(&list1, 0, 30);
    display(&list1);

    // Create a ArrayListType stucture with dynamic allocation
    // and returning pointer by parameter to function
    plist = (ArrayListType *)malloc(sizeof(ArrayListType));
    init(plist);
    add(plist, 0, 10);
    add(plist, 0, 20);
    add(plist, 0, 30);
    display(plist);
    free(plist);
}