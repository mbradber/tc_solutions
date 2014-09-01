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

const int MOD = 1000000009;

class CharacterBoard2 {
    public:
    
    // Finds x raised to the y-th exponent modulo MOD
    int modPow(int b, int e){
        long long c = 1, ep = 1;
        
        while(ep++ <= e){
            c = (c * b) % MOD;
        }
        
        return (int)c;
    }
    
    vector<char> validLength(int n){
        vector<char> test(n, 0);
        for(int i = 0; i < mFragment.size(); ++i){
            for(int j = 0; j < mFragment[0].size(); ++j){
                char megaChar = mFragment[i][j];
                int megaI = mi0 + i;
                int megaJ = mj0 + j;
                int megaPos = mW * megaI + megaJ;
                int srcPos = megaPos % n; // position within the src string
                
                if(test[srcPos] == 0){
                    test[srcPos] = megaChar;
                }else{
                    if(test[srcPos] != megaChar){
                        test.resize(0);
                        return test;
                    }
                }
            }
        }
        
        return test;
    }
    
    int countGenerators(vector<string> fragment, int W, int i0, int j0) {
        mFragment = fragment;
        mW = W;
        mi0 = i0;
        mj0 = j0;
        
        long long totalPerms = 0;
        for(int i = 1; i <= W; ++i){
            vector<char> v = validLength(i);
            int count = 0;
            // valid size
            if(v.size() > 0){
                for(int j = 0; j < v.size(); ++j){
                    if(v[j] == 0) count++;
                }
                
                totalPerms = (totalPerms + modPow(26, count)) % MOD;
            }
        }
        
        return totalPerms;
    }
    
    vector<string> mFragment;
    int mW;
    int mi0;
    int mj0;
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> fragment, int W, int i0, int j0, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    CharacterBoard2 *instance = new CharacterBoard2();
    int __result = instance->countGenerators(fragment, W, i0, j0);
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
            string fragment[] = {
                "dea",
                "abc"
            };
            int W = 7;
            int i0 = 1;
            int j0 = 1;
            int __expected = 1;
            return do_test(to_vector(fragment), W, i0, j0, __expected, __no);
        }
        case 1: {
            string fragment[] = {
                "xyxxy"
            };
            int W = 6;
            int i0 = 1;
            int j0 = 0;
            int __expected = 28;
            return do_test(to_vector(fragment), W, i0, j0, __expected, __no);
        }
        case 2: {
            string fragment[] = {
                "gogogo",
                "jijiji",
                "rarara"
            };
            int W = 6;
            int i0 = 0;
            int j0 = 0;
            int __expected = 0;
            return do_test(to_vector(fragment), W, i0, j0, __expected, __no);
        }
        case 3: {
            string fragment[] = {
                "abababacac",
                "aaacacacbb",
                "ccabababab"
            };
            int W = 882;
            int i0 = 10;
            int j0 = 62;
            int __expected = 361706985;
            return do_test(to_vector(fragment), W, i0, j0, __expected, __no);
        }
        case 4: {
            string fragment[] = {
                "asjkffqw",
                "basjkffq",
                "qbasjkff",
                "qqbasjkf"
            };
            int W = 9031;
            int i0 = 9024;
            int j0 = 1959;
            int __expected = 173947456;
            return do_test(to_vector(fragment), W, i0, j0, __expected, __no);
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
    cout << "CharacterBoard2 (1024 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409023612;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1024 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
