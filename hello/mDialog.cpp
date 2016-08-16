#include "mDialog.h"

void mDialog::buildGUI(const char* msg)
{
    lyVBox = new QVBoxLayout(this);
    lbHello = new QLabel(this);
    btnClose = new QPushButton(this);

    lbHello->setText(msg);
    btnClose->setText("Close");

    lyVBox->addWidget(lbHello);
    lyVBox->addWidget(btnClose);

    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

mDialog::mDialog(QWidget *parent) : QDialog(parent) {
    mDialog("<font color=red>Hello, World!</font>", parent);
}

mDialog::mDialog(const char* msg, QWidget *parent) : QDialog(parent) {
    buildGUI(msg);
}



mDialog::~mDialog() {
    delete btnClose;
    delete lbHello;
    delete lyVBox;
}
