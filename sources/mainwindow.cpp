#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = nullptr;

    setupStatusBar();
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

    bool fileRead = readCSVfromFile(fileName);

    if(fileRead == false)
        return;

    setupModel(ui->actionFirst_row_as_heading->isChecked());
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

void MainWindow::setupModel(bool heading)
{
    model = new TableModel();
    model->setHeading(heading);
    model->setData(CSVdata);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::setupStatusBar()
{
    statusBarPos = new QLabel;
    ui->statusBar->addWidget(statusBarPos);
    ui->statusBar->setLayoutDirection(Qt::RightToLeft);
}

void MainWindow::on_actionFirst_row_as_heading_toggled(bool arg1)
{
    Q_UNUSED(arg1);

    bool heading = ui->actionFirst_row_as_heading->isChecked();

    setupModel(heading);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    statusBarPos->setText(QString::number(index.row()) + "," + QString::number(index.column()));
}
