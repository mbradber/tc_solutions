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
#include <map>

using namespace std;

class JumpFurther {
    public:
    int furthest(int N, int badStep) {
        int res = 0;
        for(int i = 0; i <= N; ++i){
            int sum = 0;
            for(int j = 1; j <= N; ++j){
                if(j == i) continue;
                sum += j;
                if(sum == badStep){
                    sum = 0;
                    break;
                }
            }
            
            res = max(res, sum);
        }
        
        return res;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int badStep, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    JumpFurther *instance = new JumpFurther();
    int __result = instance->furthest(N, badStep);
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
            int N = 2;
            int badStep = 2;
            int __expected = 3;
            return do_test(N, badStep, __expected, __no);
        }
        case 1: {
            int N = 2;
            int badStep = 1;
            int __expected = 2;
            return do_test(N, badStep, __expected, __no);
        }
        case 2: {
            int N = 3;
            int badStep = 3;
            int __expected = 5;
            return do_test(N, badStep, __expected, __no);
        }
        case 3: {
            int N = 1313;
            int badStep = 5858;
            int __expected = 862641;
            return do_test(N, badStep, __expected, __no);
        }
        case 4: {
            int N = 1;
            int badStep = 757065;
            int __expected = 1;
            return do_test(N, badStep, __expected, __no);
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
    cout << "JumpFurther (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413076142;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
