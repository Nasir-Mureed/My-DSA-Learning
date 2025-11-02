class MyCircularDeque 
{
    int* data;
    int f;
    int r;
    int noOfEle;
    int cap;
    int getIndexRear()
    {
        if(r-1<0)
            return cap+(r-1);
        return r-1;
    }
public:
    MyCircularDeque(int k):f(0),r(0),noOfEle(0),cap(k) 
    {
        data= new int[k];        
    }
    
    bool insertFront(int value) 
    {
        if(noOfEle>=cap) return false;
        f--;
        if(f<0) f=cap-1;
        data[f]=value;
        noOfEle++;
        return true;
    }
    
    bool insertLast(int value) 
    {
       if(noOfEle>=cap) return false;
        data[r%cap]=value;
        r++;
        if(r>=cap) r=r%cap;
        noOfEle++;
        return true;
    }
    
    bool deleteFront() 
    {
        if(noOfEle==0) return false;
        f++;
        if(f>=cap) f=f%cap;
        noOfEle--;
        return true;        
    }
    
    bool deleteLast() 
    {
        if(noOfEle==0) return false;
        r--;
        if(r<0) r=cap-1;
        noOfEle--;
        return true;
        
    }
    
    int getFront() 
    {
        if(noOfEle==0) return -1;
        return data[f];
        
    }
    
    int getRear() 
    {
        if(noOfEle==0) return -1;
        int ind=getIndexRear();
    
        return data[ind];
    }
    
    bool isEmpty() 
    {
        if(noOfEle==0) return true;
        return false;
    }
    
    bool isFull() 
    {
        if(noOfEle==cap) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */