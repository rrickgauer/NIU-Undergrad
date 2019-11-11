/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 2        Summer 2019  *
 *                                                          *
 *  Class Name:  MilesRedeemer				    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:  encapsulates the logic for redeeming mileage  *
 *                                                          *
 ************************************************************/
import java.util.ArrayList;
import java.util.Scanner;


public class MileRedeemer
{
    
    private Destination[] destinations;	// list of all destinations
    private int remainingMiles;		// reamining client miles 
    
    
/************************************************************
 *                                                          
 *  Method Name:  readDestinationInfo            
 *                                                          
 *  Purpose:  reads and parses the destination data into an 
 *	      array of Destination objects
 ************************************************************/
    public void readDestinationInfo(Scanner fileScanner) {
	
	String name, mileage, ffMileage, upgradeMileage, monthStart, monthEnd;
	
	String[] names;
	
	ArrayList<Destination> destinationList = new ArrayList<Destination>();
	
	while (fileScanner.hasNextLine())
	{
	    String line = fileScanner.nextLine();   // read in next line
	    line = line.replaceAll("-", ";");	    // replace the - with ;
	    String[] fields = line.split(";");	    // split the string into ; seperated fields
	    
	    // add a new destination to the array list
	    destinationList.add(new Destination(fields[0], Integer.parseInt(fields[1]), Integer.parseInt(fields[2]), Integer.parseInt(fields[3]), Integer.parseInt(fields[4]), Integer.parseInt(fields[5]))); 
	    
	    
	}
	
	destinationList.sort(new MileageComparator()); // sorts the arrays

	// convert the array list into an array
	destinations = (Destination[])destinationList.toArray(new Destination[destinationList.size()]);
	
	
	
	
	
    }
    
/************************************************************
 *                                                          
 *  Method Name:  getDestinationNames            
 *                                                          
 *  Purpose:  prints all availble city names ascending
 ************************************************************/
    public String[] getDestinationNames() {
	
	String[] names = new String[destinations.length];
	
	// fill array with city names
	for (int count = 0; count < names.length; count++)
	    names[count] = destinations[count].getName();
	
	// sort the array using selection sort
	for (int count = 0; count < names.length - 1; count++) {
	    if (names[count].compareToIgnoreCase(names[count+1]) > 0) {
		String temp = names[count];
		names[count] = names[count + 1];
		names[count + 1] = temp;
	    }
	    
	}
	
	return names;
    }
    
    
    
 /************************************************************
 *                                                          
 *  Method Name:  redeemCustomerMiles            
 *                                                          
 *  Purpose:  return an array of String objects containing 
 *	      descriptions of redeemed tickets to be printed
 *	      out by the main program
 ************************************************************/
    public String[] redeemCustomerMiles(int miles, int month)
    {
	ArrayList<Destination> list = new ArrayList<Destination>(); // list to hold available destinations 
	
	remainingMiles = miles;
	
	// get all possible travel destinations
	
	for(int count = 0; count < destinations.length; count++)
	{
	    Destination destination = destinations[count];  // next destination
	    
	    // get the normal mileage cost
	    int cost = destination.getNormalMileage();
	    
	    // check if freq flyer promo can be applied
	    if (destination.getMonthStart() >= month && destination.getMonthEnd() <= month)
		cost = destination.getFreqFlyerMileage();
	    
	    // check if miles is greater than cost
	    if (remainingMiles >= cost) {
		list.add(destination);	// add destination to list
		remainingMiles -= cost;	// less cost from remaining miles
	    }
	    
	}
	
	
	ArrayList<String> outputList = new ArrayList<String>(list.size());
	
	// check for avaible upgrades from remaining miles
	for (Destination destination : list) {
	    // check if customer can upgrade
	    if (remainingMiles >= destination.getUpgradeMileage()) {
		remainingMiles -= destination.getUpgradeMileage();  // subtract cost of upgrade from remaining miles
		outputList.add("* A trip to " + destination.getName() + " in First Class");
	    } else {
		outputList.add("* A trip to " + destination.getName() + " in Economy Class");
	    }   
	}
	
	return (String[])outputList.toArray(new String[outputList.size()]);
	
    }
    
 /************************************************************
 *                                                          
 *  Method Name:  getLeftoverMiles            
 *                                                          
 *  Purpose:  returns client's remaining miles
 ************************************************************/
    public int getLeftoverMiles() {
	return this.remainingMiles;
    }
    
    
    
    
    
    
    
    
    
    
}
