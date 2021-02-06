// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Count the words in the dictionary
unsigned int dict_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    tolower(node.word[0]) - 97;
    // TODO
    return 0;
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
        node n * = malloc(sizeof(node));
        if (node == NULL)
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
        dict_counter++;
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
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
