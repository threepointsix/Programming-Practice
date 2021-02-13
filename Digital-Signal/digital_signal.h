#pragma once
#include <iostream> 
using namespace std;

class Digital_signal
{
private:
	int* samples;
	int no_of_samples;


public:
	Digital_signal(int no_of_samples = 0, int* samples = nullptr);
	Digital_signal(const Digital_signal&); // Copy constructor
	~Digital_signal();


	int min_val() const;
	int max_val() const;

	friend class Signal_plot;
	friend ostream& operator<<(ostream&, const Digital_signal&);
	friend Digital_signal operator+(const Digital_signal&, int c);
	Digital_signal operator=(Digital_signal); // Assignment
};
