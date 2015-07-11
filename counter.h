#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QSet>
#include <QString>
#include <QtConcurrent/QtConcurrent>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = 0);
    void handle(const QString& filename);

    Q_PROPERTY(int lines READ lines NOTIFY linesChanged)
    Q_PROPERTY(int words READ words NOTIFY wordsChanged)

    Q_INVOKABLE int lines();
    Q_INVOKABLE int words();

signals:
    void linesChanged(int number);
    void wordsChanged(int number);
    void wordAdded(const QString& word);
    void finished();

public slots:
    void run(const QString& filename);
    void stop();

private:
    int number_lines;
    int number_words;
    QSet<QString> dictionary;
    QFuture<void> future;

    void process(const QString& line);
};

#endif // COUNTER_H
