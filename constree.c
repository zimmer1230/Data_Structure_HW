#include <stdio.h>

#define MAX_NODES 2000

int how_many_nodes, how_many_links, packet_size;
int nodes_weight[MAX_NODES];
int links_info[MAX_NODES][2];

struct node{
          int weight;
          int links_to[MAX_NODES];
          int num_edge;
          int explored;
          int dist_from_0;
}nodes[MAX_NODES];
void bfs(int p);

int main(){
          scanf("%d%d%d",&how_many_nodes,&how_many_links,&packet_size);
          for(int i=0;i<how_many_nodes;i++){
                    int index;
                    scanf("%d%d",&index,&nodes[index].weight);
          }
          for(int i=0;i<how_many_links;i++){
                    int index;
                    scanf("%d",&index);
                    int node_a, node_b;
                    scanf("%d%d",&node_a,&node_b);
                    nodes[node_a].links_to[ nodes[node_a].num_edge++ ] = node_b;
                    nodes[node_b].links_to[ nodes[node_b].num_edge++ ] = node_a;
          }

          bfs(0);

return 0;
}


void bfs(int p){


}

