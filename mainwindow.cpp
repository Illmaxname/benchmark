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


    //Calculate test
    int timeStart = clock();

    long calc = 0;
    for(int count = 0; count < 99999; count++){
        calc += 9;
        calc++;
        calc++;
    }

    int res = clock()-timeStart;
    QString valueAsString = QString::number(res*5);
    ui->listWidget->addItem("Calculate time->");
    ui->listWidget->addItem(valueAsString);

    int timeStartDT = clock();

    RadialGradient *windowDT = new RadialGradient;
    windowDT->show();

    int resDT = clock()-timeStartDT;
    windowDT->hide();

    //Print test
    int timeStart2 = clock();

    RadialGradient *window2 = new RadialGradient;
    window2->show();

    int res2 = clock()-timeStart2;
    QString valueAsString2 = QString::number(res2*4);
    ui->listWidget->addItem("Print time->");
    ui->listWidget->addItem(valueAsString2);
    window2->hide();

    //Write-Read test
    int timeStart3 = clock();
    QTextStream out(stdout);

      QString filename = "distros.txt";
      QFile file(filename);

      if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);

        for(int count = 0; count<50; count++){
        out << "Xubuntu" << endl;
        out << "Arch" << endl;
        out << "Debian" << endl;
        out << "Redhat" << endl;
        out << "Slackware" << endl;
        }

      } else qWarning("Could not open file");

      file.close();
      int res3 = clock()-timeStart3;
      QString valueAsString3 = QString::number(res3*4);
      ui->listWidget->addItem("Write time->");
      ui->listWidget->addItem(valueAsString3);

      int timeStart4 = clock();
      QTextStream out2(stdout);

        QFile file2("distros.txt");

        if (!file2.open(QIODevice::ReadOnly)) {
          qWarning("Cannot open file for reading");
        }

        QTextStream in2(&file2);

        while (!in2.atEnd()) {
          QString line = in2.readLine();
          //ui->listWidget_2->addItem(line);
        }

        file2.close();
        int res4 = clock()-timeStart4;
        QString valueAsString4 = QString::number(res4*5);
        ui->listWidget->addItem("Read time->");
        ui->listWidget->addItem(valueAsString4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonStart_clicked()
{
    ui->listWidget->addItem("\n----New test----");
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
    window2->hide();

    //Write-Read test
    int timeStart3 = clock();
    QTextStream out(stdout);

      QString filename = "distros.txt";
      QFile file(filename);

      if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);

        for(int count = 0; count<50; count++){
        out << "Xubuntu" << endl;
        out << "Arch" << endl;
        out << "Debian" << endl;
        out << "Redhat" << endl;
        out << "Slackware" << endl;
        }

      } else qWarning("Could not open file");

      file.close();
      int res3 = clock()-timeStart3;
      QString valueAsString3 = QString::number(res3);
      ui->listWidget->addItem("Write time->");
      ui->listWidget->addItem(valueAsString3);

      int timeStart4 = clock();
      QTextStream out2(stdout);

        QFile file2("distros.txt");

        if (!file2.open(QIODevice::ReadOnly)) {
          qWarning("Cannot open file for reading");
        }

        QTextStream in2(&file2);

        while (!in2.atEnd()) {
          QString line = in2.readLine();
          //ui->listWidget_2->addItem(line);
        }

        file2.close();
        int res4 = clock()-timeStart4;
        QString valueAsString4 = QString::number(res4);
        ui->listWidget->addItem("Read time->");
        ui->listWidget->addItem(valueAsString4);
}

