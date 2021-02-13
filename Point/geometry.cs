using System;
using System.Numerics;

namespace lab06
{
    static class Geometry
    {
        public static double Distance(in Point2D a, in Point2D b)
        {
            return Math.Sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
        }

        public static double PolygonCircuit(params Point2D[] a)
        {
            if (a.Length < 3)
            {
                return -1.0;
            }
            double sum = 0;
            for (int i = 0; i < a.Length - 1; i++)
            {
                sum += Distance(a[i], a[i + 1]);
            }
            sum += Distance(a[0], a[^1]);
            return sum;
        }
    }

    abstract class Shape
    {
        public abstract double Circuit(params Point2D[] a);
    }

    abstract class Polygon : Shape
    {
        public Point2D[] points;

        protected Polygon(params Point2D[] a)
        {
            points = a;
        }

        public override double Circuit(params Point2D[] a)
        {
            return Geometry.PolygonCircuit(a);
        }
    }

    class Rectangle : Polygon
    {
        public double diagonal;


        public Rectangle(Point2D left_bottom, double a, double b)
        {
            points = new Point2D[4];
            points[0] = left_bottom;
            points[1] = new Point2D(left_bottom.x, left_bottom.y + b);
            points[2] = new Point2D(left_bottom.x + a, left_bottom.y + b);
            points[3] = new Point2D(left_bottom.x + a, left_bottom.y);
            diagonal = Math.Sqrt((a * a) + (b * b));
        }

        public Rectangle(Point2D left_bottom, double a) : base(left_bottom)
        {
            points = new Point2D[4];
            points[0] = left_bottom;
            points[1] = new Point2D(left_bottom.x, left_bottom.y + a);
            points[2] = new Point2D(left_bottom.x + a, left_bottom.y + a);
            points[3] = new Point2D(left_bottom.x + a, left_bottom.y);
            diagonal = Math.Sqrt((a * a) + (a * a));
        }

    }

    class Circle : Shape
    {
        public double radius;
        public Point2D center;

        public override double Circuit(params Point2D[] a)
        {
            return Geometry.PolygonCircuit(a);
        }


        public Circle(Point2D center, double a)
        {
            this.center = center;
            radius = a;
        }
    }

}