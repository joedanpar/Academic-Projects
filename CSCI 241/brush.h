#ifndef BRUSH_H
#define BRUSH_H


class Brush
  {
  public:
  Brush();
  
  const void set_color(char&);
  const void set_size(int&, int&);
  const void draw_position(Screen&, int&, int&);
  const void draw_left(Screen&);
  const void draw_right(Screen&);
  const void draw_up(Screen&);
  const void draw_down(Screen&);
  const void draw_up_left(Screen&);
  const void draw_up_right(Screen&);
  const void draw_down_left(Screen&);
  const void draw_down_right(Screen&);
  
  private:
  const void draw(Screen&);
  
  char color;
  int row_pos,
      col_pos,
      width,
      height;
  };

#endif /* BRUSH_H */
