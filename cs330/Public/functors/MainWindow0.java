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

    /*+1*/class WindowCloser implements WindowListener
    {
      public void windowClosing(WindowEvent e) {
        System.exit (0);
      }
      public void windowOpened(WindowEvent e) {}
      public void windowActivated(WindowEvent e) {}
        /*...*/
    }/*-1*/


    public MainWindow (SpreadSheet s)
    {
        sheet = s;
        clipboard = new Clipboard();
          /*...*/
        /*+2*/addWindowListener(new WindowCloser());/*-2*/

        setTitle ("SpreadSheet");
        buildMenu();
        pack();
        show();
    }

