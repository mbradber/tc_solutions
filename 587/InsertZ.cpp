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

class InsertZ {
    public:
    string canTransform(string init, string goal) {
        goal.erase(remove(goal.begin(), goal.end(), 'z'), goal.end());
        if(init == goal) return "Yes";
        return "No";
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string init, string goal, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    InsertZ *instance = new InsertZ();
    string __result = instance->canTransform(init, goal);
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
            string init = "fox";
            string goal = "fozx";
            string __expected = "Yes";
            return do_test(init, goal, __expected, __no);
        }
        case 1: {
            string init = "fox";
            string goal = "zfzoxzz";
            string __expected = "Yes";
            return do_test(init, goal, __expected, __no);
        }
        case 2: {
            string init = "foon";
            string goal = "foon";
            string __expected = "Yes";
            return do_test(init, goal, __expected, __no);
        }
        case 3: {
            string init = "topcoder";
            string goal = "zopzoder";
            string __expected = "No";
            return do_test(init, goal, __expected, __no);
        }
        case 4: {
            string init = "aaaaaaaaaa";
            string goal = "a";
            string __expected = "No";
            return do_test(init, goal, __expected, __no);
        }
        case 5: {
            string init = "mvixrdnrpxowkasufnvxaq";
            string goal = "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq";
            string __expected = "Yes";
            return do_test(init, goal, __expected, __no);
        }
        case 6: {
            string init = "opdlfmvuicjsierjowdvnx";
            string goal = "zzopzdlfmvzuicjzzsizzeijzowvznxzz";
            string __expected = "No";
            return do_test(init, goal, __expected, __no);
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
    cout << "InsertZ (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413075180;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
