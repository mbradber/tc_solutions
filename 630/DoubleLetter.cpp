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

string cutString(string s){
    if(s.length() == 0) return s;
    for(int i = 0; i < s.length() - 1; ++i){
        if(s[i] == s[i + 1]){
            s.erase(i, 2);
            return s;
        }
    }
    
    return s;
}

class DoubleLetter {
    public:
    string ableToSolve(string S) {
        
        int count = S.length();
        while(true){
            S = cutString(S);
            if(S.length() == count) break;
            count = S.length();
        }
        
        if(S.length() > 0) return "Impossible";
        return "Possible";
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string S, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    DoubleLetter *instance = new DoubleLetter();
    string __result = instance->ableToSolve(S);
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
            string S = "aabccb";
            string __expected = "Possible";
            return do_test(S, __expected, __no);
        }
        case 1: {
            string S = "aabccbb";
            string __expected = "Impossible";
            return do_test(S, __expected, __no);
        }
        case 2: {
            string S = "abcddcba";
            string __expected = "Possible";
            return do_test(S, __expected, __no);
        }
        case 3: {
            string S = "abab";
            string __expected = "Impossible";
            return do_test(S, __expected, __no);
        }
        case 4: {
            string S = "aaaaaaaaaa";
            string __expected = "Possible";
            return do_test(S, __expected, __no);
        }
        case 5: {
            string S = "aababbabbaba";
            string __expected = "Impossible";
            return do_test(S, __expected, __no);
        }
        case 6: {
            string S = "zzxzxxzxxzzx";
            string __expected = "Possible";
            return do_test(S, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "DoubleLetter (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408669319;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
