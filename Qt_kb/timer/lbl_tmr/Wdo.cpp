#include "Wdo.h"

const char *meh[] =
{ "Kabaree", "Maal", "TanBeta", "NumberTeen" };

int idx = 0;

Wdo::Wdo(QWidget *parent)
:QWidget(parent)
{
  lbl_1 = new QLabel("ABCD", this);
  // lbl_1 = new QLabel(meh[idx], this);
  lbl_1->setGeometry(50, 50, 100, 40);

  ticker = new QTimer(this);
  connect(ticker, SIGNAL(timeout()), this, SLOT(updt()));
  ticker->start(3000);
}

void Wdo::updt()
{
  lbl_1->setText(meh[idx]);

  idx++;
  if(idx >= 4)
    idx = 0;

  if(idx%2 == 0)
    lbl_1->move(10, 400);
  else
    lbl_1->move(100, 100);
}
