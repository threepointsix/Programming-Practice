#include "GeometricFormula.h"

/* ------------   ALREADY IMPLEMENTED   ------------ */
float GeometricFormula::Value() const
{
	return this->m_expression->Evaluate();
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void GeometricFormula::Info(std::ostream& out) const
{
	this->m_expression->Info(out);
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
GeometricFormula::~GeometricFormula()
{
	delete this->m_expression;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
std::ostream& operator<<(std::ostream& out, const GeometricFormula& formula)
{
	formula.Info(out); out << " = " << formula.Value();  return out;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
AreaFormulaParallelogram::AreaFormulaParallelogram(float aValue, float hValue)
{
	this->m_expression = new Multiplication(new Constant(aValue), new Constant(hValue));
}

/* ------------   STAGE_2 (1.5Pts)   ------------ */
AreaFormulaTriangle::AreaFormulaTriangle(float aValue, float hValue) {
	this->m_expression = new Division(new Multiplication(new Constant(aValue), new Constant(hValue)), new Constant(2));
}
/* ------------   STAGE_2 (1.5Pts)   ------------ */
AreaFormulaCircle::AreaFormulaCircle(float aValue) {
	this->m_expression = new Multiplication(new Power(aValue, 2.0f), new Constant(acos(-1)));
}


/* ------------   ALREADY IMPLEMENTED   ------------ */
VolumeFormulaPrism::VolumeFormulaPrism(GeometricFormula* baseArea, float hValue)
{
	this->m_expression = new Multiplication(new Constant(baseArea->Value()), new Constant(hValue));
}

/* ------------   STAGE_2 (1.5Pts)   ------------ */

VolumeFormulaPyramid::VolumeFormulaPyramid(GeometricFormula* baseArea, float hValue) {
	this->m_expression = new Division(new Multiplication(new Constant(baseArea->Value()), new Constant(hValue)), new Constant(3));
}