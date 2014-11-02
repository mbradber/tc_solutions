#include <iostream>
#include <vector>
#include <deque>

#define MAX_WEIGHT 10000

using namespace std;

typedef pair<int, int> Edge;

struct Vertex{
    int id;
    int color;
    int parent;
    vector<Edge> neighbors;
    
    Vertex():id(-1), color(0), parent(-1){}
};

class Graph{
public:
    void AddEdge(int u, int v, int w){
        int m = max(u, v);
        if(m >= mVertices.size()){
            mVertices.resize(m+1);
        }
        
        mVertices[u].id = u;
        mVertices[v].id = v;
        mVertices[u].neighbors.push_back(make_pair(v, w));
    }
    
    void ShortestPath(int s, int v){
        vector<Edge> Q;
        
        for(int i = 0; i < mVertices.size(); ++i){
            mVertices[i].parent = -1;
            Q.push_back(make_pair(i, MAX_WEIGHT));
        }
        
        Q[s].second = 0;
        int count = 0;
        while(count < mVertices.size()){
            // find min-weight vertex in Q
            int minV = MAX_WEIGHT + 1;
            int minI = -1;
            for(int i = 0; i < Q.size(); ++i){
                if(Q[i].first >= 0){
                    if(Q[i].second < minV){
                        minV = Q[i].second;
                        minI = i;
                    }
                }
            }
            
            // update each of it's neighbors
            Vertex& vtx = mVertices[Q[minI].first];
            int wS = Q[minI].second;
            for(int i = 0; i < vtx.neighbors.size(); ++i){
                Edge& e = Q[vtx.neighbors[i].first];
                int wV = vtx.neighbors[i].second;
                
                if(wV + wS < e.second){
                    e.second = wV + wS;
                    mVertices[e.first].parent = vtx.id;
                }
            }
            
            // remove v from Q
            Q[minI].first = -1;
            count++;
        }
        
        deque<int> path;
        int curr = v;
        while(curr >= 0){
            path.push_front(curr);
            curr = mVertices[curr].parent;
        }
        
        // print path
        for(int i = 0; i < path.size(); ++i){
            cout << path[i];
            if(i < path.size() - 1){
                cout << " -> ";
            }
        }
        cout << endl;
    }
    
    void DFS(int s){
        for(int i = 0; i < mVertices.size(); ++i){
            mVertices[i].color = 0;
            mVertices[i].parent = -1;
        }
        
        DFSVisit(s);
    }
    
    void PrintGraph(){
        for(int i = 0; i < mVertices.size(); ++i){
            cout << mVertices[i].id << " -> ";
            for(int j = 0; j < mVertices[i].neighbors.size(); ++j){
                cout << mVertices[i].neighbors[j].first << "(" << mVertices[i].neighbors[j].second << ")" << ",";
            }
            cout << endl;
        }
    }
    
private:
    void DFSVisit(int s){
        cout << s << endl;
        Vertex& v = mVertices[s];
        v.color = 1;
        
        for(int i = 0; i < v.neighbors.size(); ++i){
            Vertex& n = mVertices[v.neighbors[i].first];
            if(n.color == 0){
                n.parent = s;
                DFSVisit(n.id);
            }
        }
        
        v.color = 2;
    }
    
private:
    vector<Vertex> mVertices;
};

int main(){
    
    Graph g;
    g.AddEdge(0, 1, 3);
    g.AddEdge(0, 2, 1);
    g.AddEdge(1, 3, 2);
    g.AddEdge(2, 1, 1);
    g.AddEdge(2, 3, 3);
    g.AddEdge(3, 5, 2);
    g.AddEdge(3, 4, 7);
    g.AddEdge(5, 6, 3);
    g.AddEdge(6, 4, 1);

//    g.PrintGraph();
//    g.DFS(0);
    g.ShortestPath(0, 4);
    
    return 0;
}