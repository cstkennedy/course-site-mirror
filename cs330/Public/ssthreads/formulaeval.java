public class MainWindow extends java.awt.Frame {

    private SSView ssview;
    private Applet inApplet;
    private Formula formula;
    private TextField statusLine;
    private SpreadSheet sheet;
    private Clipboard clipboard;

    public MainWindow (SpreadSheet s, Applet inAnApplet)
    {
	inApplet = inAnApplet;
        sheet = s;
	clipboard = new Clipboard();

	formula = new Formula();
	formula.addActionListener(new ActionListener() {
		public void actionPerformed (ActionEvent e) {
		  if (!ssview.getSelectingRectangleMode()) {
		    CellName cn = ssview.getSelectedCells().upperLeftCorner();
		    Cell c = sheet.getCell(cn);
		    if (!formula.getText().equals("")) {
		      Expression expr = Expression.get(formula.getText());
		      if (expr != null) {
			c.putFormula(expr);
		      }
		      else {
			statusLine.setText("Syntax error in formula");
		      }
		    }
		    else {
		      c.putFormula(null);
		    }
		    sheet.evaluateAll();
		  }
		}});

