#include "counter.h"
#include <QtDebug>
#include <QFile>
#include <QtConcurrent/QtConcurrent>

Counter::Counter(QObject *parent)
    : QObject(parent),
      is_cancelled(false)
{
}

void Counter::run(const QString& filename)
{
    QtConcurrent::run(this, &Counter::handle, filename);
}

void Counter::stop()
{
    is_cancelled = true;
}

void Counter::handle(const QString& filename)
{
    QFile file(QUrl(filename).toLocalFile());
    if (file.open(QFile::ReadOnly)) {
        while (!file.atEnd() && !is_cancelled) {
            auto line = QString(file.readLine());
            statistics_.analyze(line.toLower());
            emit linesChanged();
            emit wordsChanged();
            emit uniqueWordChanged();
        }
        file.close();
        if (is_cancelled) {
            emit cancelled();
        } else {
            emit finished();
        }
    } else {
        qCritical() << QObject::tr("Could not open file ") << filename;
    }
}

int Counter::lines() const
{
    return statistics_.linesCount();
}

int Counter::words() const
{
    return statistics_.uniqueWordsCount();
}

QString Counter::uniqueWord() const
{
    return statistics_.lastUniqueWord();
}

QStringList Counter::dict() const
{
    return statistics_.uniqueWords().toList();
}
