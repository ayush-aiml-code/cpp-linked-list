#include<iostream>
using namespace std;
struct Node
{
   int data;
   Node* next;
};

Node *first, *temp, *ttemp, *p;

void init(){
    first=temp=ttemp=p=NULL;
}

void create(int x){
    first = new Node;
    first->data=x;
    first->next=first;
}

void add_node(int x){
    temp=first;
    while(temp->next!=first){
        temp=temp->next;
    }
    ttemp = new Node;
    ttemp->data=x;
    ttemp->next=first;
    temp->next=ttemp;
}

void add_before_1st(int x){
    temp=first;
    while(temp->next!=first){
        temp=temp->next;
    }
    ttemp=new Node;
    ttemp->data=x;
    ttemp->next=first;
    temp->next=ttemp;
    first=ttemp;
}

void add_after_Last(int x){
    temp=first;
    while(temp->next!=first){
        temp=temp->next;
    }
    ttemp=new Node;
    ttemp->data=x;
    ttemp->next=first;
    temp->next=ttemp;
}

void Del_first(){
    temp=first;
    while (temp->next!=first)
    {
       temp=temp->next;
    }
    ttemp=first;
    first=first->next;
    temp->next=first;
    delete ttemp;
}

void del_last(){
    temp=first;
    while (temp->next!=first)
    {
        ttemp=temp;
        temp=temp->next;
    }
    ttemp->next=first;
    delete temp;
}

void add_before(int x, int y){
    temp=first;
    while (temp->data!=x)
    {
       ttemp=temp;
       temp=temp->next;
    }
    p=new Node;
    p->data=y;
    p->next=temp;
    ttemp->next=p;
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
    create(10);
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    display();
    cout<<endl;
    cout<<"Add a node Before 1st:-"<<endl;
    add_before_1st(50);
    display();
    cout<<endl;
    cout<<"Add a node After Last:-"<<endl;
    add_after_Last(60);
    display();
    cout<<endl;
    cout<<"Delete a First node:-"<<endl;
    Del_first();
    display();
    cout<<endl;
    cout<<"Delete a Last node:-"<<endl;
    del_last();
    display();
    cout<<endl;
    cout<<"Add Before:-"<<endl;
    add_before(30,25);
    display();
    cout<<endl;
    cout<<"Add After:-"<<endl;
    add_after(30,35);
    display();
    cout<<endl;
}