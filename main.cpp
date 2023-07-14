#include "Widget.h"
#include "QJsonOnline.h"
#include "../3rd/json-3.11.2/single_include/nlohmann/json.hpp"
#include <QtWidgets/QApplication>
#include <qdebug.h>

struct SBook
{
    SBook()
        : name("hello world")
    {
    }

    QJSON_ONLINE(SBook, name, price);

    QString name;
    double price;
};

struct SPerson
{
    SPerson()
        : name("liumeng")
        , age(23)
        , income(1000)
    {
        books.push_back(SBook());
    }

    QJSON_ONLINE(SPerson, name, age, age2, income, books);

    QString name;
    int age;
    int age2;
    double income;
    QList<SBook> books;
};

void genCode()
{
    /*
    #define _QJSON_ONLINE_2(CLASS, KEY1) \
    _QJSON_ONLINE_CODE_BEGIN(CLASS) \
    _QJSON_EXPAND_FROM(KEY1) \
    _QJSON_ONLINE_CODE_PART \
    _QJSON_EXPAND_TO(KEY1) \
    _QJSON_ONLINE_CODE_END
    */
    QFile f("code.hpp");
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream s(&f);
        const auto _MAX = 64;
        for (int i = 1; i <= _MAX; ++i)
        {
            QString code = "#define _QJSON_ONLINE_";
            code += QString::number(i);
            code += "(CLASS";
            for (int j = 1; j < i; ++j)
                code += QString(", KEY%1").arg(j);
            code += ") \\\n\t_QJSON_ONLINE_CODE_BEGIN(CLASS) \\\n\t";
            for (int j = 1; j < i; ++j)
                code += QString("_QJSON_EXPAND_FROM(KEY%1) ").arg(j);
            code += "\\\n\t_QJSON_ONLINE_CODE_PART \\\n\t";
            for (int j = 1; j < i; ++j)
                code += QString("_QJSON_EXPAND_TO(KEY%1) ").arg(j);
            code += "\\\n\t_QJSON_ONLINE_CODE_END\n\n";
            s << code;
            s.flush();
        }

        s << "\n\n";
        for (int i = 1; i <= _MAX; ++i)
            s << "_" << i << ",";
        s << "\n";
        for (int i = _MAX; i >= 1; --i)
            s << i << ",";
        f.close();
    }
}

struct SLocation
{
    SLocation() {}

    double lat;
    double lng;

    QJSON_ONLINE(SLocation, lat, lng);
};

struct SFormatted_addresses
{
    SFormatted_addresses() {}

    QString recommend;
    QString rough;

    QJSON_ONLINE(SFormatted_addresses, recommend, rough);
};

struct SAddress_component
{
    SAddress_component() {}

    QVector<QString> nation;
    QString province;
    QList<QString> city;
    QString district;
    QString street;
    QString street_number;

    QJSON_ONLINE(SAddress_component, nation, province, city, district, street, street_number);
};

struct SResult
{
    SResult() {}

    SLocation location;
    QString address;
    SFormatted_addresses formatted_addresses;
    SAddress_component address_component;

    QJSON_ONLINE(SResult, location, address, formatted_addresses, address_component);
};

#include <qtextcodec.h>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // genCode();

    // SPerson p;
    // qDebug() << p._toJson();

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QFile f("jw.json");
    SResult res(f);
    res.location.lat = 100.0;
    res.address_component.city.append("hello world");
    res._toJson(f, QJsonDocument::Indented);

    return a.exec();
}
