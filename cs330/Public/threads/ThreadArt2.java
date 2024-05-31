import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 * A simple example of GUI event handling in a Java application.
 * 
 * This can be run as a main program or as an applet.
 * 
 * @author zeil
 *
 */


public class ThreadArt2 extends JApplet {

    private boolean startedInAnApplet;

    // The Model
    private Color[] colors;
    private int stepSize = 5;

    private int cycleLength;
    private int cycleCounter;
    private boolean running;
    
    // The View & Controls
    private JFrame window;
    private JPanel canvas;
    private JButton colorChooser1;
    private JButton colorChooser2;
    private JButton pause;
    private JTextField stepSizeIn;
    
    private Animator colorChanger;


    private class ColorChooser implements ActionListener {
        private JButton button;
        private int colorNum;

        public ColorChooser (JButton button, int colorNum) {
            this.button = button;
            this.colorNum = colorNum;
        }

        @Override
        public void actionPerformed(ActionEvent arg0) {
            Color chosen = JColorChooser.showDialog(window, "Choose a color", colors[colorNum]);
            if (chosen != null) {
                colors[colorNum] = chosen;
                setColor (button, chosen);
                canvas.repaint();
            }
        }
    };


    /**
     * Thread that slowly changes the color of the drawing 
     *
     */
    public class Animator extends Thread {

        public Animator()
        {
        }
        
        
        public void run()
        {
            running = true;
            while (true) {
                try {
                    sleep(50);
                } catch (InterruptedException e) {
                  break;
                }
                synchronized (this) {
                    while (!running) {
                        try {
                            wait();                           /*3*/
                        } catch (InterruptedException e) {
                            return;
                        }
                    }
                }
                cycleCounter = (cycleCounter + 1) % cycleLength;
                canvas.repaint();
            }
        }
        
    }




    public ThreadArt2()
    {
        startedInAnApplet = false;
        window = null;
        colors = new Color[2];
        colors[0] = Color.red;
        colors[1] = Color.blue;
        cycleLength = 100;
        cycleCounter = 0;
        running = true;
    }


    public static void main (String[] args)
    {
        ThreadArt2 instance = new ThreadArt2();
        instance.createAndShowGUI();  
    }

    public void createAndShowGUI() {
        window = new JFrame();
        // set up the components
        window.getContentPane().setLayout (new BorderLayout());

        canvas = new JPanel () {
            public void paint (Graphics g) {
                super.paint(g);
                drawLines (g, getSize());
            }
        };
        canvas.setBackground(Color.white);
        window.getContentPane().add (canvas, BorderLayout.CENTER);
        canvas.setPreferredSize(new Dimension(400, 400));

        JPanel controls = new JPanel();

        colorChooser1 = new JButton("Color 1");
        controls.add (colorChooser1);
        setColor(colorChooser1, colors[0]);
        colorChooser1.addActionListener (new ColorChooser(colorChooser1, 0));

        colorChooser2 = new JButton("Color 2");
        controls.add (colorChooser2);
        setColor(colorChooser2, colors[1]);
        colorChooser2.addActionListener (new ColorChooser(colorChooser2, 1));

        stepSizeIn = new JTextField (""+stepSize, 5);
        controls.add (stepSizeIn);
        stepSizeIn.addActionListener (new ActionListener()
        {
            public void actionPerformed(ActionEvent e) {
                try {
                    Integer newSize = new Integer(stepSizeIn.getText());
                    stepSize = newSize.intValue();
                    canvas.repaint();
                } catch (Exception ex) {};
            }
        });

        pause = new JButton("Pause");             /*1*/
        controls.add (pause);
        pause.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(ActionEvent e) {
                if (running) {
                    running = false;              /*2*/
                    pause.setText("Resume");
                    pause.repaint();
                } else {
                    synchronized (colorChanger) {
                        running = true;           /*4*/
                        pause.setText("Pause");
                        pause.repaint();
                        colorChanger.notifyAll();
                    }
                }
            }
        });
        
        
        window.getContentPane().add (controls, BorderLayout.SOUTH);

        window.setDefaultCloseOperation((startedInAnApplet) ? JFrame.DISPOSE_ON_CLOSE : JFrame.EXIT_ON_CLOSE);


        colorChanger = new Animator();
        colorChanger.start();

        window.pack();
        window.setVisible(true);
    }

    /**
     * Sets the background color of a button to the indicated color.
     * Changes the foreground to wither black or white, depending on
     * which will give more contrast agasint the new background.
     * 
     * @param button
     * @param color
     */
    private void setColor(JButton button, Color color) {
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

    // Applet functions

    public void init() {
        startedInAnApplet = true;
    }

    public void start() {
        if (window == null)
            createAndShowGUI();
    }

    public void stop() {
    }

    public void destroy() {
    }




    int interpolate (int x, int y, int i, int steps)
    {
        return (i * x + (steps-i)*y) / steps;
    }


    Color interpolate(Color c1, Color c2, int i, int steps)
    {
        return new Color (interpolate(c1.getRed(), c2.getRed(), i, steps),
                interpolate(c1.getGreen(), c2.getGreen(), i, steps),
                interpolate(c1.getBlue(), c2.getBlue(), i, steps));
    }


    class Point {
        double x;
        double y;
    }

    Point ptOnCircle (int degrees, int radius, Point center) 
    {
        Point p = new Point();
        double theta = Math.toRadians((double)degrees);
        p.x = center.x + (double)radius * Math.cos(theta);
        p.y = center.y + (double)radius * Math.sin(theta);
        return p;
    }

    public void drawLines(Graphics g, Dimension d)
    {
        int dmin = (d.width < d.height) ? d.width : d.height;

        if (stepSize < 1)
            stepSize = 1;

        Point center = new Point();
        center.x = (double)d.width/2.0;
        center.y = (double)d.height/2.0;

        int k = Math.abs(cycleCounter - cycleLength/2);
        int theta = 60 * cycleCounter / cycleLength; 
        
        for (int i = 0; i < 60; ++i) {
            int radius = dmin/2; //interpolate(dmin/4, dmin/2, k, cycleLength/2);
            Point origin = ptOnCircle(6*i+theta, radius, center);
            int j = i + stepSize;
            while (j >= 60)
                j -= 60;
            while (i != j) {
                Point destination = ptOnCircle(6*j+theta, radius, center);
                Color c = interpolate(colors[0], colors[1], k, cycleLength/2);
                g.setColor(c);
                g.drawLine ((int)origin.x, (int)origin.y,
                        (int)destination.x, (int)destination.y);
                j += stepSize;
                while (j >= 60)
                    j -= 60;
            }
        }
    }


}
