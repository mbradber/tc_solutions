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

class EllysNewNickname {
    public:
    bool isVowel(char c){
        string vowels = "aeiouy";
        
        for(int i = 0; i < vowels.size(); ++i){
            if(vowels[i] == c){
                return true;
            }
        }
        
        return false;
    }
    
    int getLength(string nickname) {
        for(int i = 0; i < nickname.size() - 1; ++i){
            if(isVowel(nickname[i]) && isVowel(nickname[i + 1])){
                nickname.erase(i, 1);
                i = -1;
            }
        }
        
        return nickname.size();
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string nickname, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    EllysNewNickname *instance = new EllysNewNickname();
    int __result = instance->getLength(nickname);
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
            string nickname = "tourist";
            int __expected = 6;
            return do_test(nickname, __expected, __no);
        }
        case 1: {
            string nickname = "eagaeoppooaaa";
            int __expected = 6;
            return do_test(nickname, __expected, __no);
        }
        case 2: {
            string nickname = "esprit";
            int __expected = 6;
            return do_test(nickname, __expected, __no);
        }
        case 3: {
            string nickname = "ayayayayayaya";
            int __expected = 1;
            return do_test(nickname, __expected, __no);
        }
        case 4: {
            string nickname = "wuuut";
            int __expected = 3;
            return do_test(nickname, __expected, __no);
        }
        case 5: {
            string nickname = "naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan";
            int __expected = 16;
            return do_test(nickname, __expected, __no);
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
    cout << "EllysNewNickname (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409538514;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
