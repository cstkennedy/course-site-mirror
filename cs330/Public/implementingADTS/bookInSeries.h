class BookInSeries: public Book {
   public:
     std::string getSeriesTitle() const;
     void putSeriesTitle(std::string theSeries);

     int getVolume() const;
     void putVolume(int);
   private:
     std::string seriesTitle;
     int volume;
};
