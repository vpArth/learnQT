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

protected:
    void setFilename(QString fileName);
    bool confirm();
    bool openFile(QString fileName);
    bool saveFile(QString fileName);

private slots:
    void create();
    bool open();
    bool save();
    bool saveAs();
    void quit();

private:
    QString fn;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
