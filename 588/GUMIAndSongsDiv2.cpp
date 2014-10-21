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

class GUMIAndSongsDiv2 {
    public:
    int maxSongs(vector<int> duration, vector<int> tone, int T) {
        int maxSongs = 0;
        
        for(int i = 0; i < 1 << duration.size(); ++i){
            vector<int> subset;
            for(int j = 0; j < duration.size(); ++j){
                if(i & 1 << j){
                    subset.push_back(j);
                }
            }
            
            int min = 1000000000;
            int max = -1;
            int restTime = 0;
            int singTime = 0;
            for(int j = 0; j < subset.size(); ++j){
                if(tone[subset[j]] < min){
                    min = tone[subset[j]];
                }
                if(tone[subset[j]] > max){
                    max = tone[subset[j]];
                }
                singTime += duration[subset[j]];
            }
            
            restTime = max - min;
            int totalTime = singTime + restTime;
            if(totalTime <= T && subset.size() > maxSongs){
                maxSongs = subset.size();
            }
        }
        
        return maxSongs;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> duration, vector<int> tone, int T, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GUMIAndSongsDiv2 *instance = new GUMIAndSongsDiv2();
    int __result = instance->maxSongs(duration, tone, T);
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
            int duration[] = {
                3, 5, 4, 11
            };
            int tone[] = {
                2, 1, 3, 1
            };
            int T = 17;
            int __expected = 3;
            return do_test(to_vector(duration), to_vector(tone), T, __expected, __no);
        }
        case 1: {
            int duration[] = {
                100, 200, 300
            };
            int tone[] = {
                1, 2, 3
            };
            int T = 10;
            int __expected = 0;
            return do_test(to_vector(duration), to_vector(tone), T, __expected, __no);
        }
        case 2: {
            int duration[] = {
                1, 2, 3, 4
            };
            int tone[] = {
                1, 1, 1, 1
            };
            int T = 100;
            int __expected = 4;
            return do_test(to_vector(duration), to_vector(tone), T, __expected, __no);
        }
        case 3: {
            int duration[] = {
                10, 10, 10
            };
            int tone[] = {
                58, 58, 58
            };
            int T = 30;
            int __expected = 3;
            return do_test(to_vector(duration), to_vector(tone), T, __expected, __no);
        }
        case 4: {
            int duration[] = {
                8, 11, 7, 15, 9, 16, 7, 9
            };
            int tone[] = {
                3, 8, 5, 4, 2, 7, 4, 1
            };
            int T = 14;
            int __expected = 1;
            return do_test(to_vector(duration), to_vector(tone), T, __expected, __no);
        }
        case 5: {
            int duration[] = {
                5611, 39996, 20200, 56574, 81643, 90131, 33486, 99568, 48112, 97168, 5600, 49145, 73590, 3979, 94614
            };
            int tone[] = {
                2916, 53353, 64924, 86481, 44803, 61254, 99393, 5993, 40781, 2174, 67458, 74263, 69710, 40044, 80853
            };
            int T = 302606;
            int __expected = 8;
            return do_test(to_vector(duration), to_vector(tone), T, __expected, __no);
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
    cout << "GUMIAndSongsDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413170528;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
