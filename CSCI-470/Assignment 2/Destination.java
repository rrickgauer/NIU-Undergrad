/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 2        Summer 2019  *
 *                                                          *
 *  Class Name:  Destination				    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:  represents a traveling destination	    *
 *                                                          *
 ************************************************************/

public class Destination
{   
    private String name;	    // city name
    private int normalMileage;	    // number of normal miles
    private int freqFlyerMileage;   // number of freq flyer miles 
    private int upgradeMileage;	    // number of miles needed to upgrade to 1st class
    private int monthStart;	    // freq flyer promo month start
    private int monthEnd;	    // freq flyer promo month end
    
    /************************************************************
    *                                                          
    *  Method Name:  Destination            
    *                                                          
    *  Purpose:	constructor
    ************************************************************/
    public Destination() {
	name = null;
	normalMileage = 0;
	freqFlyerMileage = 0;
	upgradeMileage = 0;
	monthStart = 1;
	monthEnd = 2;
    }
    
    /************************************************************
    *                                                    
    *  Method Name:  Destination            
    *                                                          
    *  Purpose:	constructor 2
    ************************************************************/
    public Destination(String name, int normalMileage, int freqFlyerMileage, int upgradeMileage, int monthStart, int monthEnd) {
	this.name = name;
	this.normalMileage = normalMileage;
	this.freqFlyerMileage = freqFlyerMileage;
	this.upgradeMileage = upgradeMileage;
	this.monthStart = monthStart;
	this.monthEnd = monthEnd;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  setName            
    *                                                          
    *  Purpose:	sets city name
    ************************************************************/
    public void setName(String name) {
	this.name = name;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  setNormalMileage            
    *                                                          
    *  Purpose:	sets normal mileage
    ************************************************************/
    public void setNormalMileage(int normalMileage) {
	this.normalMileage = normalMileage;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  setFreqFlyerMileage            
    *                                                          
    *  Purpose:	sets frequent flyer mileage
    ************************************************************/
    public void setFreqFlyerMileage(int freqFlyerMileage) {
	this.freqFlyerMileage = freqFlyerMileage;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  setUpgradeMileage            
    *                                                          
    *  Purpose:	sets upgradeMileage
    ************************************************************/
    public void setUpgradeMileage(int upgradeMileage) {
	this.upgradeMileage = upgradeMileage;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  setMonthStart            
    *                                                          
    *  Purpose:	sets month start
    ************************************************************/
    public void setMonthStart(int monthStart) {
	this.monthStart = monthStart;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  setMonthEnd        
    *                                                          
    *  Purpose:	sets month end
    ************************************************************/
    public void setMonthEnd(int monthEnd) {
	this.monthEnd = monthEnd;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  getName        
    *                                                          
    *  Purpose:	returns name
    ************************************************************/
    public String getName() {
	return name;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  getNormalMileage        
    *                                                          
    *  Purpose:	returns normal miles
    ************************************************************/
    public int getNormalMileage() {
	return normalMileage;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  getFreqFlyerMileage        
    *                                                          
    *  Purpose:	returns freq flyer miles
    ************************************************************/
    public int getFreqFlyerMileage() {
	return freqFlyerMileage;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  getUpgradeMileage        
    *                                                          
    *  Purpose:	returns amount of miles needed to upgrade
    ************************************************************/
    public int getUpgradeMileage() {
	return upgradeMileage;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  getMonthStart        
    *                                                          
    *  Purpose:	returns month start
    ************************************************************/
    public int getMonthStart() {
	return monthStart;
    }
    
    /************************************************************
    *                                                          
    *  Method Name:  getMonthEnd        
    *                                                          
    *  Purpose:	returns month end
    ************************************************************/
    public int getMonthEnd() {
	return monthEnd;
    }
}
