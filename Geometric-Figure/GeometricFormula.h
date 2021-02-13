#ifndef OPERATION_H
#define OPERATION_H

#include "Expression.h"

/* ------------   ALREADY IMPLEMENTED   ------------ */
class GeometricFormula
{
protected: Expression* m_expression;
public:
	float Value() const;
	void Info(std::ostream& out) const;

	virtual ~GeometricFormula();

	friend std::ostream& operator<<(std::ostream& out, const GeometricFormula& formula);
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class AreaFormulaParallelogram : public GeometricFormula
{
public:
	AreaFormulaParallelogram(float aValue, float hValue);
};

/* ------------   STAGE_2 (1.5Pts)   ------------ */
 class AreaFormulaTriangle : public GeometricFormula {
 public:
	 AreaFormulaTriangle(float aValue, float hValue);
 };

/* ------------   STAGE_2 (1.5Pts)   ------------ */
 class AreaFormulaCircle : public GeometricFormula {
 public:
	 AreaFormulaCircle(float aValue);
 };

/* ------------   ALREADY IMPLEMENTED   ------------ */
class VolumeFormulaPrism : public GeometricFormula /* Represents All Prisms And Additionally Cylinders */
{
public:
	VolumeFormulaPrism(GeometricFormula* baseArea, float hValue);
};

/* ------------   STAGE_2 (1.5Pts)   ------------ */
 class VolumeFormulaPyramid : public GeometricFormula /* Represents All Pyramids And Additionally Cones */ {
 public:
	 VolumeFormulaPyramid(GeometricFormula* baseArea, float hValue);
 };

#endif /* OPERATION_H */
