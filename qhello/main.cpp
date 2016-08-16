#include <QApplication>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setText("Press <b>button</b> to close");
    w.show();

    return a.exec();
}
