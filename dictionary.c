// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2048;
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_res = hash(word);
    node *ptr = table[hash_res];
    while (ptr != 0)
    {
        if (strcasecmp(word, ptr->word) == 0)cd
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int total = 0;
    int i;
    // TODO: Improve this hash function
    for (i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = calloc(1, sizeof(node));
    }

    FILE *input = fopen(dictionary, "r");

    char buffer[LENGTH + 1];
    while (fscanf(input, "%s", buffer) != EOF)
    {
        if (check(buffer))
        {
            continue;
        }

        node *n = calloc(1, sizeof(node));
        strcpy(n->word, buffer);
        n->next = table[hash(buffer)];
        table[hash(buffer)] = n;
        word_count++;
    }
    fclose(input);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N ; i++)
    {
        node *ptr = table[i];
        while (ptr != 0)
        {
            node *tmp = ptr;
            ptr = ptr-> next;
            free(tmp);
        }
    }
    return true;
}
