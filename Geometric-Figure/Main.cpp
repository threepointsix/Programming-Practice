#include <iostream>

#include "Expression.h"
#include "GeometricFigure.h"

/* ------------   STAGE_4 (0.5Pts)   ------------ */
// float GetVolumeSumFromSpatialFigures(FlatGeometricFigure** geometricFigures, unsigned short size) {}

int main(int argc, char** argv)
{
	 std::cout << std::endl << " --------------------- STAGE_1 (3Pts) --------------------- " << std::endl;

	 Expression* constant1 = new Constant(17.0f);
	 std::cout << "Constant(17) : " << *constant1 << " = " << constant1->Evaluate() << std::endl;
	 delete constant1;

	 Expression* constant2 = new Constant(29.5f);
	 std::cout << "Constant(29.5) : " << *constant2 << " = " << constant2->Evaluate() << std::endl;
	 delete constant2;

	 Expression* addition1 = new Addition(new Constant(29.5f), new Constant(8.0f));
	 std::cout << "Addition(Constant (29.5), Constant(8)) : " << *addition1 << " = " << addition1->Evaluate() << std::endl;
	 delete addition1;

	 Expression* substraction1 = new Subtraction(new Constant(29.5f), new Constant(8.0f));
	 std::cout << "Subtraction(Constant (51), Constant(15)) : " << *substraction1 << " = " << substraction1->Evaluate() << std::endl;
	 delete substraction1;

	 Constant* constant5 = new Constant(11.0f);
	 Constant* constant6 = new Constant(4.0f);

	 Expression* multiplication1 = new Multiplication(constant5, constant6);
	 std::cout << "Multiplication(Constant(11), Constant(4)) : " << *multiplication1 << " = " << multiplication1->Evaluate() << std::endl;
	 delete multiplication1;

	 Expression* division1 = new Division(new Constant(18.0f), new Constant(4.0f));
	 std::cout << "Subtraction(Constant (18), Constant(4)) : " << *division1 << " = " << division1->Evaluate() << std::endl;
	 delete division1;

	 Expression* constant7 = new Constant(144.0f);

	 Expression* squareRoot1 = new SquareRoot(constant7->Evaluate());
	 std::cout << "SquareRoot(144) : " << *squareRoot1 << " = " << squareRoot1->Evaluate() << std::endl;

	 Expression* power1  = new Power(12.0f, 2.0f);
	 std::cout << "Power(12) : " << *power1 << " = " << power1->Evaluate() << std::endl;

	 delete constant7;
	 delete squareRoot1;
	 delete power1;

	 Expression* multiplication2 = new Multiplication(new Addition(new Constant(9.5f), new Constant(0.5f)), new Subtraction(new Constant(29.5f), new Constant(28.0f)));
	 std::cout << "Multiplication(Addition(Constant(9.5),Constant(0.5)), Subtraction(Constant(29.5),Constant(28))) : " << *multiplication2 << " = " << multiplication2->Evaluate() << std::endl;
	 delete multiplication2;


	 std::cout << std::endl << " --------------------- STAGE_2 (1.5Pts) --------------------- " << std::endl << std::endl;

	 GeometricFormula* areaParallelogram1 = new AreaFormulaParallelogram(1.0f, 1.0f);
	 std::cout << "AreaFormulaParallelogram (a = 1; h = 1) : " << *areaParallelogram1 << std::endl;

	 GeometricFormula* areaParallelogram2 = new AreaFormulaParallelogram(1.0f, 5.0f);
	 std::cout << "AreaFormulaParallelogram (a = 1; h = 5) : " << *areaParallelogram2 << std::endl;

	 GeometricFormula* areaTriangle1 = new AreaFormulaTriangle(1.0f, 5.0f);
	 std::cout << "AreaFormulaTriangle (a = 1; h = 5) : " << *areaTriangle1 << std::endl;

	 GeometricFormula* areaTriangle2 = new AreaFormulaTriangle(2.0f, 1.0f);
	 std::cout << "AreaFormulaTriangle (a = 2; h = 1) : " << *areaTriangle2 << std::endl;

	 GeometricFormula* areaCircle1 = new AreaFormulaCircle(1.0f);
	 std::cout << "AreaFormulaCircle (r = 1) : " << *areaCircle1 << std::endl;

	 GeometricFormula* areaCircle2 = new AreaFormulaCircle(5.0f);
	 std::cout << "AreaFormulaCircle (r = 5) : " << *areaCircle2 << std::endl;

	 GeometricFormula* volumePrism1 = new VolumeFormulaPrism(areaParallelogram1, 1.0f);
	 std::cout << "VolumeFormulaPrism (Ba = 1; H = 1) : " << *volumePrism1 << std::endl;

	 GeometricFormula*  volumePrism2 = new VolumeFormulaPrism(areaCircle2, 2.0f);
	 std::cout << "VolumeFormulaPrism (Ba = 78.5; H = 2) : " << *volumePrism2 << std::endl;

	 GeometricFormula* volumePyramid1 = new VolumeFormulaPyramid(areaTriangle1, 2.0f);
	 std::cout << "VolumeFormulaPyramid (Ba = 2.5; H = 2) = " << *volumePyramid1 << std::endl;

	 GeometricFormula* volumePyramid2 = new VolumeFormulaPyramid(areaParallelogram1, 2.0f);
	 std::cout << "VolumeFormulaPyramid (Ba = 1; H = 2) = " << *volumePyramid2 << std::endl;

	 delete areaParallelogram1;
	 delete areaParallelogram2;
	 delete areaTriangle1;
	 delete areaTriangle2;
	 delete areaCircle1;
	 delete areaCircle2;
	 delete volumePrism1;
	 delete volumePrism2;
	 delete volumePyramid1;
	 delete volumePyramid2;


	 std::cout << std::endl << " --------------------- STAGE_3 (3Pts) --------------------- " << std::endl << std::endl;

	 //Parallelogram parallelogram = Parallelogram(1.0f, 5.0f);
	 //std::cout << parallelogram << std::endl;

	 //Rectangle rectangle = Rectangle(3.0f, 5.0f);
	 //std::cout << rectangle << std::endl;

	 //Square square = Square(3.0f);
	 //std::cout  << square << std::endl;

	 //Triangle triangle = Triangle(2.0f, 2.0f);
	 //std::cout << triangle << std::endl;

	 //Circle circle = Circle(2.0f);
	 //std::cout <<  circle << std::endl;

	 //std::cout << std::endl;

	 //Cube cube = Cube(2.0f);
	 //std::cout << cube << std::endl;

	 //Tetrahedron tetrahedron = Tetrahedron(1.0f, 2.0f, 6.0f);
	 //std::cout << tetrahedron << std::endl;

	 //Cone cone = Cone(1.0f, 3.0f);
	 //std::cout << cone << std::endl;


	 std::cout << std::endl << " --------------------- STAGE_4 (0.5Pts) --------------------- " << std::endl << std::endl;

	// FlatGeometricFigure* geometricFigures[] = 
	// {
	//     new Cube(5.15f),
	//     new Circle(3.0f),
	//     new Square(4.0f),
	//     new Cone(3.0f, 1.0f),
	//     new Cone(3.0f, 7.13f),
	//     new Rectangle(1.0f, 4.5f),
	//     new Parallelogram(1.0f, 2.5f),
	//     new Tetrahedron(1.5f, 2.0f, 3.0f),
	//     new Tetrahedron(1.5f, 1.0f, 5.0f),
	// };

	// float volumeValue = GetVolumeSumFromSpatialFigures(geometricFigures, 9);

	// for (int i = 0; i < 9; i++)
	//     std::cout << *geometricFigures[i] << std::endl;

	// std::cout << std::endl << "Sum Of Volumes From Spatial Figures: " << volumeValue << std::endl;

	// for (int i = 0; i < 9; i++)
	//     delete geometricFigures[i];

	return 0;
}
