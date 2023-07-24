#pragma once
#ifndef QJSON_ARRAY_ONLINE_H
#define QJSON_ARRAY_ONLINE_H
/****************************************************************************************************/
/*                    https ://github.com/Mrliu88888888/QJsonOnline                                 */
/****************************************************************************************************/

#include "QJsonOnline.h"

/****************************************************************************************************/
/*                                           LIST                                                   */
/****************************************************************************************************/
namespace lm
{
#define QJSON_JSONARRAY_TO_LIST(TO) \
    { \
        r.clear(); \
        for (const auto& i : j) {  \
            r.append(i.TO()); \
        } \
        return r; \
    }

#define QJSON_BYTEARRAY_TO_LIST \
    { \
        r.clear(); \
        auto d = QJsonDocument::fromJson(s); \
        if (d.isNull()) { return r; } \
        if (d.isArray()) { \
            r = FromJsonArray(d.array(), r); \
        } \
        return r; \
    }

#define QJSON_FILE_TO_LIST \
    { \
        r.clear(); \
        if (f.open(QIODevice::ReadOnly)) { \
            r = FromJsonArray(f.readAll(), r); \
            f.close(); \
        } \
        return r; \
    }

#define QJSON_JSONARRAY_TO_NLIST(T) \
    { \
        r.clear(); \
        for (const auto& i : j) { \
            T r2; \
            r.append(FromJsonArray(i.toArray(), r2)); \
        } \
        return r; \
    }

#define QJSON_LIST_TO_FILE \
    { \
        if (f.open(QIODevice::WriteOnly)) { \
            f.write(ToByteArray(v, fm)); \
            f.flush(); \
            f.close(); \
            return true; \
        } \
        return false; \
    }
    /*************************************************FROM JSON*************************************************/
    // QJsonArray -> QList[]
    template<typename T>
    QList<T>& FromJsonArray(const QJsonArray& j, QList<T>& r)
        QJSON_JSONARRAY_TO_LIST(toObject);
    template <> QList<bool>& FromJsonArray(const QJsonArray& j, QList<bool>& r);
    template <> QList<int>& FromJsonArray(const QJsonArray& j, QList<int>& r);
    template <> QList<double>& FromJsonArray(const QJsonArray& j, QList<double>& r);
    template <> QList<QString>& FromJsonArray(const QJsonArray& j, QList<QString>& r);

