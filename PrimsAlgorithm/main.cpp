#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;

//Tracker for visited and unvisited nodes
bool marked[MAX];

// Adjacency List for the graph
// NODE X ->  (Weight, Y) | (Weight, Z)...
vector <PII> adj[MAX];

//Prim's Algorithm for Minimum Spanning Tree, returns minimumCost of the tree
// Parameter can be any arbitrary starting node of the graph
long long prim(int x);

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;

    cin >> nodes >> edges;

    //Constructing the adjacency list for undirected graph with edge weight.
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }

    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

long long prim(int x)
{
    //Priority queues are like queues, we can only access top element, however, top element will be the one with greatest value (it will have highest priority)
    //greater<> will reverse it. Hence, smallest element will have highest priority.
    //For Prim's we need least weight edge first. Hence PQ.
    priority_queue<PII, vector<PII>, greater<PII> > Q;

    int y;
    long long minimumCost = 0;
    PII p;

    //The first starting node, will have 0 cost when added to Minimum Spanning Tree.
    Q.push(make_pair(0, x));

    //Where we still have edges that are not in the minimum spanning tree
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        //Remove from queue
        Q.pop();

        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        //Now all the edges connected with this vertex are eligible to be in PQ, if they ain't already visited.
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}
