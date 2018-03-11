#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 40000

#define HASH 1

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];

    struct __PHONE_BOOK_ENTRY *pNext;
} entry;


typedef struct __PHONE_BOOK_HASHTABLE {
    entry **list;
} hash_table;

void release_hash_table(hash_table *ht);
unsigned bkdr_hash(char *str);
hash_table *init();
entry *findName(char lastName[],hash_table *ht);
void append(char lastName[], hash_table *ht);

#endif
