#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev, *next;
};

Node *first, *temp, *ttemp, *p;

void init(){
    first=temp=NULL;
}

void create(int x){
    first= new Node;
    first->data=x;
    first->next=NULL;
    first->prev=NULL;
}

void add_before_1st(int x){
    temp=first;
    ttemp=new Node;
    ttemp->data=x;
    ttemp->next=temp;
    ttemp->prev=NULL;
    temp->prev=ttemp;
    first=ttemp;
}

void add_after_last(int x){
    temp=first;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    ttemp=new Node;
    ttemp->data=x;
    ttemp->next=NULL;
    ttemp->prev=temp;
    temp->next=ttemp;
}

void add_before(int x,int y){
    temp=first;
    while (temp->data!=x)
    {
        ttemp=temp;
        temp=temp->next;
    }
    p=new Node;
    p->data=y;
    p->next=temp;
    p->prev=ttemp;
    ttemp->next=p;
    temp->prev=p;
}

void add_after(int x,int y){
    temp=first;
    while (temp->data!=x)
    {
        temp=temp->next;
    }
    ttemp=temp->next;
    p=new Node;
    p->data=y;
    p->next=ttemp;
    p->prev=temp;
    temp->next=p;
}

void add_node(int x){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp=new Node;
    ttemp->data=x;
    ttemp->prev=temp;
    ttemp->next=NULL;
    temp->next=ttemp;
}

void swap_last_2ndLast(){
    temp=first;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    ttemp=temp->prev;
    p=ttemp->prev;
    p->next=temp;
    temp->prev=p;
    temp->next=ttemp;
    ttemp->prev=temp;
    ttemp->next=NULL;
}

void swap_1st_last(){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp=temp->prev;
    p=first->next;
    temp->next=p;
    p->prev=temp;
    temp->prev=NULL;
    ttemp->next=first;
    first->prev=ttemp;
    first->next=NULL;
    first=temp;
}

void swap_1st_2nd(){
    temp=first->next;
    ttemp=temp->next;
    ttemp->prev=first;
    first->next=ttemp;
    first->prev=temp;
    temp->next=first;
    temp->prev=NULL;
    first=temp;
}

void dis(){
    temp=first;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    init();
    create(10);
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    add_node(60);
    add_node(70);
    dis();
    cout<<endl;
    cout<<"add Before 1st Node:-"<<endl;
    add_before_1st(5);
    dis();
    cout<<endl;
    cout<<"add After last Node:-"<<endl;
    add_after_last(75);
    dis();
    cout<<endl;
    cout<<"add Before (50):-"<<endl;
    add_before(50,45);
    dis();
    cout<<endl;
    cout<<"add After (50):-"<<endl;
    add_after(50,55);
    dis();
    cout<<endl;
    cout<<"Swap last and 2nd last:-"<<endl;
    swap_last_2ndLast();
    dis();
    cout<<endl;
    cout<<"Swap 1st and last:-"<<endl;
    swap_1st_last();
    dis();
    cout<<endl;
    cout<<"Swap 1st and 2nd:-"<<endl;
    swap_1st_2nd();
    dis();
}