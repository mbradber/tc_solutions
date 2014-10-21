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

class KeyDungeonDiv2 {
    public:
    int countDoors(vector<int> doorR, vector<int> doorG, vector<int> keys) {
        int res = 0;
        
        for(int i = 0; i < doorR.size(); ++i){
            int whiteKeys = keys[2];
            int needRed = doorR[i] - keys[0];
            int needGreen = doorG[i] - keys[1];
            
            if(needRed > 0){
                whiteKeys -= needRed;
            }
            if(needGreen > 0){
                whiteKeys -= needGreen;
            }
            
            if(whiteKeys >= 0) res++;
        }
        
        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> doorR, vector<int> doorG, vector<int> keys, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    KeyDungeonDiv2 *instance = new KeyDungeonDiv2();
    int __result = instance->countDoors(doorR, doorG, keys);
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
            int doorR[] = {
                2, 0, 5, 3
            };
            int doorG[] = {
                1, 4, 0, 2
            };
            int keys[] = {
                2, 3, 1
            };
            int __expected = 3;
            return do_test(to_vector(doorR), to_vector(doorG), to_vector(keys), __expected, __no);
        }
        case 1: {
            int doorR[] = {
                0, 1, 2, 0
            };
            int doorG[] = {
                0, 2, 3, 1
            };
            int keys[] = {
                0, 0, 0
            };
            int __expected = 1;
            return do_test(to_vector(doorR), to_vector(doorG), to_vector(keys), __expected, __no);
        }
        case 2: {
            int doorR[] = {
                3, 5, 4, 2, 8
            };
            int doorG[] = {
                4, 2, 3, 8, 1
            };
            int keys[] = {
                0, 0, 10
            };
            int __expected = 5;
            return do_test(to_vector(doorR), to_vector(doorG), to_vector(keys), __expected, __no);
        }
        case 3: {
            int doorR[] = {
                4, 5, 4, 6, 8
            };
            int doorG[] = {
                2, 1, 2, 3, 5
            };
            int keys[] = {
                1, 2, 1
            };
            int __expected = 0;
            return do_test(to_vector(doorR), to_vector(doorG), to_vector(keys), __expected, __no);
        }
        case 4: {
            int doorR[] = {
                41, 44, 41, 57, 58, 74, 84, 100, 58, 2, 43, 32, 82, 97, 44, 13, 35, 98, 96, 81, 43, 77, 18, 51, 27, 27, 39, 39, 45, 82, 59, 20, 28, 93, 6, 39, 64, 78, 28, 85, 17, 56, 3, 68, 4, 0, 36, 80, 41, 77
            };
            int doorG[] = {
                67, 15, 53, 36, 88, 29, 26, 57, 68, 99, 97, 27, 51, 70, 3, 49, 65, 75, 35, 92, 66, 0, 23, 96, 38, 86, 98, 31, 26, 75, 30, 2, 92, 78, 100, 99, 38, 26, 85, 74, 77, 15, 16, 48, 100, 88, 55, 93, 99, 54
            };
            int keys[] = {
                39, 31, 34
            };
            int __expected = 17;
            return do_test(to_vector(doorR), to_vector(doorG), to_vector(keys), __expected, __no);
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
    cout << "KeyDungeonDiv2 (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413169502;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
