#include <QtWidgets/QApplication>

#include "Controller.h"
#include "couriergui.h"
#include "couriercompanygui.h"
#include "map.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Controller controller{ "couriers.txt", "packages.txt" };
    auto guis = new CourierGui[controller.getCouriers().size()];
    for (int index = 0; index < controller.getCouriers().size(); ++index)
        guis[index].init(&controller, controller.getCourier(index));

    auto companygui = new CourierCompanyGui(&controller);
    companygui->show();

    auto map = new Map(&controller);
    map->show();
    return a.exec();
}
