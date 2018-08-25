#include "statistics.h"

#include <QString>
#include <QRegularExpression>

void Statistics::analyze(const QString& line) {
    ++lines_count_;
    const auto& words = getWords(line);
    words_count_ += words.length();
    countUniqueWords(words);
}

QStringList Statistics::getWords(const QString& line) const {
    return line.split(QRegExp("(\\W|\\d|_)+"), QString::SkipEmptyParts);
}

void Statistics::countUniqueWords(const QStringList& words) {
    for (const auto& w : words) {
        if (!unique_words_.contains(w)) {
            unique_words_.insert(w);
            last_unique_word_ = w;
        }
    }
}
