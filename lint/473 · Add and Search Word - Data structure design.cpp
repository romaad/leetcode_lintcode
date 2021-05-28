class WordDictionary {
private:
    class node {
        public:
        unordered_map<char, node*> next;
        bool isWord;
        node (unordered_map<char, node*> n, bool isWord) {
            this->next =n;
            this->isWord = isWord;
        }
    };
    node * head = new node({}, false);
public:
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        // write your code here
        // yaaay triiiiiieees
        node * cur = head;
        for(char c : word) {
            if(cur->next.find(c) == cur->next.end()) {
                cur->next[c] = new node({}, false);
            }
            cur = cur->next[c];
        }
        cur->isWord = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        return search(word, head);
    }
    bool search(string word, node* start) {
        // write your code here
        node * cur = start;
        for(int i = 0 ; i < word.size(); i++) {
            char c= word[i];
            if(cur->next.find(c) == cur->next.end()) {
                if(c == '.') {
                    for(auto p : cur->next) {
                        if(search(word.substr(i+1), p.second)){
                            return true;
                        }
                    }
                }
                return false;
            } else {
                cur = cur->next[c];
            }
            
        }
        return cur->isWord;
    }
};
