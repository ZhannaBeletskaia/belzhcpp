#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

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

void MainWindow::on_btnSquare_clicked()
{
    ui->widget->currentMode = Mode::DrawRectangle;
    unsetCursor();
}


void MainWindow::on_pushButton_clicked()
{
    ui->widget->currentMode = Mode::DrawCircle;
    unsetCursor();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->currentMode = Mode::DrawTriangle;
    unsetCursor();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->currentMode = Mode::Move;
    setCursor(Qt::PointingHandCursor);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->widget->currentMode = Mode::Link;
    unsetCursor();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->widget->currentMode = Mode::Delete;
    unsetCursor();
}


void MainWindow::on_pushButton_6_clicked()
{
    unsetCursor();
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Shapes (*.dat)");
    if (!fileName.isEmpty())
        ui->widget->saveToFile(fileName);
}


void MainWindow::on_pushButton_7_clicked()
{
    unsetCursor();
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Shapes (*.dat)");
    if (!fileName.isEmpty())
        ui->widget->loadFromFile(fileName);
}

