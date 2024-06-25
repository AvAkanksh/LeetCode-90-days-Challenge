static auto fastio = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key, int _val){
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        fastio();
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    void deleteNode(node* dnode){
        // cout<<dnode->key<<" "<<dnode->val<<endl;
        node* delprev = dnode->prev;
        node* delnext = dnode->next;
        // cout<<delprev->key<<" "<<delprev->val<<endl;
        delprev->next = delnext;
        delnext->prev = delprev;
        
        delete(dnode);
    }
    
    void insertNode(node* inode){
        inode->next = head->next;
        inode->next->prev = inode;
        inode->prev = head;
        head->next = inode;
    }
    
    void printAllKeyValues(){
        node* curr = head;
        while(curr!=NULL){
            cout<<curr->key<<" "<<curr->val<<endl;
            curr = curr->next;
        }
        cout<<"done printing all the key value pairs"<<endl;
    }
    
    void printAllKeyValuesHashMap(){
        cout<<"started printing from hashmap"<<endl;
        for(auto x : mp){
            cout<<x.first<<" "<<x.second->key<<" "<<x.second->val<<endl;
        }
        cout<<"done printing from hashmap"<<endl;
    }
    
    int get(int key) {
        // cout<<"get call for key : "<<key<<endl;
        // printAllKeyValues();
        // printAllKeyValuesHashMap();
        if(mp.find(key)!=mp.end()){
            node* foundNode = mp[key];
            int ans = foundNode->val;
            node* temp = new node(foundNode->key,foundNode->val);
            deleteNode(mp[key]);
            insertNode(temp);
            mp[key] = temp;
            // printAllKeyValues();
            return ans;
        }
        // printAllKeyValues();
        return -1;
        
    }
    
    void put(int key, int value) {
        // cout<<"put call"<<endl;
        // printAllKeyValues();
        
        if(mp.find(key)==mp.end() and mp.size()>=cap){
            int key = tail->prev->key;
            deleteNode(tail->prev);
            mp.erase(key);
        }
        node* temp = new node(key,value);
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
        }
        insertNode(temp);
        mp[key] = temp;
        // printAllKeyValues();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */