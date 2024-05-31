    private void buildMenu()
    {
	MenuBar menuBar = new MenuBar();    /*1*/

	Menu fileMenu = new Menu ("File");  /*2*/

	MenuItem loadItem = new MenuItem ("Load");  /*3*/
	fileMenu.add (loadItem);                    /*4*/
	loadItem.addActionListener(new ActionListener() {  /*5*/
		public void actionPerformed(ActionEvent e) {
		    loadFile();
		}});

	if (inApplet == null) { // Applets can't write to the hard drive
	    MenuItem saveItem = new MenuItem ("Save");
	    fileMenu.add (saveItem);
	    saveItem.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e) {
			saveFile();
		    }});
	}

	MenuItem exitItem = new MenuItem ("Exit");
	fileMenu.add (exitItem);
	exitItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    if (inApplet != null) {
			hide();
			dispose();
		    }
		    else
			System.exit(0);
		}});
    

	Menu editMenu = new Menu ("Edit");          /*6*/

	MenuItem cutItem = new MenuItem ("Cut");
	editMenu.add (cutItem);
	cutItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    cutFormulae();
		}});
	
	MenuItem copyItem = new MenuItem ("Copy");
	editMenu.add (copyItem);
	copyItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    copyFormulae();
		}});

	MenuItem pasteItem = new MenuItem ("Paste");
	editMenu.add (pasteItem);
	pasteItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    pasteFormulae();
		}});


	MenuItem eraseItem = new MenuItem ("Erase");
	editMenu.add (eraseItem);
	eraseItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    eraseFormulae();
		}});



	Menu helpMenu = new Menu ("Help");

	MenuItem helpItem = new MenuItem ("Quick Help");
	helpMenu.add (helpItem);
	helpItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    quickHelp();
		}});

	MenuItem aboutItem = new MenuItem ("About");
	helpMenu.add (aboutItem);
	aboutItem.addActionListener(new ActionListener() {
		public void actionPerformed(ActionEvent e) {
		    about();
		}});


	menuBar.add (fileMenu);  /*7*/
	menuBar.add (editMenu);
	menuBar.add (helpMenu);

	setMenuBar (menuBar);    /*8*/
    }

