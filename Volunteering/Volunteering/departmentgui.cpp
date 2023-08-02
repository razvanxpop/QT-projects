#include "departmentgui.h"

#include <qmessagebox.h>

DepartmentGui::DepartmentGui(QWidget* parent) : QWidget(parent), ui(new Ui::DepartmentGuiClass), service(nullptr), department(nullptr) {
	ui->setupUi(this);
	makeConnections();
}

DepartmentGui::~DepartmentGui() {
	service->unregisterObserver(this);
	delete ui;
}

void DepartmentGui::update() {
	this->ui->volunteersList->clear();
	vector<Volunteer> volunteers = service->getVolunteersByDepartment(department->getName());
	sort(volunteers.begin(), volunteers.end(), [](const Volunteer& a, const Volunteer& b){
		return a.getName() < b.getName();
	});
	for (auto volunteer : volunteers)
		this->ui->volunteersList->addItem(QString::fromStdString(volunteer.toString()));

	this->ui->unassignedVolunteersList->clear();
	vector<Volunteer> unassignedVolunteers = service->getUnassignedVolunteers();
	sort(unassignedVolunteers.begin(), unassignedVolunteers.end(), [](const Volunteer& a, const Volunteer& b) {
		return a.getName() < b.getName();
	});
	for (auto volunteer : unassignedVolunteers)
		this->ui->unassignedVolunteersList->addItem(QString::fromStdString(volunteer.toString()));
}

void DepartmentGui::init(Service* service, Department* department){ 
	this->service = service;
	this->department = department;
	this->service->registerObserver(this);
	this->setWindowTitle(QString::fromStdString(this->department->getName()));
	this->ui->descriptionLabel->setText(QString::fromStdString(this->department->getDescription()));
	this->update();
	this->show();
}

void DepartmentGui::makeConnections() {
	QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &DepartmentGui::addVolunteer);
	QObject::connect(this->ui->assignButton, &QPushButton::clicked, this, &DepartmentGui::assignVolunteer);
	QObject::connect(this->ui->checkBox, &QCheckBox::stateChanged, this, &DepartmentGui::mostSuitable);
}

void DepartmentGui::addVolunteer() {
	string name = this->ui->nameLineEdit->text().toStdString();
	string email = this->ui->emailLineEdit->text().toStdString();
	string interests = this->ui->interestsLineEdit->text().toStdString();
	if (name == "" || email == "") {
		QMessageBox::critical(this, "Error", "Invalid input");
		return;
	}
	try {
		service->addVolunteer(name, email, interests, "No department");
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
}

void DepartmentGui::assignVolunteer() {
	if (this->ui->unassignedVolunteersList->selectedItems().size() == 0) {
		QMessageBox::critical(this, "Error", "No unassign volunteer selected!");
		return;
	}
	string volunteerString = this->ui->unassignedVolunteersList->selectedItems()[0]->text().toStdString();
	try {
		service->assignVolunteer(volunteerString, department->getName());
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
}

void DepartmentGui::mostSuitable() {
	if (this->ui->checkBox->isChecked()) {
		this->ui->unassignedVolunteersList->clear();
		vector<Volunteer> unassignedVolunteers = service->getUnassignedVolunteers();
		sort(unassignedVolunteers.begin(), unassignedVolunteers.end(), [&](const Volunteer& a, const Volunteer& b) {
			int scoreA = 0;
			for (auto interest : a.getInterests())
				if (strstr(department->getDescription().c_str(), interest.c_str()) != nullptr)
					scoreA++;
			int scoreB = 0;
			for (auto interest : b.getInterests())
				if (strstr(department->getDescription().c_str(), interest.c_str()) != nullptr)
					scoreB++;

			return scoreA > scoreB;
		});

		int count = 0;
		for (auto volunteer : unassignedVolunteers) {
			this->ui->unassignedVolunteersList->addItem(QString::fromStdString(volunteer.toString()));
			count++;
			if (count == 3)
				break;
		}
	}
	else
		this->update();
}
