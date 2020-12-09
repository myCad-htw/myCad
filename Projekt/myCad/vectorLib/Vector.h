#pragma once
#include "PointVectorBase.h"
#include "Point.h"
#include <vector>
using namespace std;
namespace Base
{
    class Vector : public PointVectorBase
    {
    public:
        double Length;
        static Vector XDir;
        static Vector YDir;
        static Vector ZDir;
        // [DataContract]
        static Vector getXDir();
        static Vector getYDir();
        static Vector getZDir();
        // [XmlIgnore]
        double getLength();
        double setLength();

        // Konstruktur 
        //Base = name Kons: name Base class();
        Vector() : Vector(0, 0, 0){}
        Vector(double x, double y, double z) : PointVectorBase(x, y, z) {}
        Vector(Point constPoint) : Vector(constPoint.X, constPoint.Y, constPoint.Z) {}
        Vector(Point fromPoint, Point toPoint) : Vector(toPoint.X - fromPoint.X, toPoint.Y - fromPoint.Y, toPoint.Z - fromPoint.Z) {}
        // Kopierte Kontruktur 
        Vector(const Vector& copyVector) : Vector(copyVector.X, copyVector.Y, copyVector.Z) {}


        // 
        Vector Add(vector<Vector> vecs);

        void AddToMe(vector<Vector> vecs);

        Point AsPoint();

        Vector MultiplyBy(double fac);

        void MultiplyMeBy(double fac);

        double DotProduct(Vector v2);

        Vector CrossProduct(Vector v2);

        double AngleTo(Vector v2, Vector reference);

        Vector Normalize();

        void NormalizeMe();

        bool IsCollinear(Vector v2, double tolerance);

        bool IsCollinear(Vector v2);

        // Überladene Operatoren 
         Vector operator -( Vector  v1);

        static Vector  operator +(Vector v1,  Vector v2);

        static  Vector operator -(Vector v1, Vector v2);

        static   Vector operator *(Vector v1, double factor);

        static  Vector operator *(double factor, Vector v1);


        // fehlt noch geerbte Methoden

    };
}
