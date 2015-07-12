#include "counter.h"
#include <QtDebug>
#include <QFile>
#include <QtConcurrent/QtConcurrent>

Counter::Counter(QObject *parent)
    : QObject(parent),
      number_lines(0),
      number_words(0),
      unique_word(),
      is_cancel(false)
{

}

void Counter::run(const QString& filename)
{
    is_cancel = false;
    number_lines = number_words = 0;
    dictionary.clear();
    QtConcurrent::run(this, &Counter::handle, filename);
}

void Counter::stop()
{
    qDebug() << "CANCEL";
    is_cancel = true;
}

void Counter::handle(const QString& filename)
{
    QFile file(QUrl(filename).toLocalFile());
    if (file.open(QFile::ReadOnly)) {
        while (!file.atEnd() && !is_cancel) {
            auto line = QString(file.readLine());
            updateLines(++number_lines);
            process(line.toLower());
        }
        file.close();
        if (!is_cancel) emit finished();
    } else {
        qCritical() << QObject::tr("Could not open file ") << filename;
    }
}

void Counter::process(const QString& line)
{
    auto list = line.split(QRegExp("(\\W|\\d|_)+"), QString::SkipEmptyParts);
    for (auto& word : list) {
        if (!dictionary.contains(word)) {
            unique_word = word;
            dictionary.insert(word);
            updateWords(++number_words);
        }
    }
}

void Counter::updateLines(int current_value)
{
    if (current_value % discrete_value == 0) {
        emit linesChanged();
    }
}

void Counter::updateWords(int current_value)
{
    if (current_value % discrete_value == 0) {
        emit wordsChanged();
        emit uniqueWordChanged();
    }
}

int Counter::lines() const
{
    return number_lines;
}

int Counter::words() const
{
    return number_words;
}

QString Counter::uniqueWord() const
{
    return unique_word;
}

int Counter::discrete() const
{
    return discrete_value;
}

void Counter::setDiscrete(int value)
{
    if (discrete_value != value) {
        discrete_value = value;
        emit discreteChanged();
    }
}
