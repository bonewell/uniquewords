#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QSet>
#include <QStringList>
#include <QTimer>
#include <atomic>

#include "core/statistics.h"

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = 0);

    Q_PROPERTY(int timeout READ timeout WRITE setTimeout)
    Q_PROPERTY(int lines READ lines NOTIFY linesChanged)
    Q_PROPERTY(int words READ words NOTIFY wordsChanged)
    Q_PROPERTY(QString uniqueWord READ uniqueWord NOTIFY uniqueWordChanged)
    Q_PROPERTY(QStringList dict READ dict)

    Q_INVOKABLE int timeout() const;
    Q_INVOKABLE void setTimeout(int value);
    Q_INVOKABLE int lines() const;
    Q_INVOKABLE int words() const;
    Q_INVOKABLE QString uniqueWord() const;
    Q_INVOKABLE QStringList dict() const;

signals:
    void linesChanged();
    void wordsChanged();
    void uniqueWordChanged();
    void finished();
    void cancelled();

public slots:
    void run(const QString& filename);
    void stop();

private:
    void handle(const QString& filename);
    Statistics statistics_;
    std::atomic<bool> is_cancelled;
    QTimer updater_;
};

#endif // COUNTER_H
