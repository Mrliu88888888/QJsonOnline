﻿#include "QJsonOnlineTest.h"
#include "QJsonOnline.h"
#include <qtest.h>

#ifdef _WIN32
#pragma execution_character_set("utf-8")
#endif

namespace utils
{
    bool isJson(const QByteArray& strJson)
    {
        auto doc = QJsonDocument::fromJson(strJson);
        if (doc.isNull()) {
            return false;
        }
        return doc.isObject();
    }

    QByteArray readAll(QFile& f)
    {
        if (f.open(QIODevice::ReadOnly))
        {
            const auto res = f.readAll();
            f.close();
            return res;
        }
        return "";
    }

    inline QByteArray readAll(QFile&& f) { return readAll(f); }

    inline QByteArray readAll(const QString& filename) { return readAll(QFile(filename)); }

    bool writeAll(const QByteArray& str, QFile& f)
    {
        if (f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            const auto len = f.write(str);
            f.close();
            return len == str.length();
        }
        return false;
    }

    inline bool writeAll(const QByteArray& str, QFile&& f) { return writeAll(str, f); }

    inline bool writeAll(const QByteArray& str, const QString& filename) { return writeAll(str, QFile(filename)); }
}

#pragma region t1
namespace t1
{
    struct KV
    {
        KV() {}

        QString key;

        QJSON_ONLINE(KV, key);
    };

    bool main()
    {
        const auto jsonStr = R"({"key":"value"})";
        KV kv;
        kv.fromJson(jsonStr);
        return kv.key == "value";
    }
}
void QJsonOnlineTest::case_t1()
{
    QVERIFY(t1::main());
}
#pragma endregion

#pragma region t2
namespace t2
{
    struct Arr
    {
        Arr() {}

        QList<int> list;

        QJSON_ONLINE(Arr, list);
    };

    bool main()
    {
        QList<int> l = { 1,2,3,4,5,6,7,8,9,0,345,2,213,456,5,7,423,23,4 };
        const auto jsonStr = R"({"list":[1,2,3,4,5,6,7,8,9,0,345,2,213,456,5,7,423,23,4]})";
        Arr ar;
        ar.fromJson(jsonStr);
        // return ar.list.size() == 19;
        return ar.list == l;
    }
}
void QJsonOnlineTest::case_t2()
{
    QVERIFY(t2::main());
}
#pragma endregion

#pragma region t3
namespace t3
{
    struct SResult
    {
        SResult() {}

        QMap<QString, QList<QList<int>>> res;

        QJSON_ONLINE(SResult, res)
    };

    class MyClass
    {
    public:
        int code;
        QString msg;
        SResult res;

    public:
        QJSON_ONLINE(MyClass, code, msg, res)
    };

    /*
    {
    "code": 200,
    "msg": "helloworld",
    "res": {
        "测试1": [
            [1,2,4],
            [2,4,4],
            [3,1,4]
        ],
        "测试随机": [
            [1,2,0],
            [2,4,0],
            [3,1,0]
        ],
        "测试6": [
            [1,2,6],
            [2,4,6],
            [3,1,6]
        ],
        "测试2": [
            [1,2,2],
            [2,4,2],
            [3,1,2]
        ]
    }
    }
    */
    bool main()
    {
        MyClass m(utils::readAll("t3.json"));
        QList<QList<int>> l = {
            {1,2,4},
            {2,4,4},
            {3,1,4}
        };

        return m.code == 200
            && m.msg == "helloworld"
            && m.res.res.size() == 4
            && m.res.res.value("测试1") == l
            && m.res.res.value("测试随机").size() == 3
            && utils::isJson(m.toJson())
            ;
    }
}
void QJsonOnlineTest::case_t3()
{
    QVERIFY(t3::main());
}
#pragma endregion

#pragma region t4
namespace t4
{
    struct T
    {
        T() {}
        QJSON_ONLINE(T)
    };

    bool main()
    {
        T t;
        return t.fromJson("") == 1
            && t.fromJson("[]") == 2
            && t.fromJson("{}") == 0
            && t.toJson() == "{}"
            ;
    }
}
void QJsonOnlineTest::case_t4()
{
    QVERIFY(t4::main());
}
#pragma endregion

#pragma region t5
namespace t5
{
    // Generated by QJsonOnline
    // https://github.com/Mrliu88888888/QJsonOnline

