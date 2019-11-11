
/** **********************************************************
 *                                                          *
 *  CSCI 470-1			Assignment 5			Summer 2019 *
 *                                                          *
 *  Class Name:  SortApp									*
 *                                                          *
 *  Programmer:  Ryan Rickgauer								*
 *                                                          *
 *  Purpose:  The main frame for the app					*
 *                                                          *
 *********************************************************** */
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class SortApp extends JFrame {
	private GridBagConstraints constraints = new GridBagConstraints();	// constraints for the layout
	private JButton populateButton = new JButton("Populate");			// populate panel button
	private JButton sortButton = new JButton("Sort");					// sorts the animation panel
	private String[] speeds = {"Slow", "Medium", "Fast"};				// available speeds to sort with
	private JComboBox speedSelect = new JComboBox(speeds);				// menu to select the speed
	private Dimension size = new Dimension(900, 500);					// size of the frame
	private SortPanel panel1;											// left sort panel
	private SortPanel panel2;											// right sort panel
	private ExecutorService executor;									// executor to start threads

	/** ************************************
	 * Method Name: SortApp
	 *
	 * Purpose: constructor
	 ************************************* */
	public SortApp(String title) {
		super(title);
		this.setLayout(new GridBagLayout());

		initComps();	// initialize components

		// setup screen
		this.setSize(size);
		this.setPreferredSize(size);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}

	/** ************************************
	 * Method Name: initComps
	 *
	 * Purpose: adds all jcomponents to the
	 * JFrame to use
	 ************************************* */
	private void initComps() {

		// add random values to the array
		int sizes[] = new int[350];
		Random r = new Random();
		for (int count = 0; count < sizes.length; count++) {
			sizes[count] = r.nextInt(350);
		}

		// add left panel
		panel1 = new SortPanel(sizes);
		add(0, 0, panel1);

		// add second panel
		panel2 = new SortPanel(sizes);
		add(1, 0, panel2);

		// add last row to a jpanel
		JPanel bottomPanel = new JPanel();
		bottomPanel.setLayout(new FlowLayout());
		bottomPanel.add(populateButton);
		bottomPanel.add(speedSelect);
		bottomPanel.add(sortButton);

		// add panel to the frame
		constraints.gridwidth = 2;
		constraints.gridx = 0;
		constraints.gridy = 2;
		add(bottomPanel, constraints);

		executor = Executors.newCachedThreadPool();

		// add action listener to buttons
		sortButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				// disable sort button
				sortButton.setEnabled(false);

				// set threads to selected speeds
				int selectedSpeed = speedSelect.getSelectedIndex();
				panel1.setSpeedIndex(selectedSpeed);
				panel2.setSpeedIndex(selectedSpeed);

				// create new threads
				Thread t1 = new Thread(panel1.getAnimatedPanel());
				Thread t2 = new Thread(panel2.getAnimatedPanel());

				// run the threads
				executor.execute(t1);
				executor.execute(t2);

			}
		});

		// add the populate button actions
		populateButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				panel1.populate();
				panel2.populate();
				sortButton.setEnabled(true);

			}
		});
	}

	/** *************************************************
	 * Method Name: add
	 *
	 * Purpose: adds an individual component to the frame
	 ******************* ******************************* */
	private void add(int x, int y, Component comp) {
		constraints.gridx = x;
		constraints.gridy = y;
		add(comp, constraints);
	}

	/** *************************************************
	 * Method Name: main
	 *
	 * Purpose: main method
	 ******************* ******************************* */
	public static void main(String[] args) {
		SortApp app = new SortApp("Sorting Application");
		app.setVisible(true);

	}

}
