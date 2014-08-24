#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Egalitarianism3Easy {
    public:
    int maxCities(int n, vector<int> a, vector<int> b, vector<int> len) {
        if(n == 1) return 1;
        
        vector< vector<int> > d(n, vector<int>(n, 50000000));
        for(int i = 0; i < a.size(); ++i){
            d[ a[i]-1 ][ b[i]-1 ] = len[i];
            d[ b[i]-1 ][ a[i]-1 ] = len[i];
        }
        
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        
        int np = 1 << n;
        int maxK = 0;
        for(int i = 0; i <= np; ++i){
            vector<int> idxs;
            for(int j = 0; j <= n; ++j){
                if(1 << j & i){
                    idxs.push_back(j);
                }
            }
            
            set<int> dPool;
            for(int m = 0; m < idxs.size(); ++m){
                for(int n = 0; n < idxs.size(); ++n){
                    if(m == n) continue;
                    dPool.insert(d[idxs[m]][idxs[n]]);
                }
            }
            
            if(dPool.size() == 1){
                if(idxs.size() > maxK)
                    maxK = idxs.size();
            }
        }
        
        return maxK;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, vector<int> a, vector<int> b, vector<int> len, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Egalitarianism3Easy *instance = new Egalitarianism3Easy();
    int __result = instance->maxCities(n, a, b, len);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int n = 4;
            int a[] = {
                1, 1, 1
            };
            int b[] = {
                2, 3, 4
            };
            int len[] = {
                1, 1, 1
            };
            int __expected = 3;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 1: {
            int n = 6;
            int a[] = {
                1, 2, 3, 2, 3
            };
            int b[] = {
                2, 3, 4, 5, 6
            };
            int len[] = {
                2, 1, 3, 2, 3
            };
            int __expected = 3;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 2: {
            int n = 10;
            int a[] = {
                1, 1, 1, 1, 1, 1, 1, 1, 1
            };
            int b[] = {
                2, 3, 4, 5, 6, 7, 8, 9, 10
            };
            int len[] = {
                1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000
            };
            int __expected = 9;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 3: {
            int n = 2;
            int a[] = {
                1
            };
            int b[] = {
                2
            };
            int len[] = {
                3
            };
            int __expected = 2;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }
        case 4: {
            int n = 1;
            int a[] = {
                
            };
            int b[] = {
                
            };
            int len[] = {
                
            };
            int __expected = 1;
            return do_test(n, to_vector(a), to_vector(b), to_vector(len), __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "Egalitarianism3Easy (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408669956;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
