#include <QWidget>
#include <QLabel>
#include <QTimer>

class Wdo : public QWidget
{
  Q_OBJECT
  public:
    Wdo(QWidget *parent = 0);
    QLabel *lbl_1;
    QTimer *ticker;

  public slots:
    void updt();
};
