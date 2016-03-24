#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QList>
#include <QVariant>
#include <QFile>
#include <QMessageBox>

#include <memory>

#include "tablemodel.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

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

private:
    Ui::MainWindow *ui;

    QString fileName;
    QList<QStringList> CSVdata;
    TableModel* model;

    bool readCSVfromFile(QString fileName);
    void setupModel(QString fileName);
};

#endif // MAINWINDOW_H
