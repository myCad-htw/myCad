#pragma once
#ifndef __POINT_H__
#define __POINT_H__
#include "Vector.h"
#include <vector>

using namespace std;
using namespace Base;

class Point 
{

public:
	float X;
	float Y;
	float Z;

	static Point Origin;
	Point():Point(0,0,0) {}
	Point(float x, float y, float z = 0) {}
	Point(Vector constVec) : Point(constVec.X(), constVec.Y(), constVec.Z()) {}
	Point(Point& copyPoint) : Point(copyPoint.X, copyPoint.Y, copyPoint.Z) {}

	void MultiplyThisBy(float factor);
	void AddToThis(vector<Vector> vecs);
	float BaseDistanceTo(Point p);
	Point Add(vector<Vector> vecs);
	void AddToMe(vector<Vector> vecs);
	Vector AsVector();
	float DistanceTo(Point Point2);
	

	friend Point operator+ (Point p1, Vector v1);
	friend Point operator- (Point p1, Vector v1);
	friend Point operator- (Point p1, Point p2);
	friend Point operator- (Point p1);
};

#endif

