# Package Delivery Management System

This C++ application, built with the Qt framework, serves as a comprehensive Package Delivery Management System. Designed for efficiency and user-friendliness, the system manages couriers with assigned streets and zones, as well as packages with recipient details, addresses, coordinates, and delivery status.

## Key Features

- **Courier Windows:** Dedicated windows for each courier, displaying undelivered packages within their assigned streets or zones.
- **Central Package Overview:** A central window provides a comprehensive overview of all packages, allowing company employees to add new packages effortlessly.
- **Real-Time Updates:** Utilizing the Observer design pattern, the system ensures real-time synchronization of modifications made by couriers or company employees across all windows.
- **Map Visualization:** An interactive map window visually represents undelivered packages using geometric figures based on their coordinates.

## How It Works

1. Couriers can view and deliver packages assigned to their streets or within their zones.
2. Company employees use the central window to manage all packages, adding new ones with ease.
3. Real-time updates ensure everyone sees modifications made by any courier or company employee.
4. The map window dynamically visualizes undelivered packages for a spatial understanding.

## Persistence

The application automatically updates the packages file upon closure, ensuring data integrity and consistency.

## Usage

1. Clone the repository.
2. Build and run the application using C++ and the Qt framework.
3. Explore the intuitive user interface to manage couriers, packages, and deliveries efficiently.

This Package Delivery Management System streamlines the logistics process, providing a scalable and synchronized solution for courier companies.


1. The information about all registered couriers is in a text file. Each Courier has a name (string), a list of assigned streets and a zone, given as a circle (coordinates for centre and a radius). This file is manually created and it is read when the application starts.
2. Another file contains information about packages. Each Package has a recipient (string), an address street and number, the location (2 coordinates), and a delivery status (bool). These are read when the application starts.
3. When the application is launched, a new window is created for each courier, having as title the courier's name. The zone for the courier is also shown. The window will show in a list only the undelivered packages (with all their information) that are assigned to the courier: the street on the package is in the list of streets of the courier or the location of the package is within the courier's zone.
4. Another "courier company" window shows all packages, with all their information. Delivered packages are shown with a green background. Using this window, any company employee can add a new package, by inputting its information. When adding a new package the delivery status is false.
5. In the courier window, a combo box will be populated with all streets and will allow the couriers to see only the packages for the selected street.
6. Couriers can deliver packages by selecting a package and pressing a "Deliver" button. The package's status delivery changes to true and package disappears from the courier's window.
7. A new window will show all undelivered packages on a "map". Each package is shown with a geometrical figure (circle, rectangle), according to its coordinates.
8. When a modification is made by any courier or by a company employee, everyone will see it, automatically. The map window will also be updated automatically. Use the Observer design pattern.
9. When the application closes, the packages file will be updated.
