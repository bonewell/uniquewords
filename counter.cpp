#include "counter.h"
#include <QtDebug>
#include <QFile>

Counter::Counter(QObject *parent) : QObject(parent), number_lines(0), number_words(0)
{

}

void Counter::run(const QString& filename) {
    future = QtConcurrent::run(this, &Counter::handle, filename);
    future.waitForFinished();
    if (future.isFinished()) {
        emit finished();
    }
}

void Counter::stop() {
    future.cancel();
}

void Counter::handle(const QString& filename) {
    QFile file(filename);
    if (file.open(QFile::ReadOnly)) {
        while (!file.atEnd()) {
            auto line = QString(file.readLine());
            emit linesChanged(++number_lines);
            process(line.toLower());
        }
        file.close();
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
