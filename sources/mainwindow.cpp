#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this);

    setupModel(fileName);
}

bool MainWindow::readCSVfromFile(QString fileName)
{
    CSVdata.clear();
    if(fileName.isEmpty())
    {
        QMessageBox::information(this, "Error!", "No file name specified", QMessageBox::Close);
        return false;
    }

    QFile csv(fileName);

    if(!csv.open(QFile::ReadOnly))
    {
        QMessageBox::information(this, "Error!", "Couldn't open", QMessageBox::Close);
        return false;
    }

    QString fileData = csv.readAll();

    QStringList lines = fileData.split("\n", QString::SkipEmptyParts);
    for(auto l: lines)
    {
        QStringList elems = l.split(",");
        CSVdata.push_back(elems);
    }
    return true;
}

void MainWindow::setupModel(QString fileName)
{
    bool fileRead = readCSVfromFile(fileName);

    if(fileRead == false)
        return;

    model = new TableModel();
    model->setData(CSVdata);
    ui->tableView->setModel(model);
}
