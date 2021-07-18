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
// bellman ford


bool Bellnam_visit[Size];
int Bellman_distance[Size];
int Bellman_graph[Size][3]; /// three places one for from node value , one for to node value , one for distance value


int  Bellman(int source, int distination,int nodes_number,int bridges_number){
for(int i=0;i<Size;i++){

    Bellman_distance[i]=2e9;

}
Bellman_distance[source]=0;
for (int node =0;node <= nodes_number-1; node++ ){
    for(int bridge=0;bridge<bridges_number;bridge++){
            int current_bridge[3];
            current_bridge[0]=Bellman_graph[bridge][0];
            current_bridge[1]=Bellman_graph[bridge][1];
            current_bridge[2]=Bellman_graph[bridge][2];
        if (Bellman_distance[ current_bridge[1] ] >Bellman_distance[ current_bridge[0] ] + current_bridge[2])

        Bellman_distance[ current_bridge[1] ] = Bellman_distance[ current_bridge[0] ] + current_bridge[2];

    }



}


return Bellman_distance[distination];
}

////////////////////////////////
/// warshall

int warshall_distance[Size][Size];

int warshall(int source ,int  distination,int nodes_number ){

for(int k=0;k<=nodes_number;k++){
    for(int i=0;i<=nodes_number;i++){
        for(int j=0;j<=nodes_number;j++){
            warshall_distance[i][j]=min(warshall_distance[i][j],warshall_distance[i][k]+warshall_distance[k][j]);




        }
    }



}



return warshall_distance[source][distination];

}


int main()
{
//    vector<int> graph[]={ {},{4,8},{},{},{},{7,1,6},{9},{2,3},{},{}
//    };
//    vector<pair<int,int>> dijkstra_graph[]={  {{1,1},{2,3} },{{0,1},{2,1}},{{0,2},{1,1}}};
//    cout<<dijkstra(0,2)<<endl;
    ///// bellman usage
//    int n,m,from ,to,cost;
//    cout<<"please enter numer of node and brideges: ";
//
//    cin>>n>>m;
//    cout<<"please enter "<<m<<"of lines with three separated values from , to ,cost: ";
//    for(int bridge=0;bridge<m;bridge++){
//        cin>> Bellman_graph[bridge][0]>>Bellman_graph[bridge][1]>>Bellman_graph[bridge][2];
//    }
//    int source,distination;
//    cout<< "enter source and distination: ";
//    cin>>source>>distination;
//    cout<<"shortest distance is : "<< Bellman(source,distination,n,m);


////////////////////
    int nodes_number;
    cout<<"enter number of nodes: ";
    cin>>nodes_number;
    int column,row;
    for(int column=0;column<=nodes_number;column++){  /// initial distances to inifinte
        for(int row=0;row<=nodes_number;row++) warshall_distance[column][row]=10000;
    }
    for(int i=0;i<5;i++){
cin>>column>>row>>warshall_distance[column][row];
        cout<<"entered"<<endl;
    }
    int source,distination;
    cout<<"source and distination: ";
    cin>> source>> distination;

    cout<<"shortest path from " << source<<" to "<< distination<< " is: "<<warshall(source,distination,nodes_number)<<endl;
    return 0;
}
