#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void set_dir(QString);

private slots:
    void on_openButton_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);


    void on_soundButton_clicked();

    void on_picButton_clicked();

    void on_videoButton_clicked();

    void on_docButton_clicked();

private:
    Ui::MainWindow *ui;
    QString dir;

    enum Mode{sound=1, picture=2, video=3, document=4};
    Mode mode;
};

#endif // MAINWINDOW_H
