#include<bits/stdc++.h>
#define MIN_INF -999999
using namespace std;

struct Node{
  int val;
  Node** next;

  Node(int value, int lvl){
    val=value;
    next=new Node*[lvl+1];
    for(int i=0;i<=lvl;i++){
      next[i]=NULL;
    }
  }
};

class SkipList{

  int maxLevel,level;
  float p;  //Probability
  Node *head;

  public:

  SkipList(int mxlvl , float probability = 0.5)
  {
    maxLevel = mxlvl;
    p = probability;
    level = 0;
    head = new Node (MIN_INF , maxLevel); // Creating a dummy node
  }

  int getRandomLevel(){
    float r = (float) rand() / RAND_MAX;
    int lvl = 0;
    while ( r < p && lvl < maxLevel ){
      lvl++;
      r = (float) rand() / RAND_MAX;
    }
    return lvl;
  }

  void insertElement(int val)
  {
    Node* current = head;
    Node** update = new Node*[maxLevel+1];

    for(int i = 0 ; i <= maxLevel ; i++)
      update[i] = NULL;

    for(int i = level ; i >=0 ; i--){
      while(current->next[i] != NULL && current->next[i]->val < val)
        current=current->next[i];

      update[i] = current;
    }

    current = current->next[0];

    if(current == NULL || current->val != val)
    {
      int rLevel = getRandomLevel();
      if(rLevel > level){
        for(int i = level+1 ; i <= rLevel ; i++)
          update[i] = head;
        level = rLevel;
      }

      Node *temp = new Node(val,level);

      for(int i=0 ; i <= level ; i++){
        temp->next[i] = update[i]->next[i];
        update[i]->next[i] = temp;
      }
      std::cout<<val<<" added!\n";
    }
  }

  void display()
  {
    for(int i=0;i<=level ;i++)
    {
      Node *temp=head->next[i];
      std::cout<<"Level "<<i<<" : ";
      while(temp!=NULL){
        std::cout<<temp->val<<"  ";
        temp = temp->next[i];
      }
      std::cout<<"\n";
    }
  }

  bool search(int val)
  {
    Node* current=head;
    for(int i=level;i>=0;i--)
      while(current->next[i]!=NULL && current->next[i]->val<val)
        current=current->next[i];
    current=current->next[0];
    if(current!=NULL && current->val == val)
      return true;
    return false;
  }

};


int main(){
  srand((unsigned)time(0));
  SkipList l(10);

  l.insertElement(3);
  l.insertElement(8);
  l.insertElement(10);
  l.insertElement(13);
  l.insertElement(11);
  l.insertElement(15);
  l.insertElement(20);
  l.insertElement(30);
  l.insertElement(80);
  l.insertElement(100);
  l.display();

  cout<<l.search(3)<<endl;
  cout<<l.search(100)<<endl;
  cout<<l.search(1000)<<endl;
  cout<<l.search(-1)<<endl;

  return 0;
}
