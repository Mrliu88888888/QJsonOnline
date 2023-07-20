# QJsonOnline
通过宏函数方式将代码入侵至struct/class内，完成json与对象的相互转换。

# 开发简介
在使用Java进行开发后，会发现json与类之间的转化是真的非常舒服，而cpp则只能手动一个个字段的去解析，而开发中发现了nlohmann json的NLOHMANN_DEFINE_TYPE_INTRUSIVE，用起来也是相当赞，所以决定模仿它，在使用原生qt json api实现一套类似的代码（主要是Qt的各种库用的太舒服了！！！

# 使用
1. 只需将 QJsonOnline.h 文件放到项目中，在需要解析json的对象中使用 QJSON_ONLINE 宏函数即可。
2. 示例代码请查看 demo 目录下的代码示例。

# 鸣谢
nlohmann json(https://github.com/nlohmann/json)
