#include <stdio.h>
#include <math.h>

#define MAX_NODES 10000
int power,noise;
int how_many_nodes;
int how_many_links;
int how_many_valid_links;

struct node{
    double x;
    double y;
    int transmit_num;
    struct node* transmit_to[MAX_NODES];
    int is_transmitter;
    int node_id;
};
typedef struct node node;

struct link{
    node* transmitter;
    node* receiver;
    double distance_t_r;
    int link_id;
};
typedef struct link link;

node nodes[MAX_NODES];
link links[MAX_NODES*5];
link* valid_links[MAX_NODES*5];

double dist(node*,node*);
int is_valid_to_append(link*);
int is_valid_links_valid();
void append(link*);
void pop();

int main(){
    /* Get input */
    scanf("%d%d%d%d",&how_many_nodes,&how_many_links,&power,&noise);
    for(int i=0;i<how_many_nodes;i++){
        int node_id;
        scanf("%d",&node_id);
        nodes[node_id].node_id=node_id;
        scanf("%lf%lf",&nodes[node_id].x,&nodes[node_id].y);
    }
    for(int i=0;i<how_many_links;i++){
        int link_id,node_1,node_2;
        scanf("%d",&link_id);
        scanf("%d%d",&node_1,&node_2);
        nodes[node_1].transmit_to[nodes[node_1].transmit_num++ ] = &nodes[node_2];
        links[link_id].transmitter=&nodes[node_1];
        links[link_id].receiver=&nodes[node_2];
        links[link_id].distance_t_r = dist(links[link_id].transmitter,links[link_id].receiver);
        links[link_id].link_id = link_id;
        nodes[node_1].is_transmitter=1;
    }

    for(int i=0;i<how_many_links;i++){
        is_valid_to_append(&links[i]);
    }


    /*Output*/
    printf("%d\n",how_many_valid_links);
    for(int i=0;i<how_many_valid_links;i++){
        printf("%d %d %d\n",valid_links[i]->link_id,valid_links[i]->transmitter->node_id,valid_links[i]->receiver->node_id);
    }


    return 0;
}

double dist(node* node_1,node* node_2){
        double dx=(node_1->x)-(node_2->x);
        double dy=(node_1->y)-(node_2->y);
    return sqrt(dx*dx+dy*dy);
}

double other_noise_counting( link* other, link* to_append ){ // dl^3/dl'^3
    double tmp;
    tmp = dist( other->transmitter, to_append->receiver );
    return pow(to_append->distance_t_r,3)/pow(tmp,3);
}

int is_receiveable(link* receiver){
    double other_noise=0;
    for(int i=0;i<how_many_valid_links;i++){
        if(receiver->link_id==valid_links[i]->link_id) continue;
        other_noise+=other_noise_counting(valid_links[i],receiver);
    }
    double tmp = noise * pow(receiver->distance_t_r,3) / power;
    if (other_noise + tmp < 1)
        return 1;
    else
        return 0;
}

int is_valid_to_append(link* link_to_append){
    append(link_to_append);
    if ( is_valid_links_valid() ){
        return 1;
    }
    else
        pop();
    return 0;
}

int is_valid_links_valid(){
    for(int i=0;i<how_many_valid_links;i++){
        if(!is_receiveable(valid_links[i]))
            return 0;
    }
    return 1;
}




void append(link* to_append){
    valid_links[how_many_valid_links++]=to_append;
}
void pop(){
    how_many_valid_links--;
}
