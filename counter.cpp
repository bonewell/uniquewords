#include "counter.h"
#include <QtDebug>
#include <QFile>
#include <QtConcurrent/QtConcurrent>

Counter::Counter(QObject *parent)
    : QObject(parent),
      number_lines(0),
      number_words(0),
      is_cancel(false)
{

}

void Counter::run(const QString& filename) {
    is_cancel = false;
    number_lines = number_words = 0;
    dictionary.clear();
    QtConcurrent::run(this, &Counter::handle, filename);
}

void Counter::stop() {
    qDebug() << "CANCEL";
    is_cancel = true;
}

void Counter::handle(const QString& filename) {
    QFile file(filename);
    if (file.open(QFile::ReadOnly)) {
        while (!file.atEnd() && !is_cancel) {
            auto line = QString(file.readLine());
            emit linesChanged(++number_lines);
            process(line.toLower());
        }
        file.close();
        if (!is_cancel) emit finished();
    } else {
        qCritical() << QObject::tr("Could not open file ") << filename;
    }
}

void Counter::process(const QString& line) {
    auto list = line.split(QRegExp("(\\W|\\d|_)+"), QString::SkipEmptyParts);
    for (auto& word : list) {
        if (!dictionary.contains(word)) {
            dictionary.insert(word);
            emit wordAdded(word);
            emit wordsChanged(++number_words);
        }
    }
}

int Counter::lines() {
    return number_lines;
}

int Counter::words() {
    return number_words;
}
