/****************************************************************************************************/
/*                    https ://github.com/Mrliu88888888/QJsonOnline                                 */
/****************************************************************************************************/

#include "QJson2Cpp.h"
#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonobject.h>

inline QString firstCharToUpper(const QString& str, const QString& beginStr = "")
{
    return beginStr + str.at(0).toUpper() + str.mid(1);
}

QString pJsonArray(const QJsonArray& arr, QList<QPair<QString, QString>>& ls, const QString& key, bool isClass);

QString pJsonObject(const QJsonObject& obj, const QString& objName, bool isClass)
{
    QString content;
    QList<QPair<QString, QString>> ls;
    for (const auto& key : obj.keys()) {
        const auto& v = obj.value(key);
        if (v.isObject()) {
            const auto& className = isClass ? firstCharToUpper(key) : firstCharToUpper(key, "S");
            content += pJsonObject(v.toObject(), className, isClass);
            ls.append(QPair<QString, QString>(className, key));
        }
        else if (v.isArray()) {
            const auto& arr = v.toArray();
            content += pJsonArray(arr, ls, key, isClass);
        }
        else if (v.isBool()) {
            ls.append(QPair<QString, QString>("bool", key));
        }
        else if (v.isDouble()) {
            ls.append(QPair<QString, QString>("double", key));
        }
        else if (v.isString()) {
            ls.append(QPair<QString, QString>("QString", key));
        }
        // else {
        //     qDebug() << "else type: " << v;
        // }
    }

    {
        const QString _objName = objName.isEmpty() ?
            (isClass ? "MyClass" : "MyStruct") : objName;

        content.append(isClass ? "class " : "struct ");
        content.append(_objName);
        content.append("\n{\n");
        if (isClass) {
            content.append("public:\n");
        }
        content.append(QString("\t%1()").arg(_objName));
        const auto nPosClassInitList = content.length();
        bool isFirstClassInitList = true;
        content.append("\n\t{ }\n\n");
        if (isClass) {
            content.append("private:\n");
        }
        QString strClassInitList;
        for (const auto& r : ls)
        {
            if (r.first == "bool") {
                isFirstClassInitList ?
                    strClassInitList.append("\n\t: " + r.second + "(false)")
                    :
                    strClassInitList.append("\n\t, " + r.second + "(false)");
                isFirstClassInitList = false;
            }
            else if (r.first == "double") {
                isFirstClassInitList ?
                    strClassInitList.append("\n\t: " + r.second + "(0.0)")
                    :
                    strClassInitList.append("\n\t, " + r.second + "(0.0)");
                isFirstClassInitList = false;
            }
            content.append(QString("\t%1 %2;\n").arg(r.first).arg(r.second));
        }
        content.insert(nPosClassInitList, strClassInitList);
        if (isClass) {
            content.append("\npublic:");
        }
        content.append("\n\tQJSON_ONLINE(" + _objName + ",");
        for (const auto& r : ls) {
            content.append(QString("%1,").arg(r.second));
        }
        content.chop(1);
        content.append(");\n");
        content.append("};\n");
    }
    return content;
}

QString pJsonArray(const QJsonArray& arr, QList<QPair<QString, QString>>& ls, const QString& key, bool isClass)
{
    QString content;
    if (arr.size() > 0) {
        const auto& c = arr.at(0);
        QString type;
        if (c.isObject()) {
            const auto& className = isClass ? firstCharToUpper(key) : firstCharToUpper(key, "S");
            content += pJsonObject(c.toObject(), className, isClass);
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
        // else {
        //     qDebug() << "else type: " << c;
        // }
        ls.append(QPair<QString, QString>(QString("QList<%1>").arg(type), key));
    }
    return content;
}

int json2cpp(const QString& inFilename, const QString& outFilename, const QString& objName, bool isClass)
{
    QFile fin(inFilename);
    if (!fin.open(QIODevice::ReadOnly)) {
        return 1;
    }
    auto doc = QJsonDocument::fromJson(fin.readAll());
    fin.close();

    if (doc.isNull()) {
        return 2;
    }
    QString content;
    if (doc.isObject()) {
        content = pJsonObject(doc.object(), objName, isClass);
    }
    else if (doc.isArray()) {
        // content = pJsonArray(doc.array());
        return 5;
    }
    else {
        return 3;
    }

    QFile fout(outFilename);
    if (!fout.open(QIODevice::WriteOnly)) {
        return 4;
    }
    content.insert(0,
        "// Generated by QJsonOnline\n"
        "// https://github.com/Mrliu88888888/QJsonOnline\n\n");
    fout.write(content.toUtf8());
    fout.flush();
    fout.close();
    return 0;
}
