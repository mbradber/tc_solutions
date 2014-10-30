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
#include <queue>

using namespace std;

class FoxAndGo {
public:
    int maxKill(vector<string> board) {
        int maxRes = 0;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] != '.') continue;
                vector<string> lBoard = board;
                lBoard[i][j] = 'x';
                int res = 0;
                
                vector< vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
                for(int m = 0; m < board.size(); ++m){
                    for(int n = 0; n < board[0].size(); ++n){
                        int compCount = 0;
                        int openCount = 0;
                        queue<pair<int, int> > neighbors;
                        
                        if(lBoard[m][n] == 'o' && !visited[m][n]){
                            visited[m][n] = true;
                            neighbors.push(make_pair(m, n));
                        }
                        
                        while(neighbors.size() > 0){
                            pair<int, int> curr = neighbors.front();
                            neighbors.pop();
                            int r = curr.first;
                            int c = curr.second;
                            compCount++;
                            
                            // add unvisited neighbors and check for free positions
                            if(c > 0){
                                if(lBoard[r][c-1] == 'o' && !visited[r][c-1]){
                                    visited[r][c-1] = true;
                                    neighbors.push(make_pair(r, c-1));
                                }else if(lBoard[r][c-1] == '.'){
                                    openCount++;
                                }
                            }
                            if(c < lBoard[0].size() - 1){
                                if(lBoard[r][c+1] == 'o' && !visited[r][c+1]){
                                    visited[r][c+1] = true;
                                    neighbors.push(make_pair(r, c+1));
                                }else if(lBoard[r][c+1] == '.'){
                                    openCount++;
                                }
                            }
                            if(r > 0){
                                if(lBoard[r-1][c] == 'o' && !visited[r-1][c]){
                                    visited[r-1][c] = true;
                                    neighbors.push(make_pair(r-1, c));
                                }else if(lBoard[r-1][c] == '.'){
                                    openCount++;
                                }
                            }
                            if(r < lBoard.size()-1){
                                if(lBoard[r+1][c] == 'o' && !visited[r+1][c]){
                                    visited[r+1][c] = true;
                                    neighbors.push(make_pair(r+1, c));
                                }else if(lBoard[r+1][c] == '.'){
                                    openCount++;
                                }
                            }
                        }
                        
                        if(openCount == 0){
                            res += compCount;
                        }
                    }
                }
                
                maxRes = max(maxRes, res);
            }
        }
        
        return maxRes;
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
    FoxAndGo *instance = new FoxAndGo();
    int __result = instance->maxKill(board);
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
                ".....",
                "..x..",
                ".xox.",
                ".....",
                "....."
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {"ooooooxoxooxoooxo", "oxooooooxooox.ooo", "ooooooooooo.ooxoo", "xoooooooooooooooo", "oooooooxooooooooo", "ooooooxoooooooo.o", "ooooooooxxoxooooo", "ooxooooxoooo.xoxo", "xoooooooooooooo.o", "o.oxooooooxoooooo", "xo.xooooxoooooooo", "oooooooooooo.oxoo", "oooo.ooooox.ooooo", ".ooooox.ooxoooooo", "xooooooooxooxoooo", ".ooooooooooxooooo", "oooooxxoooooooooo"};
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                ".xoxo",
                "ooxox",
                "oooxx",
                "xoxox",
                "oxoox"
            };
            int __expected = 13;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                ".......",
                ".......",
                ".......",
                "xxxx...",
                "ooox...",
                "ooox...",
                "ooox..."
            };
            int __expected = 9;
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
                ".......",
                ".xxxxx.",
                ".xooox.",
                ".xo.ox.",
                ".xooox.",
                ".xxxxx.",
                "......."
            };
            int __expected = 8;
            return do_test(to_vector(board), __expected, __no);
        }
        case 5: {
            string board[] = {
                "o.xox.o",
                "..xox..",
                "xxxoxxx",
                "ooo.ooo",
                "xxxoxxx",
                "..xox..",
                "o.xox.o"
            };
            int __expected = 12;
            return do_test(to_vector(board), __expected, __no);
        }
        case 6: {
            string board[] = {
                ".......",
                "..xx...",
                ".xooox.",
                ".oxxox.",
                ".oxxxo.",
                "...oo..",
                "......."
            };
            int __expected = 4;
            return do_test(to_vector(board), __expected, __no);
        }
        case 7: {
            string board[] = {
                ".ox....",
                "xxox...",
                "..xoox.",
                "..xoox.",
                "...xx..",
                ".......",
                "......."
            };
            int __expected = 5;
            return do_test(to_vector(board), __expected, __no);
        }
        case 8: {
            string board[] = {
                "...................",
                "...................",
                "...o..........o....",
                "................x..",
                "...............x...",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "...................",
                "................o..",
                "..x................",
                "...............x...",
                "...................",
                "..................."
            };
            int __expected = 0;
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
    cout << "FoxAndGo (500 Points)" << endl << endl;
    
    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 9; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;
    
    int T = time(NULL) - 1414186506;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
