
typedef ... Day

Day newDay(int aYear, int aMonth, int aDate);

int getYear(Day);
int getMonth(Day);
int getDate(Day);


Day addDays(Day d, int n);
int daysFrom(Day l, Day r);

bool comesBefore (Day l, Day r);
bool sameDay (Day l, Day r);
