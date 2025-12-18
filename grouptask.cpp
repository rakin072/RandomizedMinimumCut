#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v;
};

int func(vector<Edge> edges, int n)
{
    random_device rd;
    mt19937 gen(rd());
    int vertices = n;
    while (vertices > 2)
    {
        uniform_int_distribution<> dist(0, edges.size() - 1);
        int idx = dist(gen);
        int u = edges[idx].u;
        int v = edges[idx].v;
        for (auto &e : edges)
        {
            if (e.u == v)
                e.u = u;
            if (e.v == v)
                e.v = u;
        }
        vector<Edge> newEdges;
        for (auto &e : edges)
        {
            if (e.u != e.v)
                newEdges.push_back(e);
        }
        edges = newEdges;
        vertices--;
    }
    return edges.size();
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        fin >> edges[i].u >> edges[i].v;
    }
    fout << "Minimum Cut  " << func(edges, n) << endl;
    fin.close();
    fout.close();
    return 0;
}
