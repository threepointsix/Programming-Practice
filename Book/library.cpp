#include "Library.h"

/* ----------- STAGE 2 ----------- */
Library::Library(Book books[MAX_LIBRARY_BOOKS], unsigned short counts[MAX_LIBRARY_BOOKS]) {
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++) {
		this->resources[i].book = books[i];
		this->resources[i].count = counts[i];
	}
}

std::ostream& operator<<(std::ostream& out, Library& library) {
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++) {
		out << "Book No " << i << ":";
		out << " (" << library.resources[i].count << ") ";
		out << library.resources[i].book;
		out << std::endl;
	}
	return out;
}


/* ----------- STAGE 3 ----------- */

void Library::AddStudent(Student& newStudent) {
	if (STUDENTS_COUNT >= MAX_STUDENTS) {
		return;
	}
	else {
		this->students[STUDENTS_COUNT] = newStudent.GetID();
		newStudent.ValidateStudentCard();
		STUDENTS_COUNT++;
	}
 }

/* ----------- STAGE 4 ----------- */

void MakeReservation(Library& library, Student& student, unsigned short bookID, unsigned short amount) {
	int i, k;
	bool a = false;
	if (student.studentCard.Status() == CARD_STATUS::INVALID) {
		return;
	}
	for (i = 0; i < MAX_STUDENTS; i++) {
		if (library.students[i] == student.GetID()) {
			a = true;
		}
	}
	if (a == false) {
		return;
	}
	for (i = 0; i < amount && student.studentCard.GetBookCount() < MAX_STUDENT_BOOKS; i++) {
		for (k = 0; k < MAX_LIBRARY_BOOKS; k++) {
			if (library.resources[k].book.GetBookID() == bookID) {
				if (library.resources[k].count > 0) {
					student.BorrowBook(library.resources[k].book);
					library.resources[k].count--;
				}
			}
		}
	}
}
