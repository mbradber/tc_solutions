#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// merge two sorted vectors into one sorted vector
vector<int> vectorMerge(vector<int> a, vector<int> b){
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
vector<int> mergeSortIterative(vector<int> a){
    // initialize merge queue with single element vectors
    deque< vector<int> > mergeQueue;
    for(int i = 0; i < a.size(); ++i){
        mergeQueue.push_back(vector<int>(1, a[i]));
    }
    
    while(mergeQueue.size() > 1){
        // grab the front two vectors, merge them, then push the new vector to the back
        vector<int> merged = vectorMerge(mergeQueue[0], mergeQueue[1]);
        mergeQueue.erase(mergeQueue.begin(), mergeQueue.begin() + 2);
        mergeQueue.push_back(merged);
    }
    
    // return single sorted list
    return mergeQueue.front();
}

void mergeClassic(int A[], int p, int q, int r){
    int* a = new int[q - p + 1 + 1];
    a[q - p + 1] = INT_MAX;
    int* b = new int[r - q + 1];
    b[r - q] = INT_MAX;
    
    for(int i = p, j = 0; i <= q; ++i, ++j){
        a[j] = A[i];
    }
    for(int i = q + 1, j = 0; i <= r; ++i, ++j){
        b[j] = A[i];
    }
    
    int m = 0, n = 0;
    for(int i = p; i <= r; ++i){
        if(a[m] < b[n]){
            A[i] = a[m++];
        }
        else{
            A[i] = b[n++];
        }
    }
    
    delete[] a;
    delete[] b;
}

void mergeSortClassic(int A[], int p, int r){
    if(p - r == 0) return;
    
    int q = (p + r) / 2;
    
    mergeSortClassic(A, p, q);
    mergeSortClassic(A, q + 1, r);
    mergeClassic(A, p, q, r);
}

int main(){
    // iterative merge sort
    int a[] = {6, 2, 9, 6, 5, 10, 1};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    
    v = mergeSortIterative(v);
    
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    // recursive merge sort
    mergeSortClassic(a, 0, 6);
    
    for(int i = 0; i < 7; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}

