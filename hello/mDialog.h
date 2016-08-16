#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include <string>

class mDialog : public QDialog {
    Q_OBJECT
private:
  QVBoxLayout *lyVBox;
  QLabel *lbHello;
  QPushButton *btnClose;
public:
  mDialog(QWidget *parent = 0);
  mDialog(const char* msg, QWidget *parent = 0);
  void buildGUI(const char* msg);
  virtual ~mDialog();
};
