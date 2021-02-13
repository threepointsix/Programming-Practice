#include "Student.h"

/* ----------- STAGE 3 ----------- */
Student::Student(const char _surname[MAX_CHAR], const char _name[MAX_CHAR]) {
	int i;
	for (i = 0; i < MAX_CHAR; i++) {
		this->surname[i] = _surname[i];
	}
	for (i = 0; i < MAX_CHAR; i++) {
		this->name[i] = _name[i];
	}
}

void Student::ValidateStudentCard() {
	this->studentCard.validStatus = CARD_STATUS::VALID;
}

unsigned short Student::GetID() const {
	return this->studentCard.studentID;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
	int i;
	for (i = 0; student.surname[i]; i++) {
		out << student.surname[i];
	}
	out << " ";
	for (i = 0; student.name[i]; i++) {
		out << student.name[i];
	}
	out << student.studentCard;
	return out;
}

/* ----------- STAGE 4 ----------- */
void Student::BorrowBook(Book newBook) {
	this->studentCard.studentBooks[this->studentCard.bookCount] = newBook;
	this->studentCard.bookCount++;
}

/* ----------- STAGE 5 ----------- */
void Student::LostStudentCard() {
	if (this->studentCard.validStatus == CARD_STATUS::VALID) {
		this->studentCard = StudentCard(studentCard);
	}
}
