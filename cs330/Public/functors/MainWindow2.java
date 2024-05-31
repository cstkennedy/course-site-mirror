package SpreadSheetJ.ViewCon;

import SpreadSheetJ.Model.*;

import java.awt.*;
import java.awt.event.*;

import java.io.*;

// Thw window used to present the spreadsheet, including menu bar and
// formula bar.

public class MainWindow extends java.awt.Frame {

    private SSView ssview;
    private Formula formula;
    private TextField statusLine;
    private SpreadSheet sheet;
    private Clipboard clipboard;


    public MainWindow (SpreadSheet s)
    {
        sheet = s;
        clipboard = new Clipboard();
	  //...
        /*+*/addWindowListener(new WindowAdapter() {
                public void windowClosing(WindowEvent e) {
                        System.exit (0);
                }
            });/*-*/

        setTitle ("SpreadSheet");
        buildMenu();
        pack();
        show();
    }

