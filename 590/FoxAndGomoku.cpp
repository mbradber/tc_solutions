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

vector<string> gBoard;

bool fiveFound(int i, int j, int dir, int count){
    if(count == 4) return true;
    
    if(dir == 0){ // up
        i--;
    }
    else if(dir == 3){ // right
        j++;
    }
    else if(dir == 4){ // up right
        i--;
        j++;
    }
    else if(dir == 6){ // up left
        j--;
        i--;
    }
    
    if(i < 0 || j < 0 || i >= gBoard.size() || j >= gBoard[0].length()){
        return false;
    }
    if(gBoard[i][j] == 'o'){
        return fiveFound(i, j, dir, count + 1);
    }else{
        return false;
    }
}

class FoxAndGomoku {
    public:
    string win(vector<string> board) {
        gBoard = board;
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 'o'){
                    bool up = fiveFound(i, j, 0, 0); // 0 up
                    bool right = fiveFound(i, j, 3, 0);
                    bool upright = fiveFound(i, j, 4, 0);
                    bool upleft = fiveFound(i, j, 6, 0);
                    
                    if(up || right || upright || upleft){
                        return "found";
                    }
                }
            }
        }
        
        return "not found";
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FoxAndGomoku *instance = new FoxAndGomoku();
    string __result = instance->win(board);
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
            string board[] = {
                "....o.",
                "...o..",
                "..o...",
                ".o....",
                "o.....",
                "......"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "oooo.",
                ".oooo",
                "oooo.",
                ".oooo",
                "....."
            };
            string __expected = "not found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "oooo.",
                ".oooo",
                "oooo.",
                ".oooo",
                "....o"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "o.....",
                ".o....",
                "..o...",
                "...o..",
                "....o.",
                "......"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                "o....",
                "o.o..",
                "o.o.o",
                "o.o..",
                "o...."
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 5: {
            string board[] = {
                "..........",
                "..........",
                "..oooooo..",
                "..o.......",
                "..o.......",
                "..oooooo..",
                ".......o..",
                ".......o..",
                "..oooooo..",
                ".........."
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 6: {
            string board[] = {
                "..........",
                "..........",
                "..oooo.o..",
                "..o.......",
                "..o.......",
                "..o.oooo..",
                ".......o..",
                ".......o..",
                "..oooo.o..",
                ".........."
            };
            string __expected = "not found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 7: {
            string board[] = {
                "ooooo",
                "ooooo",
                "ooooo",
                "ooooo",
                "ooooo"
            };
            string __expected = "found";
            return do_test(to_vector(board), __expected, __no);
        }
        case 8: {
            string board[] = {
                ".....",
                ".....",
                ".....",
                ".....",
                "....."
            };
            string __expected = "not found";
            return do_test(to_vector(board), __expected, __no);
        }

        // Your custom testcase goes here
        case 9:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxAndGomoku (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 9; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413952772;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
