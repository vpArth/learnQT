#include <QApplication>
#include "mDialog.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    mDialog dialog("Press <b>button</b> to close");
    dialog.show();

    return app.exec();
}
