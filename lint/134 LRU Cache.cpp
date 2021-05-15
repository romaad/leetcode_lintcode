class LRUCache {

private:
    class Node {
        public:
        Node * next;
        Node * prev;
        int val;
        int key;
        
        Node (int key, int val) {
            this->key = key;
            this->val = val;
        }

        Node (int key, int val, Node * next, Node * prev) : 
            key(key), val(val), next(next), prev(prev) {

            }

    };
    int cnt = 0;
    unordered_map<int, Node *> mp;
    Node * tail = new Node(0, 0);
    Node * head = tail;
    int cap = 0;
    void remove(Node * n) {
        Node * prev = n->prev;
        n->prev->next = n->next;
        n->next->prev = prev;
    }
    void pop(Node * n) {
        n->prev = head;
        head->next = n;
        head = n;
        n->next = NULL;
    }
public:
    /*
    * @param capacity: An integer

    */LRUCache(int capacity) : cap(capacity) , cnt(0)  {
        // do intialization if necessary
        tail = new Node(0,0);
        head = tail;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // cout<<"get"<<key<<endl;
        // write your code here
        if(mp.find(key) != mp.end()) {
            Node * n = mp[key];
            if(n != head) {
                remove(n);
                pop(n);
            }
            return n->val;
        }
        return -1;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // cout<<"set"<<key<<":"<<value<<endl;

        // write your code here
        Node * n;
        if(mp.find(key) != mp.end()) {
            n = mp[key];
            n->val = value;
            if(n != head) {
                remove(n);
            }
        } else {
            n = new Node(key, value);
            mp[key] = n;
            cnt++;
        }
        if(n != head)
            pop(n);//careful for this case or safeguard the poping in the function itself, cauased me 30 mins of debugging
        if(cnt > cap) {
            Node * rem = tail->next;
            remove(rem);
            mp.erase(rem->key);
            // delete rem; lol map auto destructs
            cnt--;
        }

    }
};
