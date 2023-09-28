#include "QJson2CppStudio.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QJson2CppStudio w;
    w.show();
    return a.exec();
}
