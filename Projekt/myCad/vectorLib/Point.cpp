#pragma once
#include "Point.h"
#include <math.h>

using namespace std;
using namespace Base;
using namespace BasePoint;

Point Point::Add(vector<Vector> vecs) {
	Point ret(*this);
	ret.AddToMe(vecs);
	return ret;
}

void Point::AddToThis(vector<Vector> vecs) {
	for (Vector vec : vecs) {
		this->X += vec.X();
		this->Y += vec.Y();
		this->Z += vec.Z();
	}
}
void Point::AddToMe(vector<Vector> vecs) {
	AddToThis(vecs);
}
Vector Point::AsVector() {
	return Vector(this);
}
float Point::DistanceTo(Point point2) {
	return sqrt(pow(point2.X - this->X, 2) + pow(point2.Y - this->Y, 2) + pow(point2.Z - this->Z, 2));
}
float Point::x()
{
	return X;
}
float Point::y()
{
	return Y;
}
float Point::z()
{
	return Z;
}
void Point::MultiplyThisBy(float factor) {
	this->X = this->X * factor;
	this->Y = this->Y * factor;
	this->Z = this->Z * factor;
}
Point operator+ (Point p1, Vector v1) {
	vector<Vector> vecs;
	vecs.push_back(v1);
	return p1.Add(vecs);
}
Point operator- (Point p1, Vector v1) {
	vector<Vector> vecs;
	vecs.push_back(-v1);
	
	return p1.Add(vecs);
}
Point operator- (Point p1, Point p2) {

	return Vector(p1, p2);
}
Point operator- (Point p1) {
	Point ret(p1);
	ret.MultiplyThisBy(-1);
	return ret;
}