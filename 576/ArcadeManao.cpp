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


class ArcadeManao {
    public:
    
    bool validCell(pair<int, int> p){
        // check that p is on the board
        if(p.first >= 0 && p.second >= 0 && p.first < mRowMax && p.second < mColMax){
            if(mLevel[p.first][p.second] == 'X'){
                return true;
            }
        }
        
        return false;
    }
    
    int shortestLadder(vector<string> level, int coinRow, int coinColumn) {
        mColMax = level[0].size();
        mRowMax = level.size();
        mLevel = level;
        
        for(int ladderLength = 0; ladderLength <= 50; ++ladderLength){
            queue< pair<int, int> > bfs;
            bfs.push(make_pair(coinRow-1, coinColumn-1));
            vector< vector<int> > visited(mRowMax, vector<int>(mColMax, 0));
            visited[coinRow-1][coinColumn-1] = true;
            
            // breadth-first search
            while(!bfs.empty()){
                pair<int, int> p = bfs.front();
                bfs.pop();
                
                // check if we're on the floor
                if(p.first == mRowMax - 1) return ladderLength;
            
                // add valid adjacent neighbors
                pair<int, int> p1 = make_pair(p.first, p.second-1);
                pair<int, int> p2 = make_pair(p.first, p.second+1);
                
                if(validCell(p1) && !visited[p1.first][p1.second]){
                    bfs.push(p1);
                    visited[p1.first][p1.second] = true;
                }
                if(validCell(p2) && !visited[p2.first][p2.second]){
                    bfs.push(p2);
                    visited[p2.first][p2.second] = true;
                }
                
                for(int i = 1; i <= ladderLength; ++i){
                    pair<int, int> p3 = make_pair(p.first + i, p.second);
                    pair<int, int> p4 = make_pair(p.first - i, p.second);
                    
                    if(validCell(p3) && !visited[p3.first][p3.second]){
                        bfs.push(p3);
                        visited[p3.first][p3.second] = true;
                    }
                    if(validCell(p4) && !visited[p4.first][p4.second]){
                        bfs.push(p4);
                        visited[p4.first][p4.second] = true;
                    }
                }
            }
            
        }
        
        
        return 0;
    }
    
    vector<string> mLevel;
    int mRowMax;
    int mColMax;
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> level, int coinRow, int coinColumn, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ArcadeManao *instance = new ArcadeManao();
    int __result = instance->shortestLadder(level, coinRow, coinColumn);
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
//            string level[] = {
//                "XXXX....",
//                "...X.XXX",
//                "XXX..X..",
//                "......X.",
//                "XXXXXXXX"
//            };
//            int coinRow = 2;
//            int coinColumn = 4;
//            int __expected = 2;
//            return do_test(to_vector(level), coinRow, coinColumn, __expected, __no);
            string level[] = {
                "XX",
                "..",
                ".X",
                "XX"
            };
            int coinRow = 1;
            int coinColumn = 1;
            int __expected = 2;
            return do_test(to_vector(level), coinRow, coinColumn, __expected, __no);
        }
        case 1: {
            string level[] = {
                "XXXX",
                "...X",
                "XXXX"
            };
            int coinRow = 1;
            int coinColumn = 1;
            int __expected = 1;
            return do_test(to_vector(level), coinRow, coinColumn, __expected, __no);
        }
        case 2: {
            string level[] = {
                "..X..",
                ".X.X.",
                "X...X",
                ".X.X.",
                "..X..",
                "XXXXX"
            };
            int coinRow = 1;
            int coinColumn = 3;
            int __expected = 4;
            return do_test(to_vector(level), coinRow, coinColumn, __expected, __no);
        }
        case 3: {
            string level[] = {
                "X"
            };
            int coinRow = 1;
            int coinColumn = 1;
            int __expected = 0;
            return do_test(to_vector(level), coinRow, coinColumn, __expected, __no);
        }
        case 4: {
            string level[] = {
                "XXXXXXXXXX",
                "...X......",
                "XXX.......",
                "X.....XXXX",
                "..XXXXX..X",
                ".........X",
                ".........X",
                "XXXXXXXXXX"
            };
            int coinRow = 1;
            int coinColumn = 1;
            int __expected = 2;
            return do_test(to_vector(level), coinRow, coinColumn, __expected, __no);
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
    cout << "ArcadeManao (576 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408928348;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 576 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
