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

struct Vertex{
    int color;
    bool visited;
    vector<int> neighbors;
    int id;

    Vertex(){
        id = -1;
        visited = false;
        color = 0;
    }
};

class Graph{
    
public:
    void AddEdge(int a, int b){
        AddVertex(a);
        AddVertex(b);
        mVerts[a].neighbors.push_back(b);
        mVerts[b].neighbors.push_back(a);
    }
    
    void AddVertex(int id){
        if(id >= mVerts.size()){
            mVerts.resize(id + 1);
        }
        mVerts[id].id = id;
    }
    
    void PrintGraph(){
        for(int i = 0; i < mVerts.size(); ++i){
            cout << mVerts[i].id << ":";
            for(int j = 0; j < mVerts[i].neighbors.size(); ++j){
                cout << mVerts[i].neighbors[j] << ",";
            }
            cout << "\n";
        }
    }
    
public:
    vector<Vertex> mVerts;
};

class ThreeColorabilityEasy {
    public:
    string isColorable(vector<string> cells) {
        Graph g;
        
        for(int i = 0; i <= cells.size(); ++i){
            for(int j = 0; j <= cells[0].size(); ++j){
                int idx = i * (cells[0].size() + 1) + j;
                if(j < cells[0].size()){
                    g.AddEdge(idx, idx + 1);
                }
                if(i < cells.size()){
                    g.AddEdge(idx, idx + cells[0].size() + 1);
                }
            }
        }
        for(int i = 0; i < cells.size(); ++i){
            for(int j = 0; j < cells[0].size(); ++j){
                int idx = i * cells[0].size() + j;
                int lIdx = idx + i;
                if(cells[i][j] == 'Z'){
                    g.AddEdge(lIdx + 1, lIdx + cells[0].size() + 1);
                }
                else if(cells[i][j] == 'N'){
                    g.AddEdge(lIdx, lIdx + 1 + cells[0].size() + 1);
                }

            }
        }
        
        vector<Vertex> verts = g.mVerts;
        verts[0].color = 1;
        verts[verts[0].neighbors[0]].color = 2;
        
        for(int i = 0; i < verts.size(); ++i){
            Vertex& current = verts[i];
            for(int j = 0; j < verts[i].neighbors.size(); ++j){
                // find neighbor that has a color
                Vertex& neighbor = verts[verts[i].neighbors[j]];
                if(neighbor.color != 0){
                    // go through all neighbors of each vertex that they have in common
                    for(int p = 0; p < current.neighbors.size(); ++p){
                        for(int q = 0; q < neighbor.neighbors.size(); ++q){
                            // if they have a common neighbor...
                            if(current.neighbors[p] == neighbor.neighbors[q]){
                                Vertex& target = verts[current.neighbors[p]];
                                if(target.color == current.color || target.color == neighbor.color){
                                    return "No";
                                }
                                // set target to only remaining available color
                                int colors[] = {1, 2, 3};
                                set<int> available(colors, colors + 3);
                                available.erase(current.color);
                                available.erase(neighbor.color);
                                target.color = *available.begin();
                            }
                        }
                    }
                    
                    // remove the neighbor that had a fixed color from the vertex list of the current vertex
                    current.neighbors.erase(remove(current.neighbors.begin(), current.neighbors.end(), neighbor.id), current.neighbors.end());
                    j = -1;
                }
            }
        }
        
        return "Yes";
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> cells, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ThreeColorabilityEasy *instance = new ThreeColorabilityEasy();
    string __result = instance->isColorable(cells);
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
            string cells[] = {"ZZZNN", "NNNZZ", "NNNZZ", "ZZZNN", "NNNZZ"};
            string __expected = "Yes";
            return do_test(to_vector(cells), __expected, __no);
        }
        case 1: {
            string cells[] = {
                "NZ",
                "NZ"
            };
            string __expected = "Yes";
            return do_test(to_vector(cells), __expected, __no);
        }
        case 2: {
            string cells[] = {
                "ZZZ",
                "ZNZ"
            };
            string __expected = "No";
            return do_test(to_vector(cells), __expected, __no);
        }
        case 3: {
            string cells[] = {
                "NZNZNNN",
                "NNZNNNZ",
                "NNNNZZZ",
                "ZZZNZZN",
                "ZZNZNNN",
                "NZZZZNN",
                "ZZZNZNN"
            };
            string __expected = "No";
            return do_test(to_vector(cells), __expected, __no);
        }
        case 4: {
            string cells[] = {
                "ZZZZ",
                "ZZZZ",
                "ZZZZ"
            };
            string __expected = "Yes";
            return do_test(to_vector(cells), __expected, __no);
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
    cout << "ThreeColorabilityEasy (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413085069;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
