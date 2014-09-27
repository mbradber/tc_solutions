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
#include <cstdlib>

using namespace std;

class SpecialStrings {
    public:
    string findNext(string current) {
        if(current.size() == 1) return "";
        
        cout << current << endl;
        
        int idx = -1;
        for(int i = 0; i < current.size() - 1; ++i){
            if(current[i] == '1'){
                idx = i;
                break;
            }
        }
        
        if(idx == -1) return "";
        
        string binString = current.substr(idx);
        string binStringPrefix = current.substr(0, idx);
        
        char * ptr;
        long parsed = strtol(binString.c_str(), & ptr, 2);
        parsed += 1;
        std::string s = std::bitset< 64 >(parsed).to_string();
        
        int idxB = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1'){
                idxB = i;
                break;
            }
        }
        
        s = s.substr(idxB);
        
        if(s.size() > binString.size()){
            binStringPrefix = binStringPrefix.substr(0, binStringPrefix.size() - 1);
        }
        
        s = binStringPrefix + s;
        
        int a = -1, b = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1' && a == -1){
                a = i;
            }else{
                
            }
        }
        
        return s;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string current, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    SpecialStrings *instance = new SpecialStrings();
    string __result = instance->findNext(current);
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
            string current = "01";
            string __expected = "";
            return do_test(current, __expected, __no);
        }
        case 1: {
            string current = "00101";
            string __expected = "00111";
            return do_test(current, __expected, __no);
        }
        case 2: {
            string current = "0010111";
            string __expected = "0011011";
            return do_test(current, __expected, __no);
        }
        case 3: {
            string current = "000010001001011";
            string __expected = "000010001001101";
            return do_test(current, __expected, __no);
        }
        case 4: {
            string current = "01101111011110111";
            string __expected = "01101111011111111";
            return do_test(current, __expected, __no);
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
    cout << "SpecialStrings (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1411695801;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
