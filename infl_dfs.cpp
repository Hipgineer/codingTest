#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// DFS (Depth First Search) 깊이 우선 탐색

struct Vertex
{
    // int data
};

vector<Vertex> vertices;
vector< vector<int> > adjacent;
vector<bool> visited;

void CreateGraph()
{
    vertices.resize(6);
    adjacent = vector< vector<int> >(6);
    adjacent[0].push_back(1);
    adjacent[0].push_back(3);
    adjacent[2].push_back(0);
    adjacent[2].push_back(2);
    adjacent[2].push_back(3);
    adjacent[3].push_back(4);
    adjacent[5].push_back(4);
}

void Dfs(int here)
{
    visited[here] = true;
    cout << "Visited : " << here << endl;
    for (int i =0; i <adjacent[here].size(); i++)
    {
        int there = adjacent[here][i];
        if(visited[there] == false)
            Dfs(there);
    }
}

void DfsAll()
{
    visited = vector<bool>(6,false);

    for (int i = 0 ; i < 6 ; i++)
    {
        if (visited[i] == false)
            Dfs(i);
    }
}

int main()
{
    CreateGraph();

    DfsAll();
}
