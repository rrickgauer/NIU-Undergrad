
/** **********************************************************
 *                                                          *
 *  CSCI 470-1			Assignment 5			Summer 2019 *
 *                                                          *
 *  Class Name:  SortPanel									*
 *                                                          *
 *  Programmer:  Ryan Rickgauer								*
 *                                                          *
 *  Purpose:  The panel that holds the animation panel		*
 *                                                          *
 *********************************************************** */
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.util.Random;
import javax.swing.JComboBox;
import javax.swing.JPanel;

public class SortPanel extends JPanel {
	private final String sortNames[] = {"Bubble", "Selection", "Heap"};		// sort algorithm names
	private JComboBox sortSelection = new JComboBox(sortNames);				// combo box to choose a sort
	private final Dimension size = new Dimension(400, 400);					// size of the panel
	private SortAnimationPanel animationPanel = new SortAnimationPanel();	// animation panel
	private GridBagConstraints constraints = new GridBagConstraints();		// gridbaglayout constraints
	private int[] sortable;													// array of random heights
	private int speedIndex = 0;												// index for how fast to sort the arrays

	/** ************************************
	 * Method Name: SortPanel
	 *
	 * Purpose: constructor
	 ************************************* */
	public SortPanel(int[] newSortable) {

		setLayout(new GridBagLayout());
		setSize(size);
		setPreferredSize(size);

		sortable = newSortable;

		// add animation panel
		constraints.gridx = 0;
		constraints.gridy = 0;
		add(animationPanel, constraints);

		// add sort selector
		constraints.gridx = 0;
		constraints.gridy = 1;
		add(sortSelection, constraints);

	}

	/** ************************************
	 * Method Name: getAnimatedPanel
	 *
	 * Purpose: returns the animation panel
	 ************************************* */
	public SortAnimationPanel getAnimatedPanel() {
		return animationPanel;
	}

	/** ************************************
	 * Method Name: populate
	 *
	 * Purpose: populates the array with random numbers
	 ************************************* */
	public void populate() {
		sortable = new int[350];
		Random random = new Random();
		for (int count = 0; count < sortable.length; count++) {
			sortable[count] = random.nextInt(350);
		}

		animationPanel.repaint();
	}

	/** ************************************
	 * Method Name: populate
	 *
	 * Purpose: sets the speed for sorting
	 ************************************* */
	public void setSpeedIndex(int speed) {

		switch (speed) {
			case 0:
				speedIndex = 50;
				break;
			case 1:
				speedIndex = 25;
				break;
			case 2:
				speedIndex = 5;
				break;
		}
	}

	// inner animation panel
	private class SortAnimationPanel extends JPanel implements Runnable {

		private final Dimension dimension = new Dimension(350, 350);	// size of the panel
		public int sortNumber = 0;										// which algorithm to use

		/** ************************************
		 * Method Name: SortAnimationPanel
		 *
		 * Purpose: constructor
		 ************************************* */
		public SortAnimationPanel() {
			setSize(dimension);
			setPreferredSize(dimension);
		}

		/** ************************************
		 * Method Name: paintComponent
		 *
		 * Purpose: paints the panel from the array of random numbers
		 ************************************* */
		@Override
		public void paintComponent(Graphics g) {

			super.paintComponent(g);
			this.setBackground(Color.WHITE);

			g.setColor(Color.BLUE);

			for (int count = 0; count < sortable.length; count++) {
				g.drawLine(count, sortable.length, count, sortable[count]);
			}
		}

		/** ************************************
		 * Method Name: bubbleSort
		 *
		 * Purpose: applies the bubble sort to the array
		 ************************************* */
		public void bubbleSort() throws InterruptedException {

			//System.out.println("Starting bubble sort");
			int num = sortable.length;

			for (int i = 0; i < (num - 1); i++) {
				for (int j = 0; j < num - i - 1; j++) {
					if (sortable[j] < sortable[j + 1]) {
						int temp = sortable[j];
						sortable[j] = sortable[j + 1];
						sortable[j + 1] = temp;
						repaint();
					}
				}

				Thread.sleep(speedIndex);
			}

		}

		/** ************************************
		 * Method Name: selectionSort
		 *
		 * Purpose: applies the selection sort to the array
		 ************************************* */
		private void selectionSort() throws InterruptedException {

			int hold, min, n = sortable.length;

			for (int i = 0; i < n - 1; i++) {

				min = i;

				for (int j = i + 1; j < n; j++) {
					if (sortable[j] > sortable[min]) {
						min = j;
					}
				}

				if (min != i) {
					hold = sortable[i];
					sortable[i] = sortable[min];
					sortable[min] = hold;
					repaint();
				}

				Thread.sleep(speedIndex);
			}
		}

		/** **********************************************
		 * Method Name: heapSort
		 *
		 * Purpose: applies the heap sort to the array
		 ************************************************** */
		private void heapSort() throws InterruptedException {

			//build heap
			for (int root = sortable.length - 1; root > 0; root--) {
				heapify(sortable.length - 1, root);
			}

			//Conduct the sort on the now heapified int array
			int i = sortable.length - 1;
			while (i > 0) {
				int hold = sortable[0];
				sortable[0] = sortable[i];
				sortable[i] = hold;
				heapify(--i, 0);
			}
		}

		/** ************************************
		 * Method Name: heapify
		 *
		 * Purpose: used for the heap sort
		 ************************************* */
		private void heapify(int len, int root) throws InterruptedException {

			if ((2 * root) == len) {

				if (sortable[2 * root] > sortable[root]) {
					int hold = sortable[2 * root];
					sortable[2 * root] = sortable[root];
					sortable[root] = hold;
					heapify(len, 2 * root);
				}

			} else if ((2 * root + 1) < len) { //There are two children

				if (sortable[2 * root] > sortable[2 * root + 1]) {

					if (sortable[2 * root] > sortable[root]) {
						int hold = sortable[2 * root];
						sortable[2 * root] = sortable[root];
						sortable[root] = hold;
						heapify(len, 2 * root);
					}

				} else {

					if (sortable[2 * root + 1] > sortable[root]) {
						int hold = sortable[2 * root + 1];
						sortable[2 * root + 1] = sortable[root];
						sortable[root] = hold;
						heapify(len, 2 * root + 1);
					}

				}

			}

			repaint();
			Thread.sleep(speedIndex);
		}

		/** ************************************
		 * Method Name: run
		 *
		 * Purpose: overrides the Runnable interface
		 ******************************************** */
		@Override
		public void run() {
			try {
				int selectedIndex = sortSelection.getSelectedIndex();

				switch (selectedIndex) {
					case 0:
						bubbleSort();
						break;
					case 1:
						selectionSort();
						break;
					case 2:
						heapSort();
						break;
				}

			}
			catch (InterruptedException e) {
				System.out.println("Interrupted:\n" + e.getMessage());
			}

		}

	}

}
