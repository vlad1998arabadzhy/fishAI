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

    // Send Ctrl+Shift+A to select all text (standard terminal shortcut)
    QKeyEvent pressEvent(QEvent::KeyPress, Qt::Key_A, Qt::ControlModifier | Qt::ShiftModifier);
    QApplication::sendEvent(terminal, &pressEvent);

    QKeyEvent releaseEvent(QEvent::KeyRelease, Qt::Key_A, Qt::ControlModifier | Qt::ShiftModifier);
    QApplication::sendEvent(terminal, &releaseEvent);

    // Copy selected text to clipboard
    terminal->copyClipboard();
}

