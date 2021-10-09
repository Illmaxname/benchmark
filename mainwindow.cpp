#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "print.h"
#include <QApplication>
#include <time.h>
#include <QTextStream>
#include <QFile>
#include <cmath>

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
    //PC1 times
    QTableWidgetItem* calc0 = new QTableWidgetItem();calc0->setData(Qt::DisplayRole, 2221);
    QTableWidgetItem* print0 = new QTableWidgetItem();print0->setData(Qt::DisplayRole, 1459);
    QTableWidgetItem* wr0 = new QTableWidgetItem();wr0->setData(Qt::DisplayRole, 1739);
    QTableWidgetItem* I0 = new QTableWidgetItem();I0->setData(Qt::DisplayRole, 1779);

    ui->tableWidget_times->setItem(0,0,calc0);
    ui->tableWidget_times->setItem(0,1,print0);
    ui->tableWidget_times->setItem(0,2,wr0);
    ui->tableWidget_times->setItem(0,3,I0);

    //PC2 times
    QTableWidgetItem* calc1 = new QTableWidgetItem();calc1->setData(Qt::DisplayRole, 2128);
    QTableWidgetItem* print1 = new QTableWidgetItem();print1->setData(Qt::DisplayRole, 3165);
    QTableWidgetItem* wr1 = new QTableWidgetItem();wr1->setData(Qt::DisplayRole, 1906);
    QTableWidgetItem* I1 = new QTableWidgetItem();I1->setData(Qt::DisplayRole, 2341);

    ui->tableWidget_times->setItem(1,0,calc1);
    ui->tableWidget_times->setItem(1,1,print1);
    ui->tableWidget_times->setItem(1,2,wr1);
    ui->tableWidget_times->setItem(1,3,I1);

    //PC3 times
    QTableWidgetItem* calc2 = new QTableWidgetItem();calc2->setData(Qt::DisplayRole, 2162);
    QTableWidgetItem* print2 = new QTableWidgetItem();print2->setData(Qt::DisplayRole, 1930);
    QTableWidgetItem* wr2 = new QTableWidgetItem();wr2->setData(Qt::DisplayRole, 2574);
    QTableWidgetItem* I2 = new QTableWidgetItem();I2->setData(Qt::DisplayRole, 2206);

    ui->tableWidget_times->setItem(2,0,calc2);
    ui->tableWidget_times->setItem(2,1,print2);
    ui->tableWidget_times->setItem(2,2,wr2);
    ui->tableWidget_times->setItem(2,3,I2);

    //MyPC
    //Calculate test
    int timeStart = clock();

    long calc = 0;
    for(int count = 0; count < 99999; count++){
        calc += 9;
        calc++;
        calc++;
    }

    double res = clock()-timeStart;

    QTableWidgetItem* calc3 = new QTableWidgetItem();
    calc3->setData(Qt::DisplayRole, res);
    ui->tableWidget_times->setItem(3,0,calc3);

    //Print test
    int timeStart2 = clock();

    RadialGradient *window2 = new RadialGradient;
    window2->show();

    double res2 = clock()-timeStart2;
    QTableWidgetItem* print3 = new QTableWidgetItem();
    print3->setData(Qt::DisplayRole, res2);
    ui->tableWidget_times->setItem(3,1,print3);
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
      double res3 = clock()-timeStart3;

      int timeStart4 = clock();
      QTextStream out2(stdout);

        QFile file2("distros.txt");

        if (!file2.open(QIODevice::ReadOnly)) {
          qWarning("Cannot open file for reading");
        }

        QTextStream in2(&file2);

        while (!in2.atEnd()) {
          QString line = in2.readLine();
        }

        file2.close();
        double res4 = clock()-timeStart4;
        QTableWidgetItem* wr3 = new QTableWidgetItem();
        wr3->setData(Qt::DisplayRole, res3+res4);
        ui->tableWidget_times->setItem(3,2,wr3);

        int I = pow(res*res2*(res3+res4),1./3.);

        QTableWidgetItem* I3 = new QTableWidgetItem();
        I3->setData(Qt::DisplayRole, I);
        ui->tableWidget_times->setItem(3,3,I3);

        //PC1
        QTableWidgetItem* calc_0 = new QTableWidgetItem();calc_0->setData(Qt::DisplayRole, 1.04);
        QTableWidgetItem* print_0 = new QTableWidgetItem();print_0->setData(Qt::DisplayRole, 0.46);
        QTableWidgetItem* wr_0 = new QTableWidgetItem();wr_0->setData(Qt::DisplayRole, 0.91);
        QTableWidgetItem* I_0 = new QTableWidgetItem();I_0->setData(Qt::DisplayRole, 0.76);

        ui->tableWidget_map->setItem(0,0,calc_0);
        ui->tableWidget_map->setItem(0,1,print_0);
        ui->tableWidget_map->setItem(0,2,wr_0);
        ui->tableWidget_map->setItem(0,3,I_0);

        //PC2 times
        QTableWidgetItem* calc_1 = new QTableWidgetItem();calc_1->setData(Qt::DisplayRole, 1);
        QTableWidgetItem* print_1 = new QTableWidgetItem();print_1->setData(Qt::DisplayRole, 1);
        QTableWidgetItem* wr_1 = new QTableWidgetItem();wr_1->setData(Qt::DisplayRole, 1);
        QTableWidgetItem* I_1 = new QTableWidgetItem();I_1->setData(Qt::DisplayRole, 1);

        ui->tableWidget_map->setItem(1,0,calc_1);
        ui->tableWidget_map->setItem(1,1,print_1);
        ui->tableWidget_map->setItem(1,2,wr_1);
        ui->tableWidget_map->setItem(1,3,I_1);

        //PC3 times
        QTableWidgetItem* calc_2 = new QTableWidgetItem();calc_2->setData(Qt::DisplayRole, 1.01);
        QTableWidgetItem* print_2 = new QTableWidgetItem();print_2->setData(Qt::DisplayRole, 0.61);
        QTableWidgetItem* wr_2 = new QTableWidgetItem();wr_2->setData(Qt::DisplayRole, 1.35);
        QTableWidgetItem* I_2 = new QTableWidgetItem();I_2->setData(Qt::DisplayRole, 0.94);

        ui->tableWidget_map->setItem(2,0,calc_2);
        ui->tableWidget_map->setItem(2,1,print_2);
        ui->tableWidget_map->setItem(2,2,wr_2);
        ui->tableWidget_map->setItem(2,3,I_2);


        QTableWidgetItem* calc_my = new QTableWidgetItem();calc_my->setData(Qt::DisplayRole, res/2128);
        QTableWidgetItem* print_my = new QTableWidgetItem();print_my->setData(Qt::DisplayRole, res2/3165);
        QTableWidgetItem* wr_my = new QTableWidgetItem();wr_my->setData(Qt::DisplayRole, (res3+res4)/1906);
        QTableWidgetItem* I_my = new QTableWidgetItem();I_my->setData(Qt::DisplayRole, pow(res/2128*res2/3165*(res3+res4)/1906,1./3.));

        ui->tableWidget_map->setItem(3,0,calc_my);
        ui->tableWidget_map->setItem(3,1,print_my);
        ui->tableWidget_map->setItem(3,2,wr_my);
        ui->tableWidget_map->setItem(3,3,I_my);
}


