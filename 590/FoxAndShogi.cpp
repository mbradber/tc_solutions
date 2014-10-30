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

#define MOD 1000000007

using namespace std;

void moves(string s, set<string>& totalMoveSet){
    vector<string> moveList;
    for(int i = 0; i < s.length(); ++i){
        string st = s;
        if(s[i] == 'D'){
            if(i < s.length() - 1){
                if(s[i+1] == '.'){
                    swap(st[i], st[i+1]);
                    moveList.push_back(st);
                }
            }
        }else if(s[i] == 'U'){
            if(i > 0){
                if(s[i-1] == '.'){
                    swap(st[i], st[i-1]);
                    moveList.push_back(st);
                }
            }
        }
    }

    for(int i = 0; i < moveList.size(); ++i){
        totalMoveSet.insert(moveList[i]);
        moves(moveList[i], totalMoveSet);
    }
}

class FoxAndShogi {
    public:
    int differentOutcomes(vector<string> board) {
        long long res = 1;
        
        for(int i = 0; i < board.size(); ++i){
            string s = "";
            for(int j = 0; j < board.size(); ++j){
                s += board[j][i];
            }
            
            set<string> moveSet;
            moveSet.insert(s);
            moves(s, moveSet);
            res *= (long long)moveSet.size();
            res %= MOD;
        }
        
        
        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FoxAndShogi *instance = new FoxAndShogi();
    int __result = instance->differentOutcomes(board);
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
            string board[] = {"UUUUUU.UDUUUUU", ".DU..D.U..DD.D", "........U.....", ".UD.D.UD.DDDDD", "........D..DD.", "UDDDUDDDD.DDDU", "DD.UD.UD.UUUD.", "U.U....DU.DDD.", "D.U.DDDDDDUDDD", "U...U.UUUU.U.U", "U.UU...U.UU.UU", ".DDDDUU.UUD.DD", ".D.DD...D..U.D", "...UUUUUUDUUUU"};
            int __expected = 809225782;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                ".D.",
                "...",
                ".U."
            };
            int __expected = 3;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "DDDDD",
                ".....",
                ".....",
                ".....",
                "....."
            };
            int __expected = 3125;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "DDDDD",
                "U....",
                ".U...",
                "..U..",
                "...U."
            };
            int __expected = 900;
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                "....D..",
                "U....D.",
                "D.D.U.D",
                "U.U...D",
                "....U..",
                "D.U...D",
                "U.U...."
            };
            int __expected = 2268;
            return do_test(to_vector(board), __expected, __no);
        }
        case 5: {
            string board[] = {
                "DDDDDDDDDD",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                "..........",
                ".........."
            };
            int __expected = 999999937;
            return do_test(to_vector(board), __expected, __no);
        }
        case 6: {
            string board[] = {
                "..",
                ".."
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
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
    cout << "FoxAndShogi (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1414348700;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
