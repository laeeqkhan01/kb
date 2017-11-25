#include "gl_wgt_1.h"


GL_Wgt_1::GL_Wgt_1(QWidget *parent)
    :QOpenGLWidget(parent)
{

}

void GL_Wgt_1::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GL_Wgt_1::resizeGL(int w, int h)
{
    (void)w;
    (void)h;
}

void GL_Wgt_1::paintGL()
{
    // glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glVertex3f(-1.0f,  -1.0f , 0.0f);
        glVertex3f( 1.0f,  -1.0f , 0.0f);
        glVertex3f( 0.0f,   1.0f , 0.0f);
    glEnd();
}
