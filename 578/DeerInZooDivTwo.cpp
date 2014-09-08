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

class DeerInZooDivTwo {
    public:
    vector<int> getminmax(int N, int K) {
        int minDeers = max(N - K, 0);
        int maxDeers = K / 2;
        if(K & 1) maxDeers++;
        maxDeers = N - maxDeers;
        
        vector<int> deers;
        deers.push_back(minDeers);
        deers.push_back(maxDeers);
        
        return deers;
    }
};

template <typename T> ostream &operator << (ostream &out, vector<T> arr);

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(int N, int K, vector<int> __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    DeerInZooDivTwo *instance = new DeerInZooDivTwo();
    vector<int> __result = instance->getminmax(N, K);
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
            int N = 3;
            int K = 2;
            int __expected[] = {
                1, 2
            };
            return do_test(N, K, to_vector(__expected), __no);
        }
        case 1: {
            int N = 3;
            int K = 3;
            int __expected[] = {
                0, 1
            };
            return do_test(N, K, to_vector(__expected), __no);
        }
        case 2: {
            int N = 10;
            int K = 0;
            int __expected[] = {
                10, 10
            };
            return do_test(N, K, to_vector(__expected), __no);
        }
        case 3: {
            int N = 654;
            int K = 321;
            int __expected[] = {
                333, 493
            };
            return do_test(N, K, to_vector(__expected), __no);
        }
        case 4: {
            int N = 100;
            int K = 193;
            int __expected[] = {
                0, 3
            };
            return do_test(N, K, to_vector(__expected), __no);
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
    cout << "DeerInZooDivTwo (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1410052074;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
