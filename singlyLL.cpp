#include<iostream>
using namespace std;
struct Node
{
   int data;
   Node* next;
};

Node *first,*temp,*ttemp,*p;

void init(){
    first=temp=NULL;
}

void create(int x){
    first= new Node;
    first->data=x;
    first->next=NULL;
}

void add_node(int x){
    temp=first;
    while (temp->next!=NULL)
    {
       temp=temp->next;
    }
    ttemp= new Node;
    ttemp->data=x;
    ttemp->next=NULL;
    temp->next=ttemp;
}

void add_before1st(int x){
    temp=first;
    ttemp= new Node;
    ttemp->data=x;
    ttemp->next=temp;
    first=ttemp;
}

void add_AfterLast(int x){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp= new Node;
    ttemp->data=x;
    ttemp->next=NULL;
    temp->next=ttemp;
}

void add_before(int x, int y){
    temp=first;
    while(temp->data!=x){
        ttemp=temp;
        temp=temp->next;
    }
    p = new Node;
    p->data=y;
    p->next=temp;
    ttemp->next=p;
}

void add_after(int x, int y){
    temp=first;
    while(temp->data!=x){
        temp=temp->next;
    }
    p= new Node;
    p->data=y;
    p->next=temp->next;
    temp->next=p;
}

void del_1st(){
    temp=first;
    first=first->next;
    delete temp;
}

void del_last(){
    temp=first;
    while(temp->next!=NULL){
        ttemp=temp;
        temp=temp->next;
    }
    ttemp->next=NULL;
    delete temp;
}

void del_before(int x){
    temp=first;
    while(temp->next->data!=x){
        ttemp=temp;
        temp=temp->next;
    }
    p=temp->next;
    ttemp->next=p;
    delete temp;
}

void del_after(int x){
    temp=first;
    while(temp->data!=x){
        temp=temp->next;
    }
    ttemp=temp->next;
    temp->next=ttemp->next;
    delete ttemp;
}

void swap_1st_2nd()
{
    temp=first;
    ttemp=first->next;
    temp->next=ttemp->next;
    ttemp->next=temp;
    first=ttemp;
}

void swap_1st_last(){
    temp=first;
    while (temp->next!=NULL)
    {
       ttemp=temp;
       temp=temp->next;
    }
    p=first->next;
    first->next=NULL;
    ttemp->next=first;
    temp->next=p;
    first=temp;
}

void swap_last_2ndLast(){
    temp=first;
    while (temp->next->next!=NULL)
    {
       ttemp=temp;
       temp=temp->next;
    }
   p=temp->next;
   temp->next=NULL;
   p->next=temp;
   ttemp->next=p; 
}

void revers(){
    p=NULL;
    temp=first;
    while (temp!=NULL)
    {
        ttemp=temp;
        temp=temp->next;
        ttemp->next=p;
        p=ttemp;
    }
    if(p!=NULL)
        first=p;
}

void display(){
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
    display();
    cout<<endl;
    cout<<"Add a node Before the 1st Node:-"<<endl;
    add_before1st(5);
    display();
    cout<<endl;
    cout<<"Add a node After the Last Node:-"<<endl;
    add_AfterLast(75);
    display();
    cout<<endl;
    cout<<"Add Before:-"<<endl;
    add_before(50,45);
    display();
    cout<<endl;
    cout<<"Add After:-"<<endl;
    add_after(30,35);
    display();
    cout<<endl;
    cout<<"Delete 1st:-"<<endl;
    del_1st();
    display();
    cout<<endl;
    cout<<"Delete Last:-"<<endl;
    del_last();
    display();
    cout<<endl;
    cout<<"Delete Before:-"<<endl;
    del_before(40);
    display();
    cout<<endl;
    cout<<"Delete After:-"<<endl;
    del_after(40);
    display();
    cout<<endl;
    cout<<"Revers :-"<<endl;
    revers();
    display();
    cout<<endl;
    cout << "Swap First and Second Node:-" << endl;
    swap_1st_2nd();
    display();
    cout<<endl;
    cout << "Swap First and Last Node:-" << endl;
    swap_1st_last();
    display();
    cout<<endl;
    cout << "Swap 2nd last and Last Node:-" << endl;
    swap_last_2ndLast();
    display();
    cout<<endl;
}
