#include <iostream> 
#include <iomanip> 
#include <cmath>
#include "digital_signal.h"
using namespace std;

Digital_signal::Digital_signal(int no_of_samples, int* samples) {
	this->no_of_samples = no_of_samples;
	this->samples = new int[no_of_samples];
	if (samples == nullptr) {
		for (int i = 0; i < no_of_samples; i++) {
			this->samples[i] = 0;
		}
	}
	else {
		for (int i = 0; i < no_of_samples; i++) {
			this->samples[i] = samples[i];
		}
	}
}

Digital_signal::Digital_signal(const Digital_signal& a) {
	no_of_samples = a.no_of_samples;
	samples = new int[no_of_samples];
	for (int i = 0; i < no_of_samples; i++) {
		samples[i] = a.samples[i];
	}
}

Digital_signal::~Digital_signal() {
	delete[] samples;
	no_of_samples = 0;
}

int Digital_signal::min_val() const {
	if (!this->no_of_samples) {
		return 0;
	}
	int min = this->samples[0];
	for (int i = 1; i < this->no_of_samples; i++) {
		if (this->samples[i] < min) {
			min = this->samples[i];
		}
	}
	return min;
}

int Digital_signal::max_val() const {
	if (!this->no_of_samples) {
		return 0;
	}
	int max = samples[0];
	for (int i = 1; i < this->no_of_samples; i++) {
		if (this->samples[i] > max) {
			max = this->samples[i];
		}
	}
	return max;
}

ostream& operator<<(ostream& out, const Digital_signal& a) {
	out << "[ ";
	for (int i = 0; i < a.no_of_samples; i++) {
		out << a.samples[i] << " ";
	}
	out << "]" << endl;
	out << "Signal min: " << a.min_val() << "  Signal max: " << a.max_val();
	out << endl;
	return out;
}

Digital_signal operator+(const Digital_signal& a, int c) {
	for (int i = 0; i < a.no_of_samples; i++) {
		a.samples[i] += c;
	}
	return a;
}

Digital_signal Digital_signal::operator=(Digital_signal a) {
	no_of_samples = a.no_of_samples;
	samples = new int[a.no_of_samples];
	for (int i = 0; i < no_of_samples; i++) {
		samples[i] = a.samples[i];
	}
	return *this;
}
