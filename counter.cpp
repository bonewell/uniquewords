#include "counter.h"
#include <QtDebug>
#include <QFile>
#include <QtConcurrent/QtConcurrent>

Counter::Counter(QObject *parent)
    : QObject(parent),
      is_cancelled(false),
      updater_(parent)
{
    setTimeout(300);  // default value
    connect(&updater_, &QTimer::timeout, this, &Counter::linesChanged);
    connect(&updater_, &QTimer::timeout, this, &Counter::wordsChanged);
    connect(&updater_, &QTimer::timeout, this, &Counter::uniqueWordChanged);
    connect(this, &Counter::finished, &updater_, &QTimer::stop);
    connect(this, &Counter::cancelled, &updater_, &QTimer::stop);
}

int Counter::timeout() const
{
    return updater_.interval();
}

void Counter::setTimeout(int value)
{
    updater_.setInterval(value);
}

void Counter::run(const QString& filename)
{
    updater_.start();
    QtConcurrent::run(this, &Counter::handle, filename);
}

void Counter::stop()
{
    is_cancelled = true;
}

void Counter::handle(const QString& filename)
{
    QFile file(QUrl(filename).toLocalFile());
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        while (!in.atEnd() && !is_cancelled) {
            auto line = in.readLine();
            statistics_.analyze(line.toLower());
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
