#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class FileManagement : public QObject {
    Q_OBJECT
    QFile* file;
public:
    explicit FileManagement(QString fileName, QObject *parent = nullptr);
    ~FileManagement();
    void saveMessagesToFile(QString text);
};

#endif // FILEMANAGEMENT_H
