import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Color;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class StringArtGUI {

	private JFrame mainWindow;
	private JPanel canvas;
	private JTextField textField;
	private JTextField stepSizeIn;
	
	private StringArtModel art;
	private JButton colorButton1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					StringArtGUI window = new StringArtGUI();
					window.mainWindow.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public StringArtGUI() {
		art = new StringArtModel();
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		mainWindow = new JFrame();
		mainWindow.setBounds(100, 100, 450, 300);
		mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		canvas = new JPanel() {
			public void paint (Graphics g) {
				super.paint(g);
				art.drawLines(g, getSize());
			}
		};
		canvas.setBackground(Color.WHITE);
		mainWindow.getContentPane().add(canvas, BorderLayout.CENTER);
		
		JPanel controlPanel = new JPanel();
		mainWindow.getContentPane().add(controlPanel, BorderLayout.SOUTH);
		
		colorButton1 = new JButton("Color 1");
		colorButton1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Color chosen = JColorChooser.showDialog(mainWindow, "Choose a color", 
						art.getColor(0));
				if (chosen != null) {
					art.setColor(0, chosen);
					art.setColor (colorButton1, chosen);
					canvas.repaint();
				}
			}
		});
		art.setColor(colorButton1, art.getColor(0));
		controlPanel.add(colorButton1);

		JButton colorButton2 = new JButton("Color 2");
		colorButton2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Color chosen = JColorChooser.showDialog(mainWindow, "Choose a color", 
						art.getColor(1));
				JButton button = (JButton)e.getSource();
				if (chosen != null) {
					art.setColor(1, chosen);
					art.setColor (button, chosen);
					canvas.repaint();
				}
			}
		});
		art.setColor(colorButton2, art.getColor(1));
		controlPanel.add(colorButton2);
		
		stepSizeIn = new JTextField();
		stepSizeIn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
		            Integer newSize = new Integer(stepSizeIn.getText());
		            art.setStepSize(newSize.intValue());
		            canvas.repaint();
		          } catch (Exception ex) {};
		        }
		});
		stepSizeIn.setText("" + art.getStepSize());
		controlPanel.add(stepSizeIn);
		stepSizeIn.setColumns(3);
		
	}

}
