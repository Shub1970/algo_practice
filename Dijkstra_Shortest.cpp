#include <iostream>
#include <vector>
#include <list>
#include <queue>
#define INF 9999
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *hlist;
    vector<int> dist;
    vector<int> count_block;
    vector<int> temp_dist;

public:
    Graph(int V_) : V(V_)
    {
        count_block.assign(V, 0);
        hlist = new list<pair<int, int>>[V];
        dist.assign(V, INF);
        count_block.assign(V, 0);
        temp_dist.assign(V, INF);
    }
    void addEdge(int u, int v, int w)
    {
        hlist[u].push_back(make_pair(v, w));
        hlist[v].push_back(make_pair(u, w));
    }
    void dijkstra(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto i : hlist[u])
            {
                int v = i.first;
                int w = i.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (auto x : dist)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    void no_of_shortestpath(int src)
    {
        dijkstra(src);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, src));
        temp_dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto i : hlist[u])
            {
                int v = i.first;
                int w = i.second;
                if (temp_dist[v] > temp_dist[u] + w)
                {
                    temp_dist[v] = temp_dist[u] + w;
                    pq.push(make_pair(temp_dist[v], v));
                }
                if (temp_dist[u] + w == dist[v])
                {
                    count_block[v]++;
                }
            }
        }
        for (auto x : count_block)
        {
            cout << x << " ";
        }
    }
};
int main()
{
    int V = 6;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 1, 6);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 1, 5);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 3, 3);
    g.addEdge(2, 4, 4);
    g.no_of_shortestpath(0);

    return 0;
}