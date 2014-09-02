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

int gcd(int x, int y){
    while (y > 0) {
        int z = y;
        y = x % y;
        x = z;
    }
    return x;
}

int minimumFill(int a, int b){
    if(gcd(a, b) == 1){
        return 0;
    }
    else{
        for(int i = a + 1; i < b; ++i){
            if(gcd(a, i) == 1 && gcd(b, i) == 1){
                return 1;
            }
        }
    }
    
    int dp[b - a + 1];
    dp[b - a] = 1;
    
    for(int i = b - 1; i >= a; --i){
        dp[i - a] = 1000;

            for(int j = i + 1; j <= b; ++j){
                if(gcd(i, j) == 1){
                    dp[i - a] = min(dp[i - a], dp[j - a] + 1);
                }
            }
    }
    
    return dp[0] - 2;
}

class EllysCoprimesDiv2 {
    public:
    int getCount(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        
        int res = 0;
        for(int i = 0; i < numbers.size() - 1; ++i){
            res += minimumFill(numbers[i], numbers[i + 1]);
        }
        
        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> numbers, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    EllysCoprimesDiv2 *instance = new EllysCoprimesDiv2();
    int __result = instance->getCount(numbers);
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
            int numbers[] = {
                2200, 42, 2184, 17
            };
            int __expected = 3;
            return do_test(to_vector(numbers), __expected, __no);
        }
        case 1: {
            int numbers[] = {
                13, 1, 6, 20, 33
            };
            int __expected = 0;
            return do_test(to_vector(numbers), __expected, __no);
        }
        case 2: {
            int numbers[] = {
                7, 42
            };
            int __expected = 1;
            return do_test(to_vector(numbers), __expected, __no);
        }
        case 3: {
            int numbers[] = {
                55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856, 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586, 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829, 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666
            };
            int __expected = 15;
            return do_test(to_vector(numbers), __expected, __no);
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
    cout << "EllysCoprimesDiv2 (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409542790;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
