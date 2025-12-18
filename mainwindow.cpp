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

void MainWindow::on_sendButton_clicked()
{
    // Get terminal content first (select all, get text, then deselect)
    QTermWidget* terminal = terminalWidget->getTerminal();

    // Select all terminal text
    QKeyEvent pressEvent(QEvent::KeyPress, Qt::Key_A, Qt::ControlModifier | Qt::ShiftModifier);
    QApplication::sendEvent(terminal, &pressEvent);
    QKeyEvent releaseEvent(QEvent::KeyRelease, Qt::Key_A, Qt::ControlModifier | Qt::ShiftModifier);
    QApplication::sendEvent(terminal, &releaseEvent);

    // Get the selected terminal content
    QString terminalContent = terminalWidget->getTerminalContent();

    // Deselect by clicking elsewhere (send Escape key)
    QKeyEvent escPress(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QApplication::sendEvent(terminal, &escPress);
    QKeyEvent escRelease(QEvent::KeyRelease, Qt::Key_Escape, Qt::NoModifier);
    QApplication::sendEvent(terminal, &escRelease);

    // Get message and system prompt from input fields
    QString message = ui->messageInput->text();
    QString systemPrompt = ui->systemPromptInput->toPlainText();

    // Combine all content
    QString combinedOutput;
    combinedOutput += "=== MESSAGE ===\n";
    combinedOutput += message + "\n\n";
    combinedOutput += "=== SYSTEM PROMPT ===\n";
    combinedOutput += systemPrompt + "\n\n";
    combinedOutput += "=== TERMINAL OUTPUT ===\n";
    combinedOutput += terminalContent;

    // Display in the output window
    ui->outputWindow->setPlainText(combinedOutput);
}

