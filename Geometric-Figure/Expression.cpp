#include "Expression.h"


/* ------------   ALREADY IMPLEMENTED   ------------ */
std::ostream& operator<<(std::ostream& out, const Expression& expression)
{
	expression.Info(out); return out;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
SingleExpression::SingleExpression(float value) : m_value(value) { }

/* ------------   ALREADY IMPLEMENTED   ------------ */
MultiExpression::MultiExpression(Expression* lhs, Expression* rhs)
{
	this->m_left = lhs;
	this->m_right = rhs;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
MultiExpression::~MultiExpression()
{
	delete this->m_left;
	delete this->m_right;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
Constant::Constant(float value) : SingleExpression(value) { }

/* ------------   ALREADY IMPLEMENTED   ------------ */
void Constant::Info(std::ostream& out) const
{
	out << this->m_value;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
float Constant::Evaluate() const
{
	return this->m_value;
}

/* ------------   STAGE_1 (3Pts)   ------------ */
float SquareRoot::Evaluate() const { return sqrt(this->m_value); }

/* ------------   STAGE_1 (3Pts)   ------------ */
float Power::Evaluate() const { return (this->m_value * this->m_value); }

/* ------------   STAGE_1 (3Pts)   ------------ */
float Addition::Evaluate() const { return (this->m_left->Evaluate() + this->m_right->Evaluate()); }

/* ------------   STAGE_1 (3Pts)   ------------ */
float Subtraction::Evaluate() const { return (this->m_left->Evaluate() - this->m_right->Evaluate()); }

/* ------------   STAGE_1 (3Pts)   ------------ */
float Multiplication::Evaluate() const { return (this->m_left->Evaluate() * this->m_right->Evaluate()); }

/* ------------   STAGE_1 (3Pts)   ------------ */
float Division::Evaluate() const { return (this->m_left->Evaluate() / this->m_right->Evaluate()); }

/* ------------   STAGE_1 (3Pts)   ------------ */
SquareRoot::SquareRoot(float value) {
	this->m_value = value;
}
/* ------------   STAGE_1 (3Pts)   ------------ */
void SquareRoot::Info(std::ostream& out) const {
	out << "sqrt(" << this->m_value << ")";
}
/* ------------   STAGE_1 (3Pts)   ------------ */
Power::Power(float value, float degree) {
	this->m_value = value;
	this->degree = degree;
}
/* ------------   STAGE_1 (3Pts)   ------------ */
void Power::Info(std::ostream& out) const {
	out << this->m_value << "^" << this->degree;
}
/* ------------   STAGE_1 (3Pts)   ------------ */
void Addition::Info(std::ostream& out) const {
	out << "(" << *this->m_left << "+" << *this->m_right << ")";
}

/* ------------   STAGE_1 (3Pts)   ------------ */
void Multiplication::Info(std::ostream& out) const {
	out << "(" << *this->m_left << "*" << *this->m_right << ")";
}

/* ------------   STAGE_1 (3Pts)   ------------ */
void Division::Info(std::ostream& out) const {
	out << "(" << *this->m_left << "/" << *this->m_right << ")";
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Multiplication::Multiplication(Expression* lhs, Expression* rhs) {
	this->m_left = lhs;
	this->m_right = rhs;
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Division::Division(Expression* lhs, Expression* rhs) {
	this->m_left = lhs;
	this->m_right = rhs;
}

/* ------------   STAGE_1 (3Pts)   ------------ */
Addition::Addition(Expression* lhs, Expression* rhs) {
	this->m_left = lhs;
	this->m_right = rhs;
}
/* ------------   STAGE_1 (3Pts)   ------------ */
Subtraction::Subtraction(Expression* lhs, Expression* rhs) {
	this->m_left = lhs;
	this->m_right = rhs;
}
/* ------------   STAGE_1 (3Pts)   ------------ */

void Subtraction::Info(std::ostream& out) const {
	out << "(" << *this->m_left << "-" << *this->m_right << ")";
}