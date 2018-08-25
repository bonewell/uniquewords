#ifndef STATISTICS_H
#define STATISTICS_H

#include <QSet>

class QString;

class Statistics {
public:
    void analyze(const QString& line);

    int linesCount() const {
        return lines_count_;
    }

    int wordsCount() const {
        return words_count_;
    }

    int uniqueWordsCount() const {
        return unique_words_.size();
    }

    const QString& lastUniqueWord() const {
        return last_unique_word_;
    }

    const QSet<QString>& uniqueWords() const {
        return unique_words_;
    }

private:
    QStringList getWords(const QString& line) const;
    void countUniqueWords(const QStringList& words);
    int lines_count_ = 0;
    int words_count_ = 0;
    QSet<QString> unique_words_;
    QString last_unique_word_;
};

#endif // STATISTICS_H
