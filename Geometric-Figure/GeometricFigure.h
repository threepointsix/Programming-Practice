#ifndef GEOMETRIC_FUGURE_H
#define GEOMETRIC_FUGURE_H

#include "GeometricFormula.h"

/* ------------   ALREADY IMPLEMENTED   ------------ */
class FlatGeometricFigure
{
protected: GeometricFormula* m_area;
public:
	float Area() const;

	virtual ~FlatGeometricFigure();
	virtual void Info(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const FlatGeometricFigure& formula);
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class SpatialGeometricFigure : public FlatGeometricFigure
{
protected:
	GeometricFormula* m_volume;

public:
	float Volume() const;

	virtual ~SpatialGeometricFigure();
	virtual void Info(std::ostream& out) const override;
};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class Parallelogram : public FlatGeometricFigure
{
public:
	Parallelogram(float aValue, float hValue);

	virtual void Info(std::ostream& out) const override;
};

/* ------------   STAGE_3 (3Pts)   ------------ */
// class Rectangle : public Parallelogram {};

/* ------------   STAGE_3 (3Pts)   ------------ */
// class Square : public Rectangle {};

/* ------------   STAGE_3 (3Pts)   ------------ */
// class Triangle : public FlatGeometricFigure {};

/* ------------   STAGE_3 (3Pts)   ------------ */
// class Circle : public FlatGeometricFigure {};

/* ------------   ALREADY IMPLEMENTED   ------------ */
class Cube : public SpatialGeometricFigure
{
public:
	Cube(float aValue);

	virtual void Info(std::ostream& out) const override;
};

/* ------------   STAGE_3 (3Pts)   ------------ */
// class Tetrahedron : public SpatialGeometricFigure {};

/* ------------   STAGE_3 (3Pts)   ------------ */
// class Cone : public SpatialGeometricFigure {};

#endif /* GEOMETRIC_FUGURE_H */
