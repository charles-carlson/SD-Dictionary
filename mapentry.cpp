#include "mapentry.h"

MapEntry::MapEntry(QString fileName)
{
QFile file(fileName);
if(!file.oper(QIODevice::Readonly))
{
    QMessageBox::information(0, "error",file.errorString());
}
QTextStream in (&file);

while(!in.atEnd()){
    QString line = in.readLine();
    QStringList fields = line.split("Defn:");
    model->appendRow(fields);
}
file.close();
}

