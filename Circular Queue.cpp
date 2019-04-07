//On progress...
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

template <class TYPE>
class MyCircularQueue{
    int capacity,head,tail,Size;
    TYPE *q;
public:
    MyCircularQueue()
    {
        head=0;
        Size=0;
        tail=0;
        capacity=5;
        q=(TYPE*)malloc(capacity*sizeof(TYPE));
    }
    void push(TYPE x)    //push back
    {
        if(head==(tail%capacity) && Size!=0){
            printf("Queue is full!!!\n");
        }
        else{
            Size++;
            q[tail]=x;
            tail++;
            tail=tail%capacity;
        }
        //cout<<"#Push  head: "<<head<<"  tail: "<<tail<<"  Size: "<<Size<<endl;
    }
    TYPE pop()          //pop front
    {
        TYPE x;
        if(head== tail && Size==0)
        {
            printf("Queue is empty!!!\n");
            return -1;
        }
        else{
            x=q[head];
            head++;
            head=head%capacity;
            Size--;
        }
        return x;
        //cout<<"$Pop   head: "<<head<<"  tail: "<<tail<<"  Size: "<<Size<<endl;
    }
    TYPE front()
    {
        return q[head];
    }
    void display()
    {
        printf("\nQueue is:\n");
        if(tail==head && Size==0) printf("Queue is empty!!\n");
        else if(tail==head && Size!=0)
        {
            cout<<q[head]<<"  ";
            int i=head+1;
            i=i%capacity;
            for(;i!=tail;i++,i=i%capacity)
            {
                cout<<q[i]<<"  ";
            }
        }
        else if(tail>head)
        {
            for(int i=head; i<tail;i++)
            {
                cout<<q[i]<<"  ";
            }
        }
        else {
            for(int i=head; i!=tail;i++)
                {
                    i=i%capacity;
                    cout<<q[i]<<"  ";
                }
        }
        printf("\n");
    }
    int Search(TYPE x)
    {
        if(tail==head && Size==0) return -1;
        else if(tail==head && Size!=0)
        {
            if(q[head]==x) {
                    return head;
            }
            int i=head+1;
            i=i%capacity;
            for(;i!=tail;i++,i=i%capacity)
            {
                if(q[i]==x){
                        return i;
                }
            }
        }
        else if(tail>head)
        {
            for(int i=head; i<tail;i++)
            {
                if(q[i]==x){
                        return i;
                }
            }
        }
        else {
            for(int i=head; i!=tail;i++)
                {
                    i=i%capacity;
                    if(q[i]==x){
                            return i;
                    }
                }
        }
        return -1;
    }
    void CapIncrease()
    {
        capacity=capacity+capacity;
        q=(TYPE*)realloc(q,capacity*sizeof(TYPE));
        tail=Size;
    }
    ~MyCircularQueue()
    {
        free(q);
    }
};

int main()
{
    MyCircularQueue<int> qq;

    int x,ans;
    printf("1. Push element at the bottom of the Queue\n");
    printf("2. Pop element from the top of the Queue\n");
    printf("3. Print the Queue\n");
    printf("4. Show the peek element of the Queue\n");
    printf("5. Search an element in the Queue and show its position\n");
    printf("6. Increase the capacity of Queue\n");
    printf("7. Quit\n");

    while(1)
    {
        scanf("%d",&ans);
        if(ans==1)
        {
            printf("Value: ");
            scanf("%d",&x);
            qq.push(x);
        }
        else if(ans==2)
        {
            x=qq.pop();
            if(x!=-1)cout<<x<<" has popped out!!\n";
        }
        else if(ans==3)
        {
            qq.display();
        }
        else if(ans==4)
        {
            cout<<"Peek value is: "<<qq.front()<<endl;
        }
        else if(ans==5)
        {
            printf("Value: ");
            scanf("%d",&x);
            x=qq.Search(x);
            if(x!=-1) printf("Position is: %d\n",x);
            else printf("Not found!\n");
        }
        else if(ans==6)
        {
            qq.CapIncrease();
        }
        else if(ans==7) break;
    }


    return 0;
}
