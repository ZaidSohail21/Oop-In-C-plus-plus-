#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ServiceRecord {
private:
	string serviceDate;
	double serviceCost;
public:
	ServiceRecord(string date, double cost) : serviceDate(date), serviceCost(cost) {}

	void display() const
	{
		cout << "Service Date: " << serviceDate << ", Service Cost: $" << serviceCost << endl;
	}
	double getCost() const
	{
		return serviceCost;
	}
	string getDate() const
	{
		return serviceDate;
	}

	friend void saveServiceToFile(const ServiceRecord* serviceRecord);
};


class Vehicle
{
protected:
	string make, model;
	int year;
	ServiceRecord* serviceRecords[10]; 
	int serviceCount;

public:

	Vehicle(string m, string mod, int y) : make(m), model(mod), year(y), serviceCount(0)
	{
		cout << "Vehicle Constructor Called" << endl;
	}
	~Vehicle()
	{
		for (int i = 0; i < serviceCount; ++i)
		{
			delete serviceRecords[i]; 
		}
		cout << "Vehicle Destructor Called" << endl;
	}
	virtual void display() const
	{
		cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
	}

	virtual double calculateRange() const = 0;

	void addServiceRecord(ServiceRecord* record)
	{
		if (serviceCount < 10)
		{
			serviceRecords[serviceCount++] = record;
		}
		else
		{
			cout << "Max service records reached!" << endl;
		}
	}
	void viewServiceRecords() const {
		for (int i = 0; i < serviceCount; ++i)
		{
			serviceRecords[i]->display();
		}
	}
	friend void saveVehicleToFile(const Vehicle* vehicle);
};



class FuelVehicle : virtual public Vehicle {
protected:
	double fuelCapacity;
	string fuelType;
public:
      FuelVehicle(string m, string mod, int y, double fc, string ft)
		: Vehicle(m, mod, y), fuelCapacity(fc), fuelType(ft) {
		cout << "FuelVehicle Constructor Called" << endl;
	}
	virtual ~FuelVehicle() {
		cout << "FuelVehicle Destructor Called" << endl;
	}
	void display() const override {
		Vehicle::display();
		cout << "Fuel Capacity: " << fuelCapacity << " liters, Fuel Type: " << fuelType << endl;
	}
	double calculateRange() const override {
		return fuelCapacity * 15.0; 
	}
};


class ElectricVehicle : virtual public Vehicle {
protected:
	double batteryCapacity, chargingTime;
public:
	ElectricVehicle(string m, string mod, int y, double bc, double ct) : Vehicle(m, mod, y), batteryCapacity(bc), chargingTime(ct)
	{
		cout << "ElectricVehicle Constructor Called" << endl;
	}
	~ElectricVehicle() {
		cout << "ElectricVehicle Destructor Called" << endl;
	}
	void display() const override
	{
		Vehicle::display();
		cout << "Battery Capacity: " << batteryCapacity << " kWh, Charging Time: " << chargingTime << " hours" << endl;
	}
	double calculateRange() const override
	{
		return batteryCapacity * 5.0; 
	}
};


class HybridVehicle : public FuelVehicle, public ElectricVehicle {
public:
	HybridVehicle(string m, string mod, int y, double fc, string ft, double bc, double ct)
		: Vehicle(m, mod, y), FuelVehicle(m, mod, y, fc, ft), ElectricVehicle(m, mod, y, bc, ct) {
		cout << "HybridVehicle Constructor Called" << endl;
	}
	~HybridVehicle() {
		cout << "HybridVehicle Destructor Called" << endl;
	}
	void display() const override
	{
		FuelVehicle::display();
		ElectricVehicle::display();
	}
	double calculateRange() const override
	{
		return FuelVehicle::calculateRange() + ElectricVehicle::calculateRange(); 
	}
};




class User {
private:
	string username;
	string password;
	string role;
public:

	User(string u, string p, string r) : username(u), password(p), role(r) {}

	bool Permission(const string& u, const string& p) const {
		return (username == u && password == p);
	}

