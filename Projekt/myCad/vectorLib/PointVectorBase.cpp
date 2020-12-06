#include "PointVectorBase.h"
#include <cmath>
#include "Object.h"
#include <typeinfo>


double PointVectorBase::BaseLength() {
	return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
};

double PointVectorBase::BaseDistanceTo(PointVectorBase pvb) {
	return sqrt(pow(pvb.X - X, 2) + pow(pvb.Y - Y, 2) + pow(pvb.Z - Z, 2));
};

void PointVectorBase::AddToThis(vector<PointVectorBase>pvbs) {
	
    for (PointVectorBase pvb : pvbs) {
        X += pvb.X;
        Y += pvb.Y;
        Z += pvb.Z;
    }
};

void PointVectorBase::MultiplyThisBy(double factor) {
    X = X * factor;
    Y = Y * factor;
    Z = Z * factor;
};

//bool PointVectorBase::operator ==(PointVectorBase& p1, PointVectorBase& p2) {
//    if (p1 == NULL &&  p2 == NULL)
//    {
//        return true;
//    }
//    if (p1 != nullptr && p2 != nullptr)
//    {
//        //Wenn Typen nicht gleich, immer false...
//        if (typeid(p1).name() != typeid(p2).name()) {
//            return false;
//        }
//        //Vergleich mit Toleranz in Würfel
//        if (abs(p1->X - p2->X) > Tolerance) {
//            return false;
//        }
//        if (abs(p1->Y - p2->Y) > Tolerance) {
//            return false;
//        }
//        if (abs(p1->Z - p2->Z) > Tolerance) {
//            return false;
//        }
//        return true;
//        //oder Vergleich mit Toleranz in Kugel
//        //return p1.BaseDistanceTo(p2) <= Tolerance;
//    }
//    return false;
//}

//bool PointVectorBase::operator !=(PointVectorBase p1, PointVectorBase p2) {
//};
