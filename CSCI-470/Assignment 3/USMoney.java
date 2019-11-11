/************************************************************
 *                                                          
 *  CSCI 470-2/502-2       Assignment 3        Summer 2019  
 *                                                          
 *  Class Name:  USMoney				            
 *                                                          
 *  Programmer:  Ryan Rickgauer				    
 *                                                          
 *  Purpose: reprents specific amount of dollars & cents   
 *								
 ************************************************************/

public class USMoney
{
    private int dollars;    // number of dollars
    private int cents;	    // number of cents
    
    /***********************************************************************
     * 
     * Method Name: USMoney
     * 
     * Purpose:	    constructor
     * 
     ***********************************************************************/
    public USMoney(int dollars, int cents) {
	
	// check if cents is between 0-99
	if (cents < 0) {
	    this.dollars = dollars - 1;
	    this.cents = 100 + cents;   
	} else if (cents > 99) {
	    this.dollars = dollars + 1;
	    this.cents = cents - 100;
	} else {
	    this.dollars = dollars;
	    this.cents = cents;
	}
    }
    
    /***********************************************************************
     * 
     * Method Name: getDollars
     * 
     * Purpose:	    returns dollars field
     * 
     ***********************************************************************/
    public int getDollars() {
	return dollars;
    }
    
    /***********************************************************************
     * 
     * Method Name: getCents
     * 
     * Purpose:	    returns cents field
     * 
     ***********************************************************************/
    public int getCents() {
	return cents;
    }
    
    /***********************************************************************
     * 
     * Method Name: plus
     * 
     * Purpose:	    returns a USMoney object that is a combination of the 
     *		    paramater's dollars/cents and this' dollars/cents
     * 
     ***********************************************************************/
    public USMoney plus(USMoney money) {
	
	// combine given object's and this dollars and cents
	int totalDollars = money.getDollars() + this.dollars;
	int totalCents = money.getCents() + this.cents;

	// return combined dollars and cents as a new USMoney object
	return new USMoney(totalDollars, totalCents);
    }
}
