#include<stdio.h>
#include<iostream>
//#define DBG
using namespace std;
/*
constructor
copy constructor
display
size
destructor

Operators overloaded:
=   (char, char*, string)   returns string
+   (char, char*, string)   returns object         +Non Member
+=  (char, char*, string)   returns *this

==  (char*, string)         returns bool           +Non Member


remaining:
[]
<<
>>


additional functions:

str_len(char *ptr);                          returns length
str_cpy(int start , char* to , chat* from)   returns last index of to*



Point:
* NULL have to be removed
* testing all boolean operators

*/


int str_len(const char *p);
int str_cpy(int start,char *to,const char *from);
int compare(const char *a,const char *b);   //0=equal(a==b)   1=greater(a>b)   -1= less(a<b)

class MyString
{
    char *ptr;
    int Size;

public:
    MyString()
    {
        #ifdef DBG
        cout<<"Default Constructor\n";
        #endif // DBG


        ptr=new char;
        ptr[0]='\0';
        Size=0;
    }
    MyString(const char *x)
    {
        #ifdef  DBG
        cout<<"Char constructor\n";
        #endif // DBG


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
        #ifdef DBG
        cout<<"Copy constructor   "<<s.Size<<endl;
        #endif // DBG


        Size=s.Size;
        ptr=new char[Size+1];
        int i;
        for(i=0;s.ptr[i]!='\0';i++)
            ptr[i]=s.ptr[i];
        ptr[i]='\0';
    }
    void display()
    {
        if(ptr==NULL)
        {
            #ifdef DBG
            cout<<"Empty!\n";
            #endif // DBG
            return;
        }
        for(int i=0;ptr[i]!='\0';i++)
            cout<<ptr[i];
        cout<<"      Size:"<<Size<<"\n";
    }
    int size()
    {
        return Size;
    }
    ~MyString()
    {
        #ifdef DBG
        cout<<"Destructor\n";
        #endif // DBG

        if(ptr!=NULL)
            delete[] ptr;
        Size=0;
    }


//...................................................Operators................................................


//................................................( = Operator )..............................................

    MyString operator=(char x)                     //It works without reference return
    {
        #ifdef DBG
        cout<<"Operator=(character)\n";
        #endif // DBG

        Size=1;

        if(ptr!=NULL) delete[] ptr;
        ptr=new char[2];

        ptr[0]=x;
        ptr[1]='\0';

        return *this;
    }


    MyString operator=(const char *x)       //Worked
    {
        #ifdef DBG
        cout<<"Operator=(string,char*)\n";
        #endif // DBG


        Size=str_len(x);

        if(ptr!=NULL)   delete[] ptr;
        ptr=new char[Size+1];

        str_cpy(0,ptr,x);

        return *this;
    }

    MyString operator=(const MyString &x)   //worked
    {
        #ifdef  DBG
        cout<<"operator=(MyString)\n";
        #endif // DBG


        Size=x.Size;

        if(ptr!=NULL) delete[] ptr;
        ptr=new char[Size+1];

        str_cpy(0,ptr,x.ptr);

        return *this;
    }

//................................................( + Operator )..............................................

    MyString operator+(char x)
    {
        #ifdef DBG
        cout<<"Operator+(string , Char)\n";
        #endif // DBG

        int i;
        MyString RET;

        RET.Size=Size+1;
        RET.ptr=new char[Size+1];

        i=str_cpy(0,RET.ptr,ptr);
        RET.ptr[i++]=x;
        RET.ptr[i]='\0';

        return  RET;
    }

    MyString operator+(const char *x)
    {
        #ifdef DBG
        cout<<"Operator+(string , Char*)\n";
        #endif // DBG

        int i;
        MyString RET;

        RET.Size=Size+str_len(x);
        RET.ptr=new char[RET.Size+1];

        i=str_cpy(0,RET.ptr,ptr);
        str_cpy(i,RET.ptr,x);

        return RET;
    }


//................................................( += Operator)..............................................

