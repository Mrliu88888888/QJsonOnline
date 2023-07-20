#include "QJsonOnline.h"

/****************************************************************************************************/
/*                                           TO JSON                                                */
/****************************************************************************************************/
// QList
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

// QVector
#define QJSON_VECTOR_TO_JSONARRAY \
    { \
        QJsonArray r; \
        for (const auto& i : v) { \
            r.append(i); \
        } \
        return r; \
    }
template <> QJsonArray _ToJson(const QVector<bool>& v)
QJSON_VECTOR_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<int>& v)
QJSON_VECTOR_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<double>& v)
QJSON_VECTOR_TO_JSONARRAY
template <> QJsonArray _ToJson(const QVector<QString>& v)
QJSON_VECTOR_TO_JSONARRAY

/****************************************************************************************************/
/*                                           FROM JSON                                              */
/****************************************************************************************************/
// QList
#define QJSON_JSONARRAY_TO_LIST(TYPE, TO) \
    { \
        QList<TYPE> r; \
        const auto& t = j.toArray(); \
        for (const auto& i : t) { \
            r.append(i.TO()); \
        } \
        return r; \
    }
template <> QList<bool> _FromJson(const QJsonValue& j, const QList<bool>&)
QJSON_JSONARRAY_TO_LIST(bool, toBool)
template <> QList<int> _FromJson(const QJsonValue& j, const QList<int>&)
QJSON_JSONARRAY_TO_LIST(int, toInt)
template <> QList<double> _FromJson(const QJsonValue& j, const QList<double>&)
QJSON_JSONARRAY_TO_LIST(double, toDouble)
template <> QList<QString> _FromJson(const QJsonValue& j, const QList<QString>&)
QJSON_JSONARRAY_TO_LIST(QString, toString)

// QVector
#define QJSON_JSONARRAY_TO_VECTOR(TYPE, TO) \
    { \
        QVector<TYPE> r; \
        const auto& t = j.toArray(); \
        for (const auto& i : t) { \
            r.append(i.TO()); \
        } \
        return r; \
    }
template <> QVector<bool> _FromJson(const QJsonValue& j, const QVector<bool>&)
QJSON_JSONARRAY_TO_VECTOR(bool, toBool)
template <> QVector<int> _FromJson(const QJsonValue& j, const QVector<int>&)
QJSON_JSONARRAY_TO_VECTOR(int, toInt)
template <> QVector<double> _FromJson(const QJsonValue& j, const QVector<double>&)
QJSON_JSONARRAY_TO_VECTOR(double, toDouble)
template <> QVector<QString> _FromJson(const QJsonValue& j, const QVector<QString>&)
QJSON_JSONARRAY_TO_VECTOR(QString, toString)
