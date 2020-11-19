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
    QStringList cmd_list_ = {"Hi Google", "Get Off","cmd3"};
};

#endif // COMMANDLIST_H
