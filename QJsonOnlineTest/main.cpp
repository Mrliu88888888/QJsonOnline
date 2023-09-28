#include "QJsonOnlineTest.h"
#include <qtest.h>
#include <qcoreapplication.h>
#include <qdebug.h>

#if 1
QTEST_MAIN(QJsonOnlineTest)
#else
int main(int  argc, char** argv)
{
    QCoreApplication _a(argc, argv);

    for (int i = 1; i <= 63; ++i) {
        qDebug() << QString("key%1").arg(i);
    }

    return 0;
}
#endif
