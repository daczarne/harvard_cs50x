// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;

// Hash table
node *table[N];

// Count the words in the dictionary
unsigned int word_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word
    int hash_table_position = hash(word);
    // Initialize a cursor set the pointer of the linked-list at that position
    node *cursor = table[hash_table_position];
    // Check if the word is in the list
    while (cursor != NULL)
    {
        // If the word difference is zero, return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    // If the end of the linked-list was reached, return false
    return false;
}

// Hashes word to a number
/*
    Trying out different options suggested in https://stackoverflow.com/questions/14409466/simple-hash-functions
    since my original solution of N = 26 was going to be kinda slow
*/
unsigned int hash(const char *word)
{
    int hash_table_position = 0;
    for (int counter = 0; word[counter] != '\0'; counter++)
    {
        hash_table_position = ((hash_table_position << 5) + hash_table_position) + word[counter];
    }
    return (hash_table_position % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Define a "word" buffer where to store the string that is been read from the dict
    char word[LENGTH + 1];
    // Open de dictonary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    // Scan a word form the dictionary
    bool continue_scanning = true;
    while (continue_scanning)
    {
        // Read the word into memroy
        fscanf(dict, "%s", word);
        // Create a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // Hash the word
        int hash_table_position = hash(word);
        // Copy the content of the "word" variable into the "word" field of the "n" variable
        strcpy(n->word, word);
        // Assign the node to the first position of the linked-list in the position determined by the hash function
        n->next = table[hash_table_position];
        table[hash_table_position] = n;
        // Augment number of words
        word_counter++;
        // Check if end of file has been reached
        if (fscanf(dict, "%s", word) == EOF)
        {
            // Close the dictionary
            fclose(dict);
            // Set flag to false to stop loop
            continue_scanning = false;
        }
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return the value in the word counter
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // For each linked-list
    for (int i = 0; i < N; i++)
    {
        // Define a cursor that will point to the next value that needs to be freed
        node *cursor = table[i];
        // While there are still elements to be freed
        while (cursor)
        {
            // Create tmp that points to the ndoe that will be freed
            node *tmp = cursor;
            // Point cursor to the next node
            cursor = cursor->next;
            // Free tmp
            free(tmp);
        }
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
