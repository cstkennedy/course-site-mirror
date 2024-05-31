/**
   Day class

   copyright Steven J Zeil, 2003, based upon
     Day.java from Cay Horstmann's "Object-Oriented Design & Patterns"
**/

class Day
{
   /**
      Constructs a day with a given year, month, and day
      of the Julian/Gregorian calendar. The Julian calendar
      is used for all days before October 15, 1582
      @param aYear a year != 0
      @param aMonth a month between 1 and 12
      @param aDate a date between 1 and 31
   */

public:

  Day(int aYear, int aMonth, int aDate);


   /**
      Returns the year of this day
      @return the year
   */
  int getYear() const;


  /**
     Returns the month of this day
     @return the month
  */
  int getMonth() const;

  /**
     Returns the day of the month of this day
     @return the day of the month
  */
  int getDate() const;


  /**
     Returns a day that is a certain number of days away from
     this day
     @param n the number of days, can be negative
     @return a day that is n days away from this one
  */
  Day addDays(int n) const;


  /**
     Returns the number of days between this day and another
     day
     @param other the other day
     @return the number of days that this day is away from 
     the other (>0 if this day comes later)
  */
  int daysFrom(Day other) const;


  enum Months {JANUARY = 1,
	       FEBRUARY = 2,
	       MARCH = 3,
	       APRIL = 4,
	       MAY = 5,
	       JUNE = 6,
	       JULY = 7,
	       AUGUST = 8,
	       SEPTEMBER = 9,
	       OCTOBER = 10,
	       NOVEMBER = 11,
	       DECEMBER = 12};

private:

  /**
     Computes the Julian day number of the given day.
     @param year a year
     @param month a month
     @param date a date
     @return The Julian day number that begins at noon of 
     the given day
     Positive year signifies CE, negative year BCE. 
     Remember that the year after 1 BCE was 1 CE.
  */
  static int getJulian(int year, int month, int date);


  struct CalDate {
    int year;
    int month;
    int date;
  };

  /**
     Converts a Julian day number to a calendar date.
     
     @param j  the Julian day number
     @return a structure containing the year, month,
       and day of the month.
  */
  static CalDate fromJulian(int j);

  Day (int julianDate);

  
  int julian;
  
};





