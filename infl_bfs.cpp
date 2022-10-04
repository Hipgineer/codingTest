#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// BFS (Depth First Search) 깊이 우선 탐색

struct Vertex
{
    // int data
};

vector<Vertex> vertices;
vector< vector<int> > adjacent;
vector<bool> discovered;

void CreateGraph()
{
    vertices.resize(6);
    adjacent = vector< vector<int> >(6);
    adjacent[0].push_back(1);
    adjacent[0].push_back(3);
    adjacent[1].push_back(0);
    adjacent[1].push_back(2);
    adjacent[1].push_back(3);
    adjacent[3].push_back(4);
    adjacent[5].push_back(4);
}

void Bfs(int here)
{
    queue<int> q;
    q.push(here);
    discovered[here] = true;

    while (q.empty() == false)
    {
        here = q.front();
        q.pop();

        cout << "Visited : " << here << endl;
        for (int there : adjacent[here])
        {
            if (discovered[there])
            continue;

            q.push(there);
            discovered[there] = true;
        }
    }
}

int main()
{
    CreateGraph();
    discovered = vector<bool>(6, false);
    Bfs(0);
}
