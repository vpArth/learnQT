#include <QApplication>
#include <QDialog>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QDialog *dialog = new QDialog;
    QLabel *label = new QLabel(dialog);
    label->setText("<font color=red>Hello, World!</font>");
    dialog->show();

    int ret = app.exec();

    delete label;
    delete dialog;
    return ret;
}
