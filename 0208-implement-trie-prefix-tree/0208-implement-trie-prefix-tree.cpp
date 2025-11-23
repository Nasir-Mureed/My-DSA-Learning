struct Node
{
    char info;
    bool endOfWord;
    Node* child[26];
    Node(char val='d'): info(val),endOfWord(false)
    {
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr;
        }
    }
};
class Trie 
{
    Node* root;
public:
    Trie() 
    {
        root= new Node();
    }
    
    void insert(string word) 
    {
        int len= word.size();
        int i=0;
        Node* curr= root;
        while(i<len)
        {
            char ch=word[i];
            if(!curr->child[ch-97])
                curr->child[ch-97]=new Node(ch);
            curr=curr->child[ch-97];
            i++;
            
        }
        curr->endOfWord=true;
    }
    
    bool search(string word) 
    {
        int len= word.size();
        int i=0;
        Node* curr= root;
        while(i<len)
        {
            char ch= word[i];
            if(!curr->child[ch-97]) // if not exist
            {
                return false;
            }
            curr=curr->child[ch-97];
            i++;
        }
        return curr->endOfWord; // if word exist return true...        
    }
    
    bool startsWith(string word) 
    {
        int len= word.size();
        int i=0;
        Node* curr= root;
        while(i<len)
        {
            char ch= word[i];
            if(!curr->child[ch-97]) // if not exist
            {
                return false;
            }
            curr=curr->child[ch-97];
            i++;
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