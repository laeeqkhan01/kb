#ifndef GL_WGT_1_H
#define GL_WGT_1_H
#include <QOpenGLWidget>

class GL_Wgt_1 : public QOpenGLWidget
{
public:
    GL_Wgt_1(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // GL_WGT_1_H
