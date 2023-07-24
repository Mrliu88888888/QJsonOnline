#include "QJsonArrayOnline.h"
#include <QtCore/QCoreApplication>
#include <qvector.h>
#include <qdebug.h>
#include <qalgorithms.h>

struct SPair
{
    SPair() {}

    QString key;

    QJSON_ONLINE(SPair, key);
};

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    {
        QVector<QVector<SPair>> v2;
        v2 = lm::FromJsonArray(QFile("a2.json"), v2);
        qDebug() << v2.size();
        // qDebug() << v2;
        qDebug() << lm::ToFile(v2, QFile("ac2-2.json"));
    }

    {
        QVector<int> v1;
        lm::FromJsonArray(QFile("a.json"), v1);
        qDebug() << v1;

        qSort(v1.begin(), v1.end());
        qDebug() << lm::ToFile(v1, QFile("ac.json"));
    }

    {
        QList<QList<int>> v2;
        v2 = lm::FromJsonArray("[[1,2,3],[2,3,1],[3,2,1]]", v2);
        qDebug() << v2;
        qDebug() << lm::ToFile(v2, QFile("ac2.json"));
    }

    {
        QJsonArray j;
        {
            QJsonArray t1;
            for (int i = 0; i < 3; ++i)
            {
                QJsonArray t2;
                for (int j = 0; j < 3; ++j)
                {
                    t2.append(j);
                }
                t1.append(t2);
            }
            j.append(t1);
            j.append(t1);
        }

        QList<QList<QList<int>>> v3;
        lm::FromJsonArray(j, v3);
        qDebug() << v3;
        qDebug() << lm::ToFile(v3, QFile("ac3.json"));
    }

    return 0;
}
