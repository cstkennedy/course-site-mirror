class Day
{
   /**
      Represents a day with a given year, month, and day
      of the Gregorian calendar. The Gregorian calendar
      replaced the Julian calendar beginning on
      October 15, 1582
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
     Compares this day with another day.
     @param other the other day
     @return a positive number if this day comes after the
     other day, a negative number if this day comes before
     the other day, and zero if the days are the same
  */
  int compareTo(Day other) const;

  
  /**
     Computes the next day.
     @return the day following this day
  */
  Day nextDay() const;

  /**
     Computes the previous day.
     @return the day preceding this day
  */
  Day previousDay() const;

  /**
     Gets the days in a given month
     @param y the year
     @param m the month
     @return the last day in the given month
   */
  static int daysPerMonth(int y, int m);

  /**
     Tests if a year is a leap year
     @param y the year
     @return true if y is a leap year
  */
  static bool isLeapYear(int y);
  
  int year;
  int month;
  int date;

  static const int DAYS_PER_MONTH [12];
  // = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  static const int GREGORIAN_START_YEAR = 1582;
  static const int GREGORIAN_START_MONTH = 10;
  static const int GREGORIAN_START_DAY = 15;
  static const int JULIAN_END_DAY = 4;
  
};





