#include<iostream>
#define NUM_EMPLOYEE 3

using namespace std;

int main() {
    int salary[NUM_EMPLOYEE], lower=0, greater=0;

    cout << "Enter the salary for each employee" << endl;

    for (int i = 0; i < NUM_EMPLOYEE; i++) {
   	cout << "Employee number " << i + 1 << ": ";
	cin >> salary[i];
    }

    for (int i = 0; i < NUM_EMPLOYEE; i++) {
    	if(salary[i] > 3000) 
	    greater++;
	else
	    lower++;
    }

    cout << "Employees with salary greater than 3000: " << greater << endl;
    cout << "Employees with salary less than 3000: " << lower << endl;

    return 0;
}
