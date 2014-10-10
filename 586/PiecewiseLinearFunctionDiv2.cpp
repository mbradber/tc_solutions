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

class PiecewiseLinearFunctionDiv2 {
    public:
    
    bool isBetween(int a, int b, int c){
        int big = max(a, b);
        int small = min(a, b);
        if(c > small && c < big) return true;
        if(c == a) return true;
        return false;
    }
    
    vector<int> countSolutions(vector<int> Y, vector<int> query) {
        vector<int> sols;
        
        for(int i = 0; i < query.size(); ++i){
            int numSols = 0;
            for(int j = 0; j < Y.size() - 1; ++j){
                if(Y[j] == Y[j + 1] && Y[j] == query[i]){
                    numSols = -1;
                    break;
                }
                if(isBetween(Y[j], Y[j + 1], query[i])){
                    numSols++;
                }
                if(j == Y.size() - 2 && query[i] == Y[j + 1]){
                    numSols++;
                }
            }
            
            sols.push_back(numSols);
        }
        
        return sols;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> ostream &operator << (ostream &out, vector<T> arr);

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(vector<int> Y, vector<int> query, vector<int> __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    PiecewiseLinearFunctionDiv2 *instance = new PiecewiseLinearFunctionDiv2();
    vector<int> __result = instance->countSolutions(Y, query);
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
            int Y[] = {
                -1, -7, -2, -9, -4, -8, -3, -9, -6
            };
            int query[] = {
                -6
            };
            int __expected[] = {
                8
            };
            return do_test(to_vector(Y), to_vector(query), to_vector(__expected), __no);
        }
            
        case 1: {
            int Y[] = {
                1, 4, -1, 2
            };
            int query[] = {
                -2, -1, 0, 1
            };
            int __expected[] = {
                0, 1, 2, 3
            };
            return do_test(to_vector(Y), to_vector(query), to_vector(__expected), __no);
        }
        case 2: {
            int Y[] = {
                0, 0
            };
            int query[] = {
                -1, 0, 1
            };
            int __expected[] = {
                0, -1, 0
            };
            return do_test(to_vector(Y), to_vector(query), to_vector(__expected), __no);
        }
        case 3: {
            int Y[] = {
                2, 4, 8, 0, 3, -6, 10
            };
            int query[] = {
                0, 1, 2, 3, 4, 0, 65536
            };
            int __expected[] = {
                3, 4, 5, 4, 3, 3, 0
            };
            return do_test(to_vector(Y), to_vector(query), to_vector(__expected), __no);
        }
        case 4: {
            int Y[] = {
                -178080289, -771314989, -237251715, -949949900, -437883156, -835236871, -316363230, -929746634, -671700962
            };
            int query[] = {
                -673197622, -437883156, -251072978, 221380900, -771314989, -949949900, -910604034, -671700962, -929746634, -316363230
            };
            int __expected[] = {
                8, 6, 3, 0, 7, 1, 4, 8, 3, 4
            };
            return do_test(to_vector(Y), to_vector(query), to_vector(__expected), __no);
        }

        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "PiecewiseLinearFunctionDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1412740207;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
