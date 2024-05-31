cout << "Low GPA? " << flush;
cin >> lowGPA;
cout << "\nHigh GPA? " << flush;
cin >> highGPA;
listSelectedStudents (allStudents, nStudents,
		      SelectRange(lowGPA,highGPA));
