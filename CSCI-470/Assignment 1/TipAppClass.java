/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 1        Summer 2019  *
 *                                                          *
 *  Class Name:  TipClassApp				    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:     This class encapsulates the user interface * 
 *		 of the TipCalculator class.		    *
 *                                                          *
 ************************************************************/  

public class TipAppClass
{
    public static void main(String[] args) {
	System.out.println("*** Tip Calculator ***\n");
	java.util.Scanner in = new java.util.Scanner(System.in);
	String again;
	
	// run till user enters n
	do {
	    calculateTips();
	    System.out.print("\nAnother bill? (y/n): ");
	    again = in.next();
	} while (again.equalsIgnoreCase("y"));
	
	System.out.println("\nGood bye!");

    }
    
    static void calculateTips()
    {
	java.util.Scanner scanner = new java.util.Scanner(System.in);
	
	// get bill amount
	System.out.print("Enter the bill amount: ");
	double billAmount = scanner.nextDouble();
	while (billAmount < 0) {
	    System.out.println("Please enter a bill amount greater than 0.");
	    System.out.print("Enter the bill amount: ");
	    billAmount = scanner.nextDouble();
	}
	
	
	// get percentage
	System.out.print("Enter your desired tip percentage (20 equals 20%): ");
	int tipPercentage = scanner.nextInt();
	while (tipPercentage < 0) {
	    System.out.println("\nPlease enter a valid tip percentage");
	    System.out.print("Enter your desired tip percentage (20 equals 20%): ");
	    tipPercentage = scanner.nextInt();
	}
	
	
	// get party size
	System.out.print("Enter the size of your party: ");
	int partySize = scanner.nextInt();
	while (partySize < 1) {
	    System.out.println("\nPlease enter a valid party size.");
	    System.out.print("Enter the size of your party: ");
	    partySize = scanner.nextInt();
	}
	
	
	// calculate tips
	TipCalculator tipCalculator = new TipCalculator(billAmount, tipPercentage, partySize);
	double totalBill = tipCalculator.getTotalBill();
	double individualBill = tipCalculator.getIndividualShare();
	
	System.out.println("\n*** Your Bill ***\n");
	
	
	// format doubles
	String pattern = "$###,###,##0.00";
	java.text.DecimalFormat decimalFormat = new java.text.DecimalFormat(pattern);

	// format and print total bill
	String formatBill = decimalFormat.format(totalBill);
	System.out.println("Total Bill (with Tip): " + formatBill);
	
	// format and display individual shares
	String formatIndividualShare = decimalFormat.format(individualBill);
	System.out.println("Share for Each Individual: " + formatIndividualShare);
	
    }
    
}
