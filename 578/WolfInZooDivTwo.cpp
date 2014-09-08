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

using namespace std;

long long dp[350][350];
long long MOD = 1000000007;

class WolfInZooDivTwo {
    public:
    
    long long genSets(int at, int last){
        if(dp[at][last] != -1){
            return dp[at][last];
        }
        
        if(at > mN){
            return 1;
        }
        
        long long ret = 0;
        bool zeroValid = true;
        
        // check if adding a 0 goes against any of the ranges
        for(int i = 0; i < mR.size(); ++i){
            // if we've reached the end of a range, check that the last 1 is >= to its left index
            if(mR[i] == at-1){
                // mark as invalid set if the last 1 is not within the range
                if(last-1 < mL[i]){
                    zeroValid = false;
                }
            }
        }
        
        if(zeroValid){
            ret += (genSets(at + 1, last));
        }
        
        ret += (genSets(at + 1, at));
        ret %= MOD;
        
        dp[at][last] = ret;
        return dp[at][last];
    }
    
    int count(int N, vector<string> L, vector<string> R) {
        string sL = "", sR = "";
        mN = N;
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < L.size(); ++i){
            sL += L[i];
            sR += R[i];
        }
        
        stringstream ssL(sL);
        stringstream ssR(sR);
        
        int a, b;
        while(ssL >> a){
            ssR >> b;
            mL.push_back(a);
            mR.push_back(b);
        }
        
        long long setCount = genSets(1, 0);
        return setCount;
    }
    
    vector<int> mL;
    vector<int> mR;
    int mN;
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<string> L, vector<string> R, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    WolfInZooDivTwo *instance = new WolfInZooDivTwo();
    int __result = instance->count(N, L, R);
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
            int N = 5;
            string L[] = {
                "0 1"
            };
            string R[] = {
                "2 4"
            };
            int __expected = 27;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }
        case 1: {
            int N = 10;
            string L[] = {
                "0 4 2 7"
            };
            string R[] = {
                "3 9 5 9"
            };
            int __expected = 798;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }
        case 2: {
            int N = 3;
            string L[] = {
                "1"
            };
            string R[] = {
                "2"
            };
            int __expected = 6;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }
        case 3: {
            int N = 100;
            string L[] = {
                "0 2 2 7 10 1",
                "3 16 22 30 33 38",
                " 42 44 49 51 57 60 62",
                " 65 69 72 74 77 7",
                "8 81 84 88 91 93 96"
            };
            string R[] = {
                "41 5 13 22 12 13 ",
                "33 41 80 47 40 ",
                "4",
                "8 96 57 66 ",
                "80 60 71 79",
                " 70 77 ",
                "99",
                " 83 85 93 88 89 97 97 98"
            };
            int __expected = 250671525;
            return do_test(N, to_vector(L), to_vector(R), __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "WolfInZooDivTwo (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1410115944;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
