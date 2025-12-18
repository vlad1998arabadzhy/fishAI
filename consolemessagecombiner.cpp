#include "consolemessagecombiner.h"
#include <QClipboard>
#include <QApplication>

ConsoleMessageCombiner::ConsoleMessageCombiner()
    : systemPrompt("You are a helpful AI assistant analyzing terminal output.")
{
}

ConsoleMessageCombiner::~ConsoleMessageCombiner()
{
}

void ConsoleMessageCombiner::setSystemPrompt(const QString &prompt)
{
    systemPrompt = prompt;
}

QString ConsoleMessageCombiner::getSystemPrompt() const
{
    return systemPrompt;
}

QString ConsoleMessageCombiner::extractTerminalText(QTermWidget *terminal) const
{
    if (!terminal) {
        return QString();
    }

    // Store current selection
    int savedStartLine = 0;
    int savedStartCol = 0;

    // Get total lines (visible + history)
    int totalLines = terminal->screenLinesCount() + terminal->historyLinesCount();
    int totalCols = terminal->screenColumnsCount();

    // Select all text
    terminal->setSelectionStart(0, 0);
    terminal->setSelectionEnd(totalLines, totalCols);

    // Copy to clipboard
    terminal->copyClipboard();

    // Get text from clipboard
    QClipboard *clipboard = QApplication::clipboard();
    QString consoleText = clipboard->text();

    // Clear selection
    terminal->setSelectionStart(0, 0);
    terminal->setSelectionEnd(0, 0);

    return consoleText;
}

QString ConsoleMessageCombiner::getConsoleContent(QTermWidget *terminal) const
{
    return extractTerminalText(terminal);
}

QString ConsoleMessageCombiner::getCombinedMessage(QTermWidget *terminal,
                                                   const QString &message) const
{
    QString combined;

    // Add system prompt
    combined += "=== SYSTEM PROMPT ===\n";
    combined += systemPrompt;
    combined += "\n\n";

    // Add console content
    combined += "=== CONSOLE CONTENT ===\n";
    combined += getConsoleContent(terminal);
    combined += "\n\n";

    // Add user message
    combined += "=== USER MESSAGE ===\n";
    combined += message;
    combined += "\n";

    return combined;
}

void ConsoleMessageCombiner::combineAndInsert(QTermWidget *terminal,
                                              QLineEdit *messageBox,
                                              QTextEdit *answerBox)
{
    if (!terminal || !messageBox || !answerBox) {
        return;
    }

    QString message = messageBox->text();
    QString combined = getCombinedMessage(terminal, message);

    // Insert into answer box
    answerBox->setPlainText(combined);
}

void ConsoleMessageCombiner::combineAndInsert(QTermWidget *terminal,
                                              const QString &customMessage,
                                              QTextEdit *answerBox)
{
    if (!terminal || !answerBox) {
        return;
    }

    QString combined = getCombinedMessage(terminal, customMessage);

    // Insert into answer box
    answerBox->setPlainText(combined);
}
