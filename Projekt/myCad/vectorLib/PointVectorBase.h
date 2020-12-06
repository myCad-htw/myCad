#pragma once
// Abstract Class
#include <vector>
#include <string>
#include <ostream>
#include "Object.h"

using namespace std;

namespace Base
{
	class PointVectorBase : public Object
	{
	public:
		double X;
		double Y;
		double Z;
		static double Tolerance;

		PointVectorBase() :PointVectorBase(0, 0, 0) {

		}
		PointVectorBase(double x, double y, double z)
		{
			this->X = x;
			this->Y = y;
			this->Z = z;
		};
		//overload Operators
		static bool operator ==(PointVectorBase& p1, PointVectorBase& p2);
		static bool operator !=(PointVectorBase p1, PointVectorBase p2);


		operator string() const;
		bool Equals(Object obj);
		int GetHashCode();

		virtual ~PointVectorBase() {};
	protected:

		double BaseLength();

		double BaseDistanceTo(PointVectorBase pvb);

		void AddToThis(vector<PointVectorBase>pvbs);

		void MultiplyThisBy(double factor);


	};
}

