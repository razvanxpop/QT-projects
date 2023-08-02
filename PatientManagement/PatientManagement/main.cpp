#include <QtWidgets/QApplication>

#include "Repository.h"
#include "Service.h"
#include "doctorgui.h"
#include "statisticsgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository{ "doctors.txt", "patients.txt" };
    Service service(repository);
    auto guis = new DoctorGui[repository.getDoctors().size()];
    for (int index = 0; index < repository.getDoctors().size(); ++index)
        guis[index].init(&service, repository.getDoctor(index));

    auto statisticsGui = new StatisticsGui(&service);
    statisticsGui->show();

    return a.exec();
}
