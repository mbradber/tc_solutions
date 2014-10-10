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
#include <deque>

using namespace std;

class TeamsSelection {
    public:
    string simulate(vector<int> preference1, vector<int> preference2) {
        string res(preference1.size(), '0');
        vector<bool> used(preference1.size(), false);
        
        while(preference1.size() > 0 || preference2.size() > 0){
            while(preference1.size() > 0 && used[preference1[0] - 1]){
                preference1.erase(preference1.begin());
            }
            if(preference1.size() > 0){
                used[preference1[0] - 1] = true;
                res[preference1[0] - 1] = '1';
            }
            
            while(preference2.size() > 0 && used[preference2[0] - 1]){
                preference2.erase(preference2.begin());
            }
            if(preference2.size() > 0){
                used[preference2[0] - 1] = true;
                res[preference2[0] - 1] = '2';
            }
        }
        
        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> preference1, vector<int> preference2, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    TeamsSelection *instance = new TeamsSelection();
    string __result = instance->simulate(preference1, preference2);
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
            int preference1[] = {
                1, 2, 3, 4
            };
            int preference2[] = {
                1, 2, 3, 4
            };
            string __expected = "1212";
            return do_test(to_vector(preference1), to_vector(preference2), __expected, __no);
        }
        case 1: {
            int preference1[] = {
                3, 2, 1
            };
            int preference2[] = {
                1, 3, 2
            };
            string __expected = "211";
            return do_test(to_vector(preference1), to_vector(preference2), __expected, __no);
        }
        case 2: {
            int preference1[] = {
                6, 1, 5, 2, 3, 4
            };
            int preference2[] = {
                1, 6, 3, 4, 5, 2
            };
            string __expected = "212211";
            return do_test(to_vector(preference1), to_vector(preference2), __expected, __no);
        }
        case 3: {
            int preference1[] = {
                8, 7, 1, 2, 4, 5, 6, 3, 9
            };
            int preference2[] = {
                7, 2, 4, 8, 1, 5, 9, 6, 3
            };
            string __expected = "121121212";
            return do_test(to_vector(preference1), to_vector(preference2), __expected, __no);
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
    cout << "TeamsSelection (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1412655136;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
