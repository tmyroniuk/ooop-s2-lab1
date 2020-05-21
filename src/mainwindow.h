#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "genericlistmodel.h"

#include <QMainWindow>
#include <QComboBox>

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
    void on_listBox_currentIndexChanged(int index);

    void on_sortBox_currentIndexChanged(int index);

    void on_insertButton_clicked();

    void on_removeButton_clicked();

    void on_randButton_clicked();

    void on_clearButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
