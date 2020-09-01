#include <iostream>

using namespace std;

class Node
{
public:
  int value;
  Node *next;

  Node(int v)
  {
    next = NULL;
    value = v;
  }

  Node(int v, Node *n)
  {
    next = n;
    value = v;
  }
};

class LinkedList
{
public:
  LinkedList()
  {
    head = NULL;
  }

  ~LinkedList()
  {
    Node *n = head;

    while (n != NULL)
    {
      Node *nxt = n->next;
      free(n);
      n = nxt;
    }

    head = NULL;
  }

  void add(int v)
  {
    if (head == NULL)
      head = new Node(v);
    else
    {
      Node *n = head;

      while (true)
      {
        if (n->next == NULL)
          break;

        n = n->next;
      }

      n->next = new Node(v);
    }
  }

  int get(int pos)
  {
    Node *n = head;

    for (int i = 0; i < pos; i++)
    {
      if (n == NULL)
        break;

      n = n->next;
    }

    if (n == NULL)
      return -1;

    return n->value;
  }

  int find(int v)
  {
    int pos = -1;

    Node *n = head;

    while (true)
    {
      pos++;

      if (n->value == v)
        break;

      n = n->next;

      if (n == NULL)
        break;
    }

    if (n == NULL)
      return -1;

    return pos;
  }

  void del(int pos)
  {
    Node *n = head;

    for (int i = 0; i < pos - 1; i++)
    {
      if (n == NULL)
        break;

      n = n->next;
    }

    if (n != NULL)
    {
      Node *remove = n->next;
      n->next = remove->next;

      free(remove);
    }
  }

  int length()
  {
    int counter = 0;

    Node *n = head;

    while (n != NULL)
    {
      n = n->next;
      counter++;
    }

    return counter;
  }

  void print()
  {
    Node *n = head;

    while (n != NULL)
    {
      cout << n->value << " -> ";
      n = n->next;
    }

    cout << endl;
  }

private:
  Node *head;
};

int main()
{

  LinkedList l;

  for (int i = 0; i < 10; i++)
    l.add(rand() % 100 + 1);

  cout << "All items" << endl;
  l.print();

  cout << "List length: " << l.length() << endl;

  cout << "Find ind of item 22: " << l.find(22) << endl;
  cout << "Find ind of item 36: " << l.find(36) << endl;
  cout << "Find ind of item 84: " << l.find(84) << endl;
  cout << "Find ind of item 100: " << l.find(100) << endl;

  cout << "Get item at idx 9: " << l.get(9) << endl;

  cout << "Get item at idx 3: " << l.get(3) << endl;
  cout << "Remove item at idx 3" << endl;
  l.del(3);
  l.print();

  cout << "Get item at idx 3: " << l.get(3) << endl;

  cout << "Destruct linked list" << endl;
  l.~LinkedList();

  cout << "Get first item: " << l.get(0) << endl;

  return 0;
}