    // QByteArray -> QList[]
    template<typename T>
    QList<T>& FromJsonArray(const QByteArray& s, QList<T>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<bool>& FromJsonArray(const QByteArray& s, QList<bool>& r);
    template <> QList<int>& FromJsonArray(const QByteArray& s, QList<int>& r);
    template <> QList<double>& FromJsonArray(const QByteArray& s, QList<double>& r);
    template <> QList<QString>& FromJsonArray(const QByteArray& s, QList<QString>& r);

    // QFile -> QList[]
    template<typename T>
    QList<T>& FromJsonArray(QFile& f, QList<T>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<bool>& FromJsonArray(QFile& f, QList<bool>& r);
    template <> QList<int>& FromJsonArray(QFile& f, QList<int>& r);
    template <> QList<double>& FromJsonArray(QFile& f, QList<double>& r);
    template <> QList<QString>& FromJsonArray(QFile& f, QList<QString>& r);

    template<typename T>
    QList<T>& FromJsonArray(QFile&& f, QList<T>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<bool>& FromJsonArray(QFile&& f, QList<bool>& r);
    template <> QList<int>& FromJsonArray(QFile&& f, QList<int>& r);
    template <> QList<double>& FromJsonArray(QFile&& f, QList<double>& r);
    template <> QList<QString>& FromJsonArray(QFile&& f, QList<QString>& r);

    // QJsonArray -> QList[][]
    template<typename T>
    QList<QList<T>>& FromJsonArray(const QJsonArray& j, QList<QList<T>>& r)
        QJSON_JSONARRAY_TO_NLIST(QList<QList<T>>);
    template <> QList<QList<bool>>& FromJsonArray(const QJsonArray& j, QList<QList<bool>>& r);
    template <> QList<QList<int>>& FromJsonArray(const QJsonArray& j, QList<QList<int>>& r);
    template <> QList<QList<double>>& FromJsonArray(const QJsonArray& j, QList<QList<double>>& r);
    template <> QList<QList<QString>>& FromJsonArray(const QJsonArray& j, QList<QList<QString>>& r);

    // QByteArray -> QList[][]
    template<typename T>
    QList<QList<T>>& FromJsonArray(const QByteArray& s, QList<QList<T>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<bool>>& FromJsonArray(const QByteArray& s, QList<QList<bool>>& r);
    template <> QList<QList<int>>& FromJsonArray(const QByteArray& s, QList<QList<int>>& r);
    template <> QList<QList<double>>& FromJsonArray(const QByteArray& s, QList<QList<double>>& r);
    template <> QList<QList<QString>>& FromJsonArray(const QByteArray& s, QList<QList<QString>>& r);

    // QFile -> QList[][]
    template<typename T>
    QList<QList<T>>& FromJsonArray(QFile& f, QList<QList<T>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<bool>>& FromJsonArray(QFile& f, QList<QList<bool>>& r);
    template <> QList<QList<int>>& FromJsonArray(QFile& f, QList<QList<int>>& r);
    template <> QList<QList<double>>& FromJsonArray(QFile& f, QList<QList<double>>& r);
    template <> QList<QList<QString>>& FromJsonArray(QFile& f, QList<QList<QString>>& r);

    template<typename T>
    QList<QList<T>>& FromJsonArray(QFile&& f, QList<QList<T>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<bool>>& FromJsonArray(QFile&& f, QList<QList<bool>>& r);
    template <> QList<QList<int>>& FromJsonArray(QFile&& f, QList<QList<int>>& r);
    template <> QList<QList<double>>& FromJsonArray(QFile&& f, QList<QList<double>>& r);
    template <> QList<QList<QString>>& FromJsonArray(QFile&& f, QList<QList<QString>>& r);

    // QJsonArray -> QList[][][]
    template<typename T>
    QList<QList<QList<T>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<T>>>& r)
        QJSON_JSONARRAY_TO_NLIST(QList<QList<QList<T>>>);
    template <> QList<QList<QList<bool>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<bool>>>& r);
    template <> QList<QList<QList<int>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<int>>>& r);
    template <> QList<QList<QList<double>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<double>>>& r);
    template <> QList<QList<QList<QString>>>& FromJsonArray(const QJsonArray& j, QList<QList<QList<QString>>>& r);

    // QByteArray -> QList[][][]
    template<typename T>
    QList<QList<QList<T>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<T>>>& r)
        QJSON_BYTEARRAY_TO_LIST;
    template <> QList<QList<QList<bool>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<bool>>>& r);
    template <> QList<QList<QList<int>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<int>>>& r);
    template <> QList<QList<QList<double>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<double>>>& r);
    template <> QList<QList<QList<QString>>>& FromJsonArray(const QByteArray& s, QList<QList<QList<QString>>>& r);

    // QFile -> QList[][][]
    template<typename T>
    QList<QList<QList<T>>>& FromJsonArray(QFile& f, QList<QList<QList<T>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<bool>>>& FromJsonArray(QFile& f, QList<QList<QList<bool>>>& r);
    template <> QList<QList<QList<int>>>& FromJsonArray(QFile& f, QList<QList<QList<int>>>& r);
    template <> QList<QList<QList<double>>>& FromJsonArray(QFile& f, QList<QList<QList<double>>>& r);
    template <> QList<QList<QList<QString>>>& FromJsonArray(QFile& f, QList<QList<QList<QString>>>& r);

    template<typename T>
    QList<QList<QList<T>>>& FromJsonArray(QFile&& f, QList<QList<QList<T>>>& r)
        QJSON_FILE_TO_LIST;
    template <> QList<QList<QList<bool>>>& FromJsonArray(QFile&& f, QList<QList<QList<bool>>>& r);
    template <> QList<QList<QList<int>>>& FromJsonArray(QFile&& f, QList<QList<QList<int>>>& r);
    template <> QList<QList<QList<double>>>& FromJsonArray(QFile&& f, QList<QList<QList<double>>>& r);
    template <> QList<QList<QList<QString>>>& FromJsonArray(QFile&& f, QList<QList<QList<QString>>>& r);

    /*************************************************TO JSON*************************************************/
    // QList[] -> QJsonArray
    template<typename T>
    inline QJsonArray ToJsonArray(const QList<T>& v) { return _lm::toJson(v); }

    // QList[] -> QByteArray
    template<typename T>
    inline QByteArray ToByteArray(const QList<T>& v, QJsonDocument::JsonFormat f = QJsonDocument::JsonFormat::Compact)
    {
        return QJsonDocument(ToJsonArray(v)).toJson(f);
    }

    // QList[] -> QFile
    template<typename T>
    bool ToFile(const QList<T>& v, QFile& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_LIST_TO_FILE;

    template<typename T>
    bool ToFile(const QList<T>& v, QFile&& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_LIST_TO_FILE;

    // QList[][] -> QJsonArray
    template<typename T>
    inline QJsonArray ToJsonArray(const QList<QList<T>>& v) { return _lm::toJson(v); }

    // QList[][] -> QByteArray
    template<typename T>
    inline QByteArray ToByteArray(const QList<QList<T>>& v, QJsonDocument::JsonFormat f = QJsonDocument::JsonFormat::Compact)
    {
        return QJsonDocument(ToJsonArray(v)).toJson(f);
    }

    // QList[][] -> QFile
    template<typename T>
    bool ToFile(const QList<QList<T>>& v, QFile& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_LIST_TO_FILE;
    template<typename T>
    bool ToFile(const QList<QList<T>>& v, QFile&& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_LIST_TO_FILE;

    // QList[][][] -> QJsonArray
    template<typename T>
    inline QJsonArray ToJsonArray(const QList<QList<QList<T>>>& v) { return _lm::toJson(v); }

    // QList[][][] -> QByteArray
    template<typename T>
    inline QByteArray ToByteArray(const QList<QList<QList<T>>>& v, QJsonDocument::JsonFormat f = QJsonDocument::JsonFormat::Compact)
    {
        return QJsonDocument(ToJsonArray(v)).toJson(f);
    }

    // QList[][][] -> QFile
    template<typename T>
    bool ToFile(const QList<QList<QList<T>>>& v, QFile& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_LIST_TO_FILE;
    template<typename T>
    bool ToFile(const QList<QList<QList<T>>>& v, QFile&& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_LIST_TO_FILE;
}

/****************************************************************************************************/
/*                                           VECTOR                                                 */
/****************************************************************************************************/
namespace lm
{
#define QJSON_JSONARRAY_TO_VECTOR(TO) QJSON_JSONARRAY_TO_LIST(TO)
#define QJSON_BYTEARRAY_TO_VECTOR QJSON_BYTEARRAY_TO_LIST
#define QJSON_FILE_TO_VECTOR QJSON_FILE_TO_LIST
#define QJSON_JSONARRAY_TO_NVECTOR(T) QJSON_JSONARRAY_TO_NLIST(T)
#define QJSON_VECTOR_TO_FILE QJSON_LIST_TO_FILE
    /*************************************************FROM JSON*************************************************/
    // QJsonArray -> QVector[]
    template<typename T>
    QVector<T>& FromJsonArray(const QJsonArray& j, QVector<T>& r)
        QJSON_JSONARRAY_TO_VECTOR(toObject);
    template <> QVector<bool>& FromJsonArray(const QJsonArray& j, QVector<bool>& r);
    template <> QVector<int>& FromJsonArray(const QJsonArray& j, QVector<int>& r);
    template <> QVector<double>& FromJsonArray(const QJsonArray& j, QVector<double>& r);
    template <> QVector<QString>& FromJsonArray(const QJsonArray& j, QVector<QString>& r);

    // QByteArray -> QVector[]
    template<typename T>
    QVector<T>& FromJsonArray(const QByteArray& s, QVector<T>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<bool>& FromJsonArray(const QByteArray& s, QVector<bool>& r);
    template <> QVector<int>& FromJsonArray(const QByteArray& s, QVector<int>& r);
    template <> QVector<double>& FromJsonArray(const QByteArray& s, QVector<double>& r);
    template <> QVector<QString>& FromJsonArray(const QByteArray& s, QVector<QString>& r);

    // QFile -> QVector[]
    template<typename T>
    QVector<T>& FromJsonArray(QFile& f, QVector<T>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<bool>& FromJsonArray(QFile& f, QVector<bool>& r);
    template <> QVector<int>& FromJsonArray(QFile& f, QVector<int>& r);
    template <> QVector<double>& FromJsonArray(QFile& f, QVector<double>& r);
    template <> QVector<QString>& FromJsonArray(QFile& f, QVector<QString>& r);

    template<typename T>
    QVector<T>& FromJsonArray(QFile&& f, QVector<T>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<bool>& FromJsonArray(QFile&& f, QVector<bool>& r);
    template <> QVector<int>& FromJsonArray(QFile&& f, QVector<int>& r);
    template <> QVector<double>& FromJsonArray(QFile&& f, QVector<double>& r);
    template <> QVector<QString>& FromJsonArray(QFile&& f, QVector<QString>& r);

    // QJsonArray -> QVector[][]
    template<typename T>
    QVector<QVector<T>>& FromJsonArray(const QJsonArray& j, QVector<QVector<T>>& r)
        QJSON_JSONARRAY_TO_NVECTOR(QVector<QVector<T>>);
    template <> QVector<QVector<bool>>& FromJsonArray(const QJsonArray& j, QVector<QVector<bool>>& r);
    template <> QVector<QVector<int>>& FromJsonArray(const QJsonArray& j, QVector<QVector<int>>& r);
    template <> QVector<QVector<double>>& FromJsonArray(const QJsonArray& j, QVector<QVector<double>>& r);
    template <> QVector<QVector<QString>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QString>>& r);

    // QByteArray -> QVector[][]
    template<typename T>
    QVector<QVector<T>>& FromJsonArray(const QByteArray& s, QVector<QVector<T>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<bool>>& FromJsonArray(const QByteArray& s, QVector<QVector<bool>>& r);
    template <> QVector<QVector<int>>& FromJsonArray(const QByteArray& s, QVector<QVector<int>>& r);
    template <> QVector<QVector<double>>& FromJsonArray(const QByteArray& s, QVector<QVector<double>>& r);
    template <> QVector<QVector<QString>>& FromJsonArray(const QByteArray& s, QVector<QVector<QString>>& r);

    // QFile -> QVector[][]
    template<typename T>
    QVector<QVector<T>>& FromJsonArray(QFile& f, QVector<QVector<T>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<bool>>& FromJsonArray(QFile& f, QVector<QVector<bool>>& r);
    template <> QVector<QVector<int>>& FromJsonArray(QFile& f, QVector<QVector<int>>& r);
    template <> QVector<QVector<double>>& FromJsonArray(QFile& f, QVector<QVector<double>>& r);
    template <> QVector<QVector<QString>>& FromJsonArray(QFile& f, QVector<QVector<QString>>& r);

    template<typename T>
    QVector<QVector<T>>& FromJsonArray(QFile&& f, QVector<QVector<T>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<bool>>& FromJsonArray(QFile&& f, QVector<QVector<bool>>& r);
    template <> QVector<QVector<int>>& FromJsonArray(QFile&& f, QVector<QVector<int>>& r);
    template <> QVector<QVector<double>>& FromJsonArray(QFile&& f, QVector<QVector<double>>& r);
    template <> QVector<QVector<QString>>& FromJsonArray(QFile&& f, QVector<QVector<QString>>& r);

    // QJsonArray -> QVector[][][]
    template<typename T>
    QVector<QVector<QVector<T>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<T>>>& r)
        QJSON_JSONARRAY_TO_NVECTOR(QVector<QVector<QVector<T>>>);
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<bool>>>& r);
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<int>>>& r);
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<double>>>& r);
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(const QJsonArray& j, QVector<QVector<QVector<QString>>>& r);

    // QByteArray -> QVector[][][]
    template<typename T>
    QVector<QVector<QVector<T>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<T>>>& r)
        QJSON_BYTEARRAY_TO_VECTOR;
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<bool>>>& r);
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<int>>>& r);
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<double>>>& r);
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(const QByteArray& s, QVector<QVector<QVector<QString>>>& r);

    // QFile -> QVector[][][]
    template<typename T>
    QVector<QVector<QVector<T>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<T>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<bool>>>& r);
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<int>>>& r);
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<double>>>& r);
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(QFile& f, QVector<QVector<QVector<QString>>>& r);

    template<typename T>
    QVector<QVector<QVector<T>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<T>>>& r)
        QJSON_FILE_TO_VECTOR;
    template <> QVector<QVector<QVector<bool>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<bool>>>& r);
    template <> QVector<QVector<QVector<int>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<int>>>& r);
    template <> QVector<QVector<QVector<double>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<double>>>& r);
    template <> QVector<QVector<QVector<QString>>>& FromJsonArray(QFile&& f, QVector<QVector<QVector<QString>>>& r);

    /*************************************************TO JSON*************************************************/
    // QVector[] -> QJsonArray
    template<typename T>
    inline QJsonArray ToJsonArray(const QVector<T>& v) { return _lm::toJson(v); }

    // QVector[] -> QByteArray
    template<typename T>
    inline QByteArray ToByteArray(const QVector<T>& v, QJsonDocument::JsonFormat f = QJsonDocument::JsonFormat::Compact)
    {
        return QJsonDocument(ToJsonArray(v)).toJson(f);
    }

    // QVector[] -> QFile
    template<typename T>
    bool ToFile(const QVector<T>& v, QFile& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_VECTOR_TO_FILE;
    template<typename T>
    bool ToFile(const QVector<T>& v, QFile&& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_VECTOR_TO_FILE;

    // QVector[][] -> QJsonArray
    template<typename T>
    inline QJsonArray ToJsonArray(const QVector<QVector<T>>& v) { return _lm::toJson(v); }

    // QVector[][] -> QByteArray
    template<typename T>
    inline QByteArray ToByteArray(const QVector<QVector<T>>& v, QJsonDocument::JsonFormat f = QJsonDocument::JsonFormat::Compact)
    {
        return QJsonDocument(ToJsonArray(v)).toJson(f);
    }

    // QVector[][] -> QFile
    template<typename T>
    bool ToFile(const QVector<QVector<T>>& v, QFile& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_VECTOR_TO_FILE;
    template<typename T>
    bool ToFile(const QVector<QVector<T>>& v, QFile&& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_VECTOR_TO_FILE;

    // QVector[][][] -> QJsonArray
    template<typename T>
    inline QJsonArray ToJsonArray(const QVector<QVector<QVector<T>>>& v) { return _lm::toJson(v); }

    // QVector[][][] -> QByteArray
    template<typename T>
    inline QByteArray ToByteArray(const QVector<QVector<QVector<T>>>& v, QJsonDocument::JsonFormat f = QJsonDocument::JsonFormat::Compact)
    {
        return QJsonDocument(ToJsonArray(v)).toJson(f);
    }

    // QVector[][][] -> QFile
    template<typename T>
    bool ToFile(const QVector<QVector<QVector<T>>>& v, QFile& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_VECTOR_TO_FILE;
    template<typename T>
    bool ToFile(const QVector<QVector<QVector<T>>>& v, QFile&& f, QJsonDocument::JsonFormat fm = QJsonDocument::JsonFormat::Compact)
        QJSON_VECTOR_TO_FILE;
}
#endif
