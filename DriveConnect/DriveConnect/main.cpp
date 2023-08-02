#include <QtWidgets/QApplication>

#include "Repository.h"
#include "Service.h"
#include "drivergui.h"
#include "map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository{ "drivers.txt", "reports.txt" };
    Service service(repository);
    auto guis = new DriverGui[repository.getDrivers().size()];
    for (int index = 0; index < repository.getDrivers().size(); ++index)
        guis[index].init(&service, repository.getDriver(index));

    Map* mapGui = new Map(&service);
    mapGui->show();

    return a.exec();
}
