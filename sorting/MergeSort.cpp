#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

// merge two sorted vectors into one sorted vector
vector<int> merge(vector<int> a, vector<int> b){
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);
    vector<int> merged(a.size() + b.size() - 2);
    
    int m = 0, n = 0;
    for(int i = 0; i < merged.size(); ++i){
        if(a[m] < b[n]){
            merged[i] = a[m++];
        }
        else{
            merged[i] = b[n++];
        }
    }
    
    return merged;
}

// iterative merge sort using a queue
vector<int> mergeSort(vector<int> a){
    deque< vector<int> > mergeQueue;
    for(int i = 0; i < a.size(); ++i){
        mergeQueue.push_back(vector<int>(1, a[i]));
    }
    
    while(mergeQueue.size() > 1){
        vector<int> merged = merge(mergeQueue[0], mergeQueue[1]);
        mergeQueue.erase(mergeQueue.begin(), mergeQueue.begin() + 2);
        mergeQueue.push_back(merged);
    }
    
    return mergeQueue.front();
}

int main(){
    int a[] = {6, 2, 9, 6, 5, 10, 1};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    v = mergeSort(v);
    
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}

