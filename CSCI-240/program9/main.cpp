/***************************************************************
 CSCI 240         Program 9           Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 12/1/17
 
 Purpose: This program will design and use a class that can be
 used to represent a parabola.
 ***************************************************************/

class Parabola
{
private:
    double aCoef, bCoef, cCoef; //3 data members
    
public:
    Parabola(double, double, double); //constructor method
    double calcDiscrim();
    int calcRoots(double&, double&);
    double calcX();
    double calcY();
    void printEquation();
    void printVertex();
    void printRoots();
    void printConcavity();
    void print();
};

#include <iostream>
#include <iomanip>
#include <cstdlib> //Random number generator
#include <ctime> //ctime random number
#include <cmath> //math class

using namespace std;

int main(int argc, const char * argv[]) {
    
    Parabola p1 = Parabola(1, 4, -5);
    Parabola p2 = Parabola(0, 0, 25);
    Parabola p3 = Parabola(-1, 2, -1);
    Parabola p4 = Parabola(-12, -2, 3);
    Parabola p5 = Parabola(12, 2, 3);
    
    cout << "*** The first parabola ***" << endl << endl;
    p1.print();
    cout << endl << endl;
    
    cout << "*** The second parabola ***" << endl << endl;
    p2.print();
    cout << endl << endl;
    
    cout << "*** The third parabola ***" << endl << endl;
    p3.printEquation();
    p3.printConcavity();
    cout << endl << endl;
    
    cout << "*** The fourth parabola ***" << endl << endl;
    p4.printRoots();
    cout << endl << endl;
    
    cout << "*** The fifth parabola ***" << endl << endl;
    p5.printEquation();
    p5.printVertex();
   
    cout << endl;
    
    return 0;
}

/*********************************************************
 Constructor:
 The constructor takes 3 arguments: a double that holds
 the initial value for the a-coefficient, a double that
 holds the initial value for the b-coefficient, and a
 double that holds the initial value for the c-coefficient.
 *********************************************************/

Parabola::Parabola(double aVal, double bVal, double cVal)
{
    
    //If value passed in for aVal is 0, then aCeof gets assigned a value of 1
    //If value passed in for aVal is a nonzero, then that gets assigned to aCoef
    if (aVal == 0)
       aCoef = 1;
    else
        aCoef = aVal;
    
    bCoef = bVal;
    cCoef = cVal;
}

/*********************************************************
 double calcDiscrim()
 This method calculates and returns the value of the
 discriminant. It takes no arguments and returns a
 double: the calculated discriminant.
 *********************************************************/
double Parabola::calcDiscrim()
{
    double discriminant = (bCoef * bCoef) - (4 * aCoef * cCoef);
    
    return discriminant;
}

/*********************************************************
 int calcRoots()
 This method calculates and passes back the roots for the
 parabola, if they exist, and returns the number of roots.
 It takes two arguments: a reference to a double to pass
 back the first root and a reference to a double to pass
 back the second root. It returns an integer: the number
 of roots.
 *********************************************************/
int Parabola::calcRoots(double &root1, double &root2)
{
    int roots;
    
    double discriminant = calcDiscrim();
    
    if (discriminant > 0)
    {
        root1 = (-bCoef + sqrt(discriminant)) / (2 * aCoef);
        root2 = (-bCoef - sqrt(discriminant)) / (2 * aCoef);
        
        roots = 2;
    }
    
    else if(discriminant == 0)
    {
        root1 = (-bCoef + sqrt(discriminant)) / (2 * aCoef);
        
        roots = 1;
    }
    
    else
        roots = 0;
    
    return roots;
}

/*********************************************************
 double calcX()
 This method calculates and returns the x-coordinate of
 the vertex of the parabola. It takes no arguments and
 returns a double: the calculated x-coordinate.
 *********************************************************/
double Parabola::calcX()
{
    double x = -bCoef / (2 * aCoef);
    
    return x;
}


/*********************************************************
 double calcY()
 This method calculates and returns the y-coordinate of
 the vertex of the parabola. It takes no arguments and
 returns a double: the calculated y-coordinate.
 *********************************************************/
double Parabola::calcY()
{
    double x = calcX();
    double y = (aCoef * (x * x)) + (bCoef * x) + cCoef;
    
    return y;
}

/*********************************************************
 void printEquation()
 This method displays the parabola in the form of a
 quadratic equation. It takes no arguments and returns
 nothing.
 *********************************************************/
void Parabola::printEquation()
{
    cout << fixed << setprecision(1);
    cout << aCoef << "x^2 + " << bCoef << "x + " << cCoef << endl;
}


/*********************************************************
 void printVertex()
 This method displays the x and y-coordinates of the
 vertex of the parabola. It takes no arguments and returns
 nothing.
 *********************************************************/
void Parabola::printVertex()
{
    double x, y;
    x = calcX();
    y = calcY();
    
    cout << "\t";
    
    cout << fixed << setprecision(3);
    cout << "Vertex Coordinates: (" << x << ", " << y << ")" << endl;
}


/*********************************************************
 void printRoots()
 This method displays the roots of the parabola (if they
 exist). It takes no arguments and returns nothing.
 *********************************************************/
void Parabola::printRoots()
{
    double root1Val, root2Val;
    
    int roots = calcRoots(root1Val, root2Val);
    
    cout << "\t";
    
    if (roots == 0)
        cout << "There are NO real roots." << endl;
    else if(roots == 1)
        cout << fixed << setprecision(3) << "There is one real root with X-Coordinate " << root1Val << endl;
    else if(roots == 2)
        cout << fixed << setprecision(3) << "There are two real roots with X-Coordinates " << root1Val << " and " << root2Val << endl;
}

/*********************************************************
 void printConcavity()
 This method displays the direction that the parabola
 opens. It takes no arguments and returns nothing.
 *********************************************************/
void Parabola::printConcavity()
{
    cout << "\t";
    
    if (aCoef > 0)
        cout << "The parabola opens UPWARD." << endl;
    else
        cout << "The parabola opens DOWNWARD." << endl;
}

/*********************************************************
 void print()
 This method displays everything related to the parabola.
 It takes no arguments and returns nothing.
 *********************************************************/
void Parabola::print()
{
    printEquation();
    printVertex();
    printConcavity();
    printRoots();
}
