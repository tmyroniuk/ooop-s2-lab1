#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto model = new GenericListModel;
    connect(ui->sortButton, &QPushButton::clicked,  model, &GenericListModel::execSort);
    connect(ui->clearButton, &QPushButton::clicked, model, &GenericListModel::clear);
    connect(ui->typeBox, qOverload<int>(&QComboBox::currentIndexChanged), model, &GenericListModel::setType);
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui->listView->model();
    delete ui;
}

void MainWindow::on_listBox_currentIndexChanged(int index)
{
    ui->listView->model()->setData(QModelIndex(), index, ListRole);
}

void MainWindow::on_sortBox_currentIndexChanged(int index)
{
    ui->listView->model()->setData(QModelIndex(), index, SortRole);
}

void MainWindow::on_insertButton_clicked()
{
    auto index = ui->listView->currentIndex();
    if(index.row() < 0) return;
    ui->listView->model()->insertRows(index.row(), 1);
    ui->listView->model()->setData(index, ui->lineEdit->text(), Qt::DisplayRole);
    if(ui->listView->model()->rowCount() > 1) {
        ui->typeBox->setEnabled(false);
        ui->listBox->setEnabled(false);
    }
}

void MainWindow::on_removeButton_clicked()
{
    auto index = ui->listView->currentIndex();
    if(index.row() < 0) return;
    ui->listView->model()->removeRow(index.row());
    if(ui->listView->model()->rowCount() == 1) {
        ui->typeBox->setEnabled(true);
        ui->listBox->setEnabled(true);
    }
}

void MainWindow::on_randButton_clicked()
{
    ui->lineEdit->setText(ui->listView->model()->data(QModelIndex(), RandomRole).toString());
}

void MainWindow::on_clearButton_clicked()
{
    ui->typeBox->setEnabled(true);
    ui->listBox->setEnabled(true);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 == "") ui->insertButton->setEnabled(false);
    else ui->insertButton->setEnabled(true);
}
