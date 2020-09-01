#include <iostream>

using namespace std;

class Node
{
public:
  int value;
  Node *prev;
  Node *next;

  Node(int v)
  {
    value = v;
    next = NULL;
    prev = NULL;
  }
};

class SortedLinkedList
{
public:
  SortedLinkedList()
  {
    head = NULL;
  }

  // O(n)
  void add(int value)
  {
    Node *tmp = new Node(value);

    Node *n = head;

    if (n == NULL)
      head = end = new Node(value);
    else
    {
      if (n->value > value)
      {
        n->prev = tmp;
        tmp->next = n;
        head = tmp;
      }
      else
      {
        while (true)
        {
          if (n->next == NULL)
            break;

          if (n->next->value >= value)
            break;

          n = n->next;
        }

        tmp->next = n->next;
        tmp->prev = n;
        n->next = tmp;

        if (tmp->next == NULL)
          end = tmp;
        else
          tmp->next->prev = tmp;
      }
    }
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

  void printBack()
  {
    Node *n = end;

    while (n != NULL)
    {
      cout << n->value << " -> ";
      n = n->prev;
    }

    cout << endl;
  }

private:
  Node *head;
  Node *end;
};

int main()
{

  SortedLinkedList sl;

  for (int i = 0; i < 10; i++)
    sl.add(rand() % 100 + 1);

  cout << "Ascending order" << endl;
  sl.print();

  cout << "Descending order" << endl;
  sl.printBack();

  return 0;
}