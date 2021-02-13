#include <iostream> 
#include <iomanip> 
#include <cmath>
#include "signal_plot.h"
using namespace std;

Signal_plot::Signal_plot(int no_of_samples, int* samples) {
	this->signal.no_of_samples = no_of_samples;
	this->signal.samples = new int[no_of_samples];
	if (samples == nullptr) {
		for (int i = 0; i < no_of_samples; i++) {
			this->signal.samples[i] = 0;
		}
	}
	else {
		for (int i = 0; i < no_of_samples; i++) {
			this->signal.samples[i] = samples[i];
		}
	}
	init_plot();
	update_plot();
}

Signal_plot::~Signal_plot() {
	clean_plot();
	signal.no_of_samples = 0;
}

void Signal_plot::init_plot() {
	no_of_columns = signal.no_of_samples;
	no_of_rows = abs(signal.max_val() - signal.min_val()) + 1;
	plot = new char*[no_of_rows];
	for (int i = 0; i < no_of_rows; i++) {
		plot[i] = new char[no_of_columns];
	}
}

void Signal_plot::update_plot() {
	if (signal.samples == nullptr) {
		return;
	}
	int max = signal.max_val();
	for (int i = 0; i < no_of_columns; i++)
	{
		for (int j = 0; j < no_of_rows; j++)
		{
			if (j == max - signal.samples[i]) {
				plot[j][i] = '*';
			}
			else {
				plot[j][i] = ' ';
			}
		}
	}
}

void Signal_plot::clean_plot() {
	for (int i = 0; i < no_of_rows; i++) {
		delete [] plot[i];
	}
	delete[] plot;
	no_of_columns = 0;
	no_of_rows = 0;
}

ostream& operator<<(ostream& out, const Signal_plot& s)
{
	for (int j = 0; j < s.no_of_columns; j++)
		out << '-';
	out << endl;

	for (int i = 0; i < s.no_of_rows; i++)
	{
		for (int j = 0; j < s.no_of_columns; j++)
		{
			out << s.plot[i][j];
		}
		out << endl;
	}

	for (int j = 0; j < s.no_of_columns; j++)
		out << '-';
	out << endl;

	return out;
}

Signal_plot::Signal_plot(const Digital_signal& a) {
	signal = a;
	init_plot();
	update_plot();
}

Signal_plot::Signal_plot(const Signal_plot& a) {
	signal = a.signal;
	init_plot();
	update_plot();
}

Signal_plot& Signal_plot::operator=(const Signal_plot& a) {
	signal = a.signal;
	init_plot();
	update_plot();
	return *this;
}
