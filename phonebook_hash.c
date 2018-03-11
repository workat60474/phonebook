#include <stdlib.h>
#include <string.h>
#include "phonebook_hash.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */

unsigned int bkdr_hash(char *str)
{
    unsigned seed = 127;
    unsigned hash=0;
    while(*str)
        hash = hash*seed+(*str++);
    return hash % HASH_TABLE_SIZE;

}
void release_hash_table(hash_table* ht)
{
    for(int i=0; i<HASH_TABLE_SIZE; i++) {
        entry *e=ht->list[i];
        if(e!=NULL) {
            while(e->pNext) {
                entry *e_next=e->pNext;
                e->pNext = e_next->pNext;
                free(e_next);
            }
        } else {
            free(e);
        }
    }
    free(ht->list);
    free(ht);
}
hash_table *init()
{
    hash_table *new_ht= (hash_table *) malloc(sizeof(hash_table));
    new_ht->list = (entry **) malloc(sizeof(entry*)*HASH_TABLE_SIZE);
    for(int i=0; i<HASH_TABLE_SIZE; ++i) {
        new_ht->list[i]=NULL;
    }

    return new_ht;
}
entry *findName(char lastName[],hash_table *ht)
{

    unsigned hash_index = bkdr_hash(lastName);
    entry *e;
    for(e=ht->list[hash_index]; e; e=e->pNext) {
        if(strcasecmp(lastName,e->lastName)==0)
            return e;
    }
    return NULL;

}

void append(char lastName[], hash_table *ht)
{
    unsigned hash_index = bkdr_hash(lastName);
    entry *ent =  (entry *) malloc(sizeof(entry));
    strcpy(ent->lastName,lastName);
    ent->pNext = ht->list[hash_index];
    ht->list[hash_index]=ent;
}
