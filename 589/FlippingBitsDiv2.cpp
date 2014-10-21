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
#include <climits>

using namespace std;

string gBits;
vector<int> gC0;
vector<int> gC1;
int dp[2501][2][2];

int op(int t, int p, int allFlipped){
    if(t < 0) {
        return allFlipped;
    }
    
    int& res = dp[t][p][allFlipped];
    
    if(res == -1){
        res = INT_MAX;
        for(int i = 0; i < 2; ++i){
            int cost = 0;
            if(i != p){
                cost += 1;
            }
            if(i == 0){
                cost += gC0[t];
                cost += op(t - 1, i, 0);
            }
            else{
                cost += gC1[t];
                cost += op(t - 1, i, allFlipped);
            }
            
            res = min(res, cost);
        }
    }
    
    return res;
}

class FlippingBitsDiv2 {
    public:
    int getmin(vector<string> S, int M) {
        memset(dp, -1, sizeof(dp));
        
        string bits = "";
        for(int i = 0; i < S.size(); ++i){
            bits += S[i];
        }
        gBits = bits;
        
        int T = bits.size() / M;
        vector<int> c0(T+1, 0);
        vector<int> c1(T+1, 0);
        for(int i = 0; i < T; ++i){
            int e = i * M;
            for(int j = e; j < e + M; ++j){
                if(bits[j] == '0'){
                    c0[i]++;
                }else{
                    c1[i]++;
                }
            }
        }
        
        gC0 = c0;
        gC1 = c1;
        
        int res = min(op(T-1, 0, 1), op(T-1, 1, 1));
        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> S, int M, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FlippingBitsDiv2 *instance = new FlippingBitsDiv2();
    int __result = instance->getmin(S, M);
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
            string S[] = {
                "0000"
            };
            int M = 2;
            int __expected = 1;
            return do_test(to_vector(S), M, __expected, __no);
        }
        case 1: {
            string S[] = {
                "00111000"
            };
            int M = 2;
            int __expected = 3;
            return do_test(to_vector(S), M, __expected, __no);
        }
        case 2: {
            string S[] = {
                "111111"
            };
            int M = 3;
            int __expected = 0;
            return do_test(to_vector(S), M, __expected, __no);
        }
        case 3: {
            string S[] = {
                "00100"
            };
            int M = 5;
            int __expected = 2;
            return do_test(to_vector(S), M, __expected, __no);
        }
        case 4: {
            string S[] = {
                "00010",
                "11010110",
                "1010111",
                "110001010",
                "0110001100",
                "000110110",
                "011010101",
                "00",
                "111",
                "100"
            };
            int M = 13;
            int __expected = 31;
            return do_test(to_vector(S), M, __expected, __no);
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
    cout << "FlippingBitsDiv2 (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413698761;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
