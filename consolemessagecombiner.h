#ifndef CONSOLEMESSAGECOMBINER_H
#define CONSOLEMESSAGECOMBINER_H

#include <QString>
#include <QTextEdit>
#include <QLineEdit>
#include <qtermwidget6/qtermwidget.h>

class ConsoleMessageCombiner
{
public:
    ConsoleMessageCombiner();
    ~ConsoleMessageCombiner();

    // Set the system prompt
    void setSystemPrompt(const QString &prompt);

    // Get the system prompt
    QString getSystemPrompt() const;

    // Get all console content from the terminal
    QString getConsoleContent(QTermWidget *terminal) const;

    // Combine console content + system prompt + message and insert into answer box
    void combineAndInsert(QTermWidget *terminal,
                         QLineEdit *messageBox,
                         QTextEdit *answerBox);

    // Alternative: combine with custom message instead of messageBox
    void combineAndInsert(QTermWidget *terminal,
                         const QString &customMessage,
                         QTextEdit *answerBox);

    // Get the combined message without inserting
    QString getCombinedMessage(QTermWidget *terminal,
                              const QString &message) const;

private:
    QString systemPrompt;

    // Helper function to extract terminal text
    QString extractTerminalText(QTermWidget *terminal) const;
};

#endif // CONSOLEMESSAGECOMBINER_H
