/************************************************************
 *                                                          *
 *  CSCI 470-2/502-2       Assignment 4        Summer 2019  *
 *                                                          *
 *  Class Name:  TipApp					    *
 *                                                          *
 *  Programmer:  Ryan Rickgauer				    *
 *                                                          *
 *  Purpose:     GUI window for the tip calculator	    *
 *                                                          *
 ************************************************************/

import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSlider;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;


class TipApp extends JFrame implements ActionListener
{
    private JLabel totalBillLabel;		// total bill label output
    private JLabel individualBillLabel;		// output label
    private JTextField billTextField;		// input field
    private JButton calculateButton;		// calculate button
    private JButton clearButton;		// clear button	
    private JSpinner sizeSpinner;		// size slider
    private JSlider percentageSlider;		// tip slider
    private GridBagConstraints constraints;	// constraints
  
    /**
     * Method name: TipApp
     * 
     * Purpose: constructor
     */
    public TipApp()
    {
	
	
	super("Tip Calculator");
	this.setLayout(new GridBagLayout());
	
	// initialize constraints
	constraints = new GridBagConstraints();
	
	// add bill amount label
	addComp(0, 0, new JLabel("Bill Amount"));
	
	// add bill amount text field
	billTextField = new JTextField(10);
	addComp(1, 0, billTextField);
	
	// add tip percentage label
	addComp(0, 1, new JLabel("Tip Percentage"));
	
	// add slider
	percentageSlider = new JSlider(JSlider.HORIZONTAL, 0, 50, 20);  
	percentageSlider.setMinorTickSpacing(5);  
	percentageSlider.setMajorTickSpacing(10);  
	percentageSlider.setPaintTicks(true);  
	percentageSlider.setPaintLabels(true);
	percentageSlider.setSnapToTicks(true);
	addComp(1, 1, percentageSlider);
	
	// add party size label
	addComp(0, 2, new JLabel("Party Size"));
	
	// add party size spinner
	sizeSpinner = new JSpinner(new SpinnerNumberModel(1, 1, 100, 1));
	addComp(1, 2, sizeSpinner);
	
	// add calculate buotton
	calculateButton = new JButton("Calculate");
	calculateButton.addActionListener(this);
	addComp(0, 3, calculateButton);
	
	// add clear button
	clearButton = new JButton("Clear");
	clearButton.addActionListener(this);
	addComp(1, 3, clearButton);
	
	// add total bill label
	addComp(0, 4, new JLabel("Total Bill (with Tip)"));
	
	// add total bill result label
	totalBillLabel = new JLabel("$0.00");
	addComp(1, 4, totalBillLabel);
	
	// add individual bill label
	addComp(0, 5, new JLabel("Individual share"));
	
	// add total bill result label
	individualBillLabel = new JLabel("$0.00");
	addComp(1, 5, individualBillLabel);
	
	
	// setup screen
	setSize(500, 500);
	this.setPreferredSize(getSize());
	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	setVisible(true);
	
    }
    
    /**
     * Method name: addComp
     * 
     * Purpose: adds a jcomponent to the frame
     */
    private void addComp(int gridx, int gridy, Component comp) {
	constraints.gridx = gridx;
	constraints.gridy = gridy;
	this.add(comp, constraints);
	
    }

    /**
    * Method name: actionPerformed
    * 
    * Purpose: performs the actions depending on the button clicked
    */
    @Override
    public void actionPerformed(ActionEvent e)
    {
	if (e.getSource() == calculateButton)
	    calculateButtonActions();
	else
	    clearButtonActions();
    }
    
    /**
     * Method name: calculateButtonActions
     * 
     * Purpose: actions performed when calculate button is clicked
     */
    private void calculateButtonActions() {
	// retrieve text from input field
	
	try {
	    double billAmount = Double.valueOf(billTextField.getText());
	    if (billAmount > 0) {
	    
		// get party size
		int partySize = (Integer)sizeSpinner.getValue();

		// get the tip percentage
		int tipPercentage = percentageSlider.getValue();

		// create tip calculator object
		TipCalculator tipCalculator = new TipCalculator(billAmount, tipPercentage, partySize);

		// get the total and individual bills
		double totalBill = tipCalculator.getTotalBill();
		double individualShare = tipCalculator.getIndividualShare();
		
		// format the results
		String pattern = "$###,###,##0.00";
		DecimalFormat decimalFormat = new DecimalFormat(pattern);

	
		// set the output label text values
		totalBillLabel.setText(decimalFormat.format(totalBill));
		individualBillLabel.setText(decimalFormat.format(individualShare));
	    } else {
		JOptionPane.showMessageDialog(this,"Bill amount must be greater than 0.","Alert",JOptionPane.WARNING_MESSAGE);
	    }
	} catch (NumberFormatException e) {
	    JOptionPane.showMessageDialog(this,"Bill amount must be numeric.","Alert",JOptionPane.WARNING_MESSAGE);
	}
	
	
	
    }
    
    /**
     * Method name: clearButtonActions
     * 
     * Purpose: actions performed when clear button is clicked
     */
    private void clearButtonActions() {
	
	// clear the bill text field
	billTextField.setText("");
	
	// set slider to 20
	percentageSlider.setValue(20);
	
	// set party size spinner to 1
	sizeSpinner.setValue(1);
	
	// set output labels to 0
	totalBillLabel.setText("$0.00");
	individualBillLabel.setText("$0.00");
	
    }

    
}


