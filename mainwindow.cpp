#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    terminalWidget = new TerminalWidget(this);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QTermWidget* terminal = terminalWidget->getTerminal();

    QKeyEvent pressEvent(QEvent::KeyPress, Qt::Key_A, Qt::ControlModifier|Qt::ShiftModifier);

    QApplication::sendEvent(terminalWidget, &pressEvent);
    QKeyEvent releaseEvent(QEvent::KeyRelease, Qt::Key_A, Qt::ControlModifier|Qt::ShiftModifier);
    QApplication::sendEvent(terminalWidget, &releaseEvent);
    terminal->copyClipboard();
}

