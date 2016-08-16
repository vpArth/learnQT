#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void create();
    void open();
    void save();
    void saveAs();
    void quit();

    void modified();
private:
    QString fn;
    bool saved;
    Ui::MainWindow *ui;
    bool canReplace();
};

#endif // MAINWINDOW_H
