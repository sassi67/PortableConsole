#include <QApplication>
#include "consoleui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConsoleUI console;
    console.show();

    return a.exec();
}

