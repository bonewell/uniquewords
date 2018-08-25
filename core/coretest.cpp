#include <QString>
#include <QtTest>

#include "statistics.h"

class CoreTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void countLines();
    void countWords();
    void countWordsInTwoLines();
    void countWordsTwoSpaces();
    void countUniqueWords();
    void getLastUniqueWord();
    void getUniqueWords();
};

void CoreTest::countLines()
{
    Statistics statistics;
    statistics.analyze("Line 1");
    statistics.analyze("Line 2");
    statistics.analyze("Line 3");
    QCOMPARE(statistics.linesCount(), 3);
}

void CoreTest::countWords()
{
    Statistics statistics;
    statistics.analyze("one two word");
    QCOMPARE(statistics.wordsCount(), 3);
}

void CoreTest::countWordsInTwoLines()
{
    Statistics statistics;
    statistics.analyze("word");
    statistics.analyze("two words");
    QCOMPARE(statistics.wordsCount(), 3);
}

void CoreTest::countWordsTwoSpaces()
{
    Statistics statistics;
    statistics.analyze("one  two");
    QCOMPARE(statistics.wordsCount(), 2);
}

void CoreTest::countUniqueWords()
{
    Statistics statistics;
    statistics.analyze("one two one");
    QCOMPARE(statistics.uniqueWordsCount(), 2);
}

void CoreTest::getLastUniqueWord()
{
    Statistics statistics;
    statistics.analyze("one last one");
    QCOMPARE(statistics.lastUniqueWord(), QString("last"));
}

void CoreTest::getUniqueWords()
{
    Statistics statistics;
    statistics.analyze("one last one");
    QSet<QString> expected{"one", "last"};
    QCOMPARE(statistics.uniqueWords(), expected);
}

QTEST_APPLESS_MAIN(CoreTest)

#include "coretest.moc"
