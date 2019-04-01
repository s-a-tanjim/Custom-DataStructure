#include<iostream>
#include<stdio.h>
using namespace std;

template <typename TYPE>
struct NODE
{
    TYPE value;
    NODE *next,*previous;
};

template <class TYPE>
class MyDoubleLinkedList
{
    NODE<TYPE> *head,*tail;
    int Size;
public:
    MyDoubleLinkedList()
    {
        head=NULL;
        tail=NULL;
        Size=0;
    }
    MyDoubleLinkedList(const MyDoubleLinkedList &x)             //Copy Constructor
    {
        Size=x.Size;
        if(x.head==NULL)
        {
            head=tail=NULL;
        }
        else{
            NODE<TYPE> *temp=new NODE<TYPE>,*tempX=x.head;
            head=temp;
            head->value=tempX->value;
            head->previous=NULL;
            tempX=tempX->next;
            while(tempX!=NULL)
            {
                NODE<TYPE> *temp2=new NODE<TYPE>;
                temp2->value=tempX->value;
                temp2->previous=temp;
                temp->next=temp2;
                temp=temp->next;
                tempX=tempX->next;
            }
            tail=temp;
            tail->next=NULL;
        }
    }
    void push_back(TYPE x)
    {
        NODE<TYPE> *temp=new NODE<TYPE>;
        temp->value=x;
        Size++;
        temp->next=NULL;
        if(head==NULL)
        {
            head=tail=temp;
            head->previous=NULL;
        }
        else{
            tail->next=temp;
            temp->previous=tail;
            tail=tail->next;
        }
    }
    void push_front(TYPE x)
    {
        NODE<TYPE> *temp=new NODE<TYPE>;
        temp->value=x;
        Size++;
        temp->previous=NULL;
        if(head==NULL)
        {
            head=tail=temp;
            temp->next=NULL;
        }
        else{
            temp->next=head;
            head->previous=temp;
            head=head->previous;
        }
    }
    TYPE pop_back()
    {
        if(head==NULL)
        {
            printf("List is Empty!\n");
            return -1;
        }
        TYPE x=tail->value;
        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            Size=0;
            return x;
        }
        NODE<TYPE> *temp=tail;
        tail=tail->previous;
        tail->next=NULL;
        delete temp;
        Size--;
        return x;
    }
    TYPE pop_front()
    {
        if(head==NULL)
        {
            printf("List is empty!\n");
            return -1;
        }
        TYPE x=head->value;
        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            Size=0;
            return x;
        }
        NODE<TYPE> *temp=head;
        head=head->next;
        head->previous=NULL;
        Size--;
        delete temp;
        return x;
    }
    void display()
    {
        NODE<TYPE> *temp=head;
        printf("List is:  ");
        if(head==NULL) printf("Empty!!\n");
        else{
            while(temp!=NULL)
            {
                cout<<temp->value<<"  ";
                temp=temp->next;
            }
            printf("\n");
        }
    }
    void reverse_display()
    {
        NODE<TYPE> *temp=tail;
        printf("Reverse List is:  ");
        if(head==NULL) printf("Empty!!\n");
        else{
            while(temp!=NULL)
            {
                cout<<temp->value<<"  ";
                temp=temp->previous;
            }
            printf("\n");
        }
    }

    bool empty()
    {
        if(head==NULL) return true;
        return false;
    }
    int size()
    {
        return Size;
    }
    TYPE front()
    {
        if(head!=NULL) return head->value;
        return -1;
    }
    TYPE back()
    {
        if(tail!=NULL) return tail->value;
        return -1;
    }
    int search(TYPE x)                         //return index
    {
        NODE<TYPE> *temp=head;
        int index=0;
        while(temp!=NULL)
        {
            if(temp->value==x)
                return index;
            index++;
            temp=temp->next;
        }
        return -1;
    }
    ~MyDoubleLinkedList()
    {
        NODE<TYPE> *temp;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
        Size=0;
        tail=NULL;
    }
};

int main()
{

    return 0;
}
