//
// qmake -project
// qmake
// make
//
// Illustrates use of Qt Timer
// Changes a Labels text and position
// every three seconds.
//

#include <QApplication>
#include "Wdo.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Wdo w;
  w.resize(640, 480);
  w.setWindowTitle("Test - 9");
  w.show();

  return a.exec();
}