    class Result
    {
    public:
        Result()
        { }

    public:
        QList<QString> addr;
        QString disp;
        QString end;
        QString start;

    public:
        QJSON_ONLINE(Result, addr, disp, end, start);
    };
    class MyClass
    {
    public:
        MyClass()
            : code(0.0)
        { }

    private:
        double code;
        QString msg;
        Result result;

    public:
        inline const Result& getResult() const { return result; }
        inline bool isSucc() const { return code == 200; }

    public:
        QJSON_ONLINE(MyClass, code, msg, result);
    };

    bool main()
    {
        MyClass m(utils::readAll("ip.json"));
        return utils::isJson(m.toJson())
            && m.isSucc()
            && m.getResult().disp == "江苏省南京市 南京信风网络科技有限公司GreatbitDNS服务器"
            && m.getResult().start == "114.114.114.114"
            && m.getResult().end == "114.114.114.114"
            && m.getResult().addr.size() == 2
            ;
    }
}
void QJsonOnlineTest::case_t5()
{
    QVERIFY(t5::main());
}
#pragma endregion

#pragma region t6
namespace t6
{
    // Generated by QJsonOnline
    // https://github.com/Mrliu88888888/QJsonOnline

    struct SResult
    {
        SResult()
        { }

        QString desc;
        QString link;
        QString title;
        QString year;

        QJSON_ONLINE(SResult, desc, link, title, year);
    };
    struct MyStruct
    {
        MyStruct()
            : code(0.0)
        { }

        double code;
        QString msg;
        QList<SResult> result;

        QJSON_ONLINE(MyStruct, code, msg, result);
    };

    bool main()
    {
        MyStruct s;
        s.fromJson(utils::readAll("his.json"));
        auto f = [s]()->bool {
            for (const auto& res : s.result) {
                if (res.year == "-565") {
                    return true;
                }
            }
            return false;
        };
        return utils::isJson(s.toJson())
            && f()
            && s.result.size() == 16
            ;
    }
}
void QJsonOnlineTest::case_t6()
{
    QVERIFY(t6::main());
}
#pragma endregion

#pragma region t7
namespace t7
{
    // Generated by QJsonOnline
// https://github.com/Mrliu88888888/QJsonOnline

    struct Info
    {
        Info()
            : index(0.0)
        { }

        QString hot;
        QString href;
        double index;
        QString title;

        QJSON_ONLINE(Info, hot, href, index, title);
    };
    struct SResult
    {
        SResult()
        { }

        QMap<QString, QList<Info>> info;

        QJSON_ONLINE(SResult, info);
    };
    struct MyStruct
    {
        MyStruct()
            : code(0.0)
        { }

        double code;
        QString msg;
        SResult result;

        QJSON_ONLINE(MyStruct, code, msg, result);
    };

    bool main()
    {
        MyStruct m(utils::readAll("hot.json"));

        return utils::isJson(m.toJson(QJsonDocument::Indented))
            && m.result.info.value("实时榜中榜").at(0).index == 0
            && m.result.info.value("实时榜中榜").at(0).title.isEmpty()
            && m.result.info.value("实时榜中榜").at(0).hot.isEmpty()
            && m.result.info.value("实时榜中榜").at(0).href.isEmpty()
            && m.result.info.value("36氪").at(0).index == 1
            && m.result.info.value("36氪").at(0).title == "为什么大外企都在中国任命新CEO？｜焦点分析"
            && m.result.info.size() == 66
            && m.result.info.value("AcFun").size() == 30
            ;
    }
}
void QJsonOnlineTest::case_t7()
{
    QVERIFY(t7::main());
}
#pragma endregion

#pragma region t8
namespace t8
{
    // Generated by QJsonOnline
    // https://github.com/Mrliu88888888/QJsonOnline

    class MedalsList
    {
    public:
        MedalsList()
        { }

        inline const QString& getCountryid() const { return countryid; }
        inline QString& getGold() { return gold; }

    private:
        QString bronze;
        QString count;
        QString countryid;
        QString countryname;
        QString gold;
        QString rank;
        QString silver;

    public:
        QJSON_ONLINE(MedalsList, bronze, count, countryid, countryname, gold, rank, silver);
    };
    class Result
    {
    public:
        Result()
            : total(0.0)
        { }

    public:
        inline QList<MedalsList>& getMedalsList() { return medalsList; }
        inline double getTotal() const { return total; }

