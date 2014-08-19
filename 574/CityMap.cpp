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
#include <map>

using namespace std;

class CityMap {
    public:
    string getLegend(vector<string> cityMap, vector<int> POIs) {
        std::map<char, int> mymap;
        
        for(int i = 0; i < cityMap.size(); ++i){
            for(int j = 0; j < cityMap[i].size(); ++j){
                if(cityMap[i][j] == '.') continue;
                char c = cityMap[i][j];
                mymap[c] = mymap[c] + 1;
            }
        }
        
        string ret = "";
        for(int i = 0; i < POIs.size(); ++i){
            int t = POIs[i];
            
            for(map<char, int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr){
                if(itr->second == t){
                    ret += itr->first;
                }
            }
        }
        
        return ret;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> cityMap, vector<int> POIs, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    CityMap *instance = new CityMap();
    string __result = instance->getLegend(cityMap, POIs);
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
            string cityMap[] = {
                "M....M",
                "...R.M",
                "R..R.R"
            };
            int POIs[] = {
                3, 4
            };
            string __expected = "MR";
            return do_test(to_vector(cityMap), to_vector(POIs), __expected, __no);
        }
        case 1: {
            string cityMap[] = {
                "XXXXXXXZXYYY"
            };
            int POIs[] = {
                1, 8, 3
            };
            string __expected = "ZXY";
            return do_test(to_vector(cityMap), to_vector(POIs), __expected, __no);
        }
        case 2: {
            string cityMap[] = {
                "...........",
                "...........",
                "...........",
                "..........T"
            };
            int POIs[] = {
                1
            };
            string __expected = "T";
            return do_test(to_vector(cityMap), to_vector(POIs), __expected, __no);
        }
        case 3: {
            string cityMap[] = {
                "AIAAARRI.......GOAI.",
                ".O..AIIGI.OAAAGI.A.I",
                ".A.IAAAARI..AI.AAGR.",
                "....IAI..AOIGA.GAIA.",
                "I.AIIIAG...GAR.IIAGA",
                "IA.AOA....I....I.GAA",
                "IOIGRAAAO.AI.AA.RAAA",
                "AI.AAA.AIR.AGRIAAG..",
                "AAAAIAAAI...AAG.RGRA",
                ".J.IA...G.A.AA.II.AA"
            };
            int POIs[] = {
                16, 7, 1, 35, 11, 66
            };
            string __expected = "GOJIRA";
            return do_test(to_vector(cityMap), to_vector(POIs), __expected, __no);
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
    cout << "CityMap (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408300763;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
