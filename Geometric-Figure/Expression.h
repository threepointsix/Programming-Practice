#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <math.h>

class Expression /* ------------   ALREADY IMPLEMENTED   ------------ */
{
public:
	virtual float Evaluate() const = 0;
	virtual void Info(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Expression& expression);
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class SingleExpression : public Expression
{
protected:
	float m_value;

	SingleExpression(float value = 0);
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class MultiExpression : public Expression
{
protected:
	Expression* m_left;
	Expression* m_right;
	MultiExpression(Expression* lhs = nullptr, Expression* rhs = nullptr);
	virtual ~MultiExpression();
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class Constant : public SingleExpression
{
public:
	Constant(float value);
	virtual float Evaluate() const override;
	virtual void Info(std::ostream& out) const;
};

/* ------------   STAGE_1 (3Pts)   ------------ */
 class SquareRoot : public SingleExpression {
 public:
	 SquareRoot(float value);
	 void Info(std::ostream& out) const;
	 float Evaluate() const override;
 };

/* ------------   STAGE_1 (3Pts)   ------------ */
 class Power : public SingleExpression {
	 int degree;
 public:
	 Power(float value, float degree);
	 void Info(std::ostream& out) const;
	 float Evaluate() const override;
 };

/* ------------   STAGE_1 (3Pts)   ------------ */
 class Addition : public MultiExpression {
 public:

	 void Info(std::ostream& out) const;
	 float Evaluate() const override;
	 Addition(Expression* lhs, Expression* rhs);
 };

/* ------------   STAGE_1 (3Pts)   ------------ */
 class Subtraction : public MultiExpression {
 public:
	 void Info(std::ostream& out) const;
	 float Evaluate() const override;
	 Subtraction(Expression* lhs, Expression* rhs);

 };

/* ------------   STAGE_1 (3Pts)   ------------ */
 class Multiplication : public MultiExpression {
 public:
	 Multiplication(Expression* lhs, Expression* rhs);
	 void Info(std::ostream& out) const;
	 float Evaluate() const override;
 };

/* ------------   STAGE_1 (3Pts)   ------------ */
 class Division : public MultiExpression {
 public:
	 void Info(std::ostream& out) const;
	 float Evaluate() const override;
	 Division(Expression* lhs, Expression* rhs);
 };

#endif /* EXPRESSION_H */
