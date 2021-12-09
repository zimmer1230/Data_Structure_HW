#include <stdio.h>

#define MAX_NODES 10000
int power,noise;
int how_many_nodes;
int how_many_links;

struct node{
    double x;
    double y;
    int transmit_num;
    struct node* transmit_to[MAX_NODES];
};
typedef struct node node;

node nodes[MAX_NODES];


int main(){
    scanf("%d%d%d%d",&how_many_nodes,&how_many_links,&power,&noise);
    for(int i=0;i<how_many_nodes;i++){
        int node_id;
        scanf("%d",&node_id);
        scanf("%lf%lf",&nodes[node_id].x,&nodes[node_id].y);
    }
    for(int i=0;i<how_many_links;i++){
        int link_id,node_1,node_2;
        scanf("%d",&link_id);
        scanf("%d%d",&node_1,&node_2);
        nodes[node_1].transmit_to[nodes[node_1].transmit_num++ ] = &nodes[node_2];
    }

    return 0;
}
