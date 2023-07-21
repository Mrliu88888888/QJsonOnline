﻿#include "QJsonArrayOnline.h"

/****************************************************************************************************/
/*                                           LIST                                                   */
/****************************************************************************************************/
namespace lm {
    /****************************************************************************************************/
    /*                                           FROM JSON                                              */
    /****************************************************************************************************/
    template <> QList<bool>& FromJsonArray(const QJsonArray& j, QList<bool>& r)
        QJSON_JSONARRAY_TO_LIST(toBool);
    template <> QList<int>& FromJsonArray(const QJsonArray& j, QList<int>& r)
        QJSON_JSONARRAY_TO_LIST(toInt);
    template <> QList<double>& FromJsonArray(const QJsonArray& j, QList<double>& r)
        QJSON_JSONARRAY_TO_LIST(toDouble);
    template <> QList<QString>& FromJsonArray(const QJsonArray& j, QList<QString>& r)
        QJSON_JSONARRAY_TO_LIST(toString);

    template <> QList<bool>& FromJsonArray(const QByteArray& s, QList<bool>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<int>& FromJsonArray(const QByteArray& s, QList<int>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<double>& FromJsonArray(const QByteArray& s, QList<double>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QString>& FromJsonArray(const QByteArray& s, QList<QString>& r)
        QJSON_BYTEARRAY_TO_LIST;

    template <> QList<bool>& FromJsonArray(QFile& f, QList<bool>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<int>& FromJsonArray(QFile& f, QList<int>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<double>& FromJsonArray(QFile& f, QList<double>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QString>& FromJsonArray(QFile& f, QList<QString>& r)
        QJSON_FILE_TO_LIST;

    template <> QList<bool>& FromJsonArray(QFile&& f, QList<bool>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<int>& FromJsonArray(QFile&& f, QList<int>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<double>& FromJsonArray(QFile&& f, QList<double>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QString>& FromJsonArray(QFile&& f, QList<QString>& r)
        QJSON_FILE_TO_LIST;

    // JsonArray[][] -> QList
    template <> QList<QList<bool>>& FromJsonArray(const QJsonArray& j, QList<QList<bool>>& r)
        QJSON_JSONARRAY_TO_LIST2(bool);
    template <> QList<QList<int>>& FromJsonArray(const QJsonArray& j, QList<QList<int>>& r)
        QJSON_JSONARRAY_TO_LIST2(int);
    template <> QList<QList<double>>& FromJsonArray(const QJsonArray& j, QList<QList<double>>& r)
        QJSON_JSONARRAY_TO_LIST2(double);
    template <> QList<QList<QString>>& FromJsonArray(const QJsonArray& j, QList<QList<QString>>& r)
        QJSON_JSONARRAY_TO_LIST2(QString);

    // ByteArray -> JsonArray[][]
    template <> QList<QList<bool>>& FromJsonArray(const QByteArray& s, QList<QList<bool>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<int>>& FromJsonArray(const QByteArray& s, QList<QList<int>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<double>>& FromJsonArray(const QByteArray& s, QList<QList<double>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<QString>>& FromJsonArray(const QByteArray& s, QList<QList<QString>>& r)
        QJSON_BYTEARRAY_TO_LIST;

    // File -> ByteArray
    template <> QList<QList<bool>>& FromJsonArray(QFile& f, QList<QList<bool>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<int>>& FromJsonArray(QFile& f, QList<QList<int>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<double>>& FromJsonArray(QFile& f, QList<QList<double>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QString>>& FromJsonArray(QFile& f, QList<QList<QString>>& r)
        QJSON_FILE_TO_LIST;

    template <> QList<QList<bool>>& FromJsonArray(QFile&& f, QList<QList<bool>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<int>>& FromJsonArray(QFile&& f, QList<QList<int>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<double>>& FromJsonArray(QFile&& f, QList<QList<double>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QString>>& FromJsonArray(QFile&& f, QList<QList<QString>>& r)
        QJSON_FILE_TO_LIST;

    // JsonArray[][][] -> QList
    template <> QList<QList<QList<bool>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<bool>>>& r)
        QJSON_JSONARRAY_TO_LIST3(bool);
    template <> QList<QList<QList<int>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<int>>>& r)
        QJSON_JSONARRAY_TO_LIST3(int);
    template <> QList<QList<QList<double>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<double>>>& r)
        QJSON_JSONARRAY_TO_LIST3(double);
    template <> QList<QList<QList<QString>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<QString>>>& r)
        QJSON_JSONARRAY_TO_LIST3(QString);

    // ByteArray -> JsonArray[][][]
    template <> QList<QList<QList<bool>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<bool>>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<QList<int>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<int>>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<QList<double>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<double>>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<QList<QString>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<QString>>>& r)
        QJSON_BYTEARRAY_TO_LIST;

    // File -> ByteArray
    template <> QList<QList<QList<bool>>>& FromJsonArray(QFile& f, QList<QList<QList<bool>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<int>>>& FromJsonArray(QFile& f, QList<QList<QList<int>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<double>>>& FromJsonArray(QFile& f, QList<QList<QList<double>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<QString>>>& FromJsonArray(QFile& f, QList<QList<QList<QString>>>& r)
        QJSON_FILE_TO_LIST;

    template <> QList<QList<QList<bool>>>& FromJsonArray(QFile&& f, QList<QList<QList<bool>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<int>>>& FromJsonArray(QFile&& f, QList<QList<QList<int>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<double>>>& FromJsonArray(QFile&& f, QList<QList<QList<double>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<QString>>>& FromJsonArray(QFile&& f, QList<QList<QList<QString>>>& r)
        QJSON_FILE_TO_LIST;

    /****************************************************************************************************/
    /*                                           TO JSON                                                */
    /****************************************************************************************************/
    // QList -> JsonArray[]
    template <> QJsonArray ToJsonArray(const QList<bool>& v)
        QJSON_LIST_TO_JSONARRAY(i);
    template <> QJsonArray ToJsonArray(const QList<int>& v)
        QJSON_LIST_TO_JSONARRAY(i);
    template <> QJsonArray ToJsonArray(const QList<double>& v)
        QJSON_LIST_TO_JSONARRAY(i);
    template <> QJsonArray ToJsonArray(const QList<QString>& v)
        QJSON_LIST_TO_JSONARRAY(i);

    // QList[][]->JsonArray
    template <> QJsonArray ToJsonArray(const QList<QList<bool>>& v)
        QJSON_LIST2_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QList<QList<int>>& v)
        QJSON_LIST2_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QList<QList<double>>& v)
        QJSON_LIST2_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QList<QList<QString>>& v)
        QJSON_LIST2_TO_JSONARRAY;

    // QList[][][] -> JsonArray
    template <> QJsonArray ToJsonArray(const QList<QList<QList<bool>>>& v)
        QJSON_LIST3_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QList<QList<QList<int>>>& v)
        QJSON_LIST3_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QList<QList<QList<double>>>& v)
        QJSON_LIST3_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QList<QList<QList<QString>>>& v)
        QJSON_LIST3_TO_JSONARRAY;
}

/****************************************************************************************************/
/*                                           VECTOR                                                 */
/****************************************************************************************************/
#include <qvector.h>
namespace lm {
    /****************************************************************************************************/
    /*                                           FROM JSON                                              */
    /****************************************************************************************************/
    template <> QVector<bool>& FromJsonArray(const QJsonArray& j, QVector<bool>& r)
        QJSON_JSONARRAY_TO_VECTOR(toBool);
    template <> QVector<int>& FromJsonArray(const QJsonArray& j, QVector<int>& r)
        QJSON_JSONARRAY_TO_VECTOR(toInt);
    template <> QVector<double>& FromJsonArray(const QJsonArray& j, QVector<double>& r)
        QJSON_JSONARRAY_TO_VECTOR(toDouble);
    template <> QVector<QString>& FromJsonArray(const QJsonArray& j, QVector<QString>& r)
        QJSON_JSONARRAY_TO_VECTOR(toString);

    template <> QVector<bool>& FromJsonArray(const QByteArray& s, QVector<bool>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<int>& FromJsonArray(const QByteArray& s, QVector<int>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<double>& FromJsonArray(const QByteArray& s, QVector<double>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QString>& FromJsonArray(const QByteArray& s, QVector<QString>& r)
        QJSON_BYTEARRAY_TO_VECTOR;

    template <> QVector<bool>& FromJsonArray(QFile& f, QVector<bool>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<int>& FromJsonArray(QFile& f, QVector<int>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<double>& FromJsonArray(QFile& f, QVector<double>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QString>& FromJsonArray(QFile& f, QVector<QString>& r)
        QJSON_FILE_TO_VECTOR;

    template <> QVector<bool>& FromJsonArray(QFile&& f, QVector<bool>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<int>& FromJsonArray(QFile&& f, QVector<int>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<double>& FromJsonArray(QFile&& f, QVector<double>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QString>& FromJsonArray(QFile&& f, QVector<QString>& r)
        QJSON_FILE_TO_VECTOR;

    // JsonArray[][] -> QVector
    template <> QVector<QVector<bool>>& FromJsonArray(const QJsonArray& j, QVector<QVector<bool>>& r)
        QJSON_JSONARRAY_TO_VECTOR2(bool);
    template <> QVector<QVector<int>>& FromJsonArray(const QJsonArray& j, QVector<QVector<int>>& r)
        QJSON_JSONARRAY_TO_VECTOR2(int);
    template <> QVector<QVector<double>>& FromJsonArray(const QJsonArray& j, QVector<QVector<double>>& r)
        QJSON_JSONARRAY_TO_VECTOR2(double);
    template <> QVector<QVector<QString>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QString>>& r)
        QJSON_JSONARRAY_TO_VECTOR2(QString);

    // ByteArray -> JsonArray[][]
    template <> QVector<QVector<bool>>& FromJsonArray(const QByteArray& s, QVector<QVector<bool>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<int>>& FromJsonArray(const QByteArray& s, QVector<QVector<int>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<double>>& FromJsonArray(const QByteArray& s, QVector<QVector<double>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<QString>>& FromJsonArray(const QByteArray& s, QVector<QVector<QString>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;

    // File -> ByteArray
    template <> QVector<QVector<bool>>& FromJsonArray(QFile& f, QVector<QVector<bool>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<int>>& FromJsonArray(QFile& f, QVector<QVector<int>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<double>>& FromJsonArray(QFile& f, QVector<QVector<double>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QString>>& FromJsonArray(QFile& f, QVector<QVector<QString>>& r)
        QJSON_FILE_TO_VECTOR;

    template <> QVector<QVector<bool>>& FromJsonArray(QFile&& f, QVector<QVector<bool>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<int>>& FromJsonArray(QFile&& f, QVector<QVector<int>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<double>>& FromJsonArray(QFile&& f, QVector<QVector<double>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QString>>& FromJsonArray(QFile&& f, QVector<QVector<QString>>& r)
        QJSON_FILE_TO_VECTOR;

    // JsonArray[][][] -> QVector
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<bool>>>& r)
        QJSON_JSONARRAY_TO_VECTOR3(bool);
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<int>>>& r)
        QJSON_JSONARRAY_TO_VECTOR3(int);
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<double>>>& r)
        QJSON_JSONARRAY_TO_VECTOR3(double);
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<QString>>>& r)
        QJSON_JSONARRAY_TO_VECTOR3(QString);

    // ByteArray -> JsonArray[][][]
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<bool>>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<int>>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<double>>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<QString>>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;

    // File -> ByteArray
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<bool>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<int>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<double>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<QString>>>& r)
        QJSON_FILE_TO_VECTOR;

    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<bool>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<int>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<double>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<QString>>>& r)
        QJSON_FILE_TO_VECTOR;

    /****************************************************************************************************/
    /*                                           TO JSON                                                */
    /****************************************************************************************************/
    // QVector -> JsonArray[]
    template <> QJsonArray ToJsonArray(const QVector<bool>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
    template <> QJsonArray ToJsonArray(const QVector<int>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
    template <> QJsonArray ToJsonArray(const QVector<double>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
    template <> QJsonArray ToJsonArray(const QVector<QString>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);

    // QVector[][]->JsonArray
    template <> QJsonArray ToJsonArray(const QVector<QVector<bool>>& v)
        QJSON_VECTOR2_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QVector<QVector<int>>& v)
        QJSON_VECTOR2_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QVector<QVector<double>>& v)
        QJSON_VECTOR2_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QVector<QVector<QString>>& v)
        QJSON_VECTOR2_TO_JSONARRAY;

    // QVector[][][] -> JsonArray
    template <> QJsonArray ToJsonArray(const QVector<QVector<QVector<bool>>>& v)
        QJSON_VECTOR3_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QVector<QVector<QVector<int>>>& v)
        QJSON_VECTOR3_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QVector<QVector<QVector<double>>>& v)
        QJSON_VECTOR3_TO_JSONARRAY;
    template <> QJsonArray ToJsonArray(const QVector<QVector<QVector<QString>>>& v)
        QJSON_VECTOR3_TO_JSONARRAY;
}