	string getRole() const {
		return role;
	}
};



void saveVehicleToFile(const Vehicle* vehicle)
{
	ofstream file;
	file.open("vehiclesoutput.txt", ios::app); 
	if (file.is_open())
	{
		file << vehicle->make << " " << vehicle->model << " " << vehicle->year << endl;
		file.close();
	}
	else
	{
		cout << "Failed to open file for saving vehicle!" << endl;
	}
}

void saveServiceToFile(const ServiceRecord* serviceRecord)
{
	ofstream file;
	file.open("Serviceoutput.txt", ios::app);   
	if (file.is_open())
	{
		file << serviceRecord->getDate() << " " << serviceRecord->getCost() << endl;
		file.close();
	}
	else
	{
		cout << "Failed to open file for saving ServiceRecord!" << endl;
	}
}

void loadVehiclesFromFile(Vehicle* vehicles[], int& vehicleCount)
{
	ifstream file;
	file.open("vehicles.txt");

	if (file.is_open())
	{
		string type, make, model, fuelType;
		int year;
		double fuelCapacity, batteryCapacity, chargingTime;

		while (file)
		{
			file >> type >> make >> model >> year;

			if (type == "FuelVehicle")
			{
				file >> fuelCapacity >> fuelType;
				vehicles[vehicleCount++] = new FuelVehicle(make, model, year, fuelCapacity, fuelType);
			}
			else if (type == "ElectricVehicle")
			{
				file >> batteryCapacity >> chargingTime;
				vehicles[vehicleCount++] = new ElectricVehicle(make, model, year, batteryCapacity, chargingTime);
			}
			else if (type == "HybridVehicle")
			{
				file >> fuelCapacity >> fuelType >> batteryCapacity >> chargingTime;
				vehicles[vehicleCount++] = new HybridVehicle(make, model, year, fuelCapacity, fuelType, batteryCapacity, chargingTime);
			}
			else
			{
				cout << "Unknown vehicle type in file: " << type << endl;
			}
		}
		file.close();
	}
	else
	{
		cout << "Failed to open file for loading vehicles!" << endl;
	}
}


void loadServiceRecordFromFile(ServiceRecord* serviceRecords[], int& ServiceRecordCount)
{
	ifstream file;
	file.open("service.txt");

	if (file.is_open())
	{
		string serviceDate;
		double serviceCost;

		while (file >> serviceDate >> serviceCost)
		{
			serviceRecords[ServiceRecordCount++] = new ServiceRecord(serviceDate, serviceCost);
		}
		file.close();
	}
	else
	{
		cout << "Failed to open file for loading vehicles!" << endl;
	}
}

// Overloading operators
bool operator<(const Vehicle& v1, const Vehicle& v2) {
	return v1.calculateRange() < v2.calculateRange();
}

bool operator>(const Vehicle& v1, const Vehicle& v2) {
	return v1.calculateRange() > v2.calculateRange();
}

// Overload + operator for ServiceRecord to merge costs
ServiceRecord operator+(const ServiceRecord& r1, const ServiceRecord& r2)
{
	return ServiceRecord(r1.getDate(), r1.getCost() + r2.getCost());
};


