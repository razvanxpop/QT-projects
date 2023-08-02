#include <QtWidgets/QApplication>

#include "Repository.h"
#include "Service.h"
#include "departmentgui.h"
#include "showdepartmentsgui.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Repository repository{ "departments.txt", "volunteers.txt" };
    Service service{repository};
    auto guis = new DepartmentGui[repository.getDepartments().size()];
    for (int index = 0; index < repository.getDepartments().size(); ++index)
        guis[index].init(&service, repository.getDepartment(index));

    ShowDepartmentsGui* showDepartmentsWindow = new ShowDepartmentsGui(&service);
    showDepartmentsWindow->show();

    return a.exec();
}
