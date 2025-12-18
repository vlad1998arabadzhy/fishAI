#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#include <QWidget>
#include <qtermwidget6/qtermwidget.h>

class TerminalWidget: public QWidget
{
    Q_OBJECT
public:
    explicit TerminalWidget(QWidget *parent = nullptr);
    ~TerminalWidget();
    QTermWidget* getTerminal();




private:
    void setupTerminal();
    QTermWidget *terminal;


};

#endif // TERMINALWIDGET_H
