
#include "consoleui.h"

#include <QTextEdit>
#include <QLineEdit>
#include <QProcess>
#include <QByteArray>
#include <QVBoxLayout>
#include <QLabel>

ConsoleUI::ConsoleUI(QWidget *parent) :
    QDialog(parent)
{

    log_ = new QTextEdit(this);
    log_->setReadOnly(true);
    lab_ = new QLabel(tr("Type commands here:"), this);
    input_ = new  QLineEdit(this);

    connect (input_, SIGNAL(returnPressed()),  this, SLOT(execute()));

    proc_ = new QProcess(this);
    proc_->setProcessChannelMode(QProcess::MergedChannels);
    // Merge stdout and stderr.
    connect (proc_, SIGNAL(readyReadStandardOutput()), this, SLOT(display()));

    layMain_ = new QVBoxLayout(this);
    layMain_->addWidget(log_);
    layMain_->addWidget(lab_);
    layMain_->addWidget(input_);
    setLayout(layMain_);
#ifdef Q_OS_WIN
    proc_->start("cmd", QStringList(), QIODevice::ReadWrite);
#else
    // Run bash in interactive mode.
    proc_->start("bash", QStringList("-i"), QIODevice::ReadWrite);
#endif

    if (!proc_->waitForStarted())
        return;

}

ConsoleUI::~ConsoleUI()
{
    proc_->close();
}

void ConsoleUI::execute()
{
    QString cmdStr = input_->text() + "\n";
    input_->setText("");
    log_->append(cmdStr);
    QByteArray bytes = cmdStr.toUtf8(); /* 8-bit Unicode Transformation Format */
    proc_->write(bytes);               /* Send the data into the stdin stream of the bash child process */
}

void ConsoleUI::display()
{
    QByteArray bytes = proc_->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");
    foreach (QString line, lines)
    {
        log_->append(line);
    }

}

