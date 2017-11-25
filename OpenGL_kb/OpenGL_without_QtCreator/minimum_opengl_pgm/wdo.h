#include <QOpenGLWidget>

class WDO : public QOpenGLWidget
{
  Q_OBJECT
  public:
    WDO(QWidget *parent = 0);

  protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
};
