  public void createAndShowGUI() {
      window = new JFrame();       /*1*/
         //...
      canvas = new JPanel () {     /*2*/
	      //...
          }
      };
    canvas.setBackground(Color.white);
    window.getContentPane().add (canvas, BorderLayout.CENTER);  /*3*/
    canvas.setPreferredSize(new Dimension(400, 400));
    
    JPanel controls = new JPanel();                             /*4*/
    
    colorChooser1 = new JButton("Color 1");                     /*5*/
    controls.add (colorChooser1);
      //...
    colorChooser2 = new JButton("Color 2");
    controls.add (colorChooser2);
      //...
    stepSizeIn = new JTextField (""+stepSize, 5);
    controls.add (stepSizeIn);
      //...
    window.getContentPane().add (controls, BorderLayout.SOUTH);  /*6*/
      //...
    window.pack();                                               /*7*/
    window.setVisible(true);
  }
