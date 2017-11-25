#include "wdo.h"

WDO::WDO(QWidget *parent)
:QOpenGLWidget(parent)
{
}

void WDO::initializeGL()
{
}


void WDO::paintGL()
{
  glClearColor(0.0, 0.0, 1.0, 1.0); // blue background
  glColor3f(1.0, 0.0, 0.0);         // red foreground

  glBegin(GL_TRIANGLES);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f( 0.5, -0.5, 0.0);
    glVertex3f( 0.0,  0.5, 0.0);
  glEnd();
}


void WDO::resizeGL(int width, int height)
{
}


