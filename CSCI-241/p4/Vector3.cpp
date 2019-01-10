/*********************************************************************
 PROGRAM:       CSCI 241 Assignment 4
 PROGRAMMER:    Ryan Rickgauer
 LOGON ID:      z-1729300
 DUE DATE:      3/8/2018
 
 FUNCTION:      This program tests the functionality of the Vector3
                class.
 *********************************************************************/

#include "Vector3.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************
 
 FUNCTION:  Vector3::Vector3(double x, double y, double z)
 
 ARGUMENTS: x - integer representing the x-coordinate in a vector
            y - integer representing the y-coordinate in a vector
            z - integer representing the z-coordinate in a vector
 
 RETURNS:   N/A.
 
 NOTES:     Default constructor; intializes the coord data member
            to the 3 integers passed in. If no values are passed
            in when an instance is created, then the 3 values are
            assigned a value of 0.0
 
 **************************************************************/
Vector3::Vector3(double x, double y, double z)
{
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
}

/**************************************************************
 
 FUNCTION:  ostream& operator<<(ostream &lhs, const Vector3 &rhs)
 
 ARGUMENTS: lhs - output stream object to write to.
            rhs  - Vector3 object to insert into the output
            stream.
 
 RETURNS:   The updated output stream object.
 
 NOTES:     Inserts the Vector3 object into the output stream.
 
 **************************************************************/
ostream& operator<<(ostream& lhs, const Vector3& rhs)
{
    lhs << "(" << rhs.coord[0] << ", " << rhs.coord[1] << ", " << rhs.coord[2] << ")" << endl;
    
    return lhs;
}

/**************************************************************
 
 FUNCTION:  Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
 
 ARGUMENTS: lhs - a Vector3 object operand.
            rhs - a Vector3 object operand.
 
 RETURNS:   The sum of the two operands.
 
 NOTES:     Adds two Vector3 objects and returns the result.
 
 **************************************************************/
Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    double resultx = lhs.coord[0] + rhs.coord[0];           /*  calculates sum of both x coordinates            */
    double resulty = lhs.coord[1] + rhs.coord[1];           /*  calculates sum of both y coordinates            */
    double resultz = lhs.coord[2] + rhs.coord[2];           /*  calculates sum of both z coordinates            */
    
    Vector3 result = Vector3(resultx, resulty, resultz);    /*  creates a new Vector3 object with the
                                                                sum of each coordinate                          */
    return result;
}

/**************************************************************
 
 FUNCTION:  Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
 
 ARGUMENTS: lhs - a Vector3 object operand.
            rhs - a Vector3 object operand.
 
 RETURNS:   The difference of the two operands.
 
 NOTES:     Subtracts a Vector3 object fron another and returns
            the result.
 
 **************************************************************/
Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
    double resultx = lhs.coord[0] - rhs.coord[0];           /*  calculates difference of both x coordinates    */
    double resulty = lhs.coord[1] - rhs.coord[1];           /*  calculates difference of both y coordinates    */
    double resultz = lhs.coord[2] - rhs.coord[2];           /*  calculates difference of both z coordinates    */
    
    Vector3 result = Vector3(resultx, resulty, resultz);    /*  creates a new Vector3 object with the
                                                                difference of each coordinate                  */
    return result;
}

/**************************************************************
 
 FUNCTION:  Vector3 operator*(const Vector3& lhs, const double& rhs)
 
 ARGUMENTS: lhs - a Vector3 object operand.
            rhs - a double operand.
 
 RETURNS:   The product of the int and the object operand.
 
 NOTES:     Mulitplies a double and a Vector3 object and returns
            the result.
 
 **************************************************************/
Vector3 operator*(const Vector3& lhs, const double& rhs)
{
    double productx = lhs.coord[0] * rhs;                       /*  calculates product of the x coordinate and the double   */
    double producty = lhs.coord[1] * rhs;                       /*  calculates product of the x coordinate and the double   */
    double productz = lhs.coord[2] * rhs;                       /*  calculates product of the x coordinate and the double   */
    
    Vector3 result = Vector3(productx, producty, productz);     /*  creates a new Vector3 object with the
                                                                    products of the coordinate and the double               */
    return result;
}


/**************************************************************
 
 FUNCTION:  Vector3 operator*(const double& lhs, const Vector3& rhs)
 
 ARGUMENTS: rhs - a Vector3 object operand.
            lhs - a double operand.
 
 RETURNS:   The product of the int and the object operand.
 
 NOTES:     Mulitplies a double and a Vector3 object and returns
            the result.
 
 **************************************************************/
Vector3 operator*(const double& lhs, const Vector3& rhs)
{
    double productx = rhs.coord[0] * lhs;                       /*  calculates product of the x coordinate and the double   */
    double producty = rhs.coord[1] * lhs;                       /*  calculates product of the x coordinate and the double   */
    double productz = rhs.coord[2] * lhs;                       /*  calculates product of the x coordinate and the double   */
    
    Vector3 result = Vector3(productx, producty, productz);     /*  creates a new Vector3 object with the
                                                                    products of the coordinate and the double               */
    return result;
}

/**************************************************************
 
 FUNCTION:  double operator*(const Vector3& lhs, const Vector3& rhs)
 
 ARGUMENTS: lhs - a Vector3 object operand.
            rhs - a Vector3 object operand.
 
 RETURNS:   The scalar product of the two operands.
 
 NOTES:     Multiplies two Rational objects and returns the scalar
            product.
 
 **************************************************************/
double operator*(const Vector3& lhs, const Vector3& rhs)
{
    double productx = lhs.coord[0] * rhs.coord[0];              /*  calculates product of the x coordinates                 */
    double producty = lhs.coord[1] * rhs.coord[1];              /*  calculates product of the y coordinates                 */
    double productz = lhs.coord[2] * rhs.coord[2];              /*  calculates product of the z coordinates                 */
    
    double result = productx + producty + productz;             /* calculates the sum of the 3 products                     */
    
    return result;
}

/**************************************************************
 
 FUNCTION:  double Vector3::operator[] (int index) const
 
 ARGUMENTS: index - an integer representing the index of the
            coord array subscript
 
 RETURNS:   the value located in the coord array at the desired
            subscript location.
 
 NOTES:     Returns a double that located in the desired coord
            array at the index.
 
 **************************************************************/
double Vector3::operator[] (int index) const
{
    return coord[index];
}

/**************************************************************
 
 FUNCTION:  double& Vector3::operator[] (int index)
 
 ARGUMENTS: index - an integer representing the index of the
            coord array subscript
 
 RETURNS:   the double located in the coord array
 
 NOTES:     Can change the value of the coord located in the
            subscript position represented by the index value
            passed in.
 
 **************************************************************/
double& Vector3::operator[] (int index)
{
    return coord[index];
}

/**************************************************************
 
 FUNCTION:  bool operator==(const Vector3& lhs, const Vector3& rhs)
 
 ARGUMENTS: lhs - a Vector3 object operand.
            rhs - a Vector3 object operand.
 
 RETURNS:   true if the operands are equal, otherwise false.
 
 NOTES:     Compares two Vector3 objects.
 
 **************************************************************/
bool operator==(const Vector3& lhs, const Vector3& rhs)
{
    int count;                                          /* Counter variable     */
    
    /*  Uses a for loop to loop through all three coordinates.
        If any of the coordinates are not equal to eachother then
        the function returns false. If the loop executes 3 times
        without a failure, then the function returns true.                      */
    for(count = 0; count < 3; count++)
        if (lhs.coord[count] != rhs.coord[count])
            return false;
    
    return true;
}
