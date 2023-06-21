/*
Trie can be used to implement dictionary
Search for word in O(len(word))
Finding prefix strings
ordered, structured and clean data structure
*/
struct Trienode {
    char data;
    Trienode* child[26]; //array of 26 pointers pointing to character
    int wordend; //These many number of nodes are present in our dictionary which are ending at this node
};

Trienode nodepool[100000]; //100k trie nodes
Trienode* root;
int poolcount;

void init() {
    poolcount = 0;
    root = &nodepool[poolcount++];
    root -> data = '/';
    for()
}