#include "QJsonOnline.h"

/****************************************************************************************************/
/*                                           FROM JSON                                              */
/****************************************************************************************************/
// Array => QList
#define QJSON_JSONARRAY_TO_LIST(TO) \
    { \
        r.clear(); \
        const auto& t = j.toArray(); \
        for (const auto& i : t) { \
            r.append(i.TO()); \
        } \
        return r; \
    }
template <> QList<bool>& _FromJson(const QJsonValue& j, QList<bool>& r)
QJSON_JSONARRAY_TO_LIST(toBool)
template <> QList<int>& _FromJson(const QJsonValue& j, QList<int>& r)
QJSON_JSONARRAY_TO_LIST(toInt)
template <> QList<double>& _FromJson(const QJsonValue& j, QList<double>& r)
QJSON_JSONARRAY_TO_LIST(toDouble)
template <> QList<QString>& _FromJson(const QJsonValue& j, QList<QString>& r)
QJSON_JSONARRAY_TO_LIST(toString)

/****************************************************************************************************/
/*                                           TO JSON                                                */
/****************************************************************************************************/
// Array => QList
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
