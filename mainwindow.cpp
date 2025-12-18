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
    int col = terminalWidget->getTerminal()->screenColumnsCount();
    int lines= terminalWidget->getTerminal()->screenLinesCount() + terminalWidget->getTerminal()->historyLinesCount();

    terminalWidget->getTerminal()->setSelectionStart(0,0);
    terminalWidget->getTerminal()->setSelectionEnd(lines, col);

    terminalWidget->getTerminal()->copyClipboard();
}

