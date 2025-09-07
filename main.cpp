#include <QApplication>
#include "Notepad.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Notepad notepadObj;
    notepadObj.show();

    return a.exec();
}
