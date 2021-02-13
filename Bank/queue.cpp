#include <iostream>
using namespace std;
#include "queue.h"

bool Queue::isempty() const {
	if (!clients) {
		return true;
	}
	else {
		return false;
	}
}

bool Queue::isfull() const {
	if (clients == qsize) {
		return true;
	}
	else {
		return false;
	}
}

int Queue::size() const { return clients; }

bool Queue::enqueue(const Client& client) {
	if (isfull()) {
		return false;
	}
	else if (!rear) {
		Node* a = new Node;
		a->item.set(client.what_time());
		a->next = nullptr;
		front = rear = a;
		clients++;
		return true;
	}
	else
	{
		rear->next = new Node;
		rear->next->item.set(client.what_time());
		rear = rear->next;
		rear->next = nullptr;
		clients++;
		return true;
		//Node* ptr = front;
		//front = new Node;
		//front->item.set(client.what_time());
		//front->next = ptr;
		//return true;
	}
}

bool Queue::dequeue(Client& client) {
	if (isempty()) {
		return false;
	}
	else {
		client.set(front->item.what_time());
		Node* ptr;
		ptr = front;
		front = front->next;
		delete ptr;
		clients--;
		if (clients == 0) {
			front = rear = nullptr;
		}
		return true;
	}
}

Queue::Queue(int qs) : qsize(qs), clients(0), front(nullptr), rear(nullptr) {};

Queue::~Queue() {
	Node* ptr = front;
	while (ptr != nullptr)
	{
		front = front->next;
		delete ptr;
		ptr = front;
	}
	front = rear = nullptr;
}

ostream& Queue::print(ostream& out) const {
	out << "Queue:" << endl;
	if (isempty()) {
		out << "Empty queue!";
	}
	else {
		Node* ptr = front;
		while (ptr != nullptr) {
			out << ptr->item;
			ptr = ptr->next;
		}
	}
	out << endl;
	return out;
}

ostream& operator<<(ostream& out, const Queue& q)
{
	q.print(out);
	return out;
}


