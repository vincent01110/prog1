/*
    g++ lines_main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o lines_main `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
    Lines_window win {Point{100,100}, 600, 400, "Lines"};

    return gui_main();
}
