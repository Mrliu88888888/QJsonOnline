#ifndef PERSON_H
#define PERSON_H

#include "QJsonOnline.h"

class Person
{
public:
    Person() {}

    void show();

public:
    QJSON_ONLINE(Person, id, name, age);

private:
    QString id;
    QString name;
    int age;
};

#endif // !PERSON_H
