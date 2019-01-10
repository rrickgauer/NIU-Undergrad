/***************************************************************
 CSCI 240         Program 10           Fall 2017
 
 Programmer: Ryan Rickgauer
 
 Section: 1
 
 Date Due: 12/8/17
 
 Purpose: This program will implement and use the methods for a
 class called Seller that represents information about a
 salesperson.
 ***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib> //Random number generator
#include <ctime> //ctime random number
#include <cmath> //math class

using namespace std;


class Seller
{
public:
    Seller(); //constructor method 1
    Seller( const char [], const char[], const char [], double ); //constructor method 2
    
    void print(); //method 1
    
    void setFirstName( const char [] ); //method 2
    void setLastName( const char [] ); //method 3
    void setID( const char [] ); //method 4
    void setSalesTotal(double); //method 5
    
    double getSalesTotal(); //method 6
    
private:
    char firstName[20];
    char lastName[30];
    char ID[7];
    double salesTotal;
};

void space(int); //function that prints desired lines of spaces. Not required in the program assignment


int main(int argc, const char * argv[]) {
    
    Seller seller1 = Seller("Ryan", "Rickgauer", "CSI240", 1234.56); //object 1
    Seller seller2 = Seller(); //object 2
    Seller seller3 = Seller("", "Johnson", "TOOBIG999", 876.34); //object 3
    Seller seller4 = Seller("James", "Hellwig", "ULTWAR", 13579.11); //object 4
    Seller seller5 = Seller("Roderick", "Toombs", "PIPER4", 24680.24); //object 5
    
    //first seller display
    cout << "*** The first Seller object ***" << endl;
    seller1.print();
    space(3);
    
    //second seller display
    cout << "*** The second Seller object ***" << endl;
    seller2.print();
    seller2.setFirstName("Terry");
    seller2.setLastName("Bollea");
    seller2.setID("HULK96");
    seller2.setSalesTotal(246.80);
    seller2.print();
    space(3);
    
    //third seller display
    cout << "*** The third Seller object ***" << endl;
    seller3.print();
    seller3.setFirstName("Dwayne");
    seller3.setID("ROCK89");
    seller3.print();
    space(3);
    
    //fourth seller display
    cout << "*** The fourth Seller object ***" << endl;
    cout << "Sales total is $" << fixed << setprecision(2) << seller4.getSalesTotal() << endl;
    space(3);
    
    //fifth seller display
    cout << "*** The fifth Seller object ***" << endl;
    seller5.print();
    seller5.setFirstName("");
    seller5.setLastName("");
    seller5.setID("");
    seller5.setSalesTotal(-19.88);
    seller5.print();
    space(3);

    
    return 0;
}

/*********************************************************
 Constructor1 Seller
 
 The default constructor takes no arguments and returns
 nothing. It calls the various set methods to initialize
 the first and last names to "None", the seller ID to
 "ZZZ000", and the sales total to 0.
 *********************************************************/
Seller::Seller()
{
    setFirstName("None");
    setLastName("None");
    setID("ZZZ000");
    setSalesTotal(0);

}

/*********************************************************
 Constructor2 Seller
 
 The second constructor takes 4 arguments: a character
 array with a Seller's first name, a character array with
 a Seller's last name, a character array with a Seller's
 id number, and a double that holds the Seller's sales
 total. It returns nothing. It calls the various set
 methods to initialize the first and last names to "None",
 the seller ID to "ZZZ000", and the sales total to 0.
 *********************************************************/
Seller::Seller( const char fName[], const char lName[], const char idValue[], double sales)
{
    setFirstName(fName);
    setLastName(lName);
    setID(idValue);
    setSalesTotal(sales);
}

/*********************************************************
 void setFirstName(const char [])
 
 This method changes a Seller's first name. It takes one
 argument: an array of characters that represents the
 Seller's first name. It returns nothing.
 *********************************************************/
void Seller::setFirstName(const char fName[])
{
    //If the length of fName is greater than 0, it initializes the firstName data member.
    //Otherwise, the firstName is set to "None".
    if (strlen(fName) > 0)
        strcpy(firstName, fName);
    else
        strcpy(firstName, "None");

}


/*********************************************************
 void setLastName(const char [])
 
 This method changes a Seller's last name. It takes one
 argument: an array of characters that represents the
 Seller's last name. It returns nothing.
 *********************************************************/
void Seller::setLastName(const char lName[])
{
    //If the length of lName is greater than 0, it initializes the lastName data member.
    //Otherwise, the lastName is set to "None".
    if (strlen(lName) > 0)
        strcpy(lastName, lName);
    else
        strcpy(lastName, "None");
}


/*********************************************************
 void setID(const char [])
 
 This method changes a Seller's id number. It takes one
 argument: an array of characters that represents the
 Seller's id number. It returns nothing.
 *********************************************************/
void Seller::setID(const char idValue[])
{
    
    //If the length of newID is greater than 0 and less than 7, it initializes the ID data member.
    //Otherwise, the ID data member is set to "ZZZ000".
    if (strlen(idValue) > 0 && strlen(idValue) < 7)
        strcpy(ID, idValue);
    else
        strcpy(ID, "ZZZ000");
}

/*********************************************************
 void setSalesTotal(double)
 
 This method changes a Seller's sales total. It takes one
 argument: a double that represents the Seller's sales
 total. It returns nothing.
 *********************************************************/
void Seller::setSalesTotal(double sales)
{
    //If the passed in sales is greater than or equal to 0, it is used to initialize the salesTotal data member.
    //Otherwise, the salesTotal data member is set to 0.
    if (sales >= 0)
        salesTotal = sales;
    else
        salesTotal = 0;
}

/*********************************************************
 double getSalesTotal()
 
 This method returns a Seller's sales total data member.
 It takes no arguments.
 *********************************************************/
double Seller::getSalesTotal()
{
    return salesTotal;
}

/*********************************************************
 void print()
 
 This method displays the Seller information. It takes no
 arguments and returns nothing.
 *********************************************************/
void Seller::print()
{
    int space = 50;
    space = space - strlen(firstName);
    space = space - strlen(lastName);
    
    cout << lastName << ", " << firstName << setw(space) << ID << setw(10) << "$" << fixed << setprecision(2) << salesTotal << endl;
}



/*********************************************************
 void space(int)
 
 This function takes one argument: an int value. It returns
 nothing. This function prints a desired number of line
 spaces.
 
 This function was for my own personal use and was not
 required in the assignment.
 *********************************************************/
void space(int space)
{
    int count;
    for (count = 0; count < space; count++)
        cout << endl;
}
