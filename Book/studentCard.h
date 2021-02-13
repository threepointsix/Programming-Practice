#ifndef STUDENT_CARD_H
#define STUDENT_CARD_H

#define MAX_STUDENT_BOOKS 5

#include "Book.h"
#include <iostream>

using namespace std;

enum class CARD_STATUS { INVALID, VALID };

class StudentCard
{
	friend class Student;

	/* ----------- ALREADY IMPLEMENTED ----------- */
	unsigned short studentID; unsigned short bookCount = 0;

	/* ----------- ALREADY IMPLEMENTED ----------- */
	CARD_STATUS validStatus = CARD_STATUS::INVALID;
	Book studentBooks[MAX_STUDENT_BOOKS];

public:
	/* ----------- ALREADY IMPLEMENTED ----------- */
	static unsigned short STUDENT_CARD_COUNT;


	/* ----------- STAGE 1 ----------- */
	StudentCard() : studentID(STUDENT_CARD_COUNT) {
		++STUDENT_CARD_COUNT;
	};
	StudentCard(StudentCard& studentCard) {
		this->studentID = STUDENT_CARD_COUNT;
		this->validStatus = studentCard.validStatus;
		this->bookCount = studentCard.bookCount;
		for (int i = 0; i < MAX_STUDENT_BOOKS; i++) {
			this->studentBooks[i] = studentCard.studentBooks[i];
		}
		studentCard.validStatus = CARD_STATUS::INVALID;
		STUDENT_CARD_COUNT++;
	};

	/* ----------- STAGE 1 ----------- */
	friend std::ostream& operator<<(std::ostream& out, const StudentCard& studentCard) {
		out << " " << studentCard.studentID;
		if (studentCard.validStatus == CARD_STATUS::INVALID) {
			out << " (Not valid)";
		}
		else {
			out << " (Valid)";
		}
		for (int i = 0; i < studentCard.bookCount; i++) {
			out << endl;
			out.width(5);
			out << left << " ";
			out << studentCard.studentBooks[i];
		}
		out << endl;
		return out;
	};


	/* ----------- STAGE 4 ----------- */
	unsigned short GetBookCount() const;
	unsigned short GetID() const;


	/* ----------- ALREADY IMPLEMENTED ----------- */
	CARD_STATUS Status() const { return this->validStatus; }
	void SetState(CARD_STATUS validStatus) { this->validStatus = validStatus; }
};

#endif /* STUDENT_CARD_H */
