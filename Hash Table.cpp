#include <iostream>
#define TABLE_SIZE 10
using namespace std;

//There are three type of method to avoid collision.
//Each of them implemented in different class

class LinearProbing
{
  int arr[TABLE_SIZE];

public:
  LinearProbing()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
      arr[i] = -1;
  }
  void setVal(int key)
  {
    int index = hashFunc(key);
    if (index < TABLE_SIZE)
      arr[index] = key;
    else
      cout << "Not Enough Space!\n";
  }
  int hashFunc(int key)
  {
    int i = key % TABLE_SIZE;
    int j = 0;
    while (arr[i] != -1 && j < TABLE_SIZE)
    {
      i = (i + 1) % TABLE_SIZE;
      j++;
    }
    if (j == TABLE_SIZE)
    {
      cout << "Not enough space!!\n";
      return 0;
    }
    return i;
  }
  bool search(int key)
  {
    for (int i = key; i < TABLE_SIZE && arr[i] != -1; i++)
    {
      if (arr[i] == key)
        return true;
    }
    return false;
  }
  void display()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
      cout << arr[i] << "   ";
    cout << "\n\n";
  }
};

class quadraticProbing
{
  int arr[TABLE_SIZE];

public:
  LinearProbing()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
      arr[i] = -1;
  }
  void setVal(int key)
  {
    int index = hashFunc(key);
    if (index < TABLE_SIZE)
      arr[index] = key;
    else
      cout << "Not Enough Space!\n";
  }
  int hashFunc(int key)
  {
    int i = key % TABLE_SIZE;
    while (arr[i] != -1 && i < TABLE_SIZE)
      i++;
    return i;
  }
  bool search(int key)
  {
    for (int i = key; i < TABLE_SIZE && arr[i] != -1; i++)
    {
      if (arr[i] == key)
        return true;
    }
    return false;
  }
  void display()
  {
    for (int i = 0; i < TABLE_SIZE; i++)
      cout << arr[i] << "   ";
    cout << "\n\n";
  }
};

int main()
{

  LinearProbing l;
  l.setVal(15);
  l.setVal(25);
  l.setVal(35);
  l.setVal(45);
  l.setVal(55);
  l.setVal(65);
  l.setVal(5);
  l.setVal(1);
  l.setVal(2);
  l.setVal(7);

  if (l.search(0))
  {
    cout << "Found!\n";
  }
  else
  {
    cout << "Not Found!\n";
  }

  l.display();
}
