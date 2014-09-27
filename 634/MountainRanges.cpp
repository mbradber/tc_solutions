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

class MountainRanges {
    public:
    int countPeaks(vector<int> heights) {
        int count = 0;
        if(heights.size() == 1) return 1;
        
        if(heights[0] > heights[1]) ++count;
        if(heights[heights.size() - 1] > heights[heights.size() - 2]) ++count;
        
        for(int i = 1; i < heights.size() - 1; ++i){
            if(heights[i] > heights[i - 1] && heights[i] > heights[i + 1]) ++count;
        }
        
        
        return count;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> heights, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    MountainRanges *instance = new MountainRanges();
    int __result = instance->countPeaks(heights);
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
            int heights[] = {
                5, 6, 2, 4
            };
            int __expected = 2;
            return do_test(to_vector(heights), __expected, __no);
        }
        case 1: {
            int heights[] = {
                1, 1, 1, 1, 1, 1, 1
            };
            int __expected = 0;
            return do_test(to_vector(heights), __expected, __no);
        }
        case 2: {
            int heights[] = {
                2, 1
            };
            int __expected = 1;
            return do_test(to_vector(heights), __expected, __no);
        }
        case 3: {
            int heights[] = {
                2, 5, 3, 7, 2, 8, 1, 3, 1
            };
            int __expected = 4;
            return do_test(to_vector(heights), __expected, __no);
        }
        case 4: {
            int heights[] = {
                1
            };
            int __expected = 1;
            return do_test(to_vector(heights), __expected, __no);
        }
        case 5: {
            int heights[] = {
                1, 2, 3, 4, 4, 3, 2, 1
            };
            int __expected = 0;
            return do_test(to_vector(heights), __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "MountainRanges (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1411693207;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
