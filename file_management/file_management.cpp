#include "file_management.h"
#include <stdexcept>

FileManagement::FileManagement(QString fileName, QObject *parent)
    : QObject{parent} {
    file = new QFile(fileName);

}

FileManagement::~FileManagement() {
    delete file;
}

void FileManagement::saveMessagesToFile(QString text) {
    if (!file->open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << file->errorString();
    }
    QTextStream output(file);
    output << text;
    file->close();
}
