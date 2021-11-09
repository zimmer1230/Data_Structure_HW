#include <stdio.h>

#define MAX_NODES 2000

int how_many_nodes, how_many_links, packet_size;
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
    for(int i=0; i<how_many_nodes;i++){
        printf("%d %d %d %d %d\n",nodes[i].weight,nodes[i].links_to[0],nodes[i].weight,nodes[i].explored,nodes[i].dist_from_0);
    }

    for(int i=0;i<how_many_nodes;i++){
        int index;
        scanf("%d",&index);
        scanf("%d",&nodes[index].weight);
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
    for(int i=0; i<how_many_nodes;i++){
        printf("%d %d %d %d %d\n",nodes[i].weight,nodes[i].links_to[0],
               nodes[i].num_edge,nodes[i].explored,nodes[i].dist_from_0);
    }



return 0;
}

int QQ[MAX_NODES];
int QQ_index=0;
void bfs(int p){
    nodes[p].explored=1;
    for( int i=0;i<nodes[p].num_edge; i++ ){
        if( nodes[ nodes[p].links_to[i] ].explored==0 ){
            nodes[ nodes[p].links_to[i] ].dist_from_0 = nodes[p].dist_from_0 + 1;
            QQ[QQ_index++]=nodes[p].links_to[i];
        }
    }
    for( int i=0; i<QQ_index; i++ ){
        nodes[ QQ[i] ].explored=1;
        for( int j=0; j<nodes[ QQ[i] ].num_edge; j++ ){
            if( nodes[ nodes[ QQ[i] ].links_to[j] ].explored == 0 ){
                nodes[ nodes[ QQ[i] ].links_to[j] ].dist_from_0 = nodes[ QQ[i] ].dist_from_0 + 1;
                QQ[QQ_index++]=nodes[ QQ[i] ].links_to[j];
            }
        }
    }

}

