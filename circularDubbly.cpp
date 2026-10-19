#include<iostream>
using namespace std;
struct Node
{
   int data;
   Node *prev, *next;
};

Node *first, *temp, *ttemp, *p;

void init(){
    first=temp=ttemp=p=NULL;
}

void create(int x){
    first= new Node;
    first->data=x;
    first->next=first;
    first->prev=first;
}

void add_node(int x){
    temp=first->prev;
    while (temp->next!=first)
    {
        temp=temp->next;
    }
    ttemp=new Node;
    ttemp->data=x;
    ttemp->next=first;
    first->prev=ttemp;
    temp->next=ttemp;
    first->prev=temp;
}

void swap_1st_2nd(){
    temp=first->next;
    ttemp=temp->next;
    p=first->prev;

    first->next=ttemp;
    ttemp->prev=first;

    temp->prev=p;
    temp->next=first;

    p->next=temp;
    first->prev=temp;

    first=temp;
}

void swap_1st_last(){
    temp=first->next;
    p=first->prev;
    ttemp=p->prev;
    ttemp->next=first;
    first->prev=ttemp;
    first->next=p;
    p->next=temp;
    p->prev=first;
    temp->next=p;
}

void display(){
    temp=first;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while (temp!=first);
    cout<<endl;
}

int main(){
    init();
    create(1);
    add_node(2);
    add_node(3);
    add_node(4);
    display();
    cout<<endl;
    cout<<"Swap 1st and 2nd:-"<<endl;
    swap_1st_2nd();
    display();
    cout<<endl;
    cout<<"Swap 1st and Last:-"<<endl;
    swap_1st_last();
    display();
}
