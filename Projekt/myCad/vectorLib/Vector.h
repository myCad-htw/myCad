#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Math.h"
#include <ostream>
#include "Point.h"
#include<vector>
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
        Vector(Point constPoint) : Vector(constPoint.X, constPoint.Y, constPoint.Z) {}
        Vector(Point fromPoint, Point toPoint) : Vector(toPoint.X - fromPoint.X, toPoint.Y - fromPoint.Y, toPoint.Z - fromPoint.Z) {}





        //******************************************************************
        //* Friend Operators
        //******************************************************************
        // AreEqual
        //------------------------------------------------------------------
         // Compares the value of two parameters  and returns true if they are 
        // identical. Otherwise, it returns false.
        //------------------------------------------------------------------
        friend bool AreEqual(float n1, float n2);
        //------------------------------------------------------------------
        // EqualsZero
       //------------------------------------------------------------------
        // Returns true if the value of this parameter is 
        // equal to zero.
       //------------------------------------------------------------------
        friend bool EqualsZero(float v1);
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
        //* Functions
        //******************************************************************
        // DotProduct
        //------------------------------------------------------------------
        // Computes the dot product between Vector v1 and Vector v2 and 
        // returns the result.
        //------------------------------------------------------------------
    public:
        float DotProduct(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // CrossProduct
        //------------------------------------------------------------------
        // Computes the cross product between Vector v1 and Vector v2 and 
        // returns the result.
        //------------------------------------------------------------------
        Vector CrossProduct(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // DistanceBetween
        //------------------------------------------------------------------
        // Returns the scalar distance between the Vector v1 and the Vector 
        // v2.
        //------------------------------------------------------------------
        float DistanceBetween(const Vector& v1, const Vector& v2);
        //------------------------------------------------------------------
        // DistanceBetweenSquared
        //------------------------------------------------------------------
        // Returns the scalar squared distance between the Vector v1 and 
        // the Vector v2.
        //------------------------------------------------------------------
         float DistanceBetweenSquared(const Vector& v1, const Vector& v2);
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
        Vector Normalize();
        //------------------------------------------------------------------
        // IsNormalized
        //------------------------------------------------------------------
        // Compares the magnitude of this Vector to one.
        //------------------------------------------------------------------
        bool IsNormalized();
        //------------------------------------------------------------------
        // AddToThis
        //------------------------------------------------------------------
        // Adds vectors to this vector this and thereby changes it
        //------------------------------------------------------------------
        void AddToThis(vector<Vector>pvbs);
        // Add
        //------------------------------------------------------------------
        // Adds vectors to this vector and gives the result all new
        //------------------------------------------------------------------
        Vector Add(vector<Vector>pvbs);

        double AngleTo(Vector v2, Vector reference);

        // Test ?????????????
        bool IsCollinear(Vector v2, float tolerance);
        //******************************************************************

    public:
        //******************************************************************
        //* public Member Variables
        //******************************************************************
        // x
        //------------------------------------------------------------------
        // The x component of this Vector.
        //------------------------------------------------------------------
        float x;
        //------------------------------------------------------------------
        // y
        //------------------------------------------------------------------
        // The y component of this Vector.
        //------------------------------------------------------------------
        float y;
        //------------------------------------------------------------------
        // z
        //------------------------------------------------------------------
        // The z component of this Vector.
        //------------------------------------------------------------------
        float z;
        //******************************************************************

    };
}
#endif
