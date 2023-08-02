#include <QtWidgets/QApplication>

#include "Repository.h"
#include "Service.h"
#include "usergui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository("users.txt", "items.txt");
    Service service(repository);
    auto guis = new UserGui[repository.getUsers().size()];
    for (int index = 0; index < repository.getUsers().size(); ++index)
        guis[index].init(&service, repository.getUser(index));

    return a.exec();
}
