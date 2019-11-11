/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 2        Summer 2019  *
 *                                                          *
 *  Class Name:  MilesRedemptionApp			    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:  main class to calculate client miles	    *
 *                                                          *
 ************************************************************/

import java.io.File;
import java.io.IOException;
import java.util.Scanner;


public class MileRedemptionApp
{

    public static void main(String[] args) throws IOException
    {
	Scanner keyScanner = new Scanner(System.in);
	
	System.out.print("Enter name of text file: ");
	String fileName = keyScanner.next();
	File file = new File(fileName);
	Scanner fileScanner = new Scanner(file);
	
	MileRedeemer mr = new MileRedeemer();
	mr.readDestinationInfo(fileScanner);
	
	// print out all city names
	System.out.println("List of destination cities your client can travel to:\n");
	for (String name : mr.getDestinationNames())
	    System.out.println(name);
	
	
	String response;
	
	do {
	
	    // read in client's miles
	    System.out.print("\nPlease enter client's accumulated frequent flyer miles: ");
	    int miles = keyScanner.nextInt();

	    // read in departure month
	    System.out.print("Please enter client's departure month (1-12): ");
	    int month = keyScanner.nextInt();


	    // get available travel destinations
	    String[] list = mr.redeemCustomerMiles(miles, month);

	    // check if not empty
	    if (list.length > 0) {

		// print output
		for (String line : list)
		    System.out.println(line);
	    } else {
		System.out.println("*** Your client  has not accumulated enough frequent flyer miles ***");
	    }

	    // print out remiaing miles
	    System.out.println("\nRemaining miles: " + mr.getLeftoverMiles());


	    System.out.print("\nEnter y to do another customer: ");
	    response = keyScanner.next();
	
	} while (response.equalsIgnoreCase("y"));

    }
    
}
