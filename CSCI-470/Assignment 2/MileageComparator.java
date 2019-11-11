/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 2        Summer 2019  *
 *                                                          *
 *  Class Name:  MileageComparator  			    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:  compares 2 destination class normal miles	    *
 *	      and returns the greater one		    *
 *                                                          *
 ************************************************************/
import java.util.Comparator;


public class MileageComparator implements Comparator<Destination> {
    public int compare(Destination d1, Destination d2) {
	return (d2.getNormalMileage() - d1.getNormalMileage());
    }
}
