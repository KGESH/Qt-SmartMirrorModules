#include "commandlist.h"


CommandList::CommandList(QObject *parent) : QObject(parent)
{

}


QStringList& CommandList::GetCmdList()
{
    return cmd_list_;
}

