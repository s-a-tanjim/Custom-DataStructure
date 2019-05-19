/*
Member Functions:
constructors
copy constructor
destructor
display
size
clear
empty
at
back
front

Operators overloaded:
=   (char, char*, string)   returns string
+   (char, char*, string)   returns object   +Non Member
+=  (char, char*, string)   returns *this

==  (char*, string)         returns bool     +Non Member
!=  (char*, string)         returns bool     +Non Member
>   (char*, string)         returns bool     +Non Member
<   (char*, string)         returns bool     +Non Member
>=  (char*, string)         returns bool     +Non Member
<=  (char*, string)         returns bool     +Non Member

[]  (int , char)
<<  (string)                returns ostream  Non Member
>>  (String)                returns istream  Non Member


additional functions:

str_len(char *ptr);                          returns length
str_cpy(int start , char* to , chat* from)   returns last index of to*
int compare(const char *a,const char *b);    returns [0=equal(a==b)   1=greater(a>b)   -1= less(a<b)]


Note:
* testing all boolean operators
* checking memory leak
* adding more member functions

Upcoming functions:
1. push_back
2. pop_back

*/

int str_len(const char *p);
int str_cpy(int start,char *to,const char *from);
int compare(const char *a,const char *b);

class MyString
{
    char *ptr;
    int Size;

public:
    MyString()
    {
        ptr=new char;
        ptr[0]='\0';
        Size=0;
    }
    MyString(const char *x)
    {
        Size=0;
        while(x[Size]!='\0') Size++;

        ptr=new char[Size+1];
        int i;
        for(i=0;x[i]!='\0';i++)
            ptr[i]=x[i];
        ptr[i]='\0';
    }
    MyString(const MyString &s)     //Copy Constructor
    {
        Size=s.Size;
        ptr=new char[Size+1];
        int i;
        for(i=0;s.ptr[i]!='\0';i++)
            ptr[i]=s.ptr[i];
        ptr[i]='\0';
    }
    ~MyString()
    {
        delete[] ptr;
        Size=0;
    }
    void display()
    {
        for(int i=0;ptr[i]!='\0';i++)
            cout<<ptr[i];
        cout<<"      Size:"<<Size<<"\n";
    }
    int size()
    {
        return Size;
    }
    void erase()
    {
        delete[] ptr;
        ptr=new char;
        ptr[0]='\0';
        Size=0;
    }
    bool empty()
    {
        if(ptr[0]=='\0' && Size==0) return true;
        return false;
    }
    char at(int x)
    {
        return ptr[x];
    }
    char back()
    {
        if(ptr[0]!='\0')
            return ptr[Size-1];
        return '\0';
    }
    char front()
    {
        if(ptr[0]!='\0')
            return ptr[0];
        return '\0';
    }


//--------------------------------------------------Operators------------------------------------------------

//................................................( = Operator )..............................................

    MyString operator=(char x)                     //It works without reference return
    {
        Size=1;

        delete[] ptr;
        ptr=new char[2];

        ptr[0]=x;
        ptr[1]='\0';

        return *this;
    }

    MyString operator=(const char *x)
    {
        Size=str_len(x);

        delete[] ptr;
        ptr=new char[Size+1];

        str_cpy(0,ptr,x);

        return *this;
    }

    MyString operator=(const MyString &x)
    {
        Size=x.Size;

        delete[] ptr;
        ptr=new char[Size+1];

        str_cpy(0,ptr,x.ptr);

        return *this;
    }

//................................................( + Operator )..............................................

    MyString operator+(char x)
    {
        int i;
        MyString RET;
        delete[] RET.ptr;

        RET.Size=Size+1;
        RET.ptr=new char[Size+1];

        i=str_cpy(0,RET.ptr,ptr);
        RET.ptr[i++]=x;
        RET.ptr[i]='\0';

        return  RET;
    }

    MyString operator+(const char *x)
    {
        int i;
        MyString RET;
        delete[] RET.ptr;

        RET.Size=Size+str_len(x);
        RET.ptr=new char[RET.Size+1];

        i=str_cpy(0,RET.ptr,ptr);
        str_cpy(i,RET.ptr,x);

        return RET;
    }


//................................................( += Operator)..............................................

    MyString operator+=(char x)
    {
        int i=0;
        Size++;

        char *char_ptr=new char[Size+1];
        i=str_cpy(0,char_ptr,ptr);
        char_ptr[i++]=x;
        char_ptr[i]='\0';

        delete[] ptr;
        ptr=char_ptr;

        return *this;
    }

    MyString operator+=(const char *x)
    {
        int i=0;
        Size+=str_len(x);

        char *char_ptr=new char[Size+1];
        i=str_cpy(0,char_ptr,ptr);
        str_cpy(i,char_ptr,x);

        delete[] ptr;
        ptr=char_ptr;

        return *this;
    }

    MyString operator+=(const MyString &str)
    {
        int i=0;
        Size+=str.Size;
        char *char_ptr=new char[Size+1];

        i=str_cpy(0,char_ptr,ptr);
        str_cpy(i,char_ptr,str.ptr);

        delete[] ptr;
        ptr=char_ptr;
        return *this;
    }

//................................................( Boolean Operators ).......................................

    bool operator==(const char *x)
    {
        if(compare(ptr,x)==0) return true;
        return false;
    }

    bool operator==(const MyString &x)
    {
        if(compare(ptr,x.ptr)==0) return true;
        return false;
    }

