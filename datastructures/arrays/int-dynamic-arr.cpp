#include <iostream>
#define GROWTH 2
#define CAPACITY 10

using namespace std;

class IntArr {
  public:
    IntArr();
    ~IntArr();

    int pop();
    int getAt(size_t idx);
    void push(int value);
    size_t size();
  
  private:
    size_t m_capacity;
    size_t m_size;

    int* m_data;

    void resize();
};

IntArr::IntArr() {
  m_capacity = CAPACITY;
  m_size = 0;
  m_data = (int*)malloc(m_capacity * sizeof(*m_data));

  if (!m_data)
    throw bad_alloc();
}

IntArr::~IntArr(){
  free(m_data);
}

int IntArr::getAt(size_t idx) {
  return *(m_data + idx);
}

void IntArr::push(int value) {
  if (m_size >= m_capacity)
    resize();

  *(m_data + m_size++) = value;
}

size_t IntArr::size(){
  return m_size;
}

void IntArr::resize() {
  size_t capacity = m_capacity * GROWTH;
  int* tmp = (int*)realloc(m_data, capacity * sizeof(*m_data));

  if (!tmp) {
    throw bad_alloc();
  }

  m_data = tmp;
  m_capacity = capacity;
}

int IntArr::pop() {
  return *(m_data + --m_size);
}

int main() {
  IntArr arr;

  for(int i=0; i < CAPACITY; i++) {
    arr.push(i);
  }

  arr.push(10);

  for(size_t i=0; i<arr.size(); i++) {
    cout << arr.getAt(i) << endl;
  }

  cout << "pop" << endl;
  arr.pop();
  cout << arr.getAt(11) << endl;

  return 0;
}
