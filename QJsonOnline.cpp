#include "QJsonOnline.h"
#include <qvector.h>

/****************************************************************************************************/
/*                                           FROM JSON                                              */
/****************************************************************************************************/
// Array[] -> QList
#define QJSON_JSONVALUE_TO_LIST(TO) \
    { \
        r.clear(); \
        const auto& t = j.toArray(); \
        for (const auto& i : t) { \
            r.append(i.TO()); \
        } \
        return r; \
    }
template <> QList<bool>& _FromJson(const QJsonValue& j, QList<bool>& r)
QJSON_JSONVALUE_TO_LIST(toBool)
template <> QList<int>& _FromJson(const QJsonValue& j, QList<int>& r)
QJSON_JSONVALUE_TO_LIST(toInt)
template <> QList<double>& _FromJson(const QJsonValue& j, QList<double>& r)
QJSON_JSONVALUE_TO_LIST(toDouble)
template <> QList<QString>& _FromJson(const QJsonValue& j, QList<QString>& r)
QJSON_JSONVALUE_TO_LIST(toString)

// Array[] -> QVector
#define QJSON_JSONVALUE_TO_VECTOR(TO) QJSON_JSONVALUE_TO_LIST(TO)
template <> QVector<bool>& _FromJson(const QJsonValue& j, QVector<bool>& r)
QJSON_JSONVALUE_TO_VECTOR(toBool)
template <> QVector<int>& _FromJson(const QJsonValue& j, QVector<int>& r)
QJSON_JSONVALUE_TO_VECTOR(toInt)
template <> QVector<double>& _FromJson(const QJsonValue& j, QVector<double>& r)
QJSON_JSONVALUE_TO_VECTOR(toDouble)
template <> QVector<QString>& _FromJson(const QJsonValue& j, QVector<QString>& r)
QJSON_JSONVALUE_TO_VECTOR(toString)

/****************************************************************************************************/
/*                                           TO JSON                                                */
/****************************************************************************************************/
// Array[] -> QList
#define QJSON_LIST_TO_JSONARRAY \
    { \
        QJsonArray r; \
        for (const auto& i : v) { \
            r.append(i); \
        } \
        return r; \
    }
template <> QJsonArray _ToJson(const QList<bool>& v)
QJSON_LIST_TO_JSONARRAY
template <> QJsonArray _ToJson(const QList<int>& v)
QJSON_LIST_TO_JSONARRAY
template <> QJsonArray _ToJson(const QList<double>& v)
QJSON_LIST_TO_JSONARRAY
template <> QJsonArray _ToJson(const QList<QString>& v)
QJSON_LIST_TO_JSONARRAY

// Array[] -> QVector
#define QJSON_VECTOR_TO_JSONARRAY QJSON_LIST_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<bool>& v)
QJSON_VECTOR_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<int>& v)
QJSON_VECTOR_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<double>& v)
QJSON_VECTOR_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<QString>& v)
QJSON_VECTOR_TO_JSONARRAY
