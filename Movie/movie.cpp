#include "movie.h"
#include <iostream>

using namespace std;

int strleng(const char* a) {
	int len;
	for (len = 0; len < MAX_NAME && a[len] != '\0'; len++); 
	return len;
}

void movie::ratOrYear(int a) {
	if (a >= 0 && a <= 10) { // If the given number is between 0 and 10, then it is considered as a rating of the movie 
		this->rating = a;
	}
	else if (a > 1888 && a < 2021) { // If the number is between 1888 and 2021, then it is considered as a year
		this->year = a;
	}
	// If the given number is negative or between 10 and 1888, then it is neither a rating, nor a year
}

movie::movie() : name(nullptr), year(0), gen(genre::Unknown), rating(0) {}

movie::movie(const char* a) {
	int len = strleng(a), i;
	name = new char[len + 1];
	for (i = 0; i < len; i++) {name[i] = a[i];}
	name[i] = '\0';
	year = 0;
	gen = genre::Unknown;
	rating = 0;
}

movie::movie(const char* a, int b) {
	int len = strleng(a), i;
	name = new char[len + 1];
	for (i = 0; i < len; i++) { name[i] = a[i]; }
	name[i] = '\0';	
	gen = genre::Unknown;
	this->ratOrYear(b);
}

movie::movie(const char* a, genre b) {
	int len = strleng(a), i;
	name = new char[len + 1];
	for (i = 0; i < len; i++) { name[i] = a[i]; }
	name[i] = '\0';
	gen = b;
	rating = 0;
	year = 0;
}


movie::movie(const char* a, int b, genre c) {
	int len = strleng(a), i;
	name = new char[len + 1];
	for (i = 0; i < len; i++) { name[i] = a[i]; }
	name[i] = '\0';	
	gen = c;
	this->ratOrYear(b);
}

movie::movie(const char* a, int b, genre c , int d) {
	int len = strleng(a), i;
	name = new char[len + 1];
	for (i = 0; i < len; i++) { name[i] = a[i]; }
	name[i] = '\0';
	gen = c;
	this->ratOrYear(b);
	this->ratOrYear(d);
}

ostream& operator<<(ostream& out, const movie &a) {
	out << "Name: ";
	cout.width(20);
	out << left << a.name;
	if (a.year < 1888) {
		out << "  Year: ";
		cout.width(4);
		out << left << 0;
	}
	else {
		out << "  Year: ";
		cout.width(4);
		out << left << a.year;
	}
	out << "  Genre: ";
	cout.width(10);
	switch (a.gen) {
	case genre::Unknown: out << left << "Unknown"; break;
	case genre::Comedy:	out << left << "Comedy"; break;
	case genre::Crime: out << left << "Crime"; break;
	case genre::Horror: out << left << "Horror"; break;
	case genre::Detective: out << left << "Detective"; break;
	case genre::Drama: out << left << "Drama"; break;
	case genre::Fantasy: out << left << "Fantasy"; break;
	}
	if (a.rating < 0) {
		out << "  Rating: Unknown" << endl;
	}
	else {
		out << "  Rating: " << a.rating << endl;
	}
	return out;
}

istream& operator>>(istream& in, movie& a) {
	cout << "Write a name of the movie: ";
	a.name = new char[MAX_NAME];
	in >> a.name;
	cout << "Write a year (if you don't know the exact year, just write 0): ";
	in >> a.year;
	while (a.year < 1888 && a.year != 0) {
		cout << "First movie was recorded in 1888. Write a year later than 1888: ";
		in >> a.year;
	}
	int i;
	cout << "1. Drama" << endl << "2. Crime" << endl << "3. Detective" << endl << "4. Horror" << endl << "5. Fantasy" << endl << "6. Comedy" << endl;
	cout << "Choose a genre by number (if you don't want to choose, just write 0): ";
	in >> i;
	if (i == 0) {
		a.gen = genre::Unknown;
	}
	while (i < 0 || i > 6) {
		cout << "1. Drama" << endl << "2. Crime" << endl << "3. Detective" << endl << "4. Horror" << endl << "5. Fantasy" << endl << "6. Comedy" << endl << "Type a number from 1 to 6: ";
		in >> i;
	}
	switch (i) {
	case 1: a.gen = genre::Drama; break;
	case 2: a.gen = genre::Crime; break;
	case 3: a.gen = genre::Detective; break;
	case 4: a.gen = genre::Horror; break;
	case 5: a.gen = genre::Fantasy; break;
	case 6: a.gen = genre::Comedy; break;
	}
	cout << "Write a rating from 0 to 10 (if you don't want to rate, just write any non-zero negative number): ";
	in >> a.rating;
	while (a.rating > 10) {
		cout << "Write a number from 0 to 10: ";
		in >> a.rating;
	}
	return in;
}

movie& movie::operator=(movie& a) {
	int leng = strleng(a.name), i;
	name = new char[leng + 1];
	for (i = 0; i < leng; i++) {
		name[i] = a.name[i];
	}
	name[i] = '\0';
	rating = a.rating;
	year = a.year;
	gen = a.gen;
	return *this;
}

int operator>(movie a, movie b) {
	if (a.rating > b.rating) {
		return 1;
	}
	else {
		return 0;
	}
}

int operator<(movie a, movie b) {
	if (a.rating < b.rating) {
		return 1;
	}
	else {
		return 0;
	}
}

void movie::chooseByGenre(int leng) {
	int c, i = 0, p = 0;
	cout << "1. Drama" << endl << "2. Crime" << endl << "3. Detective" << endl << "4. Horror" << endl << "5. Fantasy" << endl << "6. Comedy" << endl;
	cout << "Type a number of a genre: ";
	cin >> c;
	while (c < 1 || c > 6) {
		cout << "Type a number from 1 to 6: " << "1. Drama | " << "2. Crime | " << "3. Detective | " << "4. Horror | " << "5. Fantasy | " << "6. Comedy";
		cin >> c;
	}
	switch (c) {
	case 1:
		while (i < leng) {
			if (this[i].gen == genre::Drama) {
				cout << this[i];
			}
			i++;
		}
	case 2:
		while (i < leng) {
			if (this[i].gen == genre::Crime) {
				cout << this[i];
			}
			i++;
		}
	case 3:
		while (i < leng) {
			if (this[i].gen == genre::Detective) {
				cout << this[i];
			}
			i++;
		}
	case 4:
		while (i < leng) {
			if (this[i].gen == genre::Horror) {
				cout << this[i];
			}
			i++;
		}
	case 5:
		while (i < leng) {
			if (this[i].gen == genre::Fantasy) {
				cout << this[i];
			}
			i++;
		}
	case 6:
		while (i < leng) {
			if (this[i].gen == genre::Comedy) {
				cout << this[i];
			}
			i++;
		}
	}
}

movie *sortByRating(movie* a, int n) {
	movie key;
	int i, j;
		for (i = 1; i < n; i++)
		{
			key = a[i];
			j = i - 1;
			while (j >= 0 && a[j] < key)
			{
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = key;
		}
		return a;
}

movie* sortByYear(movie* a, int n) {
	movie key;
	int i, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j].year < key.year)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
	return a;
}

movie::~movie() {
	delete [] name;
	year = 0;
	gen = genre::Unknown;
	rating = 0;
}

movie::movie(const movie& a) {
	int leng = strleng(a.name), i;
	name = new char[leng + 1];
	for (i = 0; i < leng; i++) {
		name[i] = a.name[i];
	}
	name[i] = '\0';
	year = a.year;
	gen = a.gen;
	rating = a.rating;
}
