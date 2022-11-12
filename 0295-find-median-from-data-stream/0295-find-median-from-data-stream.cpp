class MedianFinder {
    priority_queue<int> sh;
    priority_queue<int,vector<int> , greater<int> > lh;
    bool evenCheck = true;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        evenCheck = !evenCheck;
        if(evenCheck){
            lh.push(num);
            sh.push(lh.top());
            lh.pop();
        }
        else{
            sh.push(num);
            lh.push(sh.top());
            sh.pop();
        }
        
    }
    
    double findMedian() {
        int sh_size = sh.size();
        int lh_size = lh.size();
        if(lh_size==sh_size){
            double ans = (sh.top() + lh.top())/2.0;
            return ans;
        }
        else{
            if(lh_size>sh_size){
                return lh.top();
            }
            else{
                return sh.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */