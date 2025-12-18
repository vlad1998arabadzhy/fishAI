#include "terminalwidget.h"
#include <QVBoxLayout>
#include <QClipboard>

TerminalWidget::TerminalWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setupTerminal();

}

TerminalWidget::~TerminalWidget(){

}

void TerminalWidget::setupTerminal()
{
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    terminal = new QTermWidget(0, this);
    terminal->setShellProgram("/bin/fish");
    terminal->setColorScheme("Linux");
    terminal->setTerminalFont(QFont("Monospace",11));
    terminal->setScrollBarPosition(QTermWidget::ScrollBarRight);

    terminal->startShellProgram();

    layout->addWidget(terminal);
    setLayout(layout);

    terminal->setFocus();
}

QTermWidget* TerminalWidget::getTerminal(){
    return terminal;
}

QString TerminalWidget::getTerminalContent(){
    return terminal->selectedText(false);
}


