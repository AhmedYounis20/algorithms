#include <bits/stdc++.h>
#define Size 10000
using namespace std;


//////////////////////
//// dfs explore
bool DFS_visit[Size];
vector<int> DFS(vector<int> graph[], int source){
vector<int> DFS_result;
DFS_visit[source]=1;
DFS_result.push_back(source);
cout<<source <<' ';
for(int item: graph[source]){

    if(! DFS_visit[item]){
        DFS(graph,item);
    }
}

return DFS_result;

}
//////////////////////////
//// Bfs explore
bool Bfs_visit[Size];

void BFS(vector<int> graph[],int source){
queue<int> BFS_Queue;
BFS_Queue.push(source);
while(!BFS_Queue.empty())
{
    int current_node= BFS_Queue.front();
    BFS_Queue.pop();
    cout<<current_node<<' ';
    Bfs_visit[current_node]=1;
    for (int node : graph[current_node]){
       if (!Bfs_visit[node]) BFS_Queue.push(node);
    }
}
}
////////////////////////////////////////////////////



/////////////////
/// single source shortest path


// first dijkstra's algorithm


vector<pair <int,int>> graph1[]={  {{1,1},{2,3}},{{0,1},{2,1}},{{0,4},{1,1}}};
int dijkstra_distance[Size];
bool dijkstra_visit[Size];



int dijkstra( int source,int distination,vector<pair<int,int>> graph[]=graph1){

    for (int node=0;node<Size;node++){
        dijkstra_distance[node]=2e9;

    }
    dijkstra_distance[source]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> > dijkstra_queue;

    dijkstra_queue.push({source,dijkstra_distance[source]});

    while(!dijkstra_queue.empty()){

        pair<int,int> node_data=dijkstra_queue.top();
        dijkstra_queue.pop();
        int node = node_data.first, distance=node_data.second;
        if (dijkstra_visit[node]) continue;
        dijkstra_visit[node]=1;
        for (int nighbour=0;nighbour<graph[node].size();nighbour++){
            pair<int,int> neighbour_data=graph[node][nighbour];
                int neighbour_node=neighbour_data.first;
                int neighbour_distance=neighbour_data.second;
                if (dijkstra_distance[neighbour_node]> neighbour_distance+dijkstra_distance[node]){
                    dijkstra_distance[neighbour_node]= neighbour_distance+dijkstra_distance[node];

            dijkstra_queue.push({neighbour_node,dijkstra_distance[neighbour_node]});

                }

        }







    }




    return dijkstra_distance[distination];

}
//



int main()
{
    vector<int> graph[]={ {},{4,8},{},{},{},{7,1,6},{9},{2,3},{},{}
    };
    vector<pair<int,int>> dijkstra_graph[]={  {{1,1},{2,3} },{{0,1},{2,1}},{{0,2},{1,1}}};
    cout<<dijkstra(0,2);
    return 0;
}
