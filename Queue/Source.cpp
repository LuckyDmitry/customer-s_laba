#include <iostream>
#include "Queue.h"
#include "Customer.h"
using namespace std;





int main() {
	try{

		Queue<Customer> s;
		s.push(Customer("Alex", 123));
		s.push(Customer("Dima", 99));
		s.push(Customer("Loli", 100));
		Queue<Customer> q(s);
		q.print_all();
		q.pop();
		cout << endl;
		q.print_all();
		cout << endl;
		s.print_all();
		cout << s.get_size() << endl;
		s.pop();
		s.pop();
		cout << s.is_empty() << endl;
		s.pop();
		cout << s.is_empty() << endl;
		q.clean();
		cout << q.is_empty();
		
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
	


	return 0;
}