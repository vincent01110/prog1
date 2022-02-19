/* g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` */

#include "Graph.h"
#include "Simple_window.h"


int main() {
  using namespace Graph_lib;

  int winx=600, winy=400;
  Simple_window win {Point{100,100}, 600, 400, "My window"};

  Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};

  Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
  ya.set_color(Color::cyan);
  ya.label.set_color(Color::dark_red);

  Function sine {sin, 0, 100, Point{20,150}, 1000, 50, 50};
  sine.set_color(Color::blue);

  Polygon poly;
  poly.add(Point{310,210});
  poly.add(Point{360,110});
  poly.add(Point{410,210});
  poly.set_color(Color::dark_magenta);
  poly.set_style(Line_style(Line_style::dot, 4));

  Rectangle r{Point{200,200}, 100, 50};
  r.set_fill_color(Color::yellow);

  Closed_polyline poly_rect;
  poly_rect.add(Point{100,50});
  poly_rect.add(Point{200,50});
  poly_rect.add(Point{200,100});
  poly_rect.add(Point{100,100});
  poly_rect.add(Point{50,75});
  poly_rect.set_style(Line_style(Line_style::dash,10));
  poly_rect.set_fill_color(Color::green);

  Text t{Point{150, 150}, "Hello, graphical world!"};
  t.set_font(Font::times_bold_italic);
  t.set_font_size(20);

  Image ii{Point{20,20}, "cat.jpg"};

  Circle c{Point{100,200}, 50};
  Ellipse e{Point{100,200}, 75, 25};
  e.set_color(Color::dark_red);
  Mark m{Point{100,200}, 'x'};

  ostringstream oss;
  oss << "screen size: " << x_max() << "*" << y_max() << "; window size: "
      << win.x_max() << "*" << win.y_max();
  Text sizes{Point{100,20}, oss.str()};

  Image cal{Point{225,225}, "badge.jpg"};
  cal.set_mask(Point{40,40}, 200, 150);


  win.attach(ii);
  win.attach(xa);
  win.attach(ya);
  win.attach(sine);
  win.attach(poly);
  win.attach(r);
  win.attach(poly_rect);
  win.attach(t);

  win.attach(c);
  win.attach(m);
  win.attach(e);
  win.attach(sizes);
  win.attach(cal);
  win.wait_for_button();

}
