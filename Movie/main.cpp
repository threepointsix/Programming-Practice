#include "movie.h"
#include <iostream>

using namespace std;

int main(void) {
	/*------------------------- Part 1 - Checking basic functionality, such as constructors and overloaded output and input-------------------------*/

	//movie a("Interstellar"); // Initializing the movie with only a name
	//movie b("Inception", 2010); // Name and year
	//movie c("Prestige", 7); // Name and rating, so far as the number is between 0 and 10, not between 1888 and 2020. It was realized in ratOrYear method
	//movie d("The Dark Knight", 2008, genre::Crime); // Name, year and genre
	//movie e("Dunkirk", 2017, genre::Drama, 8); // Full initialization by name, year, genre and rating
	//cout << a; // Checking the overloaded output. Name of the movie is an obligatory field, but year, genre or rating of the movie may be unknown
	//cout << a;
	//cout << b;
	//cout << c;
	//cout << d;
	//cout << e;

	//movie h(e); // Checking copy constructor
	//cout << h;

	//movie f;
	//cin >> f; // Checking the overloaded input 
	//cout << f; // Output the result

	//----------------------------------------------- Part 2 - Checking overloaded operators = < >--------------------------------------------------

	//movie a("Hacksaw Ridge", 2016, genre::Drama, 9);
	//movie b = a; // = operator is just assigning all fields of one movie to another
	//cout << a; cout << b; // Two same outputs
	//movie c("Se7en", 1995, genre::Detective, 7);
	//cout << ((a < c) ? 1 : 0) << endl; 
	//cout << ((a > c) ? 1 : 0) << endl; // < and > operators compare two movies according to their ratings. Ratings comparison was used later on - in the sorting function

	//------------------------------- Part 3 - Checking a chooseByGenre method, which outputs movies of a particular genre--------------------------

	//movie arr[24] = { movie("Titanic", 1997, genre::Drama, 8), movie("Whiplash", 2013, genre::Drama, 8), movie("Arrival", 2016, genre::Drama, 8), movie("The Game", 1997 , genre::Drama, 7), movie("The Departed", 2006, genre::Crime, 9), movie("The Godfather", 1972, genre::Crime, 8), movie("Pulp Fiction", 1994, genre::Crime, 6), movie("The Gentlemen", 2018, genre::Crime, -1), movie("Shutter Island", 2009, genre::Detective, 7), movie("Memento", 2000, genre::Detective, -1), movie("Zodiac", 2007, genre::Detective, 7), movie("Non-stop", 2014, genre::Detective, 7), movie("1408", 2007, genre::Horror, 8), movie("It", 2017, genre::Horror, 8), movie("The Mist", 2007, genre::Horror, 8), movie("The Thing", 2011, genre::Horror, 7), movie("The Jungle Book", 2016, genre::Fantasy, 8), movie("Warcraft", 2016, genre::Fantasy, -1), movie("Thor: Ragnarok", 2017, genre::Fantasy, 7), movie("Jumanji", 1995, genre::Fantasy, 7), movie("Deadpool", 2016, genre::Comedy, 7), movie("The Mask", 1994, genre::Comedy, 7), movie("Taxi", 1998, genre::Comedy, 7), movie("We're the Millers", 2013, genre::Comedy, 7) };

	//arr->chooseByGenre(24); // Integer passed as argument is the array size

	//-------------------------------- Part 4 - Checking a function, which sorts an array of films by their ratings----------------------------------

	//movie arr[7] = { movie("Titanic", 1997, genre::Drama, 8), movie("The Game", 1997 , genre::Drama, 7), movie("The Departed", 2006, genre::Crime, 9), movie("The Godfather", 1972, genre::Crime, 8), movie("Pulp Fiction", 1994, genre::Crime, 6), movie("The Gentlemen", 2018, genre::Crime, -1), movie("Deadpool", 2016, genre::Comedy, 7) };
	//cout << "Before sorting: " << endl;
	//for (int i = 0; i < 7; i++) { // Array before sorting
	//	cout << arr[i];
	//}
	//cout << endl;

	//sortByRating(arr, 7);
	//cout << "After sorting: " << endl;
	//for (int i = 0; i < 7; i++) { // Array after sorting
	//	cout << arr[i];
	//}

	//------------------------------- Part 5 - Checking a function, which sorts an array of films by the release year------------------------------------

	//movie arr[7] = { movie("Titanic", 1997, genre::Drama, 8), movie("The Game", 1997 , genre::Drama, 7), movie("The Departed", 2006, genre::Crime, 9), movie("The Godfather", 1972, genre::Crime, 8), movie("Pulp Fiction", 1994, genre::Crime, 6), movie("The Gentlemen", 2018, genre::Crime, -1), movie("Deadpool", 2016, genre::Comedy, 7) };

	//for (int i = 0; i < 7; i++) { // Array before sorting
	//	cout << arr[i];
	//}
	//cout << endl;

	//sortByYear(arr, 7);

	//for (int i = 0; i < 7; i++) { // Array after sorting
	//	cout << arr[i];
	//}
	
	return 1;
}
