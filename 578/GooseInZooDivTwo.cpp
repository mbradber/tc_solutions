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

const int MOD = 1000000007;

class GooseInZooDivTwo {
    public:
    // Finds x raised to the y-th exponent modulo MOD
    int modPow(int b, int e){
        int a = 1;
        while(e > 0){
            a = a * b % MOD;
            --e;
        }
        
        return a % MOD;
    }
    
    int count(vector<string> field, int dist) {
        int numGroups = 0;
        for(int i = 0; i < field.size(); ++i){
            for(int j = 0; j < field[0].size(); ++j){
                if(field[i][j] == 'v'){
                    ++numGroups;
                    
                    // run bfs from this bird
                    queue< pair<int, int> > birdQueue;
                    birdQueue.push(make_pair(i, j));
                    
                    while(!birdQueue.empty()){
                        pair<int, int> birdLoc = birdQueue.front();
                        birdQueue.pop();
                        
                        for(int x = 0; x <= dist; ++x){
                            for(int y = 0; y <= dist; ++y){
                                if(x + y > dist) continue;
                                
                                int colMax = field[0].size() - 1;
                                int rowMax = field.size() - 1;
                                pair<int, int> neighbors[4];
                                
                                neighbors[0] = make_pair(min(birdLoc.first + x, rowMax), min(birdLoc.second + y, colMax));
                                neighbors[1] = make_pair(min(birdLoc.first + x, rowMax), max(birdLoc.second - y, 0));
                                neighbors[2] = make_pair(max(birdLoc.first - x, 0), min(birdLoc.second + y, colMax));
                                neighbors[3] = make_pair(max(birdLoc.first - x, 0), max(birdLoc.second - y, 0));
                                
                                for(int k = 0; k < 4; ++k){
                                    if(field[neighbors[k].first][neighbors[k].second] == 'v'){
                                        birdQueue.push(neighbors[k]);
                                        field[neighbors[k].first][neighbors[k].second] = '.';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return modPow(2, numGroups) - 1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> field, int dist, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GooseInZooDivTwo *instance = new GooseInZooDivTwo();
    int __result = instance->count(field, dist);
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
            string field[] = {
                "vvv"
            };
            int dist = 0;
            int __expected = 7;
            return do_test(to_vector(field), dist, __expected, __no);
        }
        case 1: {
            string field[] = {
                "."
            };
            int dist = 100;
            int __expected = 0;
            return do_test(to_vector(field), dist, __expected, __no);
        }
        case 2: {
            string field[] = {
                "vvv"
            };
            int dist = 1;
            int __expected = 1;
            return do_test(to_vector(field), dist, __expected, __no);
        }
        case 3: {
            string field[] = {
                "v.v..................v............................",
                ".v......v..................v.....................v",
                "..v.....v....v.........v...............v......v...",
                ".........vvv...vv.v.........v.v..................v",
                ".....v..........v......v..v...v.......v...........",
                "...................vv...............v.v..v.v..v...",
                ".v.vv.................v..............v............",
                "..vv.......v...vv.v............vv.....v.....v.....",
                "....v..........v....v........v.......v.v.v........",
                ".v.......v.............v.v..........vv......v.....",
                "....v.v.......v........v.....v.................v..",
                "....v..v..v.v..............v.v.v....v..........v..",
                "..........v...v...................v..............v",
                "..v........v..........................v....v..v...",
                "....................v..v.........vv........v......",
                "..v......v...............................v.v......",
                "..v.v..............v........v...............vv.vv.",
                "...vv......v...............v.v..............v.....",
                "............................v..v.................v",
                ".v.............v.......v..........................",
                "......v...v........................v..............",
                ".........v.....v..............vv..................",
                "................v..v..v.........v....v.......v....",
                "........v.....v.............v......v.v............",
                "...........v....................v.v....v.v.v...v..",
                "...........v......................v...v...........",
                "..........vv...........v.v.....................v..",
                ".....................v......v............v...v....",
                ".....vv..........................vv.v.....v.v.....",
                ".vv.......v...............v.......v..v.....v......",
                "............v................v..........v....v....",
                "................vv...v............................",
                "................v...........v........v...v....v...",
                "..v...v...v.............v...v........v....v..v....",
                "......v..v.......v........v..v....vv..............",
                "...........v..........v........v.v................",
                "v.v......v................v....................v..",
                ".v........v................................v......",
                "............................v...v.......v.........",
                "........................vv.v..............v...vv..",
                ".......................vv........v.............v..",
                "...v.............v.........................v......",
                "....v......vv...........................v.........",
                "....vv....v................v...vv..............v..",
                "..................................................",
                "vv........v...v..v.....v..v..................v....",
                ".........v..............v.vv.v.............v......",
                ".......v.....v......v...............v.............",
                "..v..................v................v....v......",
                ".....v.....v.....................v.v......v......."
            };
            int dist = 3;
            int __expected = 797922654;
            return do_test(to_vector(field), dist, __expected, __no);
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
    cout << "GooseInZooDivTwo (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1410052496;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
