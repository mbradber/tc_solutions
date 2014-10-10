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

#define MOD 1000000009

long long factorialMod(int val, int limit){
    long long res = 1;
    for(int i = 0; i < limit; ++i){
        res *= val--;
        res %= MOD;
    }
    
    return res;
}

long dp[27][1001];

long op(int a, int L){
    long& res = dp[a][L];
    
    if(res == -1){
        if(L == 0){
            res = a == 0;
        }else if(a == 0){
            res = 0;
        }else{
            res = 0;
            for(int i = 1; i <= L; ++i){
                res += (a * op(a - 1, L - i));
                res %= MOD;
            }
        }
    }
    
    return res;
}

class StringWeightDiv2 {
    public:
    int countMinimums(int L) {
        if(L <= 26){
            return factorialMod(26, L);
        }
        
        memset(dp, -1, sizeof(dp));
 
        return op(26, L);
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int L, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    StringWeightDiv2 *instance = new StringWeightDiv2();
    int __result = instance->countMinimums(L);
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
            int L = 1;
            int __expected = 26;
            return do_test(L, __expected, __no);
        }
        case 1: {
            int L = 2;
            int __expected = 650;
            return do_test(L, __expected, __no);
        }
        case 2: {
            int L = 50;
            int __expected = 488801539;
            return do_test(L, __expected, __no);
        }

        // Your custom testcase goes here
        case 3:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "StringWeightDiv2 (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 3; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1412828316;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
