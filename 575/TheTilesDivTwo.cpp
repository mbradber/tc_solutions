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

bool validSpot(vector<string> board, int iPos, int jPos){
    if(jPos < board[0].size() && jPos >= 0 && iPos < board.size() && iPos >= 0){
        if(board[iPos][jPos] == '.'){
            return true;
        }
    }
    
    return false;
}

int placeTile(vector<string> board, int cellNumber){
    int currI = cellNumber / board[0].size();
    int currJ = cellNumber % board[0].size();
    
    if(cellNumber == 24){
        cout << "Hello there";
    }
    
    for(int i = currI; i < board.size(); ++i){
        for(int j = currJ; j < board[0].size(); ++j){
            if((i + j) % 2 == 0){
                // available black tile
                if(board[i][j] == '.'){
                    int v[] = {0, 0, 0, 0, 0};
                    
                    // choice 1 is to not place any tile
                    v[0] = placeTile(board, cellNumber + 1);
                    
                    // choose to place at 0 orientation
                    if(validSpot(board, i, j + 1) && validSpot(board, i-1, j)){
                        vector<string> boardCopy = board;
                        boardCopy[i][j] = 'T';
                        boardCopy[i][j + 1] = 'T';
                        boardCopy[i-1][j] = 'T';
                        
                        v[1] = 1 + placeTile(boardCopy, cellNumber + 1);
                    }
                    
                    // choose to place at 90 orientation
                    if(validSpot(board, i-1, j) && validSpot(board, i, j-1)){
                        vector<string> boardCopy = board;
                        boardCopy[i][j] = 'T';
                        boardCopy[i-1][j] = 'T';
                        boardCopy[i][j - 1] = 'T';
                        
                        v[2] = 1 + placeTile(boardCopy, cellNumber + 1);
                    }
                    
                    // choose to place at 180 orientation
                    if(validSpot(board, i, j-1) && validSpot(board, i + 1, j)){
                        vector<string> boardCopy = board;
                        boardCopy[i][j] = 'T';
                        boardCopy[i][j-1] = 'T';
                        boardCopy[i+1][j] = 'T';
                        
                        v[3] = 1 + placeTile(boardCopy, cellNumber + 1);
                    }
                    
                    // choose to place at 180 orientation
                    if(validSpot(board, i, j+1) && validSpot(board, i + 1, j)){
                        vector<string> boardCopy = board;
                        boardCopy[i][j] = 'T';
                        boardCopy[i][j+1] = 'T';
                        boardCopy[i+1][j] = 'T';
                        
                        v[3] = 1 + placeTile(boardCopy, cellNumber + 1);
                    }
                    
                    return *max_element(v, v + 5);
                }
            }
        }
    }
    
    return 0;
}

class TheTilesDivTwo {
    public:
    int find(vector<string> board) {
        return placeTile(board, 0);
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
    TheTilesDivTwo *instance = new TheTilesDivTwo();
    int __result = instance->find(board);
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
                "X.X",
                "...",
                "X.X"
            };
            int __expected = 1;

            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "...",
                "...",
                "..."
            };
            int __expected = 2;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "......X.X.XXX.X.XX."
            };
            int __expected = 0;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
                ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
                "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
                "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."
            };
            int __expected = 13;
            return do_test(to_vector(board), __expected, __no);
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
    cout << "TheTilesDivTwo (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408846076;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
