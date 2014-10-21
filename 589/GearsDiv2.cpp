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

// DP SOLUTION:

//int dp[50][50][2];
//string Dir;
//
//int op(int g, int r, int e) {
//    if(g >= Dir.length() - 1 - e){
//        return r;
//    }
//    
//    int& res = dp[g][r][e];
//    if(res == -1){
//        if(Dir[g] == Dir[g + 1]){
//            res = min(op(g + 1, r + 1, e), op(g + 2, r + 1, e));
//        }
//        else{
//            res = op(g + 1, r, e);
//        }
//    }
//    
//    return res;
//}
//
//class GearsDiv2 {
//public:
//    int getmin(string Directions) {
//        memset(dp, -1, sizeof(dp));
//        
//        Dir = Directions;
//        
//        if(Directions[0] == Directions[Directions.size() - 1]){
//            return min(op(1, 1, 0), op(0, 1, 1));
//        }else{
//            return min(op(0, 0, 0), op(1, 1, 0));
//        }
//    }
//};

string dir;

int removeGears(int s, int e, int v){
    for(int i = s; i <= e; ++i){
        if(dir[i] == dir[i + 1]){
            v++;
            i++;
        }
    }
    
    return v;
}

class GearsDiv2 {
    public:
    int getmin(string Directions) {
        dir = Directions;
        if(dir[0] == dir[dir.size() - 1]){
            return min(removeGears(0, dir.size() - 3, 1), removeGears(1, dir.size() - 2, 1));
        }
        
        return removeGears(0, dir.size() - 2, 0);
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string Directions, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GearsDiv2 *instance = new GearsDiv2();
    int __result = instance->getmin(Directions);
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
            string Directions = "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
            int __expected = 25;
            return do_test(Directions, __expected, __no);
        }
        case 1: {
            string Directions = "RRR";
            int __expected = 2;
            return do_test(Directions, __expected, __no);
        }
        case 2: {
            string Directions = "LRLR";
            int __expected = 0;
            return do_test(Directions, __expected, __no);
        }
        case 3: {
            string Directions = "LRLLRRLLLRRRLLLL";
            int __expected = 6;
            return do_test(Directions, __expected, __no);
        }
        case 4: {
            string Directions = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR";
            int __expected = 14;
            return do_test(Directions, __expected, __no);
        }

        // Your custom testcase goes here
        case 5: {
            string Directions = "RRRRLLLRLLR";
            int __expected = 4;
            return do_test(Directions, __expected, __no);
        }
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "GearsDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413696308;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
