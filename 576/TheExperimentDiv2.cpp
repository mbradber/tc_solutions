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

class TheExperimentDiv2 {
    public:
    vector<int> determineHumidity(vector<int> intensity, int L, vector<int> leftEnd) {
        vector<int> ret;
        
        for(int i = 0; i < leftEnd.size(); ++i){
            int sum = 0;
            float spongeLeft = leftEnd[i];
            float spongeRight = spongeLeft + L;
            
            for(int j = 0; j < intensity.size(); ++j){
                float loc = 0.5f + j;
                if(loc >= spongeLeft && loc <= spongeRight){
                    sum += intensity[j];
                    intensity[j] = 0;
                }
            }
            
            ret.push_back(sum);
        }
        
        return ret;
    }
};

// CUT begin
template <typename T> ostream &operator << (ostream &out, vector<T> arr);

// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) {
    stringstream s;
    
//    if(typeid(T) == typeid(string)){
//        s << "\"" << t << "\"";
//    }
//    else if(typeid(T) == typeid(vector<int>)){
//        
//    }
//    else{
//        s << t;
//    }
    typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t;
    
    return s.str();
}

// Vector print
template <typename T> ostream &operator << (ostream &out, vector<T> arr) {
    out << "{ ";
    for (int i = 0; i < arr.size(); ++i) out << (i == 0 ? "" : ", ") << pretty_print(arr[i]);
    out << " }";
    return out;
}

bool do_test(vector<int> intensity, int L, vector<int> leftEnd, vector<int> __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    TheExperimentDiv2 *instance = new TheExperimentDiv2();
    vector<int> __result = instance->determineHumidity(intensity, L, leftEnd);
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
            int intensity[] = {
                3, 4, 1, 1, 5, 6
            };
            int L = 3;
            int leftEnd[] = {
                3, 1, 0
            };
            int __expected[] = {
                12, 5, 3
            };
            return do_test(to_vector(intensity), L, to_vector(leftEnd), to_vector(__expected), __no);
        }
        case 1: {
            int intensity[] = {
                5, 5
            };
            int L = 2;
            int leftEnd[] = {
                0, 0
            };
            int __expected[] = {
                10, 0
            };
            return do_test(to_vector(intensity), L, to_vector(leftEnd), to_vector(__expected), __no);
        }
        case 2: {
            int intensity[] = {
                92, 11, 1000, 14, 3
            };
            int L = 2;
            int leftEnd[] = {
                0, 3
            };
            int __expected[] = {
                103, 17
            };
            return do_test(to_vector(intensity), L, to_vector(leftEnd), to_vector(__expected), __no);
        }
        case 3: {
            int intensity[] = {
                2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13
            };
            int L = 4;
            int leftEnd[] = {
                1, 7, 4, 5, 8, 0
            };
            int __expected[] = {
                39, 14, 110, 0, 13, 2
            };
            return do_test(to_vector(intensity), L, to_vector(leftEnd), to_vector(__expected), __no);
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
    cout << "TheExperimentDiv2 (256 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408926946;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 256 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
