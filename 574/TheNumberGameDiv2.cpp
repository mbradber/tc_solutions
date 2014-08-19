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
#include <climits>

using namespace std;

int Reverse(int op){
    int reverse = 0;
    
    for(; op != 0 ;)
    {
        reverse = reverse * 10;
        reverse = reverse + op % 10;
        op = op / 10;
    }
    
    return reverse;
}

int Shrink(int op){
    op /= 10;
    return op;
}

int Transform(int A, int B, bool flipped, int numMoves){
    if(B > A){
        if(Reverse(A) == B) return numMoves + 1;
    }
    
    if(A < B) return INT_MAX;
    if(A == B) return numMoves;
    
    int x = INT_MAX;
    if(!flipped)
        x = Transform(Reverse(A), B, true, numMoves + 1);
    int y = Transform(Shrink(A), B, false, numMoves + 1);
    
    return std::min(x, y);
}

class TheNumberGameDiv2 {
    public:
    int minimumMoves(int A, int B) {
        int minMoves = Transform(A, B, false, 0);
        if(minMoves == INT_MAX) minMoves = -1;
        return minMoves;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int A, int B, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    TheNumberGameDiv2 *instance = new TheNumberGameDiv2();
    int __result = instance->minimumMoves(A, B);
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
            int A = 25;
            int B = 5;
            int __expected = 2;
            return do_test(A, B, __expected, __no);
        }
        case 1: {
            int A = 5162;
            int B = 16;
            int __expected = 4;
            return do_test(A, B, __expected, __no);
        }
        case 2: {
            int A = 334;
            int B = 12;
            int __expected = -1;
            return do_test(A, B, __expected, __no);
        }
        case 3: {
            int A = 218181918;
            int B = 9181;
            int __expected = 6;
            return do_test(A, B, __expected, __no);
        }
        case 4: {
            int A = 9798147;
            int B = 79817;
            int __expected = -1;
            return do_test(A, B, __expected, __no);
        }

        // Your custom testcase goes here
        case 5: {
            int A = 95282784;
            int B = 5282784;
            int __expected = 3;
            return do_test(A, B, __expected, __no);
        }

        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "TheNumberGameDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408313895;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
