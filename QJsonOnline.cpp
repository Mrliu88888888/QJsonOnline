#include "QJsonOnline.h"

/****************************************************************************************************/
/*                                           TO JSON                                                */
/****************************************************************************************************/
// QList
template <> QJsonArray _ToJson(const QList<bool>& l)
{
    QJsonArray j;
    for (const auto& v : l) {
        j.append(v);
    }
    return j;
}
template <> QJsonArray _ToJson(const QList<int>& l)
{
    QJsonArray j;
    for (const auto& v : l) {
        j.append(v);
    }
    return j;
}
template <> QJsonArray _ToJson(const QList<double>& l)
{
    QJsonArray j;
    for (const auto& v : l) {
        j.append(v);
    }
    return j;
}
template <> QJsonArray _ToJson(const QList<QString>& l)
{
    QJsonArray j;
    for (const auto& v : l) {
        j.append(v);
    }
    return j;
}

// QVector
template <> QJsonArray _ToJson(const QVector<bool>& v)
{
    QJsonArray j;
    for (const auto& _v : v) {
        j.append(_v);
    }
    return j;
}
template <> QJsonArray _ToJson(const QVector<int>& v)
{
    QJsonArray j;
    for (const auto& _v : v) {
        j.append(_v);
    }
    return j;
}
template <> QJsonArray _ToJson(const QVector<double>& v)
{
    QJsonArray j;
    for (const auto& _v : v) {
        j.append(_v);
    }
    return j;
}
template <> QJsonArray _ToJson(const QVector<QString>& v)
{
    QJsonArray j;
    for (const auto& _v : v) {
        j.append(_v);
    }
    return j;
}

/****************************************************************************************************/
/*                                           FROM JSON                                              */
/****************************************************************************************************/
// QList
template <> QList<bool> _FromJson(const QJsonValue& j, const QList<bool>&)
{
    QList<bool> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toBool());
    }
    return l;
}
template <> QList<int> _FromJson(const QJsonValue& j, const QList<int>&)
{
    QList<int> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toInt());
    }
    return l;
}
template <> QList<double> _FromJson(const QJsonValue& j, const QList<double>&)
{
    QList<double> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toDouble());
    }
    return l;
}
template <> QList<QString> _FromJson(const QJsonValue& j, const QList<QString>&)
{
    QList<QString> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toString());
    }
    return l;
}

// QVector
template <> QVector<bool> _FromJson(const QJsonValue& j, const QVector<bool>&)
{
    QVector<bool> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toBool());
    }
    return l;
}
template <> QVector<int> _FromJson(const QJsonValue& j, const QVector<int>&)
{
    QVector<int> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toInt());
    }
    return l;
}
template <> QVector<double> _FromJson(const QJsonValue& j, const QVector<double>&)
{
    QVector<double> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toDouble());
    }
    return l;
}
template <> QVector<QString> _FromJson(const QJsonValue& j, const QVector<QString>&)
{
    QVector<QString> l;
    const auto& _j = j.toArray();
    for (const auto& v : _j) {
        l.append(v.toString());
    }
    return l;
}
