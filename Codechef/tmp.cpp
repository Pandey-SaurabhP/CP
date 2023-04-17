const long long inf = 100000000;
const long long mxn = 1e5;
    
class Graph {
public:
    
    vector <vector <pair <long long, long long>>> adj;
    long long gn;
    
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(mxn);
        gn = n + 1;
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
    }
    
    void printList(){
        for(long long i = 0; i < gn; ++i){
            cout << i << " : ";
            
            for(auto j : adj[i]){
                cout << j.first << " ";
            }
            
            cout << "\n";
        }
        
        cout << "-------------\n";
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        
        
        long long dist[gn + 1][gn + 1];
        
        for(long long i = 0; i < gn; ++i){
            for(long long j = 0; j < gn; ++j){
                dist[i][j] = inf;
            }
        }
        
    
        
        for(long long i = 0; i < gn; ++i){
            for(auto j : adj[i]){
                dist[i][j.first] = min(dist[i][j.first], j.second);
            }
        }
        
        for(long long k = 0; k < gn; ++k){
            for(long long i = 0; i < gn; ++i){
                for(long long j = 0; j < gn; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        return (dist[node1][node2] == inf? -1: dist[node1][node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * long long param_2 = obj->shortestPath(node1,node2);
 */