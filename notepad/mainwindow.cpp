#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addAction(ui->actionNew);
    addAction(ui->actionOpen);
    addAction(ui->actionSave);
    addAction(ui->actionSave_as);
    addAction(ui->actionQuit);

    saved = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create()
{
    if (!canReplace()) return;
    saved = true;
    fn = "";
    ui->textEdit->setText("");
}

bool MainWindow::canReplace()
{
    if (!saved) {
        // todo: confirmation dialog(save/not save/cancel)
        //return false; // on cancel
    }
    return true;
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

        if (!canReplace()) return;

        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
        fn = fileName;
        saved = true;
    }
}

void MainWindow::save()
{
    if (fn == "") return saveAs();
    if (saved) return;
    QFile file(fn);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not save to file"));
    } else {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        stream.flush();
        file.close();
        saved = true;
    }
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        fn = fileName;
        save();
    }
}

void MainWindow::quit()
{
    close();
}

void MainWindow::modified()
{
    saved = false;
}
