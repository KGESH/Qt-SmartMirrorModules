#ifndef COMMANDLIST_H
#define COMMANDLIST_H


#include <QObject>


class CommandList : public QObject
{
    Q_OBJECT

public:
    explicit CommandList(QObject *parent = nullptr);
    QStringList& GetCmdList();



private:

    QStringList CmdList = {"Hi Google", "Get Off","cmd3"}; //100000개 있음
};

#endif // COMMANDLIST_H