    MyString operator+=(char x)
    {
        #ifdef DBG
        cout<<"operator+=( String , char )\n";
        #endif // DBG

        int i=0;
        Size++;

        char *char_ptr=new char[Size+1];
        if(ptr!=NULL)
            i=str_cpy(0,char_ptr,ptr);
        char_ptr[i++]=x;
        char_ptr[i]='\0';

        if(ptr!=NULL)
            delete[] ptr;
        ptr=char_ptr;

        return *this;
    }

    MyString operator+=(const char *x)
    {
        #ifdef DBG
        cout<<"operator+=( String , char* )\n";
        #endif // DBG

        int i=0;
        Size+=str_len(x);

        char *char_ptr=new char[Size+1];
        if(ptr!=NULL)
            i=str_cpy(0,char_ptr,ptr);
        str_cpy(i,char_ptr,x);

        if(ptr!=NULL)
            delete[] ptr;
        ptr=char_ptr;

        return *this;
    }

    MyString operator+=(const MyString &str)
    {
        #ifdef DBG
        cout<<"operator+=( String , string )\n";
        #endif // DBG

        int i=0;
        Size+=str.Size;
        char *char_ptr=new char[Size+1];

        if(ptr!=NULL)
            i=str_cpy(0,char_ptr,ptr);
        if(str.ptr!=NULL)
            str_cpy(i,char_ptr,str.ptr);


        delete[] ptr;
        ptr=char_ptr;
        return *this;
    }

//................................................( == Operator ).............................................

    bool operator==(const char *x)      //Worked
    {
        //MyString == "aaa"
        #ifdef DBG
        cout<<"Operator==( string , char* )\n";
        #endif // DBG

        if(compare(ptr,x)==0) return true;
        return false;
    }

    bool operator==(const MyString &x)      //Worked
    {
        //MyString == MyString
        #ifdef DBG
        cout<<"Operator==( MyString , MyString )\n";
        #endif // DBG

        if(compare(ptr,x.ptr)==0) return true;
        return false;
    }

//................................................( != Operator ).............................................

    bool operator!=(const char *x)
    {
        #ifdef DBG
        cout<<"Operator!=( string , char* )\n";
        #endif // DBG

        if(compare(ptr,x)!=0) return true;
        return false;
    }

    bool operator!=(const MyString &x)
    {
        #ifdef DBG
        cout<<"Operator!=( MyString , MyString )\n";
        #endif // DBG


        if(compare(ptr,x.ptr)!=0) return true;
        return false;
    }

//................................................( > Operator ).............................................

    bool operator>(const char *x)
    {
        #ifdef DBG
        cout<<"Operator>( string , char* )\n";
        #endif // DBG

        if(compare(ptr,x)==1) return true;
        return false;
    }

    bool operator>(const MyString &x)
    {
        #ifdef DBG
        cout<<"Operator>( MyString , MyString )\n";
        #endif // DBG

        if(compare(ptr,x.ptr)==1) return true;
        return false;
    }

//................................................( < Operator ).............................................

    bool operator<(const char *x)
    {
        #ifdef DBG
        cout<<"Operator<( string , char* )\n";
        #endif // DBG

        if(compare(ptr,x)==-1) return true;
        return false;
    }

    bool operator<(const MyString &x)
    {
        #ifdef DBG
        cout<<"Operator<( MyString , MyString )\n";
        #endif // DBG


        if(compare(ptr,x.ptr)==-1) return true;
        return false;
    }

//................................................( >= Operator ).............................................

    bool operator>=(const char *x)
    {
        #ifdef DBG
        cout<<"Operator>=( string , char* )\n";
        #endif // DBG

        int i=compare(ptr,x);
        if(i==1 || i==0) return true;
        return false;
    }

    bool operator>=(const MyString &x)
    {
        #ifdef DBG
        cout<<"Operator>=( MyString , MyString )\n";
        #endif // DBG


        int i=compare(ptr,x.ptr);
        if(i==1 || i==0) return true;
        return false;
    }

//................................................( <= Operator ).............................................

    bool operator<=(const char *x)
    {
        //MyString == "aaa"
        #ifdef DBG
        cout<<"Operator<=( string , char* )\n";
        #endif // DBG

        int i=compare(ptr,x);
        if(i==-1 || i==0) return true;
        return false;
    }

