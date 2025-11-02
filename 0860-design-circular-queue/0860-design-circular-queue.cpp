class MyCircularQueue {
    int* data;
    int f;
    int r;
    int noOfEle;
    int cap;
public:
    MyCircularQueue(int k):f(0),r(0),noOfEle(0),cap(k) 
    {
        data=new int[k];
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) return false;
        data[r]=value;
        r++;
        if(r>=cap) r=r%cap;  // rounding
        noOfEle++;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty()) return false;
        f++;
        if(f>=cap) f=0;
        noOfEle--;
        return true;        
    }
    
    int Front() 
    {
        if(isEmpty()) return -1;
        return data[f];
        
    }
    
    int Rear() 
    {
        if(isEmpty()) return -1;
        if(r-1<0) return data[cap-1];
        else
            return data[r-1];

        
    }
    
    bool isEmpty() 
    {
        if(noOfEle==0) return true;
        return false;
        
    }
    
    bool isFull() 
    {
        if(noOfEle>=cap) return true;
        return false;        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */