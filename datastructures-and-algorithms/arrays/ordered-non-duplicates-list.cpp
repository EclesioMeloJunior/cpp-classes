#include <iostream>

using namespace std;

class OrderedSetList {
  public:
    OrderedSetList() {
      m_size = 0;
      m_capacity = 10;
      m_data = (int*)malloc(m_capacity*sizeof(*m_data));

      if (!m_data)
        throw bad_alloc();
    }

    ~OrderedSetList() {
      free(m_data);
    }

    void add(int value) {
      if (m_size >= m_capacity)
        resize();
      
      if (m_size==0)
        insert(0, value);
      else {
        int pos = binarySearch(0, m_size-1, value);
        if (pos != -1)
          displacementAndAdd(pos, value);
      }
    }

    void print() {
      for(size_t i = 0; i < m_size; i ++) {
        cout << *(m_data + i);

        if (i < m_size -1)
          cout << " -> ";
      }

      cout << endl;
    }

  private:
    size_t m_capacity;
    size_t m_size;

    int* m_data;

    void resize() {
      size_t c = m_capacity * 2;
      int* tmp = (int*)realloc(m_data, c*sizeof(*m_data));
      if (!tmp)
        throw bad_alloc();

      m_data = tmp;
      m_capacity = c;
    }

    int binarySearch(int l, int r, int v) {      
      if (l > r)
        return l;
   
      int mid = l + (r - l) / 2;   

      if(*(m_data + mid) == v)
        return -1;

      if(*(m_data + mid) < v) {
        return binarySearch(mid+1, r, v);
      }
      
      return binarySearch(l, mid-1, v);
    }

    void insert(size_t pos, int v) {
      *(m_data + pos) = v;
      m_size++;
    }

    void displacementAndAdd(size_t pos, int v) {
      for (size_t i = m_size; i > pos; i--) {
        *(m_data+i)=*(m_data + i - 1);
      }

      insert(pos, v);
    }
};

int main() {
  int numbers[] = {50, 1, 6, 4, 10, 5, 49, 13, 8, 15};
  OrderedSetList s;

  for (int i = 0; i<10; i++) {
    s.add(numbers[i]);
    s.print();
  }

  s.add(2);
  s.add(4);
  s.add(2);

  s.print();

  return 0;
}
