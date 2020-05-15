#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_typeBox_currentIndexChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui->listView->model();
    delete ui;
}

void MainWindow::on_typeBox_currentIndexChanged(int index)
{
    auto temp = ui->listView->model();
    switch (index) {
        case 0: createModel<int>(); break;
        case 1: createModel<double>(); break;
        case 2: createModel<std::string>(); break;
        case 3: createModel<IPv4>(); break;
        case 4: createModel<IPv6>(); break;
        case 5: createModel<MAC>(); break;
    }
    if(temp && temp != ui->listView->model()) delete temp;
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
    ui->listView->model()->insertRow(index.row());
    ui->listView->model()->setData(index.sibling(index.row() + 1, index.column()), ui->lineEdit->text(), Qt::DisplayRole);
}

void MainWindow::on_removeButton_clicked()
{
    ui->listView->model()->removeRow(ui->listView->currentIndex().row());
}

template<typename T>
void MainWindow::createModel()
{
    auto model = new ListModel<T>;
    connect(ui->sortButton, &QPushButton::clicked,  model, &ListModel<T>::sort);
    connect(ui->clearButton, &QPushButton::clicked, model, &ListModel<T>::clear);
    ui->listView->setModel(model);
}

void MainWindow::on_randButton_clicked()
{
    ui->lineEdit->setText(ui->listView->model()->data(QModelIndex(), RandomRole).toString());
}
