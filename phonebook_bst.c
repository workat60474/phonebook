#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "phonebook_bst.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
bst *findName(char lastName[], bst* root)
{
    bst* temp = root;
    while (temp != NULL) {
        int val = strcasecmp(lastName, temp->lastName);
        if(val == 0)
            return temp;
        temp = (val < 0) ? temp->left : temp->right;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}

bst *list_to_BST(entry *pHead)
{
    int listLen = 0;
    entry *cur = pHead;
    while(cur) {
        listLen++;
        cur = cur->pNext;
    }
    return buildbst(&pHead, listLen);
}

bst *buildbst(entry **pHead, int listLen)
{
    if(listLen <= 0)
        return NULL;

    bst *left = buildbst(pHead, listLen/2);
    bst *root = (bst *) malloc(sizeof(bst));
    strcpy(root->lastName, (*pHead)->lastName);
    root->left = left;
    *pHead = (*pHead)->pNext;
    root->right = buildbst(pHead, listLen-listLen/2-1);
    return root;
}

void releaseTree(bst *root)
{
    if(root == NULL) return;
    releaseTree(root->left);
    releaseTree(root->right);
    free(root);
}