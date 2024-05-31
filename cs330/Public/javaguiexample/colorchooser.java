  private class ColorChooser implements ActionListener {
      private JButton button;          /*1*/
      private int colorNum;

      public ColorChooser (JButton button, int colorNum) {
          this.button = button;        /*2*/
          this.colorNum = colorNum;
      }

      @Override
      public void actionPerformed(ActionEvent arg0) {   /*3*/
          Color chosen = JColorChooser.showDialog(window, "Choose a color", 
                  colors[colorNum]);
          if (chosen != null) {
              colors[colorNum] = chosen;   /*4*/
              setColor (button, chosen);
              canvas.repaint();
          }
      }
  };