    private:
        QList<MedalsList> medalsList;
        double total;

    public:
        QJSON_ONLINE(Result, medalsList, total);
    };
    class MyClass
    {
    public:
        MyClass()
            : code(0.0)
        { }

    public:
        inline Result& getResult() { return result; }

    private:
        double code;
        QString msg;
        Result result;

    public:
        QJSON_ONLINE(MyClass, code, msg, result);
    };

    bool main()
    {
        MyClass m;
        m.fromJson(utils::readAll("ol.json"));
        for (auto& res : m.getResult().getMedalsList())
        {
            if (res.getCountryid() == "CHN") {
                res.getGold() = "99";
            }
        }

        bool flag = false;
        {
            auto doc = QJsonDocument::fromJson(m.toJson());
            if (doc.isNull()) { return false; }
            if (!doc.isObject()) { return false; }
            auto obj = doc.object();
            auto result = obj.value("result").toObject();
            auto medalsList = result.value("medalsList").toArray();
            for (const auto& i : medalsList) {
                if (i.toObject().value("gold").toString() == "99"
                    && i.toObject().value("countryid").toString() == "CHN") {
                    flag = true;
                    break;
                }
            }
        }
        return flag
            && m.getResult().getMedalsList().size() == 93
            && m.getResult().getTotal() == 93
            ;
    }
}
void QJsonOnlineTest::case_t8()
{
    QVERIFY(t8::main());
}
#pragma endregion

#pragma region t9
namespace t9
{
    // Generated by QJsonOnline
// https://github.com/Mrliu88888888/QJsonOnline

    struct SResult
    {
        SResult()
        { }

        QString date;
        QString mov_area;
        QString mov_director;
        QString mov_intro;
        QString mov_link;
        QString mov_pic;
        QString mov_rating;
        QString mov_text;
        QString mov_title;
        QList<QString> mov_type;
        QString mov_year;
        QString poster_url;

        bool print()
        {
            return date == "20230917"
                && mov_area == "法国"
                && mov_director == "奥黛丽·迪万"
                && mov_intro == "上个世纪60年代，法国禁止堕胎。高中女孩安娜因为一次放纵而不小心怀孕，因非法堕胎而面临的法律和生命危险，以及牺牲在学业和未来之间做出选择，寻求各种办法偷偷堕胎的故事。"
                && mov_type.size() == 1
                && mov_year == "2021"
                ;
        }

        QJSON_ONLINE(SResult, date, mov_area, mov_director, mov_intro, mov_link, mov_pic, mov_rating, mov_text, mov_title, mov_type, mov_year, poster_url);
    };
    struct Mov
    {
        Mov()
            : code(0.0)
        { }

        double code;
        QString msg;
        SResult result;

        bool print()
        {
            return result.print()
                && code == 200
                && msg == "success"
                ;
        }

        QJSON_ONLINE(Mov, code, msg, result);
    };

    bool main()
    {
        Mov m(utils::readAll("mov.json"));
        return m.print();
    }
}
void QJsonOnlineTest::case_t9()
{
    QVERIFY(t9::main());
}
#pragma endregion

#pragma region t10
namespace t10
{
    struct SData
    {
        SData() {}

        QString k;

        QJSON_ONLINE(SData, k);
    };

    struct SVe
    {
        QVector<QVector<QVector<QVector<QVector<QVector<QVector<QVector<QVector<SData>>>>>>>>> v;

        QJSON_ONLINE(SVe, v);
    };

    bool main()
    {
        SVe v(R"({"v":[[[[[[[[[{"k":"1"}]]]]]]]]]})");
        return utils::isJson(v.toJson())
            && v.v.at(0).at(0).at(0).at(0).at(0).at(0).at(0).at(0).at(0).k == "1"
            ;
    }
}
void QJsonOnlineTest::case_t10()
{
    QVERIFY(t10::main());
}
#pragma endregion

#pragma region t11
namespace t11
{
    class Obj
    {
    public:
        Obj() = default;

        QString _1;
        QString n;
        QString _22;
        QString __;

        QJSON_ONLINE(Obj, _1, n, _22, __)
    };

