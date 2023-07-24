#include "QJsonOnline.h"
#include <qvector.h>

/****************************************************************************************************/
/*                                           LIST                                                   */
/****************************************************************************************************/
namespace _lm {
    /*************************************************FROM JSON*************************************************/
    // QJsonValue -> QList[]
    template <> QList<bool>& fromJson(const QJsonValue& j, QList<bool>& r)
        QJSON_JSONVALUE_TO_LIST(toBool);
    template <> QList<int>& fromJson(const QJsonValue& j, QList<int>& r)
        QJSON_JSONVALUE_TO_LIST(toInt);
    template <> QList<double>& fromJson(const QJsonValue& j, QList<double>& r)
        QJSON_JSONVALUE_TO_LIST(toDouble);
    template <> QList<QString>& fromJson(const QJsonValue& j, QList<QString>& r)
        QJSON_JSONVALUE_TO_LIST(toString);

    /*************************************************TO JSON*************************************************/
    // QList[] -> QJsonArray
    template <> QJsonArray toJson(const QList<bool>& v)
        QJSON_LIST_TO_JSONARRAY(i);
    template <> QJsonArray toJson(const QList<int>& v)
        QJSON_LIST_TO_JSONARRAY(i);
    template <> QJsonArray toJson(const QList<double>& v)
        QJSON_LIST_TO_JSONARRAY(i);
    template <> QJsonArray toJson(const QList<QString>& v)
        QJSON_LIST_TO_JSONARRAY(i);
}

/****************************************************************************************************/
/*                                           VECTOR                                                 */
/****************************************************************************************************/
namespace _lm {
    /*************************************************FROM JSON*************************************************/
    // QJsonValue -> QVector[]
    template <> QVector<bool>& fromJson(const QJsonValue& j, QVector<bool>& r)
        QJSON_JSONVALUE_TO_VECTOR(toBool);
    template <> QVector<int>& fromJson(const QJsonValue& j, QVector<int>& r)
        QJSON_JSONVALUE_TO_VECTOR(toInt);
    template <> QVector<double>& fromJson(const QJsonValue& j, QVector<double>& r)
        QJSON_JSONVALUE_TO_VECTOR(toDouble);
    template <> QVector<QString>& fromJson(const QJsonValue& j, QVector<QString>& r)
        QJSON_JSONVALUE_TO_VECTOR(toString);

    /*************************************************TO JSON*************************************************/
    // QVector[] -> QJsonArray
    template <> QJsonArray toJson(const QVector<bool>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
    template <> QJsonArray toJson(const QVector<int>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
    template <> QJsonArray toJson(const QVector<double>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
    template <> QJsonArray toJson(const QVector<QString>& v)
        QJSON_VECTOR_TO_JSONARRAY(i);
}
