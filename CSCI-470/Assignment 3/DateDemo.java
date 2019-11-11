/************************************************************
 *                                                          
 *  CSCI 470-2/502-2       Assignment 3        Summer 2019  
 *                                                          
 *  Class Name:  DateDemo				            
 *                                                          
 *  Programmer:  Ryan Rickgauer				    
 *                                                          
 *  Purpose: tests the Date class  
 *								
 ************************************************************/

import java.util.Scanner;

public class DateDemo
{
    public static void main(String[] args)
    {
	Scanner scanner = new Scanner(System.in);
	
	// get the day
	System.out.print("Enter day: ");
	int day = scanner.nextInt();
	
	// get the month
	System.out.print("Enter month: ");
	int month = scanner.nextInt();
	
	// get the year
	System.out.print("Enter year: ");
	int year = scanner.nextInt();
	
	// create date object
	Date date = new Date(day, month, year);
	
	// print number of days since January 1st of that year
	System.out.println("\nIt has been " + date.daysSinceJan1() + " days since January 1st!");
	
    }
}
