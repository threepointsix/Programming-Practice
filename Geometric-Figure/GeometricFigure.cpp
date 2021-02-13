#include "GeometricFigure.h"
#include "Expression.h"

/* ------------   ALREADY IMPLEMENTED   ------------ */
float FlatGeometricFigure::Area() const
{
	return this->m_area->Value();
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
FlatGeometricFigure::~FlatGeometricFigure()
{
	delete this->m_area;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void FlatGeometricFigure::Info(std::ostream& out) const
{
	out << "Area: " << *m_area;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
std::ostream& operator<<(std::ostream& out, const FlatGeometricFigure& figure)
{
	figure.Info(out); return out;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
float SpatialGeometricFigure::Volume() const
{
	return this->m_volume->Value();
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
SpatialGeometricFigure::~SpatialGeometricFigure()
{
	delete this->m_volume;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void SpatialGeometricFigure::Info(std::ostream& out) const
{
	FlatGeometricFigure::Info(out); out << " Volume: " << *m_volume;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
Parallelogram::Parallelogram(float aValue, float hValue)
{
	this->m_area = new AreaFormulaParallelogram(aValue, hValue);
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void Parallelogram::Info(std::ostream& out) const
{
	out << "Parallelogram: "; FlatGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   ALREADY IMPLEMENTED   ------------ */
Cube::Cube(float aValue)
{
	this->m_area = new AreaFormulaParallelogram(aValue, aValue);
	this->m_volume = new VolumeFormulaPrism(this->m_area, aValue);
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void Cube::Info(std::ostream& out) const
{
	out << "Cube - "; SpatialGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */
