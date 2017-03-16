#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFileDialog>
#include <QListView>
#include <QStringListModel>
#include <QPixmap>

#include <QtMultimediaWidgets/QVideoWidget>
#include <QMessageBox>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //player = new QMediaPlayer;


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::set_dir(QString dirPath)
{
    dir=dirPath;
}

void MainWindow::on_openButton_clicked()
{
    QFileDialog dialog(this);
      dialog.setFileMode(QFileDialog::DirectoryOnly);
    dir= dialog.getExistingDirectory(this);

}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{

}

void MainWindow::on_soundButton_clicked()
{
    mode = sound;
    QStringListModel  *model = new QStringListModel;
    QStringList sounds;sounds << "*.mp3"<<"*.wav";
    QDirIterator it1(dir, sounds, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    int count=0;
    QStringList list;
    while (it1.hasNext()){
        count++;
        if (count> 500) break;
        list<< it1.next();
    }
    ui->soundLabel->setNum(count);
    model->setStringList(list);
    ui->listView->setModel(model);
}

void MainWindow::on_picButton_clicked()
{
    mode = picture;
    QStringListModel  *model = new QStringListModel;
    QStringList pics;pics << "*.jpg"<<"*.ejpg";
    QDirIterator it1(dir, pics, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    int count=0;
    QStringList list;
    while (it1.hasNext()){
        count++;
        if (count> 500) break;
        list<< it1.next();
    }
    ui->picLabel->setNum(count);
    model->setStringList(list);
    ui->listView->setModel(model);
}

void MainWindow::on_videoButton_clicked()
{
    mode = video;
    QStringListModel  *model = new QStringListModel;
    QStringList videos;videos << "*.mp4" << "*.wmv";
    QDirIterator it1(dir, videos, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    int count=0;
    QStringList list;
    while (it1.hasNext()){
        count++;
        if (count> 500) break;
        list<< it1.next();
    }
    ui->videoLabel->setNum(count);
    model->setStringList(list);
    ui->listView->setModel(model);
}

void MainWindow::on_docButton_clicked()
{
    mode = document;
    QStringListModel  *model = new QStringListModel;
    QStringList docs;docs << "*.pdf"<<"*.txt"<<"*.rtf";
    QDirIterator it1(dir, docs, QDir::NoDotAndDotDot | QDir::Files, QDirIterator::Subdirectories);
    int count=0;
    QStringList list;
    while (it1.hasNext()){
        count++;
        if (count> 500) break;
        list<< it1.next();
    }
    ui->docLabel->setNum(count);
    model->setStringList(list);
    ui->listView->setModel(model);
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    switch (mode) {
        /*case sound:

            break;*/
        case picture:
        {
            QPixmap pix(index.data().toString());
            int w =ui->view->width();
            int h =ui->view->height();
            ui->view->setPixmap((pix.scaled(w,h,Qt::KeepAspectRatio)));
            break;
        }
        case sound:
        case video:
        {
            /*player->stop();
            QVideoWidget *videoWidget = new QVideoWidget(this);
            ui->horizontalLayout_3-> addWidget(videoWidget);

                player->setMedia(QUrl::fromLocalFile(index.data().toString()));
                player->setVolume(50);
            player->setVideoOutput(videoWidget);
            videoWidget->show();
            player->play();*/


                QDesktopServices::openUrl(QUrl::fromLocalFile(index.data().toString()));

            break;
        }
        case document:
        {
            if(index.data().toString() == "*.pdf"){
                qDebug()<< index.data().toString();
                QDesktopServices::openUrl(QUrl::fromLocalFile(index.data().toString()));
            }else{
                qDebug()<< "else" <<index.data().toString();
                QDesktopServices::openUrl(QUrl::fromLocalFile(index.data().toString()));
                /*QFile file(index.data().toString());

                if (!file.open(QFile::ReadOnly | QFile::Text)){
                    QMessageBox::warning(this,"..","file not open");
                    return;
                }
                QTextStream in(&file);
                QString text = in.readAll();
                ui->view->setText(text);
                file.close();*/
            }
            break;
        }
        default:
            break;
    }
}
