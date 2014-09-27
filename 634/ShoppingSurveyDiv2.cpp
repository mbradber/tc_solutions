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

class ShoppingSurveyDiv2 {
    public:
    int minValue(int N, vector<int> s) {
        
        int M = s.size();
        
        while(true){
            int c = 0;
            for(int i = 0; i < s.size(); ++i){
                if(s[i] >= N){
                    c++;
                }
            }
            
            if(c > M - 1) break;
            
            // decrement greatest M-1 elements
            sort(s.rbegin(), s.rend());
            for(int j = 0; j < M - 1; ++j){
                s[j] = s[j] - 1;
            }
            
            --N;
        }
        
        return max(0, N);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<int> s, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ShoppingSurveyDiv2 *instance = new ShoppingSurveyDiv2();
    int __result = instance->minValue(N, s);
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
            int N = 5;
            int s[] = {
                3, 3
            };
            int __expected = 1;
            return do_test(N, to_vector(s), __expected, __no);
        }
        case 1: {
            int N = 100;
            int s[] = {
                97
            };
            int __expected = 97;
            return do_test(N, to_vector(s), __expected, __no);
        }
        case 2: {
            int N = 10;
            int s[] = {
                9, 9, 9, 9, 9
            };
            int __expected = 5;
            return do_test(N, to_vector(s), __expected, __no);
        }
        case 3: {
            int N = 7;
            int s[] = {
                1, 2, 3
            };
            int __expected = 0;
            return do_test(N, to_vector(s), __expected, __no);
        }
        case 4: {
            int N = 5;
            int s[] = {
                3, 3, 3
            };
            int __expected = 0;
            return do_test(N, to_vector(s), __expected, __no);
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
    cout << "ShoppingSurveyDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1411693491;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
