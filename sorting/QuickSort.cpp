#include <iostream>

using namespace std;

void swap(int a[], int c, int d){
    if(c == d) return;
    
    int t = a[c];
    a[c] = a[d];
    a[d] = t;
}

void quicksort(int a[], int b, int e){
    if(e - b <= 0) return;
    
    int pivotIdx = b;
    int pivotValue = a[pivotIdx];
    int swapIdx = e;
    
    // move all values greater than pivot to the right
    for(int i = b + 1; i <= e; ++i){
        while(a[swapIdx] >= pivotValue && swapIdx >= i){
            swapIdx--;
        }
        
        if(a[i] >= pivotValue && swapIdx > i){
            swap(a, i, swapIdx);
        }
    }
    
    // move pivot value into place
    swap(a, pivotIdx, swapIdx);
    
    quicksort(a, swapIdx + 1, e);
    quicksort(a, b, swapIdx - 1);
}

int main(){
    int a[] = {7, 6, 5, 4, 3, 2, 1};
    quicksort(a, 0, 6);
    
    for(int i = 0; i < 7; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}