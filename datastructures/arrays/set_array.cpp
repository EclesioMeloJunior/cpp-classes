#include <iostream>

using namespace std;

class SetInt
{
public:
  SetInt();
  ~SetInt();

  void add(int value);
  int get(int pos);
  void del(int pos);
  void print();
  void invert();

private:
  int m_size;
  int m_capacity;
  int *m_data;

  void insert(int pos, int value);

  // find the position to insert a new item
  int insertAt(int l, int r, int v);

  void resize();
};

//constructor
SetInt::SetInt()
{
  m_size = 0;
  m_capacity = 10;

  m_data = (int *)malloc(m_capacity * sizeof(*m_data));

  if (!m_data)
    throw bad_alloc();
}

//destructor
SetInt::~SetInt()
{
  m_size = 0;
  m_capacity = 0;
  free(m_data);
}

//private: resize the array
void SetInt::resize()
{
  int capacity = m_capacity * 2;
  int *tmp = (int *)realloc(m_data, capacity * sizeof(*m_data));

  if (!tmp)
    throw bad_alloc();

  m_data = tmp;
  m_capacity = capacity;
}

//private: find the position using an binary search algorithm O(log n)
int SetInt::insertAt(int l, int r, int v)
{
  if (l > r)
    return l;

  int mid = l + (r - l) / 2;

  if (*(m_data + mid) == v)
    return -1;

  if (*(m_data + mid) > v)
    return insertAt(l, mid - 1, v);

  return insertAt(mid + 1, r, v);
}

//private: insert the value at some position an increment 1 on m_size
void SetInt::insert(int pos, int value)
{
  *(m_data + pos) = value;
  m_size++;
}

//public: add a new value O(n)
void SetInt::add(int value)
{
  if (m_size >= m_capacity)
    resize();

  if (m_size == 0)
    insert(0, value);
  else
  {
    int pos = insertAt(0, m_size - 1, value);

    if (pos != -1)
    {
      for (int i = m_size; i > pos; i--)
        *(m_data + i) = *(m_data + i - 1);

      insert(pos, value);
    }
  }
}

//public: get a element at some position O(1)
int SetInt::get(int pos)
{
  return *(m_data + pos);
}

//public: deleta an item given position
//the array list should shift all the next to the left
//O(n)
void SetInt::del(int pos)
{
  for (int i = pos; i < m_size - 1; i++)
    *(m_data + i) = *(m_data + i + 1);

  m_size--;
}

//public: invert the array order
//O(1/2 n) => O(n) => linear complexity
void SetInt::invert()
{
  for (int i = 0; i < (int)m_size / 2; i++)
  {
    int tmp = *(m_data + i);
    *(m_data + i) = *(m_data + m_size - (i + 1));
    *(m_data + m_size - (i + 1)) = tmp;
  }
}

//public: just print the entire array
void SetInt::print()
{
  for (int i = 0; i < m_size; i++)
  {
    cout << *(m_data + i);

    if (i < m_size - 1)
      cout << " -> ";
  }

  cout << endl;
}

int main()
{
  int arr[] = {0, 8, 3, 2, 10, 70, 33, 1, -3, 0};

  SetInt s;

  for (int i = 0; i < 10; i++)
  {
    s.add(arr[i]);
    s.print();
  }

  cout << "Item at position 0: " << s.get(0) << endl;

  cout << "Deleting item at position 0" << endl;

  s.del(0);

  cout << "Item at position 0: " << s.get(0) << endl;

  s.print();

  cout << "Inverting array" << endl;

  s.invert();
  s.print();

  return 0;
}