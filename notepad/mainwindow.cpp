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

    if (argc>1) {
        open();
    }
    create();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create()
{
    QTextDocument *doc = ui->textEdit->document();
    if (!confirm()) return;
    fn = "";
    setWindowTitle("Notepad - untitled.txt");
    doc->clear();
    doc->setModified(false);
}

bool MainWindow::confirm()
{
    QTextDocument *doc = ui->textEdit->document();
    if (doc->isModified()) {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        switch (msgBox.exec()) {
          case QMessageBox::Save:
              return save();
          case QMessageBox::Discard:
              return true;
          case QMessageBox::Cancel:
              return false;
        }
    }
    return true;
}

bool MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));


    bool ret = fileName != "";
    if (ret) {
        openFile(fileName);
    }
    return ret;
}

bool MainWindow::save()
{
    if (fn == "") return saveAs();
    return saveFile(fn);
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        return saveFile(fileName);
    }
    return false;
}

void MainWindow::quit()
{
    close();
}

// protected

void MainWindow::setFilename(QString fileName)
{
    if (fn != fileName) {
        fn = fileName;
        setWindowTitle("Notepad - "+fileName);
    }
}

bool MainWindow::openFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return false;
    }

    if (!confirm()) return false;

    QTextStream in(&file);
    ui->textEdit->document()->setPlainText(in.readAll());
    ui->textEdit->document()->setModified(false);

    file.close();

    setFilename(fileName);
    return true;
}

bool MainWindow::saveFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not save to file"));
    } else {
        QTextStream stream(&file);
        stream << ui->textEdit->document()->toPlainText();
        stream.flush();
        file.close();

        ui->textEdit->document()->setModified(false);
        setFilename(fileName);
        return true;
    }
    return false;
}

