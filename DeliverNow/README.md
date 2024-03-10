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

## License

This project is licensed under the MIT License.
