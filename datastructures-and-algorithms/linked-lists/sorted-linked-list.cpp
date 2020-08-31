#include <iostream>

using namespace std;

class Node
{
public:
  int value;
  Node *next;

  Node(int v)
  {
    value = v;
    next = NULL;
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
      head = new Node(value);
    else
    {
      if (n->value > value)
      {
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
        n->next = tmp;
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

private:
  Node *head;
};

int main()
{

  SortedLinkedList sl;

  for (int i = 0; i < 10; i++)
    sl.add(rand() % 100 + 1);

  sl.print();

  return 0;
}