    bool operator!=(const char *x)
    {
        if(compare(ptr,x)!=0) return true;
        return false;
    }

    bool operator!=(const MyString &x)
    {
        if(compare(ptr,x.ptr)!=0) return true;
        return false;
    }

    bool operator>(const char *x)
    {
        if(compare(ptr,x)==1) return true;
        return false;
    }

    bool operator>(const MyString &x)
    {
        if(compare(ptr,x.ptr)==1) return true;
        return false;
    }

    bool operator<(const char *x)
    {
        if(compare(ptr,x)==-1) return true;
        return false;
    }

    bool operator<(const MyString &x)
    {
        if(compare(ptr,x.ptr)==-1) return true;
        return false;
    }

    bool operator>=(const char *x)
    {
        int i=compare(ptr,x);
        if(i==1 || i==0) return true;
        return false;
    }

    bool operator>=(const MyString &x)
    {
        int i=compare(ptr,x.ptr);
        if(i==1 || i==0) return true;
        return false;
    }

    bool operator<=(const char *x)
    {
        int i=compare(ptr,x);
        if(i==-1 || i==0) return true;
        return false;
    }

    bool operator<=(const MyString &x)
    {
        int i=compare(ptr,x.ptr);
        if(i==-1 || i==0) return true;
        return false;
    }

//................................................( [] Operator ).............................................

    char &operator[](int i)
    {
        return ptr[i];
    }

    int operator[](char x)
    {
        for(int i=0;ptr[i]!='\0';i++)
            if(ptr[i]==x)
                return i;
        return -1;
    }


    friend MyString operator+(const char x,MyString s);
    friend MyString operator+(const char *p,MyString s);
    friend MyString operator+(MyString a,MyString b);

    friend  bool operator==(const char *x, MyString &str);
    friend  bool operator!=(const char *x, MyString &str);
    friend  bool operator>(const char *x, MyString &str);
    friend  bool operator<(const char *x, MyString &str);
    friend  bool operator>=(const char *x, MyString &str);
    friend  bool operator<=(const char *x, MyString &str);

    friend  ostream &operator<<(ostream &out,MyString &str);
    friend  istream &operator>>(istream &in , MyString &str);

    friend int compare(const char *a,const char *b);

};


//........................................( NonMember functions ).............................................

int str_len(const char *p)
{
    int len=0;
    while(p[len]!='\0') len++;
    return len;
}

int str_cpy(int start,char *to,const char *from)
{
    int i,j;
    for(i=start,j=0;from[j]!='\0';j++,i++)
        to[i]=from[j];
    to[i]='\0';
    return i;
}

int compare(const char *a,const char *b)   //0=equal(a==b)   1=greater(a>b)   -1= less(a<b)
{
    int lenA=str_len(a),lenB=str_len(b);
    if(lenA==lenB){
        for(int i=0;i<lenA;i++){
            if(a[i]>b[i])
                return 1;
            if(a[i]<b[i])
                return -1;
        }
        return 0;
    }
    else{
        int i;
        for(i=0;a[i]!='\0' && b[i]!='\0' ;i++){
            if(a[i]>b[i])
                return 1;
            if(a[i]<b[i])
                return -1;
        }
        if(lenA>lenB) return 1;
        return -1;
    }
}


//................................................( + Operators ).............................................

MyString operator+(const char x,MyString s)
{
        MyString RET;
        delete[] RET.ptr;

        RET.Size=s.Size+1;
        RET.ptr=new char[RET.Size+1];

        RET.ptr[0]=x;
        str_cpy(1,RET.ptr,s.ptr);

        return  RET;
}

MyString operator+(const char *p, MyString s)
{
    int i;
    MyString RET;
    delete[] RET.ptr;

    RET.Size=str_len(p)+s.Size;
    RET.ptr=new char[RET.Size+1];

    i=str_cpy(0,RET.ptr,p);
    str_cpy(i,RET.ptr,s.ptr);

    return RET;
}

MyString operator+(MyString a,MyString b)
{
    MyString RET;
    delete[] RET.ptr;

    RET.Size=a.Size+b.Size;
    RET.ptr=new char[RET.Size+1];
    int i=str_cpy(0,RET.ptr,a.ptr);
    str_cpy(i,RET.ptr,b.ptr);

    return  RET;
}


//................................................( Boolean Operators ).......................................

bool operator==(const char *x, MyString &str)
{
    if(compare(x,str.ptr)==0) return true;
    return false;
}

bool operator!=(const char *x, MyString &str)
{
    if(compare(x , str.ptr)!=0) return true;
    return false;
}

bool operator>(const char *x , MyString &str)
{
    if(compare(x , str.ptr)==1) return true;
    return false;
}

bool operator<(const char *x , MyString &str)
{
    if(compare(x , str.ptr)==-1) return true;
    return false;
}

bool operator>=(const char *x , MyString &str)
{
    int i=compare(x,str.ptr);
    if(i==1 || i==0) return true;
    return false;
}

bool operator<=(const char *x , MyString &str)
{
    int i=compare(x , str.ptr);
    if(i==-1 || i==0) return true;
    return false;
}


//................................................( << & >> Operator )........................................

ostream &operator<<(ostream &out,MyString &str)
{
    out<<str.ptr;
    return out;
}

istream &operator>>(istream &in , MyString &str)
{
    char *ptr=new char[1000];
    in>>ptr;
    delete[] str.ptr;
    str.ptr=ptr;
    str.Size=str_len(ptr);
    return in;
}
