#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "print.h"
#include <QApplication>
#include <time.h>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonStart_clicked()
{
    //Calculate test
    int timeStart = clock();

    long calc = 0;
    for(int count = 0; count < 99999; count++){
        calc += 9;
        calc++;
        calc++;
    }

    int res = clock()-timeStart;
    QString valueAsString = QString::number(res);
    ui->listWidget->addItem("Calculate time->");
    ui->listWidget->addItem(valueAsString);

    //Print test
    int timeStart2 = clock();

    RadialGradient *window2 = new RadialGradient;
    window2->show();

    int res2 = clock()-timeStart2;
    QString valueAsString2 = QString::number(res2);
    ui->listWidget->addItem("Print time->");
    ui->listWidget->addItem(valueAsString2);

    //Write-Read test
    int timeStart3 = clock();
    QTextStream out(stdout);

      // Создаем объект класса QFile и связываем его с указанным именем файла
      QString filename = "distros.txt";
      QFile file(filename);

      // Открываем файл в режиме "Только для записи"
      if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file); // поток записываемых данных направляем в файл

        // Для записи данных в файл используем оператор <<
        for(int count = 0; count<50; count++){
        out << "Xubuntu" << endl;
        out << "Arch" << endl;
        out << "Debian" << endl;
        out << "Redhat" << endl;
        out << "Slackware" << endl;
        }

      } else {
        qWarning("Could not open file");
      }

      // Закрываем файл
      file.close();
      int res3 = clock()-timeStart3;
      QString valueAsString3 = QString::number(res3);
      ui->listWidget->addItem("Write time->");
      ui->listWidget->addItem(valueAsString3);
}

