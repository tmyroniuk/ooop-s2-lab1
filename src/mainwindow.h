#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "listmodel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_typeBox_currentIndexChanged(int index);

    void on_listBox_currentIndexChanged(int index);

    void on_sortBox_currentIndexChanged(int index);

    void on_sortButton_clicked();

    void on_insertButton_clicked();

    void on_removeButton_clicked();

    void on_clearButton_clicked();

    void on_randButton_clicked();

private:
    Ui::MainWindow *ui;

    template<typename T> void createModel();

signals:
    void clear();

    void sort();
};
#endif // MAINWINDOW_H