int main()
{
	User admin("Ahmad", "4215", "Admin");
	User viewer("Basil", "12345", "Viewer");

	string username, password;
	cout << "Enter username: ";
	getline(cin, username);
	cout << "Enter password: ";
	getline(cin, password);

	User* currentUser = nullptr;


	const int maxVehicles = 10;

	const int maxServiceRecords = 10;

	Vehicle* vehicles[maxVehicles] = { nullptr };

	ServiceRecord* serviceRecords[maxServiceRecords] = { nullptr };

	int vehicleCount = 0;
	int serviceCount = 0;


	if (admin.Permission(username, password))
	{
		currentUser = &admin;
		cout << "Admin logged in successfully!" << endl;

		while (true)
		{
			cout << "\n===== Vehicle Management System =====" << endl;
			cout << "1. Add Vehicle" << endl;
			cout << "2. View Vehicles" << endl;
			cout << "3. Add Service Record" << endl;
			cout << "4. View Service Records" << endl;
			cout << "5. Exit" << endl;

			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			cin.ignore(); 

			if (choice == 1 && currentUser->getRole() == "Admin")
			{
				if (vehicleCount < maxVehicles)
				{
					while (true)
					{
						cout << "===Tell us your Vehicle Type===" << endl;
						cout << "1. FuelVehicle" << endl;
						cout << "2. ElectricVehicle" << endl;
						cout << "3. HybridVehicle" << endl;
						cout << "Enter your choice: ";

						int choice;
						cin >> choice;
						cin.ignore(); 

						if (choice == 1)
						{
							string make, model, fuelType;
							int year;
							double fuelCapacity;

							cout << "Enter vehicle make: " << endl;
							getline(cin, make);
							cout << "Enter vehicle model: " << endl;
							getline(cin, model);

							cout << "Enter vehicle year: " << endl;
							cin >> year;
							while (year <= 0)
							{
								cout << "Year cannot be zero or negative Re-Enter: ";
								cin >> year;
								if (year > 0)
								{
									break;
								}
							}

							cout << "Enter fuel type (e.g., Diesel, Petrol): ";
							getline(cin, fuelType);

							cout << "Enter fuel capacity (in liters): " << endl;
							cin >> fuelCapacity;
							while (fuelCapacity <= 0)
							{
								cout << "fuelCapacity cannot be zero or negative Re-Enter: ";
								cin >> fuelCapacity;
								if (fuelCapacity > 0)
								{
									break;
								}
							}

							vehicles[vehicleCount++] = new FuelVehicle(make, model, year, fuelCapacity, fuelType);
							cout << "Vehicle added successfully!" << endl;

							saveVehicleToFile(vehicles[vehicleCount]);    

						}
						else if (choice == 2)
						{
							string make, model;
							int year;
							double batteryCapacity, chargingTime;

							cout << "Enter vehicle make: " << endl;
							getline(cin, make);
							cout << "Enter vehicle model: " << endl;
							getline(cin, model);

							cout << "Enter vehicle year: " << endl;
							cin >> year;
							while (year <= 0)
							{
								cout << "Year cannot be zero or negative Re-Enter: ";
								cin >> year;
								if (year > 0)
								{
									break;
								}
							}

							cout << "Enter battery capacity (in kWh): " << endl;
							cin >> batteryCapacity;
							while (batteryCapacity <= 0)
							{
								cout << "batteryCapacity cannot be zero or negative Re-Enter: ";
								cin >> batteryCapacity;
								if (batteryCapacity > 0)
								{
									break;
								}
							}

							cout << "Enter charging time (in hours): " << endl;
							cin >> chargingTime;
							while (chargingTime <= 0)
							{
								cout << "chargingTime cannot be zero or negative Re-Enter: ";
								cin >> chargingTime;
								if (chargingTime > 0)
								{
									break;
								}
							}

							vehicles[vehicleCount++] = new ElectricVehicle(make, model, year, batteryCapacity, chargingTime);
							cout << "Vehicle added successfully!" << endl;

							saveVehicleToFile(vehicles[vehicleCount]);       
						}
						else if (choice == 3)
						{
							string make, model, fuelType;
							int year;
							double fuelCapacity, batteryCapacity, chargingTime;

							cout << "Enter vehicle make: " << endl;
							getline(cin, make);
							cout << "Enter vehicle model: " << endl;
							getline(cin, model);

							cout << "Enter vehicle year: " << endl;
							cin >> year;
							while (year <= 0)
							{
								cout << "Year cannot be zero or negative Re-Enter: ";
								cin >> year;
								if (year > 0)
								{
									break;
								}
							}

							cout << "Enter fuel type (e.g., Diesel, Petrol): ";
							getline(cin, fuelType);

							cout << "Enter fuel capacity (in liters): " << endl;
							cin >> fuelCapacity;
							while (fuelCapacity <= 0)
							{
								cout << "fuelCapacity cannot be zero or negative Re-Enter: ";
								cin >> fuelCapacity;
								if (fuelCapacity > 0)
								{
									break;
								}
							}

							cout << "Enter battery capacity (in kWh): " << endl;
							cin >> batteryCapacity;
							while (batteryCapacity <= 0)
							{
								cout << "batteryCapacity cannot be zero or negative Re-Enter: ";
								cin >> batteryCapacity;
								if (batteryCapacity > 0)
								{
									break;
								}
							}

							cout << "Enter charging time (in hours): " << endl;
							cin >> chargingTime;
							while (chargingTime <= 0)
							{
								cout << "chargingTime cannot be zero or negative Re-Enter: ";
								cin >> chargingTime;
								if (chargingTime > 0)
								{
									break;
								}
							}

							vehicles[vehicleCount++] = new HybridVehicle(make, model, year, fuelCapacity, fuelType, batteryCapacity, chargingTime);
							cout << "Vehicle added successfully!" << endl;

							saveVehicleToFile(vehicles[vehicleCount]);      
						}
						else
						{
							cout << "Invalid choice! Please try again." << endl;
						}
					}
				}
				else
				{
					cout << "Vehicle storage is full!" << endl;
				}
			}
			else if (choice == 2)
			{
				loadVehiclesFromFile(vehicles, vehicleCount);

				for (int i = 0; i < vehicleCount; ++i)
				{
					vehicles[i]->display();
					cout << endl;
				}
			}
			else if (choice == 3 && currentUser->getRole() == "Admin")
			{
				if (serviceCount < maxServiceRecords)
				{
					string date;
					double cost;

					cout << "Enter service date: ";
					getline(cin, date);

					cout << "Enter service cost: " << endl;
					cin >> cost;
					while (cost <= 0)
					{
						cout << "Year cannot be zero or negative Re-Enter: ";
						cin >> cost;
						if (cost > 0)
						{
							break;
						}
					}

					serviceRecords[serviceCount++] = new ServiceRecord(date, cost);

					cout << "Service record added successfully!" << endl;

					saveServiceToFile(serviceRecords[serviceCount]);   
				}
				else
				{
					cout << "Service records are full!" << endl;
				}
			}
			else if (choice == 4)
			{

				loadServiceRecordFromFile(serviceRecords, serviceCount);

				for (int i = 0; i < serviceCount; ++i)
				{
					serviceRecords[i]->display();
					cout << endl;
				}
			}
			else if (choice == 5)
			{
				cout << "Exiting program." << endl;
				break;
			}
			else
			{
				cout << "Invalid choice! Please try again." << endl;
			}
		}
	}
	else if (viewer.Permission(username, password))
	{
		currentUser = &viewer;
		cout << "Viewer logged in successfully!" << endl;

		while (true)
		{
			cout << "\n===== Vehicle Management System =====" << endl;
			cout << "1. View Vehicles" << endl;
			cout << "2. View Service Records" << endl;
			cout << "3. Exit" << endl;

			cout << "Enter your choice: ";

			int choice;
			cin >> choice;
			cin.ignore(); 

			if (choice == 1)
			{
				loadVehiclesFromFile(vehicles, vehicleCount);

				for (int i = 0; i < vehicleCount; ++i)
				{
					vehicles[i]->display();
					cout << endl;
				}
			}
			else if (choice == 2)
			{

				loadServiceRecordFromFile(serviceRecords, serviceCount);

				for (int i = 0; i < serviceCount; ++i)
				{
					serviceRecords[i]->display();
					cout << endl;
				}
			}
			else if (choice == 3)
			{
				cout << "Exiting program." << endl;
				break;
			}
			else
			{
				cout << "Invalid choice! Please try again." << endl;
			}

		}

	}
	else
	{
		cout << "Our System Shows you are an Outsider! (Invalid User)" << endl;
		
	}


	

	for (int i = 0; i < vehicleCount; ++i) {
		delete vehicles[i];
	}
	for (int i = 0; i < serviceCount; ++i) {
		delete serviceRecords[i];
	}

	system("pause");
	return 0;
}