/************************************************************
 *                                                          
 *  CSCI 470-2/502-2       Assignment 3        Summer 2019  
 *                                                          
 *  Class Name:  Date				            
 *                                                          
 *  Programmer:  Ryan Rickgauer				    
 *                                                          
 *  Purpose: reprents a specific date (day, month, year)  
 *								
 ************************************************************/

import java.util.HashMap;
import java.util.Map;

public class Date
{
    private int day;		    // current day of the month
    private int month;		    // month of the year
    private int year;		    // curent year
    Map<Integer, Integer> daysMap;  // a structure to hold all the days of each month
    
    /***********************************************************************
     * 
     * Method Name: Date
     * 
     * Purpose:	    default constructor
     * 
     ***********************************************************************/
    public Date(int day, int month, int year) {
	this.day = day;
	this.month = month;
	this.year = year;
	
	daysMap = new HashMap<Integer, Integer>();
	fillMap();  // fills the map with corresponding days
    }
    
    /***********************************************************************
     * 
     * Method Name: isLeapYear
     * 
     * Purpose:	    returns true if the current year is a leap year
     * 
     ***********************************************************************/
    public boolean isLeapYear() {
	boolean isLeapYear = false;
	
	if (year % 4 == 0) {
	    
	    isLeapYear = true;
	    
	    // check if century year
	    if (year % 100 == 0) {
		
		// check if divisible by 400
		if (year % 400 != 0)
		    isLeapYear = false;
	    }
	}
	
	return isLeapYear;
    }

    /***********************************************************************
     * 
     * Method Name: fillMap
     * 
     * Purpose:	    fills the hash map with the number of days in each month
     * 
     ***********************************************************************/
    private void fillMap() {
	
	daysMap.put(1, 31);	    // january 
	if (isLeapYear())	    // feb
	    daysMap.put(2, 29);	    // leap year feb
	else 
	    daysMap.put(2, 28);	    // regular year feb
	daysMap.put(3, 31);	    // march
	daysMap.put(4, 30);	    // april
	daysMap.put(5, 31);	    // may
	daysMap.put(6, 30);	    // june
	daysMap.put(7, 31);	    // july
	daysMap.put(8, 31);	    // aug
	daysMap.put(9, 30);	    // sep
	daysMap.put(10, 31);	    // oct
	daysMap.put(11, 30);	    // nov
	daysMap.put(12, 31);	    // dec
    }
    
    /***********************************************************************
     * 
     * Method Name: daysSinceJan1
     * 
     * Purpose:	    returns the number of days since Jan 1st of the given year
     * 
     ***********************************************************************/
    public int daysSinceJan1() {
	
	// if january return days
	if (month == 1)
	    return this.day;
	
	// sum up all the days in the previous months
	int previousMonthsDays = 0;
	for (int count = 1; count < this.month; count++)
	    previousMonthsDays += daysMap.get(count);
	
	// return sum of number of days in current month plus all previous days
	return this.day + previousMonthsDays;

    }
}
