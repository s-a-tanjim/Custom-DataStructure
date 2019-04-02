//It contains extra functions which may have complexity of N [O(N)]
#include<iostream>
#include<cstdio>
#define dbg(x) {cout<<#x<<" --- "<<x<<endl;}
using namespace std;

template <typename TYPE>
struct NODE{
    TYPE value;
    NODE *next;
};

template <class TYPE>
class MyLinkedList{
    NODE<TYPE> *head,*tail;
    int Size;
public:
    MyLinkedList(){                         //Constructor
        head=NULL;
        tail=NULL;
        Size=0;
    }
    MyLinkedList(const MyLinkedList &x){     //Copy Constructor
        if(x.head==NULL){
            head=tail=NULL;
            Size=0;
        }
        else{
            Size=0;
            NODE<TYPE> *temp=x.head;
            NODE<TYPE> *temp2=new NODE<TYPE>,*temp3;
            head=temp2;
            head->value=temp->value;
            Size++;
            temp=temp->next;
            while(temp!=NULL)
            {
                temp3 = new NODE<TYPE>;
                temp3->value=temp->value;
                temp=temp->next;
                temp2->next=temp3;
                temp2=temp2->next;
                Size++;
            }
            temp2->next=NULL;
            tail=temp2;
        }
    }
    void push_front(TYPE x){
        NODE<TYPE> *temp= new NODE<TYPE>;
        temp->value=x;
        if(head==NULL){
            temp->next=NULL;
            head=tail=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
        Size++;
    }
    void push_back(TYPE x){
        NODE<TYPE> *temp=new NODE<TYPE>;
        temp->value=x;
        temp->next=NULL;
        if(head==NULL){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }
        Size++;
    }
    TYPE pop_front(){
        if(head==NULL){
            printf("List is empty!!\n");
            return -1;
        }
        Size--;
        NODE<TYPE> *temp=head;
        TYPE x=temp->value;
        if(head==tail){
            delete temp;
            head=tail=NULL;
            return x;
        }
        head=head->next;
        delete temp;
        return x;
    }
    TYPE pop_back(){                 //Order of N!!
        if(head==NULL){
            printf("List is Empty!!\n");
            return -1;
        }
        TYPE x;
        NODE<TYPE> *temp=head,*temp2;
        if(head->next==NULL){
            x=head->value;
            delete head;
            head=tail=NULL;
            return x;
        }
        while(temp->next->next!=NULL) temp=temp->next;
        temp2=temp->next;
        temp->next=NULL;
        tail=temp;
        x=temp2->value;
        delete temp2;
        return x;
    }
    void display(){
        NODE<TYPE> *temp=head;
        while(temp!=NULL){
            cout<<temp->value<<"   ";
            temp=temp->next;
        }
        printf("\n");
    }
    int search(TYPE x){
        NODE<TYPE> *temp=head;
        int pos=0;
        if(head==NULL) return -1;
        while(temp!=NULL){
            if(temp->value==x) return pos;
            temp=temp->next;
            pos++;
        }
        return -1;
    }
    int size(){
        return Size;
    }
    TYPE front(){
        if(head!=NULL) return head->value;
        return -1;
    }
    TYPE back(){
        if(tail!=NULL) return tail->value;
        return -1;
    }
    bool empty(){
        if(Size==0) return true;
        return false;
    }
    ~MyLinkedList(){
        NODE<TYPE> *temp;
        while(head!=NULL){
            temp=head;
            head=head->next;
            delete temp;
        }
        tail=NULL;
        Size=0;
    }
};

template <class TYPE>
class MyStack{
    MyLinkedList<TYPE> ll;
public:
    void push(TYPE x)
    {
        ll.push_front(x);
    }
    TYPE pop()
    {
        return ll.pop_front();
    }
    TYPE front()
    {
        return ll.front();
    }
    int size()
    {
        return ll.size();
    }
    bool empty()
    {
        return ll.empty();
    }
    void display()
    {
        ll.display();
    }
    int search(TYPE x)
    {
        return ll.search(x);
    }
};

int main()
{
    MyStack<float> ss;
    int q;
    float x;
    printf("1. Push element at the top of the Stack\n");
    printf("2. Pop element from the top of the Stack\n");
    printf("3. Print the Stack\n");
    printf("4. Show the peek element of the Stack\n");
    printf("5. Search an element in the Stack and show its position\n");
    printf("6. Quit\n");
    while(1)
    {
        printf(">>>");
        scanf("%d",&q);
        if(q==1)
        {
            printf("Value: ");
            cin>>x;
            ss.push(x);
        }
        else if(q==2)
        {
            x=ss.pop();
            if(x!=-1)
            cout<<x<<" is popped out!!\n";
            else printf("Stack is empty!!\n");
        }
        else if(q==3)
        {
            printf("Stack is:\n");
            ss.display();
        }
        else if(q==4)
        {
            x=ss.front();
            cout<<"Peek value is: "<<x<<"\n";
        }
        else if(q==5)
        {
            printf("Value: ");
            cin>>x;
            int y=ss.search(x);
            if(y==-1) cout<<x<<" is not found!!\n";
            else
                cout<<"Position of "<<x<<" is "<<y<<"\n";
        }
        else if(q==6)
        {
            break;
        }
    }

    return 0;
}
