#include "QJsonOnline.h"
#include <QtCore/QCoreApplication>
#include <qtextcodec.h>
#include <qdebug.h>

struct SJsonInfo
{
    SJsonInfo(const QString& t = "", const QString& k = "")
        : type(t)
        , key(k)
    {
    }

    void print() const
    {
        qDebug() << "type: " << type;
        qDebug() << "key: " << key;
        qDebug() << "==============================";
    }

    QString type;
    QString key;
};

inline QString firstCharToUpper(const QString& str, const QString& beginStr = "")
{
    return beginStr + str.at(0).toUpper() + str.mid(1);
}

QString pJsonArray(const QJsonArray& arr, QList<SJsonInfo>& ls, const QString& key, bool isClass);

#if 1
QString pJsonObject(const QJsonObject& obj, const QString& objName = "MyStruct", bool isClass = false)
#else
QString pJsonObject(const QJsonObject& obj, const QString& objName = "MyClass", bool isClass = true)
#endif
{
    QString res;
    QList<SJsonInfo> ls;
    for (const auto& key : obj.keys()) {
        const auto v = obj.value(key);
        if (v.isObject()) {
            qDebug() << "obj: " << key;
            const auto className = isClass ? firstCharToUpper(key) : firstCharToUpper(key, "S");
            res += pJsonObject(v.toObject(), className);
            ls.append(SJsonInfo(className, key));
        }
        else if (v.isArray()) {
            qDebug() << "arr";
            const auto arr = v.toArray();
            res += pJsonArray(arr, ls, key, isClass);
        }
        else if (v.isBool()) {
            qDebug() << "b";
            ls.append(SJsonInfo("bool", key));
        }
        else if (v.isDouble()) {
            qDebug() << "d";
            ls.append(SJsonInfo("double", key));
        }
        else if (v.isString()) {
            qDebug() << "str";
            ls.append(SJsonInfo("QString", key));
        }
        else {
            qDebug() << "else";
        }
    }

    {
        res.append(isClass ? "class " : "struct ");
        res.append(objName);
        res.append("\n{\n");
        res.append(QString("\t%1() {}\n\n").arg(objName));
        for (const auto& r : ls) {
            res.append(QString("\t%1 %2;\n").arg(r.type).arg(r.key));
        }
        res.append("\n\tQJSON_ONLINE(" + objName + ",");
        for (const auto& r : ls) {
            res.append(QString("%1,").arg(r.key));
        }
        res.chop(1);
        res.append(");\n");
        res.append("};\n\n");
    }
    return res;
}

QString pJsonArray(const QJsonArray& arr, QList<SJsonInfo>& ls, const QString& key, bool isClass)
{
    QString res;
    if (arr.size() > 0) {
        const auto c = arr.at(0);
        QString type;
        if (c.isObject()) {
            const auto className = isClass ? firstCharToUpper(key) : firstCharToUpper(key, "S");
            res += pJsonObject(c.toObject(), className);
            type = className;
        }
        else if (c.isArray()) {
            type = QString("QList<%1>").arg("");
        }
        else if (c.isBool()) {
            type = "bool";
        }
        else if (c.isDouble()) {
            type = "double";
        }
        else if (c.isString()) {
            type = "QString";
        }
        else {
            qDebug() << "type err";
        }
        ls.append(SJsonInfo(QString("QList<%1>").arg(type), key));
    }
    return res;
}

void json2cpp(const QString& filename)
{
    QFile f(filename + ".json");
    if (f.open(QIODevice::ReadOnly)) {
        auto doc = QJsonDocument::fromJson(f.readAll());
        if (doc.isObject()) {
            auto obj = doc.object();
            auto r = pJsonObject(obj);
            QFile fout(filename + ".cpp");
            if (fout.open(QIODevice::WriteOnly)) {
                fout.write(r.toUtf8());

                fout.flush();
                fout.close();
            }
        }
        else if (doc.isArray()) {
        }
        f.close();
    }
}

void test(const QString& filename);

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    const QString filename = "tb";
#if 0
    json2cpp(filename);
#else
    test(filename);
#endif

    return 0;
}

#if 1
#include "QJsonOnline.h"
struct STitle
{
    STitle() {}

    QString english;
    QString native;
    QString romaji;

    QJSON_ONLINE(STitle, english, native, romaji);
};

struct SAnilist
{
    SAnilist() {}

    double id;
    double idMal;
    bool isAdult;
    STitle title;

    QJSON_ONLINE(SAnilist, id, idMal, isAdult, title);
};

struct SResult
{
    SResult() {}

    SAnilist anilist;
    double episode;
    QString filename;
    double from;
    QString image;
    double similarity;
    double to;
    QString video;

    QJSON_ONLINE(SResult, anilist, episode, filename, from, image, similarity, to, video);
};

struct MyStruct
{
    MyStruct() {}

    double code;
    QString msg;
    QList<SResult> result;

    QJSON_ONLINE(MyStruct, code, msg, result);
};

void test(const QString& filename)
{
    MyStruct s;
    s.fromJson(QFile(filename + ".json"));
    qDebug() << "";
}
#endif
