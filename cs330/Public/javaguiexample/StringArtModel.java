import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;

import javax.swing.JButton;

/**
 * The core data and drawing algorithm for the CS330 string art program.
 * 
 * @author zeil
 *
 */
public class StringArtModel {

	/**
	 * The two colors used in drawing the picture.
	 * Lines are shaded gradually from colors[0]
	 * to colors[1].
	 */
    private Color[] colors;    
	
	/**
	 * Each of the 60 points around the circle will get
	 * a line connecting it to the points k*stepSize away,
	 * for all values of k (until we start to repeat
	 * the same lines).
	 */
	private int stepSize = 5;    /*2*/


	/**
	 * Create a new set of model data.
	 */
	public StringArtModel() {
		colors = new Color[2];
		colors[0] = Color.red;
		colors[1] = Color.blue;
	}

	/**
	 * Get the value of one of the colors.
	 * @param colorNum an integer in the range 0..1
	 * @return the requested color.
	 */
    public Color getColor(int colorNum) {     /*3*/
		return colors[colorNum];
	}

	/**
	 * Change the value of one of the colors.
	 * @param colorNum an integer in the range 0..1
	 * @param color the desired color
	 */
	public void setColor(int colorNum, Color color) {  /*3*/
		colors[colorNum] = color;
	}

	/**
	 * Get the current step size.  When drawLines is called,
	 * each of the 60 points around the circle will get
	 * a line connecting it to the points k*getStepSize() away,
	 * for all values of k (until we start to repeat
	 * the same lines).
	 * 
	 * @return the step size
	 */
	public int getStepSize() {     /*3*/
		return stepSize;
	}

	/**
	 * Change the step size value.
	 * @param newStepSize the desired step size
	 */
	public void setStepSize (int newStepSize) {    /*3*/
		stepSize = newStepSize;
	}


	/**
	 * Compute the value that lies (i/n) of the way between x and y.
	 * 
	 * @param x any integer value
	 * @param y any integer value
	 * @param i an integer in the range 0..steps indicating how close to y we want to be
	 * @param steps how many steps from x to y
	 * @return an interpolated value between x and y
	 */
	private int interpolate (int x, int y, int i, int steps) {
		return (i * x + (steps-i)*y) / steps;
	}

	/**
	 * Compute a color that lies between c1 and c2.  This is the function
	 * used  to "shade" lines between the two base colors.
	 *  
	 * @param c1 any color
	 * @param c2 any colot
	 * @param i an integer in the range 0..steps indicating how close to c2 we want to be
	 * @param steps how many steps from c1 to c2
	 * @return an interpolated value between c1 and c2
	 * @return an interpolated color value.
	 */

	private Color interpolate(Color c1, Color c2, int i, int steps) {
		return new Color (interpolate(c1.getRed(), c2.getRed(), i, steps),
				interpolate(c1.getGreen(), c2.getGreen(), i, steps),
				interpolate(c1.getBlue(), c2.getBlue(), i, steps));
	}


	/**
	 * An (x,y) Cartesian coordinate.
	 * @author zeil
	 *
	 */
	private class Point {
		public double x;
		public double y;
	}

	/**
	 * Get the coordinates of a point on a circle.
	 * @param degrees The angle around the circle where we want the point.
	 * @param radius  The radius of the circle.
	 * @param center  The center of the circle.
	 * @return  the coordinates of a point on the edge of the circle at the desired angle. 
	 */
	private Point ptOnCircle (int degrees, int radius, Point center) {
		Point p = new Point();
		double theta = Math.toRadians((double)degrees);
		p.x = center.x + (double)radius * Math.cos(theta);
		p.y = center.y + (double)radius * Math.sin(theta);
		return p;
	}

	/**
	 * Draw a series of lines connecting 60 points set around
	 * a circle.
	 * 
	 * @param g the graphics device on which we are to drawn.
	 * @param d the dimension (width and height) of the available
	 *          drawing area.
	 */
    public void drawLines(Graphics g, Dimension d) {    /*4*/
		int dmin = (d.width < d.height) ? d.width : d.height;

		if (stepSize < 1)
			stepSize = 1;

		Point center = new Point();
		center.x = (double)d.width/2.0;
		center.y = (double)d.height/2.0;

		for (int i = 0; i < 60; ++i) {
			Point origin = ptOnCircle(6*i, dmin/2, center);
			int j = i + stepSize;
			while (j >= 60)
				j -= 60;
			while (i != j) {
				Point destination = ptOnCircle(6*j, dmin/2, center);
				g.setColor(interpolate(interpolate(colors[0], colors[1], i%30, 30),
						interpolate(colors[0], colors[1], j, 60),
						1, 2));
				g.drawLine ((int)origin.x, (int)origin.y,
						(int)destination.x, (int)destination.y);
				j += stepSize;
				while (j >= 60)
					j -= 60;
			}
		}
	}


	/**
	   * Sets the background color of a button to the indicated color.
	   * Changes the foreground to either black or white, depending on
	   * which will give more contrast against the new background.
	   * 
	   * @param button
	   * @param color
	   */
	  public void setColor(JButton button, Color color) {  /*5*/
	    button.setBackground(color);
	    int brightness = color.getRed() + color.getGreen() + color.getBlue(); // max of 3*255
	    if (brightness > 3*255/2) {
	        // This is a fairly bright color. Use black lettering
	        button.setForeground (Color.black);
	    } else {
	        // This is a fairly dark color. Use white lettering
	        button.setForeground (Color.white);
	    }
	}
}
