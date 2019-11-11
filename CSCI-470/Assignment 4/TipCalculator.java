/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 4        Summer 2019  *
 *                                                          *
 *  Class Name:  TipCalculator				    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:     This calculates tips and total bill for    *
 *		 people at the resturant		    *
 *                                                          *
 ************************************************************/


public class TipCalculator
{
    
    private double amount = 0;
    private int percentage = 20;
    private int size = 1;
    
    public TipCalculator(double newAmount, int newPercentage, int newSize) {
	setAmount(newAmount);
	setPercentage(newPercentage);
	setSize(newSize);
    }
    
    public void setAmount(double newAmount) {
	if (newAmount > 0)
	    amount = newAmount;
	    
    }
    
    public void setPercentage(int newPercentage) {
	if (newPercentage >= 0)
	    percentage = newPercentage;
    }
    
    public void setSize(int newSize) {
	if (newSize >= 1)
	    size = newSize;
    }
    
    public double getAmount() {
	return amount;
    }
    
    public int getPercentage() {
	return percentage;
    }
    
    public int getSize() {
	return size;
    }
    
    public double getTotalBill() {
	double tipAmount = (double)((amount * percentage) / 100);
	return tipAmount + amount;
    }
    
    public double getIndividualShare() {
	double totalBill = getTotalBill();
	return totalBill / (double)size;
    }
    
}
