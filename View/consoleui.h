
#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <QDialog>

class QLineEdit;
class QProcess;
class QTextEdit;
class QVBoxLayout;
class QLabel;

class ConsoleUI : public QDialog
{
    Q_OBJECT
public:
    explicit ConsoleUI(QWidget *parent=0);
    ~ConsoleUI();

protected:

private:
    //Pre C++2011 hide by making private and don't implement
    explicit ConsoleUI(const ConsoleUI& rhs);
    ConsoleUI& operator= (const ConsoleUI& rhs);

    QVBoxLayout *layMain_;
    QTextEdit   *log_;
    QLabel      *lab_;
    QLineEdit   *input_;
    QProcess    *proc_;

signals:

public slots:
    void execute();
    void display();

private slots:

};
#endif // CONSOLEUI_H



