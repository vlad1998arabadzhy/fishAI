#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Use the terminalWidget from the UI file
    terminalWidget = ui->terminalWidget;

    // Initialize the ConsoleMessageCombiner
    messageCombiner = new ConsoleMessageCombiner();

    // Optionally set a custom system prompt
    messageCombiner->setSystemPrompt("You are a helpful AI assistant analyzing terminal output and helping with debugging.");
}


MainWindow::~MainWindow()
{
    delete messageCombiner;
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

void MainWindow::on_combineButton_clicked()
{
    // Use the ConsoleMessageCombiner to combine console content with user message
    messageCombiner->combineAndInsert(
        terminalWidget->getTerminal(),
        ui->messageBox,
        ui->answerBox
    );
}

