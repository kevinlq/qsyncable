#include <QUuid>
#include <QtQml>
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
#include <QRegExp>
#else
#include <QRegularExpression>
#endif

#include "qsuuid.h"

/*! \qmltype Uuid
    \inqmlmodule QSyncable
    \brief Uuid Generator

 */

QSUuid::QSUuid(QObject *parent) : QObject(parent)
{

}

/*! \qmlmethod string Uuid::create()

  Call this function to generate a random Uuid in string format.
  It use the result from QUuid::createUuid().
 */

QString QSUuid::create() const
{
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    return QUuid::createUuid().toString().replace(QRegExp("[{}]"), "");
#else
    return QUuid::createUuid().toString().replace(QRegularExpression("[{}]"), "");
#endif
}
