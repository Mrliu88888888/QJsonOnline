#pragma once
#include <qstring.h>

/// @brief json转cpp类
/// @param inFilename 输入文件名
/// @param outFilename 输出文件名
/// @param objName 对象名，空为默认值 class: MyClass, struct: MyStruct
/// @param isClass 是否为class true: class, false: struct
/// @return 0: 成功
///         1: 打开读文件失败
///         2: Json为空
///         3: Json类型未知
///         4: 打开写文件失败
///         5: 不支持Json Array的解析
int json2cpp(const QString& inFilename, const QString& outFilename, const QString& objName = "", bool isClass = true);
