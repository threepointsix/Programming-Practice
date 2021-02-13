#include <iostream>
using namespace std;
#include "bank.h"

BankWindow::BankWindow(int queue_size, int working_time) {
	Queue queue_to_window(queue_size);
	this->working_time = working_time;
}

void BankWindow::simulation(int time_between_clients) {
	int min = working_time * min_per_hr, k;
	for (k = 0; k < min; k++) {
		if (k % time_between_clients == 0) {
			if (queue_to_window.isfull()) {
				number_returned++;
			}
			else {
				Client c1;
				c1.set(k);
				queue_to_window.enqueue(c1);
				number_accepted++;
			}
		}
		if (release_time <= 0) {
			if (queue_to_window.size() > 0) {
				Client c2;
				queue_to_window.dequeue(c2);
				release_time = c2.how_long();
				number_served++;
			}
		}
		else {
			release_time--;
		}
	}


}

ostream& operator<<(ostream& out, const BankWindow& a) {
	out << "The number of customers accepted into the queue: " << a.number_accepted << endl;
	out << "The number of customers served by the window: " << a.number_served << endl;
	out << "The number of clients returned from the queue: " << a.number_returned << endl;
	return out;
}