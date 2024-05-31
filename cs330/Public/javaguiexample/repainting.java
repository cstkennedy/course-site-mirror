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
              /*+*/canvas.repaint();/*-*/
          }
      }
  };


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
            /*+*/canvas.repaint();/*-*/
          } catch (Exception ex) {};
        }
      });

    window.getContentPane().add (controls, BorderLayout.SOUTH);
    
    window.setDefaultCloseOperation((startedInAnApplet) ? JFrame.DISPOSE_ON_CLOSE : JFrame.EXIT_ON_CLOSE);
    
    window.pack();
    window.setVisible(true);
  }
