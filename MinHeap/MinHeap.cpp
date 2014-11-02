#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
public:
    
    MinHeap(){
        mHeap.push_back(0);
    }
    
    void Insert(int a){
        mHeap.push_back(a);
        
        int curr = mHeap.size() - 1;
        int p = curr / 2;
        while(mHeap[curr] < mHeap[p] && p >= 1){
            swap(mHeap[curr], mHeap[p]);
            curr = p;
            p = curr / 2;
        }
    }
    
    int GetMin(){
        int res = mHeap[1];
        swap(mHeap[1], mHeap[mHeap.size() - 1]);
        mHeap.pop_back();
        Heapify(1);
        
        return res;
    }
    
    void Heapify(int a){
        int smallest = a;
        int left = a * 2;
        int right = a * 2 + 1;
        if(left < mHeap.size() && mHeap[left] < mHeap[smallest]){
            smallest = left;
        }
        if(right < mHeap.size() && mHeap[right] < mHeap[smallest]){
            smallest = right;
        }
        
        if(smallest != a){
            swap(mHeap[a], mHeap[smallest]);
            Heapify(smallest);
        }
    }
    
    void PrintHeap(){
        for(int i = 1; i < mHeap.size(); ++i){
            cout << mHeap[i] << " ";
        }
        cout << endl;
    }
    
private:
    vector<int> mHeap;
};

int main(){
    MinHeap mh;
    mh.Insert(2);
    mh.Insert(3);
    mh.Insert(5);
    mh.Insert(10);
    mh.Insert(1);
    mh.PrintHeap();
    
    // heapsort
    for(int i = 0; i < 5; ++i){
        cout << mh.GetMin() << " ";
    }
    
    return 0;
}