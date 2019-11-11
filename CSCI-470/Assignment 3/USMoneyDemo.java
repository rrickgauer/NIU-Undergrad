/************************************************************
 *                                                          
 *  CSCI 470-2/502-2       Assignment 3        Summer 2019  
 *                                                          
 *  Class Name:  USMoneyDemo				            
 *                                                          
 *  Programmer:  Ryan Rickgauer				    
 *                                                          
 *  Purpose: tests the USMoney class 
 *								
 ************************************************************/

import java.util.Scanner;

public class USMoneyDemo
{

    public static void main(String[] args)
    {
	
	Scanner scanner = new Scanner(System.in);
	
	// create first USMoney object
	System.out.print("Enter dollars for obj1: ");
	int dollars1 = scanner.nextInt();
	System.out.print("Enter cents for obj1: ");
	int cents1 = scanner.nextInt();
	USMoney money1 = new USMoney(dollars1, cents1);
	System.out.println("Object 1: $" + money1.getDollars() + "." + money1.getCents());
	
	// create second USMoney object
	System.out.print("\nEnter dollars for obj2: ");
	int dollars2 = scanner.nextInt();
	System.out.print("Enter cents for obj2: ");
	int cents2 = scanner.nextInt();
	USMoney money2 = new USMoney(dollars2, cents2);
	System.out.println("Object 2: $" + money2.getDollars() + "." + money2.getCents());
	
	// combine objects and print results
	USMoney combination = money1.plus(money2);
	System.out.println("\nCombined objects: $" + combination.getDollars() + "." + combination.getCents());
	
    }
    
}
