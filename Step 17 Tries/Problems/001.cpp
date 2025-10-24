// Implement Trie - II

// Problem Statement: Implement a Trie data structure that supports the following methods:
// Insert (word): To insert a string `word` in the Trie.
// Count Words Equal To (word): Return the count of occurrences of the string word in the Trie.
// Count Words Starting With (prefix): Return the count of words in the Trie that have the string “prefix” as a prefix.
// Erase (word): Delete one occurrence of the string word from the Trie.
// Note:
// The Erase(word) function is guaranteed to be called only when a word is present in the Trie.
// Release the memory associated with variables using dynamic memory allocation at the end of your solution.

// Algorithm / Intuition
// The Trie data structure is used to efficiently store and retrieve a set of strings.
// It organises strings such that common prefixes are shared among strings, making operations like searching for words with a given prefix efficient. Trie allows for quick retrieval of all strings with a given prefix, making it highly efficient for autocomplete and predictive text applications.
// The prefix tree specifically uses counters to keep track of the number of words ending with the current node and how many words contain the current node letter. A classical Trie accomplished this using the boolean flag to indicate that a word ends at this node.

// Each node in this Prefix Trie contains:
// An array of pointers to child nodes (26 slots, one for each lowercase English letter).
// Counters for tracking the number of words that end at the node (‘cntEndWith’) and the number of words that have the node as a prefix (‘cntPrefix’).

// Algorithm 1: To Insert a Node in the Prefix Trie:
// Step 1:Start at the root node.
// Step 2: Iterate over each character in the word. For each character:
// Check if a child node corresponding to that character exists.
// If not, create a new node for that character and link it to the current node.
// Increment the prefix count for each node.
// Step 3: Finally, increment the end count for the last node of the word.

// Algorithm 2: To Count the Number of Words Equal to the Given Word in the Trie
// Step 1:Start at the root node.
// Step 2: Iterate over each character in the word. For each character:
// Traverse down the Trie following the characters of the word.
// If any character is not found, return 0 (Indicating the word is not in the Trie).
// Step 3: Once all characters are found, return the end count of the node corresponding to the last character.

// Algorithm 3: To Count the Number of Words Starting with the Given Word in the Trie:
// Step 1:Start at the root node.
// Step 2: Iterate over each character in the word. For each character:
// Traverse down the Trie following the characters of the word.
// If any character is not found, return 0 (Indicating no words start with the given prefix).
// Step 3: Once all characters are found, return the prefix count of the node corresponding to the last character.

// Algorithm 4: To Erase the Given Word from the Trie
// Step 1:Start at the root node.
// Step 2: Iterate over each character in the word. For each character traverse down the Trie following the characters of the word and at each node:
// Decrement the prefix count.
// It is given that the given word to erase will always be found in the Trie.
// Step 3: Once the end of the word is reached, decrement the end count.

#include <bits/stdc++.h> 

using namespace std;

// Define a struct for
// each node in the trie
struct Node {
     // Array to store
     // links to child nodes
    Node* links[26];
     // Counter for number of
     // words that end at this node
    int cntEndWith = 0;
    // Counter for number of words
    // that have this node as a prefix
    int cntPrefix = 0; 

    // Function to check if the
    // node contains a specific key
    bool containsKey(char ch) {
        // Check if the link corresponding
        // to the character exists
        return (links[ch - 'a'] != NULL); 
    }

    // Function to get the child
    // node corresponding to a key
    Node* get(char ch) {
        // Return the link
        // corresponding to the character
        return links[ch - 'a']; 
    }

    // Function to insert a child
    // node with a specific key
    void put(char ch, Node* node) {
         // Set the link corresponding to
         // the character to the provided node
        links[ch - 'a'] = node;
    }

    // Function to increment the
    // count of words that end at this node
    void increaseEnd() {
        // Increment the counter
        cntEndWith++; 
    }

    // Function to increment the count of
    // words that have this node as a prefix
    void increasePrefix() {
         // Increment the counter
        cntPrefix++;
    }

    // Function to decrement the count
    // of words that end at this node
    void deleteEnd() {
        // Decrement the counter
        cntEndWith--; 
    }

    // Function to decrement the count of
    // words that have this node as a prefix
    void reducePrefix() {
        // Decrement the counter
        cntPrefix--; 
    }
};

// Define a class for the
// trie data structure
class Trie {
private:
    // Pointer to the
    // root node of the trie
    Node* root; 

public:
    // Constructor to initialize
    // the trie with an empty root node
    Trie() {
        // Create a new root node
        root = new Node(); 
    }

    // Function to insert
    // a word into the trie
    void insert(string word) {
        // Start from the root node
        Node* node = root; 
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
             // If the character is
             // not already in the trie
            if (!node->containsKey(word[i])) {
                // Create a new node
                // for the character
                node->put(word[i], new Node()); 
            }
             // Move to the child node
             // corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix
            // count for the node
            node->increasePrefix(); 
        }
        // Increment the end count
        // for the last node of the word
        node->increaseEnd(); 
    }

    // Function to count the number
    // of words equal to a given word
    int countWordsEqualTo(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
            } else {
                 // Return 0 if the
                 // character is not found
                return 0;
            }
        }
        // Return the count of
        // words ending at the node
        return node->cntEndWith; 
    }

    // Function to count the number of
    // words starting with a given prefix
    int countWordsStartingWith(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++) { 
            // If the character is found in the trie
            if (node->containsKey(word[i])) { 
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]); 
            } else {
                // Return 0 if the
                // character is not found
                return 0; 
            }
        }
        // Return the count of
        // words with the prefix
        return node->cntPrefix; 
    }

    // Function to erase a
    // word from the trie
    void erase(string word) {
         // Start from the root node
        Node* node = root;
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++) { 
            // If the character is
            // found in the trie
            if (node->containsKey(word[i])) { 
                 // Move to the child node
                 // corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix
                // count for the node
                node->reducePrefix(); 
            } else {
                // Return if the
                // character is not found
                return; 
            }
        }
        // Decrement the end count
        // for the last node of the word
        node->deleteEnd(); 
    }
};


int main() {
    Trie trie; 
    trie.insert("apple"); 
    trie.insert("app"); 
    cout << "Inserting strings 'apple', 'app' into Trie"<< endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    cout << "Erasing word 'app' from trie"<< endl;
    trie.erase("app"); 
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    return 0; 
}                    
                        
// Output
// Inserting strings 'apple', 'app' into Trie
// Count Words Equal to 'apple': 1
// Count Words Starting With 'app': 2
// Erasing word 'app' from trie
// Count Words Equal to 'apple': 1
// Count Words Starting With 'apple': 1

// Time Complexity: O(N) where N is the length of the word or prefix being processed.
// Each method (insertion, counting words equal to a given word, counting words starting with a prefix, and erasing a word) requires traversing the Trie for each character of the input word or prefix.
// Therefore, the time complexity is linear with respect to the length of the word or prefix being processed.
// Space Complexity: O(N) where N is the total characters across all words inserted into the Trie. The space complexity is proportional to the number of unique words inserted into the Trie and the average length of those words.