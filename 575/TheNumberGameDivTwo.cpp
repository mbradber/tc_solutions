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

vector<int> findFactors(int n){
    vector<int> factors;
    for(int i = 2; i <= n / 2; ++i){
        if(n % i == 0){
            factors.push_back(i);
        }
    }
    
    return factors;
}

class TheNumberGameDivTwo {
    public:
    string find(int n) {
        vector<bool> results(n + 1);
        int minBase = min(n, 3);
        for(int i = 0; i <= minBase; ++i){
            results[i] = false;
        }
        
        if(n > 3){
            for(int i = 4; i <= n; ++i){
                vector<int> factors = findFactors(i);
                for(int j = 0; j < factors.size(); ++j){
                    if(results[ i - factors[j] ] == false){
                        results[i] = true;
                        break;
                    }
                }
            }
        }
        
        if(results[n]) return "John";
        return "Brus";
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    TheNumberGameDivTwo *instance = new TheNumberGameDivTwo();
    string __result = instance->find(n);
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
            int n = 6;
            string __expected = "John";
            return do_test(n, __expected, __no);
        }
        case 1: {
            int n = 2;
            string __expected = "Brus";
            return do_test(n, __expected, __no);
        }
        case 2: {
            int n = 747;
            string __expected = "Brus";
            return do_test(n, __expected, __no);
        }
        case 3: {
            int n = 128;
            string __expected = "Brus";
            return do_test(n, __expected, __no);
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
    cout << "TheNumberGameDivTwo (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408844196;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
