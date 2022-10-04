#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>

using namespace std;

struct Vertex
{
    // int data;
};

vector<Vertex> vertices;
vector<vector<int> > adjacent;
vector<int> discovered;

void CreateGraph()
{
    vertices.resize(6);
    adjacent = vector<vector<int> >(6, vector<int>(6, -1));
    adjacent[0][1] = 15;
    adjacent[0][3] = 35;
    adjacent[1][0] = 15;
    adjacent[1][2] = 5;
    adjacent[1][3] = 10;
    adjacent[3][4] = 5;
    adjacent[5][4] = 5;
    discovered = vector<int>(6, false);
}

void Daijstra(int here)
{
    struct VertexCost
    {
        int vertex;
        int cost;

        VertexCost(int a, int b)
        { 
            vertex = a ;
            cost = b;
        };
    };

    list<VertexCost> discovered;
    vector<int> best(6, INT32_MAX);

    discovered.push_back(VertexCost(here, 0));
    best[here] = 0;

    while (discovered.empty() == false)
    {
        list<VertexCost>::iterator bestIt;
        int bestCost = INT32_MAX;

        for (auto it = discovered.begin(); it != discovered.end(); it++)
        {
            const int vertex = it->vertex;
            const int cost = it->vertex;   

            if (cost < bestCost)
            {
                bestCost = cost;
                bestIt = it;
            }
        }

        int cost = bestIt->cost;
        here = bestIt->vertex;
        discovered.erase(bestIt);

        if (best[here] < cost)
            continue;

        for (int there = 0 ;  there < 6 ; there++)
        {
            if (adjacent[here][there] == -1)
                continue;

            int nextCost = best[here] + adjacent[here][there];
            if (nextCost >= best[there])
                continue;

            best[there] = nextCost;

            discovered.push_back( VertexCost(there, nextCost) );
        }

        cout << " Vertex :" << here << endl;
    }
    int a;
}

int main()
{
    CreateGraph();

    Daijstra(0);
}
