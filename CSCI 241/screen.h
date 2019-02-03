#ifndef SCREEN_H
#define SCREEN_H


class Screen
  {
  static const int MAX_ROW = 23,
                   MAX_COL = 75;
  public:
  Screen();
  
  const void clear();
  const void print();
  const void set(int, int);
  const void plot(int, int, char);
  const void write(char*);
  
  private:
  char array[MAX_ROW][MAX_COL];
  int cur_row,
      cur_col;
  };

#endif /* SCREEN_H */