    bool operator<=(const MyString &x)      //Worked
    {
        //MyString == MyString
        #ifdef DBG
        cout<<"Operator<=( MyString , MyString )\n";
        #endif // DBG

        int i=compare(ptr,x.ptr);
        if(i==-1 || i==0) return true;
        return false;
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




    friend int compare(const char *a,const char *b);

};


//........................................NonMember function...........................................


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
    if(lenA==lenB)
    {
        for(int i=0;i<lenA;i++)
        {
            if(a[i]>b[i])
                return 1;
            if(a[i]<b[i])
                return -1;
        }
        return 0;
    }
    else
    {
        int i;
        for(i=0;a[i]!='\0' && b[i]!='\0' ;i++)
        {
            if(a[i]>b[i])
                return 1;
            if(a[i]<b[i])
                return -1;
        }
        if(lenA>lenB) return 1;
        return -1;
    }
}

// Plus operators................................................................................
MyString operator+(const char x,MyString s)
{
    #ifdef DBG
        cout<<"Operator+(Character , String)(Non-Member)\n";
        #endif // DBG


        MyString RET;

        RET.Size=s.Size+1;
        RET.ptr=new char[RET.Size+1];

        RET.ptr[0]=x;
        str_cpy(1,RET.ptr,s.ptr);

        return  RET;
}

MyString operator+(const char *p, MyString s)
{
    #ifdef DBG
    cout<<"Operator+(char,MyString)(Non-Member)\n";
    #endif // DBG


    int i;
    MyString RET;

    RET.Size=str_len(p)+s.Size;
    RET.ptr=new char[RET.Size+1];

    i=str_cpy(0,RET.ptr,p);
    str_cpy(i,RET.ptr,s.ptr);

    return RET;
}

MyString operator+(MyString a,MyString b)
{
    #ifdef DBG
    cout<<"Operator+(String, String)(Non-Member)\n";
    #endif // DBG

    MyString RET;

    RET.Size=a.Size+b.Size;
    RET.ptr=new char[RET.Size+1];
    int i=str_cpy(0,RET.ptr,a.ptr);
    str_cpy(i,RET.ptr,b.ptr);

    return  RET;
}


//................................................( == Operator ).............................................

    bool operator==(const char *x, MyString &str)
    {
        #ifdef DBG
        cout<<"Operator==( char* ,string ) (nonMember)\n";
        #endif // DBG

        if(compare(x,str.ptr)==0) return true;
        return false;
    }

//................................................( != Operator ).............................................

    bool operator!=(const char *x, MyString &str)
    {
        #ifdef DBG
        cout<<"Operator!=( string , char* )\n";
        #endif // DBG

        if(compare(x , str.ptr)!=0) return true;
        return false;
    }

//................................................( > Operator ).............................................

    bool operator>(const char *x , MyString &str)
    {
        #ifdef DBG
        cout<<"Operator>( string , char* )\n";
        #endif // DBG

        if(compare(x , str.ptr)==1) return true;
        return false;
    }

//................................................( < Operator ).............................................

    bool operator<(const char *x , MyString &str)
    {
        #ifdef DBG
        cout<<"Operator<( string , char* )\n";
        #endif // DBG

        if(compare(x , str.ptr)==-1) return true;
        return false;
    }


//................................................( >= Operator ).............................................

    bool operator>=(const char *x , MyString &str)
    {
        #ifdef DBG
        cout<<"Operator>=( string , char* )\n";
        #endif // DBG

        int i=compare(x,str.ptr);
        if(i==1 || i==0) return true;
        return false;
    }


//................................................( <= Operator ).............................................

    bool operator<=(const char *x , MyString &str)
    {
        //MyString == "aaa"
        #ifdef DBG
        cout<<"Operator<=( string , char* )\n";
        #endif // DBG

        int i=compare(x , str.ptr);
        if(i==-1 || i==0) return true;
        return false;
    }







int main()
{
    MyString a("a"),b,c("c"),d("faa"),e("e"),f("f");

    //b=c=a+=a;
    //b.display();

    if("aa"<=f)
        cout<<"1111\n";
    else
        cout<<"222\n";


}

//test cases:
//b="aaa"+c+"xxxxx"+"aaaaa"+"s"+"AaA"+a+'a'+'c'+c+"xxx";
