#pragma once
#include <iostream>

using namespace std;
static constexpr int MAX_NAME = 20;
enum class genre {Unknown, Drama, Crime, Detective, Horror, Fantasy, Comedy};

class movie {
	char* name;
	int year;
	genre gen;
	int rating;
public:
	// Constructors
	movie();
	movie(const char*);
	movie(const char*, int);
	movie(const char*, genre);
	movie(const char*, int, genre);
	movie(const char*, int, genre, int);
	// Copy Constructor
	movie(const movie&);
	// Destructor
	~movie();
	// Methods
	void ratOrYear(int); // A method, to initialize year and rating
	void chooseByGenre(int); // A method, that print from a given array only movies with the chosen genre
	// Functions
	friend movie* sortByRating(movie*, int); // A friend function, that sort an array of movies according to their ratings
	friend movie* sortByYear(movie*, int); // A friend function, that sort an array of movies according to their release year
	// Overloading
	friend ostream& operator<<(ostream& out, const movie &a);
	friend istream& operator>>(istream& in, movie& a);
	movie& operator=(movie&); // Assignment
	friend int operator<(movie a, movie b); // Rating comparison
	friend int operator>(movie a, movie b); // Rating comparison
};

// Functions
int strleng(const char*); // Calculating the length of the given name string. So far as using <string> library is forbidden, I used "for" loop
