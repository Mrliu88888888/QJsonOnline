#include "Person.h"
#include <qdebug.h>

void Person::show()
{
    qDebug() << id;
    qDebug() << name;
    qDebug() << age;
}
