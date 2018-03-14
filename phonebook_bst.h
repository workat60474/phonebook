#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define BST 2

typedef struct __ENTRY_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entryDetail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entryDetail *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __BST {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __BST *left;
    struct __BST *right;
} bst;

bst *findName(char lastName[], bst *root);
entry *append(char lastName[], entry *e);
bst *list_to_BST(entry *pHead);
bst *buildbst(entry **head, int listLen);
void releaseTree(bst *root);

#endif