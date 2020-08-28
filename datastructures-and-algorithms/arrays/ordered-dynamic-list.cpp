#include <iostream>

using namespace std;

class OrderedIntList {
  public:
    OrderedIntList() {
      m_size = 0;
      m_capacity = 10;

      m_data = (int*)malloc(m_capacity * sizeof(*m_data));

      if (!m_data)
        throw bad_alloc();    
    }

    void push(int v) {
      if (m_size >= m_capacity)
        resize();

      if (m_size == 0)
        insert(0, v);
      else {
        size_t pos = find_order(v);
        replace_and_insert(pos, v);
      }
    }

    void print() {
      for (size_t i = 0; i < m_size; i++) {
        cout << *(m_data + i);

        if (i != m_size - 1)
          cout << " -> ";
        else
          cout << endl;
      }
    }

  private:
    size_t m_capacity;
    size_t m_size;

    int* m_data;

    void resize() {
      size_t capacity = m_capacity * 2;
      int* tmp = (int*)realloc(m_data, capacity * sizeof(*m_data));

      if (!tmp)
        throw bad_alloc();

      m_data = tmp;
      m_capacity = capacity;
    }

    void insert(size_t pos, int v) {
      *(m_data + pos) = v;
      m_size++;
    }

    void replace_and_insert(size_t limit, int v) {
      for (size_t i = m_size; i > limit; i--) {
        *(m_data + i) = *(m_data + i - 1);
      }

      insert(limit, v);
    }

    size_t find_order(int v) {
      size_t pos = m_size;

      for (size_t i = 0; i < m_size; i++) {
        int curr = *(m_data + i);

        if (v < curr) {
          pos = i;
          break;  
        }
      }
      
      return pos;
    }
};

int main() {

  int arr[11] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10};

  OrderedIntList o;

  for(int i = 0; i < 11; i++){
    o.push(arr[i]);
    o.print();
  }

  o.print();
}
