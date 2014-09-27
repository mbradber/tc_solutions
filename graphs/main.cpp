#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex{
    int id;
    int color;
    int pred;
    int dist;
    vector<int> neighbors;
    
    Vertex(){
        id = -1;
        Reset();
    }
    
    void Reset(){
        color = 0;
        pred = -1;
        dist = 0;
    }
};

class Graph{
public:
    
    Graph(int n){
        m_vVertices.resize(n);
        for(int i = 0; i < n; ++i){
            m_vVertices[i].id = i;
        }
    }
    
    void AddEdge(int u, int v){
        m_vVertices[u].neighbors.push_back(v);
    }
    
    void PrintNeighbors(int u){
        for(int i = 0; i < m_vVertices[u].neighbors.size(); ++i){
            cout << m_vVertices[u].neighbors[i] << ",";
        }
        cout << endl;
    }
    
    void BFS(int s){
        m_vVertices[s].color = 1; // gray
        m_vVertices[s].pred = -1;
        m_vVertices[s].dist = 0;
        
        queue<int> frontier;
        frontier.push(s);
        while(frontier.size() > 0){
            int v = frontier.front();
            frontier.pop();
            
            for(int i = 0; i < m_vVertices[v].neighbors.size(); ++i){
                int neighbor = m_vVertices[v].neighbors[i];
                if(m_vVertices[neighbor].color == 0){ // white?
                    m_vVertices[neighbor].pred = v;
                    m_vVertices[neighbor].color = 1;
                    m_vVertices[neighbor].dist = m_vVertices[v].dist + 1;
                    frontier.push(neighbor);
                }
            }
        }
    }
    
    int Distance(int u, int v){
        BFS(u);
        return m_vVertices[v].dist;
    }
    
    void PrintPath(int u, int v){
        BFS(u);
        PrintPath(v);
    }
    
    void ResetGraph(){
        for(int i = 0; i < m_vVertices.size(); ++i){
            m_vVertices[i].Reset();
        }
    }
    
    void DFS(){
        ResetGraph();
        
        for(int i = 0; i < m_vVertices.size(); ++i){
            if(m_vVertices[i].pred < 0){
                DFS_Visit(i);
            }
        }
    }
    
private:
    
    void DFS_Visit(int s){
        cout << s << ",";
        m_vVertices[s].color = 1;
        vector<int> neighbors = m_vVertices[s].neighbors;
        for(int i = 0; i < neighbors.size(); ++i){
            if(m_vVertices[neighbors[i]].color == 0){
                m_vVertices[neighbors[i]].pred = s;
                DFS_Visit(neighbors[i]);
            }
        }
    }
    
    void PrintPath(int v){
        if(m_vVertices[v].pred >= 0){
            PrintPath(m_vVertices[v].pred);
        }
        
        cout << m_vVertices[v].id << ",";
    }
    
private:
    vector<Vertex> m_vVertices;
};

int main(){
    
    /*
     
     0 ### 2 #### 4
     # #         #
     #  #       #
     #   #     #
     #    #   #
     #     # #
     #      #
     1      3
     
     */
    
    Graph g(5);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(0, 3);
    
    g.AddEdge(2, 0);
    g.AddEdge(2, 4);
    
    g.AddEdge(3, 0);
    g.AddEdge(3, 4);
    
    g.AddEdge(4, 2);
    g.AddEdge(4, 3);
    
    //g.PrintPath(4, 1);
    g.DFS();
    
    
    return 0;
}