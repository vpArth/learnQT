#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QLabel l("Hello, World!");
    l.show();
    return a.exec();
}
