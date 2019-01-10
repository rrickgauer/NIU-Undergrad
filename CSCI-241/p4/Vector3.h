/*********************************************************************
 PROGRAM:       CSCI 241 Assignment 4
 PROGRAMMER:    Ryan Rickgauer
 LOGON ID:      z-1729300
 DUE DATE:      3/8/2018
 
 FUNCTION:      This program tests the functionality of the Vector3
                class.
 *********************************************************************/
#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
using namespace std;

class Vector3
{
    friend ostream& operator << (ostream& lhs, const Vector3& rhs);         /*  Outstream operator overloader       */
    friend Vector3  operator +  (const Vector3& lhs, const Vector3& rhs);   /*  Addition operator overloader        */
    friend Vector3  operator -  (const Vector3& lhs, const Vector3& rhs);   /*  Subtraction operator overloader     */
    friend Vector3  operator *  (const Vector3& lhs, const double& rhs);    /*  Multiplication operator overloader  */
    friend Vector3  operator *  (const double& lhs, const Vector3& rhs);    /*  Multiplication operator overloader  */
    friend double   operator *  (const Vector3& lhs, const Vector3& rhs);   /*  Multiplication operator overloader  */
    friend bool     operator == (const Vector3& lhs, const Vector3& rhs);   /*  Equality operator overloader        */
    
private:
    double coord[3];                                                        /*  Data member array of doubles        */
    
public:
    Vector3(double x = 0.0, double y = 0.0, double z = 0.0);                /*  Constructor                         */
    double  operator [] (int index) const;                                  /*  Subscript operator overloader       */
    double& operator [] (int index);                                        /*  Subscript operator overloader       */
};

#endif
