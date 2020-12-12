#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Math.h"
#include <ostream>
#include "Point.h"
using namespace std;
namespace Base
{
    class Vector 
    {
    public:
        //******************************************************************
        //* Constructors
        //******************************************************************
        // Default Constructor
        //------------------------------------------------------------------
        // Sets the x, y and z components of this Vector to zero.
        //------------------------------------------------------------------
        Vector();
        //------------------------------------------------------------------
        // Component Constructor
        //------------------------------------------------------------------
        // Sets the x, y and z components of this Vector to corresponding 
        // x, y and z parameters.
        //------------------------------------------------------------------
        Vector(float x, float y, float z);
        //------------------------------------------------------------------
        // Copy Constructor
        //------------------------------------------------------------------
        // Sets the x, y and z components of this Vector to equal the x, y 
        // and z components of Vector v.
        //------------------------------------------------------------------
        Vector(const Vector& v);
        //******************************************************************

        //******************************************************************
        //* Friend Operators
        //******************************************************************
        // Stream Insertion Operator
        //------------------------------------------------------------------
        // Writes the Vector v into the output stream in the format (x,y,z) 
        // so it can be used by various iostream functions.
        //------------------------------------------------------------------
        friend ostream& operator << (std::ostream& os, const Vector& v);
        //------------------------------------------------------------------
        // Equal To Operator
        //------------------------------------------------------------------
        // Compares the x, y and z components of Vector v1 and to the x, y 
        // and z components of Vector v2 and returns true if they are 
        // identical. Otherwise, it returns false.
        //------------------------------------------------------------------
        friend bool operator == (const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // Not Equal To Operator
        //------------------------------------------------------------------
        // Compares the x, y and z components of Vector v1 and to the x, y 
        // and z components of Vector v2 and returns true if they are not 
        // identical. Otherwise, it returns false.
        //------------------------------------------------------------------
        friend bool operator != (const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // Addition Operator
        //------------------------------------------------------------------
        // Adds the x, y and z components of Vector v1 to the x, y and z 
        // compenents of Vector v2 and returns the result.
        //------------------------------------------------------------------
        friend Vector operator + (const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // Subtraction Operator
        //------------------------------------------------------------------
        // Subtracts the x, y and z components of Vector v2 to the x, y and 
        // z compenents of Vector v1 and returns the result.
        //------------------------------------------------------------------
        friend Vector operator - (const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // Multiplication Operator
        //------------------------------------------------------------------
        // Multiplies the x, y and z components of Vector v with a scalar 
        // value and returns the result.
        //------------------------------------------------------------------
        friend Vector operator * (const Vector& v, float scalar);
        friend Vector operator * (float scalar, const Vector& v);
        //------------------------------------------------------------------
        // Division Operator
        //------------------------------------------------------------------
        // Divides the x, y and z components of Vector v with a scalar 
        // value and returns the result.
        //------------------------------------------------------------------
        friend Vector operator / (const Vector& v, float scalar);
        friend Vector operator / (float scalar, const Vector& v);
        //******************************************************************

        //******************************************************************
        //* Friend Functions
        //******************************************************************
        // DotProduct
        //------------------------------------------------------------------
        // Computes the dot product between Vector v1 and Vector v2 and 
        // returns the result.
        //------------------------------------------------------------------
        friend float DotProduct(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // CrossProduct
        //------------------------------------------------------------------
        // Computes the cross product between Vector v1 and Vector v2 and 
        // returns the result.
        //------------------------------------------------------------------
        friend Vector CrossProduct(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // Lerp
        //------------------------------------------------------------------
        // Returns a linear interpolation between Vector v1 and Vector v2 
        // for paramater t, in the closed interval [0, 1].
        //------------------------------------------------------------------
        friend Vector Lerp(const Vector& v1, const Vector& v2, float t);
        //------------------------------------------------------------------
        // Clamp - TODO: make this a method instead?
        //------------------------------------------------------------------
        // Clamps this Vector's x, y and z components to lie within min and 
        // max.
        //------------------------------------------------------------------
        friend Vector Clamp(const Vector& v1, float min, float max);
        //------------------------------------------------------------------
        // Min
        //------------------------------------------------------------------
        // Returns a Vector whos x, y and z components are the minimum 
        // components found in Vector v1 and Vector v2.
        //------------------------------------------------------------------
        friend Vector Min(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // Max
        //------------------------------------------------------------------
        // Returns a Vector whos x, y and z components are the maximum 
        // components found in Vector v1 and Vector v2.
        //------------------------------------------------------------------
        friend Vector Max(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // DistanceBetween
        //------------------------------------------------------------------
        // Returns the scalar distance between the Vector v1 and the Vector 
        // v2.
        //------------------------------------------------------------------
        friend float DistanceBetween(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // DistanceBetweenSquared
        //------------------------------------------------------------------
        // Returns the scalar squared distance between the Vector v1 and 
        // the Vector v2.
        //------------------------------------------------------------------
        friend float DistanceBetweenSquared(const Vector& v1, const Vector& v2);
        //******************************************************************

        //******************************************************************
        //* Operators
        //******************************************************************
        // Copy Assignment Operator
        //------------------------------------------------------------------
        // Assigns this Vector's components to be equal to Vector v's 
        // components.
        //------------------------------------------------------------------
        Vector& operator = (const Vector& v);
        //------------------------------------------------------------------
        // Addition Assignment Operator
        //------------------------------------------------------------------
        // Adds to this Vector's components the components of Vector v.
        //------------------------------------------------------------------
        Vector& operator += (const Vector& v);
        //------------------------------------------------------------------
        // Subtraction Assignment Operator
        //------------------------------------------------------------------
        // Subtract from this Vector's components the components of Vector 
        // v.
        //------------------------------------------------------------------
        Vector& operator -= (const Vector& v);
        //------------------------------------------------------------------
        // Multiplication Assignment Operator
        //------------------------------------------------------------------
        // Multiply this Vector's components by a scalar value.
        //------------------------------------------------------------------
        Vector& operator *= (float scalar);
        //------------------------------------------------------------------
        // Division Assignment Operator
        //------------------------------------------------------------------
        // Divide this Vector's components by a scalar value.
        //------------------------------------------------------------------
        Vector& operator /= (float scalar);
        //------------------------------------------------------------------
        // Unary Minus Operator
        //------------------------------------------------------------------
        // Negate the components of this Vector.
        //------------------------------------------------------------------
        Vector& operator - ();
        //------------------------------------------------------------------
        // Array Subscript Operator
        //------------------------------------------------------------------
        // Allows access to the x, y and z components through an array 
        // subscript notation.
        //------------------------------------------------------------------
        float& operator [] (int i);
        //******************************************************************

        //******************************************************************
        //* Methods
        //******************************************************************
        // X
        //------------------------------------------------------------------
        // Returns the x component of this Vector.
        //------------------------------------------------------------------
        float X();
        //------------------------------------------------------------------
        // Y
        //------------------------------------------------------------------
        // Returns the y component of this Vector.
        //------------------------------------------------------------------
        float Y();
        //------------------------------------------------------------------
        // Z
        //------------------------------------------------------------------
        // Returns the z component of this Vector.
        //------------------------------------------------------------------
        float Z();
        //------------------------------------------------------------------
        // Set
        //------------------------------------------------------------------
        // Sets the x, y and z components of this Vector to the paramaters 
        // of this function.
        //------------------------------------------------------------------
        void Set(float x, float y, float z);
        //------------------------------------------------------------------
        // MakeZero
        //------------------------------------------------------------------
        // Sets the x, y and z components of this Vector to zero.
        //------------------------------------------------------------------
        void MakeZero();
        //------------------------------------------------------------------
        // IsZero
        //------------------------------------------------------------------
        // Returns true if the x, y and z components of this Vector are 
        // equal to zero.
        //------------------------------------------------------------------
        bool IsZero();
        //------------------------------------------------------------------
        // LengthSquared
        //------------------------------------------------------------------
        // Returns the magnitude of the x, y and z components squared.
        //------------------------------------------------------------------
        float LengthSquared();
        //------------------------------------------------------------------
        // Length
        //------------------------------------------------------------------
        // Returns the magnitude of the x, y and z components.
        //------------------------------------------------------------------
        float Length();
        //------------------------------------------------------------------
        // Normalize
        //------------------------------------------------------------------
        // Sets the components of this Vector in such a way that their 
        // magnitude is equal to one.
        //------------------------------------------------------------------
        void Normalize();
        //------------------------------------------------------------------
        // IsNormalized
        //------------------------------------------------------------------
        // Compares the magnitude of this Vector to one.
        //------------------------------------------------------------------
        bool IsNormalized();
        //******************************************************************

    private:
        //******************************************************************
        //* Private Member Variables
        //******************************************************************
        // x
        //------------------------------------------------------------------
        // The x component of this Vector.
        //------------------------------------------------------------------
        double x;
        //------------------------------------------------------------------
        // y
        //------------------------------------------------------------------
        // The y component of this Vector.
        //------------------------------------------------------------------
        double y;
        //------------------------------------------------------------------
        // z
        //------------------------------------------------------------------
        // The z component of this Vector.
        //------------------------------------------------------------------
        double z;
        //******************************************************************

    };
}
#endif
