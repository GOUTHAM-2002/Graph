#include <iostream>
#include <list>
#include<vector>

using namespace std;

class Graph{
private:
        int V; //number of vertices
        vector<list<int>> adj; // adjacency list of integers
public:
    explicit Graph(int V):V(V),adj(V){}

    void addEdge(int v, int w){
        adj[v].push_back(w); // add w into v's list.

    }
    void display(){
        for(int i=0;i < V;i++){
            cout<< "Adjacency list of vertex " << i << ":\n head";
            for(auto x : adj[i])
                cout<<"->"<<x;
            cout<<endl;
        }
    }
    void Bfs(int a){
        vector<int> visited={0,0,0,0};
        vector<int> queue;
        int start = adj[0].front();
        queue.insert(queue.begin(),start);
        int popped;
        while(!queue.empty()){
            popped = queue[0];
            queue.erase(queue.begin());
            for(auto it : adj[popped]){
                if (it==a)
                    cout<<"Key found"<<" "<<a<<endl;
                if(visited[it]==0)
                    queue.push_back(it);
                visited[it]=1;
            }
        }


    }


};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.display();
    g.Bfs(1);
    return 0;
}
