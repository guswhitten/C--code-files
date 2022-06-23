/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to 
efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.

void insert(String word) Inserts the string word into the trie.

boolean search(String word) Returns true if the string word is in the 
trie (i.e., was inserted before), and false otherwise.

boolean startsWith(String prefix) Returns true if there is a previously 
inserted string word that has the prefix prefix, and false otherwise.
*/

class TrieNode {
public:
    TrieNode* children[26]; // treats the letters as integers
    bool isEnd;
    TrieNode() {
        isEnd=false;
        for (int i = 0; i<26; i++) {
            children[i]=NULL;
        }
    }
};



class Trie {
public:
    // initialize trie object
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.length(); i++) {
            int letter = word[i] - 'a';             //convert first letter of word to int
            if (temp->children[letter]==NULL) {     //this letter hasn't been seen yet
                //TrieNode automatically creates the 26 children nodes (pointing to NULL)
                temp->children[letter] = new TrieNode();    
            }
            temp = temp->children[letter];          //new current node is the added letter
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for (int i = 0; i<word.length(); i++) {
            int letter = word[i] - 'a';             //convert first letter of word to int
            if (temp->children[letter] == NULL) {
                return false;
            }
            else {
                temp = temp->children[letter];          //new current node is the added letter
            }
        }
        return temp->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (int i = 0; i < prefix.length(); i++) {
            int letter = prefix[i] - 'a';
            if (temp->children[letter] == NULL) {
                return false;
            }
            else {
                temp = temp->children[letter];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


/*
Runtime: 113 ms
Memory: 44.8 MB
*/
