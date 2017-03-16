#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_opeDirectory_clicked()
{
    QFileDialog dialog(this);
      dialog.setFileMode(QFileDialog::DirectoryOnly);

    mainWin =new MainWindow(this);
    mainWin->set_dir(QFileDialog::getExistingDirectory(this)) ;
    mainWin->show();
    this->hide();
}
