#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QList>
#include <QLabel>
#include <QFile>
#include <QMessageBox>

#include "headers/tablemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionFirst_row_as_heading_toggled(bool arg1);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QString fileName;
    QList<QStringList> CSVdata;
    TableModel* model;

    QLabel *statusBarPos;

    bool readCSVfromFile(QString fileName);
    void setupModel(bool heading = false);
    void setupStatusBar();
};

#endif // MAINWINDOW_H
