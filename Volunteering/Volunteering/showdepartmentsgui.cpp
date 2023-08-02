#include "showdepartmentsgui.h"

ShowDepartmentsGui::ShowDepartmentsGui(Service* service, QWidget *parent) : service(service), QWidget(parent), ui(new Ui::ShowDepartmentsGuiClass) {
	ui->setupUi(this);
	this->service->registerObserver(this);
	this->setWindowTitle("Departments");
	this->update();
}

ShowDepartmentsGui::~ShowDepartmentsGui() {
	service->unregisterObserver(this);
	delete ui;
}

void ShowDepartmentsGui::update() {
	this->ui->departmentsList->clear();
	vector<Department> departments = service->getDepartments();
	sort(departments.begin(), departments.end(), [&](const Department& a, const Department& b) {
		return this->service->getVolunteersByDepartment(a.getName()).size() < this->service->getVolunteersByDepartment(b.getName()).size();
	});
	for (auto department : departments)
		this->ui->departmentsList->addItem(QString::fromStdString(department.getName() + " - " + to_string(service->getVolunteersByDepartment(department.getName()).size()) + " volunteers"));
}
