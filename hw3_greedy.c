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
    int is_transmitter;
};
typedef struct node node;

struct link{
    node* transmitter;
    node* receiver;
};
typedef struct link link;

node nodes[MAX_NODES];
link links[MAX_NODES*5];

int is_valid_to_append();
void append();

int main(){
    /* Get input */
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
        links[link_id].transmitter=&nodes[node_1];
        links[link_id].receiver=&nodes[node_2];
        nodes[node_1].is_transmitter=1;
    }

    for(int i=0;i<how_many_links;i++){
        if( is_valid_to_append() ){
            append();
        }

    }


    return 0;
}

double current_

int is_valid_to_append(){


}
