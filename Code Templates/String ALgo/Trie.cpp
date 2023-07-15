//Easy AF Trie

//Make a new class TrieNode
class TrieNode{
public:
    int wordCount;
    TrieNode* children[26];

    //Constructor
    TrieNode() {
        wordCount = 0;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * node = root;
        for(auto &c : word) {
            int ind = c - 'a';
            if(node -> children[ind] == NULL) node -> children[ind] = new TrieNode();
            node = node -> children[ind];
        }
        node -> wordCount++;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto &c : word) {
            int ind = c - 'a';
            if(node -> children[ind] == NULL) return false;
            node = node -> children[ind];
        }
        return (node -> wordCount > 0);
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &c : prefix) {
            int ind = c - 'a';
            if(node -> children[ind] == NULL) return false;
            node = node -> children[ind];
        }
        return true;
    }
};