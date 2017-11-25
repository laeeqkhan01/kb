
//
// gcc  simplest_OpenGL_1.c  -lGL  -lGLU   -lglut
// This simplest OpenGL program in C
//

#include <GL/glut.h>
#include <stdio.h>

void myDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 0, 0);   // draw with red color
  glPointSize(5);       // Make points a little thick

  glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);  // Center of window
    glVertex2f(0.9, 0.9);  // Near top right corner
  glEnd();

  glFlush();
}


void main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Test - 1");

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearColor(0, 0, 0, 1);  // Black background
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(myDisplay);

  glutMainLoop();
}
