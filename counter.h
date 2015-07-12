#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QSet>
#include <QString>
#include <atomic>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = 0);
    void handle(const QString& filename);

    Q_PROPERTY(int discrete READ discrete WRITE setDiscrete NOTIFY discreteChanged)
    Q_PROPERTY(int lines READ lines NOTIFY linesChanged)
    Q_PROPERTY(int words READ words NOTIFY wordsChanged)
    Q_PROPERTY(QString uniqueWord READ uniqueWord NOTIFY uniqueWordChanged)

    Q_INVOKABLE int discrete() const;
    Q_INVOKABLE int lines() const;
    Q_INVOKABLE int words() const;
    Q_INVOKABLE QString uniqueWord() const;

signals:
    void discreteChanged();
    void linesChanged();
    void wordsChanged();
    void uniqueWordChanged();
    void finished();

public slots:
    void run(const QString& filename);
    void stop();
    void setDiscrete(int value);

private:
    int discrete_value;
    int number_lines;
    int number_words;
    QString unique_word;
    QSet<QString> dictionary;
    std::atomic<bool> is_cancel;

    void process(const QString& line);
    inline void updateLines(int current_value);
    inline void updateWords(int current_value);
};

#endif // COUNTER_H
