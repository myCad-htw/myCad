#include "Vector.h"
#include "Point.h"
#include <vector>
#include"PointVectorBase.h"
#include <iostream> 
#include<cmath>

using namespace std;
using namespace Base;


// [DataContract]
Vector Vector::getXDir()
{
	return  Vector(1, 0, 0);
}
Vector Vector::getYDir()
{
	return  Vector(0, 1, 0);
}
Vector Vector::getZDir()
{
	return  Vector(0, 0, 1);
}
// [XmlIgnore]
 //Method aufrufen from Base Class BasClassName::MethodName
double Vector::getLength()
{
	return  BaseLength();
}
double Vector::setLength()
{
	this->MultiplyMeBy( getLength());	
}


// Konstruktur 
//Base = name Kons: name Base class();
Vector::Vector() : Vector(0, 0, 0)
{

}
Vector::Vector(double x, double y, double z) : PointVectorBase(x, y, z)
{

}
Vector::Vector(Point constPoint) : Vector(constPoint.X, constPoint.Y, constPoint.Z)
{

}
Vector::Vector(Point fromPoint, Point toPoint) : Vector(toPoint.X - fromPoint.X, toPoint.Y - fromPoint.Y, toPoint.Z - fromPoint.Z)
{

}
Vector::Vector( const Vector& copyVector) : Vector(copyVector.X, copyVector.Y, copyVector.Z)
{

}

 /// <summary>
/// Addiert Vektoren zu diesem Vektor und gibt das Ergebnis ale neuen 
/// Vektor zurück (this wird nicht verändert)
/// </summary>
/// <param name="vecs"></param>
/// <returns></returns>
Vector Vector::Add(vector<Vector> vecs)
{
	Vector ret(*this) ;
	ret.AddToMe(vecs);
	return ret;
}
/// <summary>
/// Addiert Vektoren zu diesem Vektor (this) und verändert dieses dadurch
/// </summary>
/// <param name="vecs"></param>
void Vector::AddToMe(vector<Vector> vecs)
{   

	vector<PointVectorBase> all_vecs = { vecs.begin(),vecs.end()};
	AddToThis(all_vecs);
}

Point Vector::AsPoint()
{
	return  Point();
}

/// <summary>
/// Gibt Produkt dieses Vektors mit Faktor fac als neuen Vektor zurück
/// </summary>
/// <param name="fac"></param>
/// <returns></returns>
Vector Vector::MultiplyBy(double fac)
{
	Vector ret(*this) ;
	ret.MultiplyMeBy(fac);
	return ret;
}
/// <summary>
/// /// Multipliziert diesen Vektor mit Faktor fac
/// </summary>
/// <param name="fac"></param>
void Vector::MultiplyMeBy(double fac)
{
	MultiplyThisBy(fac);
}
double Vector::DotProduct(Vector v2)
{
	return X* v2.X + Y * v2.Y + Z * v2.Z;
}
Vector Vector::CrossProduct(Vector v2)
{
	return  Vector(Y * v2.Z - Z * v2.Y, Z * v2.X - X * v2.Z, X * v2.Y - Y * v2.X);
}

double Vector::AngleTo(Vector v2, Vector reference)
{
	Vector mm_v1 = this->Normalize();
	Vector mm_v2 = v2.Normalize();

	double cosAlp = mm_v1.DotProduct(mm_v2);
	double alp = acos(cosAlp);
	//senkrechte auf v1
	Vector mm_y = reference.CrossProduct(mm_v1).Normalize();
	double doty = mm_y.DotProduct(mm_v2);
	if (doty < 0)
	{
		return -alp;
	}
	return alp;
}

/// <summary>
/// Gibt (neuen) normalisierten Vektor dieses Objekts zurück
/// </summary>
/// <returns></returns>
Vector Vector::Normalize()
{
	Vector ret(*this) ;
	ret.Length = 1;
	return ret;
}
void Vector::NormalizeMe()
{
	this->Length = 1;
}
/// <summary>
/// Sind zwei Vektoren parallel (collinear) mit spezifizierter Toleranz
/// </summary>
/// <param name="v2">ist dieser Vektor parallel zu this</param>
/// <param name="tolerance">Toleranz</param>
/// <returns></returns>
bool Vector::IsCollinear(Vector v2, double tolerance)
{
	return abs(abs(this->DotProduct(v2)) - Length * v2.Length) <= tolerance;
}
bool Vector::IsCollinear(Vector v2)
{
	return this->IsCollinear(v2, Tolerance);
}
// Überladene Operatoren 
Vector Vector::operator -(Vector v1)
{
	return v1.MultiplyBy(-1);
}
Vector Vector::operator +(Vector v1, Vector v2)
{
	return v1.Add({ v2 });
}
/// <summary>
/// Test ???????????????????????????????????????
/// </summary>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <returns></returns>
/// v1-v2)-v1
Vector Vector::operator -(Vector v1, Vector v2)
{
	v2.MultiplyBy(-1);
	return v1.Add({ v2 });
}	
Vector Vector::operator *(Vector v1, double factor)
{
	return v1.MultiplyBy(factor);
}

Vector Vector::operator *(double factor, Vector v1)
{
	return v1.MultiplyBy(factor);
}


// fehlt noch geerbte Methoden