    bool main()
    {
        const auto cstr =
            R"({
                "1": "hello",
                "n": "123",
                "22": "456",
                "_": "++"
                })";

        Obj o;
        const auto res = o.fromJson(cstr);
        return res == 0
            && utils::isJson(o.toJson(QJsonDocument::Indented))
            && o._1 == "hello"
            && o.n == "123"
            && o._22 == "456"
            && o.__ == "++"
            ;
    }
}
void QJsonOnlineTest::case_t11()
{
    QVERIFY(t11::main());
}
#pragma endregion

#pragma region t12
namespace t12
{
    struct SKeys
    {
        QString key1;
        QString key2;
        QString key3;
        QString key4;
        QString key5;
        QString key6;
        QString key7;
        QString key8;
        QString key9;
        QString key10;
        QString key11;
        QString key12;
        QString key13;
        QString key14;
        QString key15;
        QString key16;
        QString key17;
        QString key18;
        QString key19;
        QString key20;
        QString key21;
        QString key22;
        QString key23;
        QString key24;
        QString key25;
        QString key26;
        QString key27;
        QString key28;
        QString key29;
        QString key30;
        QString key31;
        QString key32;
        QString key33;
        QString key34;
        QString key35;
        QString key36;
        QString key37;
        QString key38;
        QString key39;
        QString key40;
        QString key41;
        QString key42;
        QString key43;
        QString key44;
        QString key45;
        QString key46;
        QString key47;
        QString key48;
        QString key49;
        QString key50;
        QString key51;
        QString key52;
        QString key53;
        QString key54;
        QString key55;
        QString key56;
        QString key57;
        QString key58;
        QString key59;
        QString key60;
        QString key61;
        QString key62;
        QString key63;

        QJSON_ONLINE(SKeys,
            key1, key2, key3, key4, key5, key6, key7, key8, key9, key10,
            key11, key12, key13, key14, key15, key16, key17, key18, key19, key20,
            key21, key22, key23, key24, key25, key26, key27, key28, key29, key30,
            key31, key32, key33, key34, key35, key36, key37, key38, key39, key40,
            key41, key42, key43, key44, key45, key46, key47, key48, key49, key50,
            key51, key52, key53, key54, key55, key56, key57, key58, key59, key60,
            key61, key62, key63);
    };

    bool main()
    {
        const auto str = QString(
            R"({
            "key1" :"hello world",
            "key2" :"hello world",
            "key3" :"hello world",
            "key4" :"hello world",
            "key5" :"hello world",
            "key6" :"hello world",
            "key7" :"hello world",
            "key8" :"hello world",
            "key9" :"hello world",
            "key10":"hello world",
            "key11":"hello world",
            "key12":"hello world",
            "key13":"hello world",
            "key14":"hello world",
            "key15":"hello world",
            "key16":"hello world",
            "key17":"hello world",
            "key18":"hello world",
            "key19":"hello world",
            "key20":"hello world",
            "key21":"hello world",
            "key22":"hello world",
            "key23":"hello world",
            "key24":"hello world",
            "key25":"hello world",
            "key26":"hello world",
            "key27":"hello world",
            "key28":"hello world",
            "key29":"hello world",
            "key30":"hello world",
            "key31":"hello world",
            "key32":"hello world",
            "key33":"hello world",
            "key34":"hello world",
            "key35":"hello world",
            "key36":"hello world",
            "key37":"hello world",
            "key38":"hello world",
            "key39":"hello world",
            "key40":"hello world",
            "key41":"hello world",
            "key42":"hello world",
            "key43":"hello world",
            "key44":"hello world",
            "key45":"hello world",
            "key46":"hello world",
            "key47":"hello world",
            "key48":"hello world",
            "key49":"hello world",
            "key50":"hello world",
            "key51":"hello world",
            "key52":"hello world",
            "key53":"hello world",
            "key54":"hello world",
            "key55":"hello world",
            "key56":"hello world",
            "key57":"hello world",
            "key58":"hello world",
            "key59":"hello world",
            "key60":"hello world",
            "key61":"hello world",
            "key62":"hello world",
            "key63":"hello world"
            })");
        SKeys k(str.toUtf8());
        return k.key1 == "hello world"
            && k.key10 == "hello world"
            && k.key20 == "hello world"
            && k.key30 == "hello world"
            && k.key40 == "hello world"
            && k.key50 == "hello world"
            && k.key60 == "hello world"
            ;
    }
}
void QJsonOnlineTest::case_t12()
{
    QVERIFY(t12::main());
}
#pragma endregion