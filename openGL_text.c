//
// gcc  openGL_text.c  -lGL  -lGLU   -lglut
//
// Program demonstrates procedure
// to draw text using OpenGL, glut
//

#include <GL/glut.h>

void myDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 0, 0);

  // Draw a bitmap char
  glRasterPos3f(0.0, 0.0, 0.0);  // draw char in center
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');

  // Draw some points, unrelated to text
  glPointSize(5);
  glBegin(GL_POINTS);
    // glVertex2f(0.0, 0.0);  // center
    glVertex2f(0.9, 0.9); // near top right corner
  glEnd();

  glFlush();
}


void main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 600);
  glutCreateWindow("OpenGL Text - 1");

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearColor(0, 0, 0, 1);  // black background color
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(myDisplay);

  glutMainLoop();
}
