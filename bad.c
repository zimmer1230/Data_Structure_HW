#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20000

int how_many_nodes, how_many_links, packet_size;
struct node{
    int weight;
    int links_to[MAX_NODES];
    int num_edge;
    int explored;
    int parent_node;
    int dist_from_0;
    int ID;
}nodes[MAX_NODES];
struct comparing_for_dist{
int ID;
int dist;
}temp[MAX_NODES];
int cmp(const void* a, const void* b){
    struct comparing_for_dist aaa= *(struct comparing_for_dist*)a;
    struct comparing_for_dist bbb= *(struct comparing_for_dist*)b;
    return bbb.dist - aaa.dist;
}

int total_cost;

void bfs(int p);
void prt_QQ();

int main(){
    //getting input
    scanf("%d%d%d",&how_many_nodes,&how_many_links,&packet_size);
    for(int i=0;i<how_many_nodes;i++){
        int index;
        scanf("%d",&index);
        scanf("%d",&nodes[index].weight);
        nodes[i].ID=i;
    }
    for(int i=0;i<how_many_links;i++){
        int index;
        scanf("%d",&index);
        int node_a, node_b;
        scanf("%d%d",&node_a,&node_b);
        nodes[node_a].links_to[ nodes[node_a].num_edge++ ] = node_b;
        nodes[node_b].links_to[ nodes[node_b].num_edge++ ] = node_a;
    }
    //getting input

    //bfs for distance
    bfs(0);
    //bfs for distance

    // get the list of the node by distance
    for(int i=0;i<how_many_nodes;i++){
        temp[i].ID=nodes[i].ID;
        temp[i].dist=nodes[i].dist_from_0;
    }
    qsort(temp,how_many_nodes,sizeof(struct comparing_for_dist),cmp);
    // get the list of the node by distance

    //transfer weight and counting cost
    for(int i=0;i<how_many_nodes-1;i++){
        if( nodes[ temp[i].ID ].weight%packet_size==0 )
            total_cost+= (nodes[ temp[i].ID ].weight/packet_size);
        else
            total_cost+= (nodes[ temp[i].ID ].weight/packet_size)+1;
        nodes[ nodes[ temp[i].ID ].parent_node ].weight += nodes[ temp[i].ID ].weight;
    }
    //transfer weight and counting cost


    //output
    printf("%d %d\n0 0\n",how_many_nodes,total_cost);
    for(int i=1;i<how_many_nodes;i++){
        printf("%d %d\n",i,nodes[i].parent_node );
    }
    //output


return 0;
}

int QQ[MAX_NODES];
int QQ_index=0;
void bfs(int p){
    nodes[p].explored=1;
    //add 0's adjacent nodes to QQ
    for( int i=0;i<nodes[p].num_edge; i++ ){
        if( nodes[ nodes[p].links_to[i] ].explored==0 ){
            nodes[ nodes[p].links_to[i] ].dist_from_0 = nodes[p].dist_from_0 + 1;
            nodes[ nodes[p].links_to[i] ].parent_node = p;
            QQ[QQ_index++]=nodes[p].links_to[i];
        }
    }
    //add 0's adjacent nodes to QQ

    //doing bfs
    for( int i=0; i<QQ_index; i++ ){
        nodes[  QQ[i]  ].explored = 1;
        for( int j=0; j<nodes[ QQ[i] ].num_edge; j++ ){
             if( nodes[ nodes[ QQ[i] ].links_to[j] ].explored == 1 ) continue;
             QQ[QQ_index++] = nodes[ QQ[i] ].links_to[j];
             nodes[ nodes[ QQ[i] ].links_to[j] ].parent_node = QQ[i];
             nodes[ nodes[ QQ[i] ].links_to[j] ].dist_from_0 = nodes[  QQ[i]  ].dist_from_0+1;
        }
    }
    //doing bfs

}
void prt_QQ(){
    for(int i=0;i<QQ_index;i++){
        printf("%d ",QQ[i]);
    }
}

