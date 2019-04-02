// Array-list is known as vector in cpp
#include<iostream>
#include<cstdio>
#include<windows.h>
using namespace std;

template <class TYPE>
class MyArray
{
    TYPE *ptr;
    int Size,cap,icap;                          //cap: Capacity, icap: Initial capacity
public:
    MyArray()
    {
        Size=0;
        ptr=(TYPE*)malloc(10*sizeof(TYPE));
        cap=icap=10;
    }
    MyArray(int Cap)                            //Constructor
    {
        Size=0;
        ptr=(TYPE*) malloc(Cap*sizeof(TYPE));
        cap=icap=Cap;
    }
    MyArray(const MyArray &x)                   //Copy Constructor
    {
        Size=x.Size;
        cap=x.cap;
        icap=x.icap;
        ptr=(TYPE*) malloc(cap*sizeof(TYPE));
        for(int i=0;i<Size;i++)
        {
            ptr[i]=x.ptr[i];
        }
    }
    void push_front(TYPE x)
    {
        if(Size==cap)                           //Increasing capacity
        {
            cap=cap+icap;
            ptr=(TYPE*)realloc(ptr,cap*sizeof(TYPE));
        }
        for(int i=Size;i>0;i--)                  //shifting right
        {
            ptr[i]=ptr[i-1];
        }
        ptr[0]=x;
        Size++;
    }
    void push_back(TYPE x)
    {
        if(Size==cap)                            //Increasing capacity
        {
            cap=cap+icap;
            ptr=(TYPE*)realloc(ptr,cap*sizeof(TYPE));
        }
        ptr[Size]=x;
        Size++;
    }
    void push_at(int pos)
    {
        if(pos>0 && pos<=(Size+1))               //bound checking
        {
            TYPE x;
            printf("Enter value: ");
            cin>>x;
            if(Size==cap)                         //increasing capacity
            {
                cap=cap+icap;
                ptr=(TYPE*)realloc(ptr,cap*sizeof(TYPE));
            }
            for(int i=Size;i>=pos;i--)             //shifting right
            {
                ptr[i]=ptr[i-1];
            }
            ptr[pos-1]=x;
            Size++;
        }
        else    printf("Entered position is not a valid!\n");
    }
    TYPE pop_front()
    {
        if(Size>0)                                    // bound checking
        {
            TYPE x;
            x=ptr[0];
            for(int i=0;i<Size-1;i++)                   // shifting left
            {
                ptr[i]=ptr[i+1];
            }
            Size--;
            if(cap-icap==Size+1)                        // decreasing capacity
            {                                            // Size+1 for 1 more space
                cap=cap-icap;
                ptr=(TYPE*)realloc(ptr,cap*sizeof(TYPE));
            }
            return x;
        }
        printf("Array is Empty!\n");
        return -1;
    }
    TYPE pop_back()
    {
        if(Size>0)                                      // bound checking
        {
            TYPE x=ptr[Size-1];
            Size--;
            if(cap-icap==Size+1)                        // decreasing capacity
            {
                cap=cap-icap;
                ptr=(TYPE*)realloc(ptr,cap*sizeof(TYPE));
            }
            return x;
        }
        printf("Array is Empty!!\n");
        return -1;
    }
    TYPE pop_at(int pos)
    {
        if(pos>0 && Size>=pos)                           // bound checking
        {
            TYPE x=ptr[pos-1];
            for(int i=pos-1;i<Size;i++)  ptr[i]=ptr[i+1];  //shifting  left
            Size--;
            if(cap-icap==Size+1)                            // decreasing capacity
            {
                cap=cap-icap;
                ptr=(TYPE*)realloc(ptr,cap*sizeof(TYPE));
            }
            return x;
        }
        printf("Entered position is not a valid!\n");
        return -1;
    }
    void update(int pos)
    {
        if(pos>0 && pos<=Size)                              // bound checking
        {
            TYPE x;
            printf("Enter Value: ");
            cin>>x;
            ptr[pos-1]=x;                                   // pos-1: position and index is not same
        }
        else printf("Entered position is not a valid!\n");
    }
    void display()
    {
        for(int i=0;i<Size;i++) cout<<ptr[i]<<"   ";
        printf("\n");
    }
    void shrink()                                           //No free space will remain
    {
        if(Size<cap)
        {
            ptr=(TYPE*)realloc(ptr,Size*sizeof(TYPE));
            cap=Size;
        }
    }
    bool empty()                                            // IsEmpty?
    {
        if(Size==0) return true;
        return false;
    }
    int capacity()
    {
        return cap;
    }
    int size()
    {
        return Size;
    }
    int search(TYPE x)                                      // Return Index
    {
        for(int i=0;i<Size;i++)
            if(ptr[i]==x)
                return i;
        return -1;
    }
    ~MyArray()
    {
        free(ptr);
        ptr=NULL;
    }
};

int main()
{
    int ans,Siz,pos;
    int x;
    printf("Enter the size of the array: ");
    scanf("%d",&Siz);
    MyArray<int> ls(Siz);
    system("cls");
    printf("Choose one of the option:\n");
    printf("1. Insert element at the first position of the array\n");
    printf("2. Insert element at the last position of the array\n");
    printf("3. Insert element at any middle position of the array\n");
    printf("4. Delete an element from the first position of the array\n");
    printf("5. Delete an element from the last position of the array\n");
    printf("6. Delete an element from any position of the array\n");
    printf("7. Update any value of any position of the array\n");
    printf("8. Print the array\n");
    printf("9. Search\n");
    printf("10. Quit\n");
    while(1)
    {
        printf("Enter Option: ");
        cin>>ans;
        if(ans==1)
        {
            printf("Enter Value: ");
            cin>>x;
            ls.push_front(x);
        }
        else if(ans==2)
        {
            printf("Enter Value: ");
            cin>>x;
            ls.push_back(x);
        }
        else if(ans==3)
        {
            printf("Enter the position: ");
            cin>>pos;
            ls.push_at(pos);
        }
        else if(ans==4)
        {
            x=ls.pop_front();
            if(x!=-1) cout<<x<<" is popped!\n";
        }
        else if(ans==5)
        {
            x=ls.pop_back();
            if(x!=-1) cout<<x<<" is popped!\n";
        }
        else if(ans==6)
        {
            printf("Enter the position: ");
            cin>>pos;
            x=ls.pop_at(pos);
            if(x!=-1) cout<<x<<" is popped!\n";
        }
        else if(ans==7)
        {
            printf("Enter the position: ");
            cin>>pos;
            ls.update(pos);
        }
        else if(ans==8)
        {
            ls.display();
        }
        else if(ans==9){
            printf("Value: ");
            cin>>x;
            pos=ls.search(x);
            if(pos!=-1) cout<<x<<" is at "<<pos<<" position\n";
            else printf("Not found!\n");
        }
        else break;
    }
    system("cls");
    printf("Thank You!!!\n\n\n\n");
    return 0;
}
