  public void createAndShowGUI() {
      window = new JFrame();
      // set up the components
      window.getContentPane().setLayout (new BorderLayout());
    
      canvas = new JPanel () {
	      //...
          }
      };
    /*+*/canvas.setBackground(Color.white);/*-*/
    window.getContentPane().add (canvas, BorderLayout.CENTER);
/*+*/canvas.setPreferredSize(new Dimension(400, 400));/*-*/  /*1*/
    
    JPanel controls = new JPanel();
    
    colorChooser1 = new JButton("Color 1");
    controls.add (colorChooser1);
    /*+*/setColor(colorChooser1, colors[0]);/*-*/
    colorChooser1.addActionListener (new ColorChooser(colorChooser1, 0));
    
    colorChooser2 = new JButton("Color 2");
    controls.add (colorChooser2);
    /*+*/setColor(colorChooser2, colors[1]);/*-*/
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

    window.getContentPane().add (controls, BorderLayout.SOUTH);
    
    window.setDefaultCloseOperation((startedInAnApplet) ? JFrame.DISPOSE_ON_CLOSE : JFrame.EXIT_ON_CLOSE);
    
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
  private void setColor(JButton button, Color color) {   /*2*/
    /*+*/button.setBackground(color);/*-*/
    int brightness = color.getRed() + color.getGreen() + color.getBlue(); // max of 3*255
    if (brightness > 3*255/2) {
        // This is a fairly bright color. Use black lettering
        /*+*/button.setForeground (Color.black);/*-*/
    } else {
        // This is a fairly dark color. Use white lettering
        /*+*/button.setForeground (Color.white);/*-*/
    }
}
