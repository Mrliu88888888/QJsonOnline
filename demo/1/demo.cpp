#include "QJsonOnline.h"
#include <qapplication.h>
#include <qtextcodec.h>
#include <qlist.h>

struct SPair
{
    SPair() {}

    QString key;
    QString value;

    QJSON_ONLINE(SPair, key, value);
};

class Demo
{
public:
    Demo() {}

public:
    QJSON_ONLINE(Demo, __flag, _class, _0, msg, obj, arr, vec, list);

public:
    void test()
    {
        __flag = true;
        _class = 8520;
        qSort(arr.begin(), arr.end());
        int i = 0;
        for (auto& l : list) {
            l.key = QString::number(i);
            l.value = QString::number(i);
            ++i;
        }
    }

private:
    bool __flag;
    int _class;
    double _0;
    QString msg;
    SPair obj;
    QVector<int> arr;
    QVector<QString> vec;
    QList<SPair> list;
};

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QFile f("demo.json");
    Demo d(f);
    d.test();
    d._toJson(f, QJsonDocument::Indented);

    return a.exec();
}
