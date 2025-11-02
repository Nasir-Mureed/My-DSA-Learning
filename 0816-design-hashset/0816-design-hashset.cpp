struct Node
{
    int key;
    Node* next;
    Node(int k):key(k),next(nullptr)
    {}
    Node(int k, Node* ptr):key(k),next(ptr)
    {}
};
class MyHashSet {
    Node* head;
public:
    MyHashSet():head(nullptr)
    {  }
    //O(N)
    void add(int key) 
    {
        if(!head)
        {
            head=new Node(key);
            return;
        }
        Node* curr=head;
        while(curr->next)
        {
            if(key==curr->key) //key exist 
                return ;
            curr=curr->next;
        }
        if(key!=curr->key)
        {
            curr->next=new Node(key);
        }

    }
    // O(N)
    void remove(int key) 
    {
        if(!head)//empty
        {
            return;
        }
        if(head->key==key)
        {
            head=head->next;
            return;
        }
        Node* curr=head;
        while(curr && curr->next)
        {
            if(key==curr->next->key) //key exist 
            {
                curr->next=curr->next->next;
            }
            curr=curr->next;
        }
        
        
    }
    
    //  O(N)
    bool contains(int key)
    {
        Node* curr=head;
        while(curr)
        {
            if(key==curr->key) //key exist 
                return true;
            curr=curr->next;
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */