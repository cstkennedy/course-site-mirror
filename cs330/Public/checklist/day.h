
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

  bool comesBefore (Day other) const;
  bool sameDay (Day other) const;

private:
  int daysSinceStart;  // start is 10/15/1582

  /* alternate implem:
  int theYear;
  int theMonth;
  int theDate;
  */
};
