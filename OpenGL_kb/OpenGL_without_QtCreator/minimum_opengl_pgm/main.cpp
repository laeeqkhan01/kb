
//
// qmake -project
// .pro file will be generated
// In .pro file add following line
// QT += opengl
// qmake
// Makefile will be generated
// make
//

#include <QApplication>
#include "wdo.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  WDO w;
  w.show();

  return app.exec();
}

