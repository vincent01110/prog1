#include "Graph.h"
#include "Simple_window.h"

int main() {

  using namespace Graph_lib;

  Simple_window win{Point{100,100}, 800, 1000, "Ch13"};

  Lines grid;
  int x_size = win.x_max();
  int y_size = win.y_max();

  for (int x = 100; x < x_size; x+=100) {
    grid.add(Point{x,0}, Point{x,y_size});
  }

  for (int y = 100; y < y_size; y+=100) {
    grid.add(Point{0,y}, Point{x_size,y});
  }
  win.attach(grid);

  Vector_ref<Rectangle> vr;
  for (int i = 0; i <= x_size-100; i+=100) {
    vr.push_back(new Rectangle {Point{i,i}, 100,100});
    vr[vr.size()-1].set_color(Color::red);
    vr[vr.size()-1].set_style(Line_style(Line_style::solid, 4));
    win.attach(vr[vr.size()-1]);
  }

  /*Vector_ref<Image> iv;
  for (i = 0; i <= x_size-100; i+=100) {
    iv.push_back(new Image{Point{i,i}, "cat.jpg"});
    win.attach(iv[iv.size()-1]);
  }*/

  Image img{Point{0,400}, "cat.jpg"};
  img.set_mask(Point{20,100}, 200, 200);
  Image img2{Point{400,0}, "cat.jpg"};
  img2.set_mask(Point{20,100}, 200, 200);
  Image img3{Point{300,700}, "cat.jpg"};
  img3.set_mask(Point{20,100}, 200, 200);
  win.attach(img);
  win.attach(img2);
  win.attach(img3);

  int i,j;
  Image img_gru{Point{0,0}, "gru_re.jpg"};
  win.attach(img_gru);
  for (i = 0; i <= y_size-100; i+=100) {
    for (j = 0; j <= x_size-100; j+=100) {
      win.wait_for_button();
      img_gru.move(100, 0);
      win.attach(img_gru);
    }
    img_gru.move(-x_size, 100);
  }

  win.wait_for_button();

}
