#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Use the terminalWidget from the UI file
    terminalWidget = ui->terminalWidget;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QTermWidget* terminal = terminalWidget->getTerminal();

    // Select all text in the terminal
    terminal->selectAll();

    // Copy to clipboard
    terminal->copyClipboard();
}

