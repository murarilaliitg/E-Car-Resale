#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
class Car {
	private:
	    string make_;
	    string model_;
	    int year_;
	    double price_;
	    int mileage_;
	public:
	    Car(const string& make, const string& model, int year, double price, int mileage)
	    {
	    	make_=make;
	    	model_=model;
			year_=year;
			price_=price;
			mileage_=mileage;
		}
    string getMake() const { return make_; }
    string getModel() const { return model_; }
    int getYear() const { return year_; }
    double getPrice() const { return price_; }
    int getMileage() const { return mileage_; }

    void displayDetails() const {
        cout << "Make: " << make_ << endl;
        cout << "Model: " << model_ << endl;
        cout << "Year: " << year_ << endl;
        cout << "Price: $" << price_ << endl;
        cout << "Mileage: " << mileage_ << " miles" << endl;
    }
};
vector<Car> cars;
int numOfCars=0;
int savedCars=0;
class CarInventory {
public:
	//vector<Car> cars;
	 void addCar(const Car& car) {
        cars.push_back(car);
    }
    void removeCar(int index) {
        if (index >= 0 && index < cars.size()) {
            cars.erase(cars.begin() + index);
        }
    }

    int getInventorySize() {
        return cars.size();
    }

    Car getCarByIndex(int index) {
        if (index >= 0 && index < cars.size()) {
            return cars[index];
        }
        // Return a default car object if index is out of range
        return Car("", "", 0, 0.0, 0);
    }
};
 void addCar() 
 {
 	string make, model;
    int year, mileage;
    double price;
    
	cout << "Enter car make: ";
    cin >> make;
    
    cout << "Enter car model: ";
    cin >> model;
    
	cout << "Enter car year: ";
    cin >> year;

    cout << "Enter car price: ";
    cin >> price;

    cout << "Enter car mileage: ";
    cin >> mileage;

    Car newCar(make, model, year, price, mileage);
    cars.push_back(newCar);
    numOfCars++;
    std::cout << "Car added successfully!" << std::endl;
        //cars.push_back(car);
    }
void removeCar(int index) 
{
        if (index >= 0 && index < numOfCars) 
		{
            cars.erase(cars.begin() + index);
        }
}
    
void saveCarsToFile(const string& filename) {
    fstream file;//(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    if(savedCars<numOfCars)
	{
		file.open(filename, std::ios::app);
    	cout<<"start adding"<<endl;
	    for(int i=savedCars;i<numOfCars;i++)
		{
			Car car=cars[i];
			cout<<i<<endl;
			file << car.getMake() << "," << car.getModel() << "," << car.getYear() << ","
	             << car.getPrice() << "," << car.getMileage() << "\n";
		}
		savedCars=numOfCars;
	    file.close();
	    cout << "Cars saved to file successfully!" << endl;
	}
    else cout<<"Already Add"<<endl;
}


void loadCarsFromFile(const std::string& filename) {
    ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    cars.clear();

    string line;
    while (getline(file, line)) 
	{
        stringstream iss(line);
        string make, model;
        int year, mileage;
        double price;

        if (!(iss >> make >> model >> year >> price >> mileage)) {
            cerr << "Error parsing line: " << line << endl;
            continue;
        }

        Car newCar(make, model, year, price, mileage);
        cars.push_back(newCar);
    }

    file.close();

    cout << "Cars loaded from file successfully!" << endl;
}
// Search for a car by make
void searchCarByMake(const std::string& make) {
    std::cout << "Searching for cars with make: " << make << std::endl;

    bool found = false;

    for (const auto& car : cars) {
        if (car.getMake() == make) {
            car.displayDetails();
            std::cout << "------------------------" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No cars with make '" << make << "' found." << std::endl;
    }
}

// Sort cars by price in ascending order
bool compareCarByPriceAsc(const Car& car1, const Car& car2) {
    return car1.getPrice() < car2.getPrice();
}

// Sort cars by price in descending order
bool compareCarByPriceDesc(const Car& car1, const Car& car2) {
    return car1.getPrice() > car2.getPrice();
}

// List all cars
void listCars() {
    std::cout << "Listing all cars:" << std::endl;

    for (const auto& car : cars) {
        car.displayDetails();
        std::cout << "------------------------" << std::endl;
    }
}


int main()
{
	 int choice;

    while (true) {
        std::cout << "Car Selling System" << std::endl;
        std::cout << "1. Add a car" << std::endl;
        std::cout << "2. List all cars" << std::endl;
        std::cout << "3. Search cars by make" << std::endl;
        std::cout << "4. Sort cars by price (ascending)" << std::endl;
        std::cout << "5. Sort cars by price (descending)" << std::endl;
        std::cout << "6. Save cars to file" << std::endl;
        std::cout << "7. Load cars from file" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
            	addCar();
//                std::string make, model;
//                int year, mileage;
//                double price;
//
//                std::cout << "Enter car make: ";
//                std::cin >> make;
//
//                std::cout << "Enter car model: ";
//                std::cin >> model;
//
//                std::cout << "Enter car year: ";
//                std::cin >> year;
//
//                std::cout << "Enter car price: ";
//                std::cin >> price;
//
//                std::cout << "Enter car mileage: ";
//                std::cin >> mileage;
//
//                Car newCar(make, model, year, price, mileage);
//                cars.push_back(newCar);
//                numOfCars++;
//                std::cout << "Car added successfully!" << std::endl;
                break;
            }
            case 2:
                listCars();
                break;
            case 3: {
                std::string make;
                std::cout << "Enter car make to search: ";
                std::cin >> make;
                searchCarByMake(make);
                break;
            }
            case 4:
                std::sort(cars.begin(), cars.end(), compareCarByPriceAsc);
                std::cout << "Cars sorted by price (ascending)!" << std::endl;
                break;
            case 5:
                std::sort(cars.begin(), cars.end(), compareCarByPriceDesc);
                std::cout << "Cars sorted by price (descending)!" << std::endl;
                break;
            case 6: {
                std::string filename;
                std::cout << "Enter filename to save cars: ";
                std::cin >> filename;
                saveCarsToFile(filename);
                break;
            }
            case 7: {
                std::string filename;
                std::cout << "Enter filename to load cars: ";
                std::cin >> filename;
                loadCarsFromFile(filename);
                break;
            }
            case 8:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
	
}
