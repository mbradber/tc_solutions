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
    
    int swapIdx = b - 1;
    for(int i = b; i <= e - 1; ++i){
        if(a[i] <= a[e]){
            ++swapIdx;
            swap(a, swapIdx, i);
        }
    }
    
    swap(a, swapIdx + 1, e);
    
    quicksort(a, swapIdx + 2, e);
    quicksort(a, b, swapIdx);
}

int main(){
    int a[] = {2, 8 , 7, 1, 3, 5, 6, 4};
    quicksort(a, 0, 7);
    
    for(int i = 0; i < 8; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}