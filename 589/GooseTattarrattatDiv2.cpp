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

class GooseTattarrattatDiv2 {
    public:
    int getmin(string S) {
        int a[1000];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < S.length(); ++i){
            a[S[i]] = a[S[i]] + 1;
        }
        
        int maxCount = 0;
        char maxLetter;
        for(int i = 0; i < 1000; ++i){
            if(a[i] > maxCount){
                maxCount = a[i];
                maxLetter = i;
            }
        }
        
        return S.length() - maxCount;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string S, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GooseTattarrattatDiv2 *instance = new GooseTattarrattatDiv2();
    int __result = instance->getmin(S);
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
            string S = "geese";
            int __expected = 2;
            return do_test(S, __expected, __no);
        }
        case 1: {
            string S = "tattarrattat";
            int __expected = 6;
            return do_test(S, __expected, __no);
        }
        case 2: {
            string S = "www";
            int __expected = 0;
            return do_test(S, __expected, __no);
        }
        case 3: {
            string S = "topcoder";
            int __expected = 6;
            return do_test(S, __expected, __no);
        }
        case 4: {
            string S = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
            int __expected = 43;
            return do_test(S, __expected, __no);
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
    cout << "GooseTattarrattatDiv2 (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413695532;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
