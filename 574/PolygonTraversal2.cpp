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
#include <utility>
#include <iterator>

using namespace std;

typedef pair<int, int> Line;

Line SortLine(Line a){
    if(a.first > a.second){
        int t = a.first;
        a.first = a.second;
        a.second = t;
    }
    
    return a;
}

bool Intersect(vector<Line> lines, int a, int b){
    Line newLine = make_pair(a, b);
    newLine = SortLine(newLine);
    
    for(int i = 0; i < lines.size(); ++i){
        Line l = SortLine(lines[i]);
        set<int> pointSet;
        pointSet.insert(l.first);
        pointSet.insert(l.second);
        pointSet.insert(a);
        pointSet.insert(b);
        
        if(pointSet.size() < 4){
            continue;
        }
        
        Line big, small;
        if(l.second > newLine.second){
            big = l;
            small = newLine;
        }
        else{
            big = newLine;
            small = l;
        }
        
        int v[4] = {small.first, big.first, small.second, big.second};
        
        int j = 0;
        bool match = true;
        for(set<int>::iterator itr = pointSet.begin(); itr != pointSet.end(); ++itr, ++j){
            if(*itr != v[j]) match = false;
        }
        
        if(match)
            return true;
    }
    
    return false;
}

int ProcTail(vector<Line> lines, vector<int> tailPoints){
    Line firstLine = lines[0];
    Line lastLine = lines[lines.size() - 1];
    
    // base case
    if(tailPoints.size() == 0){
        if(Intersect(lines, lastLine.second, firstLine.first)){
            return 1;
        }else{
            return 0;
        }
    }
    
    int sum = 0;
    for(int i = 0; i < tailPoints.size(); ++i){
        if(Intersect(lines, lastLine.second, tailPoints[i])){
            Line newLine = make_pair(lastLine.second, tailPoints[i]);
            vector<int> newTail = tailPoints;
            newTail.erase(newTail.begin() + i);
            vector<Line> newLines = lines;
            newLines.push_back(newLine);
            
            sum += ProcTail(newLines, newTail);
        }
    }
    
    return sum;
}

class PolygonTraversal2 {
public:
    int count(int N, vector<int> points) {
        vector<Line> lines;
        set<int> tailPoints;
        
        for(int i = 1; i <= N; ++i){
            tailPoints.insert(i);
        }
        
        for(int i = 0; i < points.size(); ++i){
            if(i < points.size() - 1){
                lines.push_back(make_pair(points[i], points[i + 1]));
            }
            
            set<int>::iterator itr = tailPoints.find(points[i]);
            tailPoints.erase(itr);
        }
        
        vector<int> tp;
        copy(tailPoints.begin(), tailPoints.end(), back_inserter(tp));
        
        return ProcTail(lines, tp);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, vector<int> points, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    PolygonTraversal2 *instance = new PolygonTraversal2();
    int __result = instance->count(N, points);
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
            int N = 5;
            int points[] = {
                1, 3, 5
            };
            int __expected = 1;
            return do_test(N, to_vector(points), __expected, __no);
        }
        case 1: {
            int N = 6;
            int points[] = {
                1, 4, 2
            };
            int __expected = 1;
            return do_test(N, to_vector(points), __expected, __no);
        }
        case 2: {
            int N = 7;
            int points[] = {
                2, 4, 7
            };
            int __expected = 2;
            return do_test(N, to_vector(points), __expected, __no);
        }
        case 3: {
            int N = 7;
            int points[] = {
                1, 2, 3, 4, 6, 5
            };
            int __expected = 0;
            return do_test(N, to_vector(points), __expected, __no);
        }
        case 4: {
            int N = 11;
            int points[] = {
                1, 5, 10
            };
            int __expected = 1412;
            return do_test(N, to_vector(points), __expected, __no);
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
    cout << "PolygonTraversal2 (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1408330124;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
