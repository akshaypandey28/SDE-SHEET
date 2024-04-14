#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/find-median-from-data-stream/ */
class MedianFinder {
    priority_queue<int> max_heap; //for lowest half
    priority_queue<int,vector<int>,greater<int> > min_heap; //for greatest half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() || num<=max_heap.top() ){
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }
        //rebalance the pq
        if(max_heap.size() > min_heap.size() +1){ // when max_heap size is greater than the size of min_heap by 
        //and diff is more than 1 
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size() ){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() { //even elements
        if( min_heap.size()==max_heap.size() ){
            return (min_heap.top() + max_heap.top() )/2.0;
        }
        else{ //odd elements
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(){
return 0;
}