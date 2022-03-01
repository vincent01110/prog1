/* g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` */

#include "Graph.h"
#include "Simple_window.h"

double one(double x){
  return 1;
}

double slope(double x){
  return x/2;
}

double square(double x){
  return x*x;
}

double sloping_cos(double x){
  return slope(cos(x));
}



int main() {
  using namespace Graph_lib;

  Simple_window win{Point{100,100}, 600, 600, "Function graphs"};
  Axis ax{Axis::x, Point{100,300}, 400, 20, "1==20pixels"};
  Axis ay{Axis::y, Point{300,500}, 400, 20, "1==20pixels"};
  ax.set_color(Color::red);
  ay.set_color(Color::red);

  Function s_one{one, -10, 11, Point{300, 300}, 400, 20, 20};
  Function s_slope{slope, -10, 11, Point{300, 300}, 400, 20, 20};
  Text slope_text{Point{100, 385}, "x/2"};
  Function s_square{square, -10, 11, Point{300, 300}, 400, 20, 20};
  Function s_cosine{cos, -10, 11, Point{300, 300}, 400, 20, 20};
  s_cosine.set_color(Color::blue);
  Function slope_cos{sloping_cos, -10, 11, Point{300, 300}, 400, 20, 20};

  
  win.attach(slope_cos);
  win.attach(s_cosine);
  win.attach(s_square);
  win.attach(slope_text);
  win.attach(s_one);
  win.attach(s_slope);
  win.attach(ax);
  win.attach(ay);
  win.wait_for_button();
}
