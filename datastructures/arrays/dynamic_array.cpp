#include <iostream>
#define MIN_CAPACITY 10
#define GROWTH_FACTOR 2

using namespace std;

class IntArray {
	public:
	    IntArray();
	    ~IntArray();

	    void push(int value);
	    int pop();
	    void set(size_t position, int value);
	    size_t size();

	private:
	    size_t m_size;
	    size_t m_capacity;
	    int* m_data;
	    void resize();
};


IntArray::IntArray() {
    m_size = 0;
    m_capacity = MIN_CAPACITY;

    m_data = (int*)malloc(m_capacity * sizeof(*m_data));

    if (!m_data)
	throw bad_alloc();
}

IntArray::~IntArray() {
	free(m_data);
}

void IntArray::resize() {
	size_t capacity = m_capacity * GROWTH_FACTOR;
	cout << "Resizing: " << capacity << endl;

	int* tmpdata = (int*)realloc(m_data, capacity * sizeof(*m_data));

	if (!tmpdata)
	    throw bad_alloc();

	m_data = tmpdata;
	m_capacity = capacity;
}

void IntArray::push(int value) {
	if (m_size >= m_capacity){
		resize();
	}

    	*(m_data + m_size++) = value;
}

int IntArray::pop() {
	return *(m_data + --m_size);
}

size_t IntArray::size() {
	return m_size;
}

int main() {
	IntArray intarr;
	for (int i = 0; i < 50; i++)
	    intarr.push(i);

	cout << "Size of intarr: " << intarr.size() << endl;
	
	cout << "Remove the last item: " << intarr.pop() << endl;

}
