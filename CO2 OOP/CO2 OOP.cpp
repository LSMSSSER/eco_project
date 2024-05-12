#include <iostream>
#include <cmath> // Для использования функции округления
#include <string>

using namespace std;

class Truck {
private:
    int truckCapacity;
    int WasteTruckConsumption;
    float CO2Coefficient; 
    float FuelDensity;
    int idleFuel;
    int workFuel;
    int warmUpTime;
    float truck_fuel_energy;
    string name_fuel;

public:
    Truck() {
        truckCapacity = 0;
        WasteTruckConsumption = 0;
        CO2Coefficient = 0;
        FuelDensity = 0;
        idleFuel = 0;
        workFuel = 0;
        warmUpTime = 0;
        truck_fuel_energy = 0;
        name_fuel = "";
    }

    ~Truck(void) {};

    void Input_values() {
        int choice_of_fuel;
        int choiceBenz;
        int choiceDiesel;
        int choiceGas;

        cout << "Введите грузоподъемность мусоровоза в килограммах: ";
        cin >> truckCapacity;

        cout << "Введите средний расход топлива мусоровоза (л/100км): ";
        cin >> WasteTruckConsumption;

        cout << "Введите расход топлива на холостом ходу  (л/ч): ";
        cin >> idleFuel;

        cout << "Введите время прогрева мусоровоза в минутах: ";
        cin >> warmUpTime;

        cout << "Укажите вид топлива для мусоровоза" << endl;
        cout << "(0) - бензин" << endl;
        cout << "(1) - дизель" << endl;
        cout << "(2) - газ" << endl;
        cin >> choice_of_fuel;

        switch (choice_of_fuel) {
        case 0:
            truck_fuel_energy = 33.5;
            name_fuel = "benz";
            cout << "Выберите марку бензина: " << endl;
            cout << "(0) - А-76" << endl;
            cout << "(1) - АИ-92" << endl;
            cout << "(2) - АИ-93" << endl;
            cout << "(3) - АИ-95" << endl;
            cout << "(4) - АИ-98" << endl;
            cin >> choiceBenz;
            switch (choiceBenz) {
            case 0:
                CO2Coefficient = 3.149;
                FuelDensity = 0.715;
                break;
            case 1:
                CO2Coefficient = 3.149;
                FuelDensity = 0.735;
                break;
            case 2:
                CO2Coefficient = 3.149;
                FuelDensity = 0.745;
                break;
            case 3:
                CO2Coefficient = 3.149;
                FuelDensity = 0.750;
                break;
            case 4:
                CO2Coefficient = 3.149;
                FuelDensity = 0.765;
                break;
            }
            break;
        case 1:
            truck_fuel_energy = 43;
            name_fuel = "diesel";
            cout << "Выберите вид дизельного топлива: " << endl;
            cout << "(0) - летний дизель" << endl;
            cout << "(1) - зимний дизель" << endl;
            cin >> choiceDiesel;
            switch (choiceDiesel) {
            case 0:
                CO2Coefficient = 3.149;
                FuelDensity = 0.860;
                break;
            case 1:
                CO2Coefficient = 3.149;
                FuelDensity = 0.840;
                break;
            }
            break;
        case 2:
            truck_fuel_energy = 27;
            name_fuel = "gas";
            cout << "Выберите вид газ: " << endl;
            cout << "(0) - сжиженый нефтяной (пропан)" << endl;
            cout << "(1) - сжиженый природный газ (спг)" << endl;
            cin >> choiceGas;
            switch (choiceGas) {
            case 0:
                CO2Coefficient = 2.903;
                FuelDensity = 0.528;
                break;
            case 1:
                CO2Coefficient = 2.710;
                FuelDensity = 0.424;
                break;
            }
            break;
        }

        cout << "Введите расход топлива при работе оборудования (л/ч): ";
        cin >> workFuel;
    }

    int getTruckCapacity() const { return truckCapacity; }

    int getWasteTruckConsumption() const { return WasteTruckConsumption; }

    float getCO2Coefficient() const { return CO2Coefficient; }

    float getFuelDensity() const { return FuelDensity; }

    int getIdleFuel() const { return idleFuel; }

    int getWorkFuel() const { return workFuel; }

    int getWarmUpTime() const { return warmUpTime; }

    float get_fuel_energy() const { return truck_fuel_energy; }

    string get_name_fuel() const { return name_fuel; }

    friend ostream& operator<<(ostream& out, const Truck& a) {
        out << "Грузоподъемность мусоровоза в килограммах:" << a.truckCapacity << "\n";
        out << "Средний расход топлива мусоровоза (л/100км): " << a.WasteTruckConsumption << "\n";
        out << "Расход топлива на холостом ходу  (л/ч):" << a.idleFuel << "\n";
        out << "Расход топлива при работе оборудования (л/ч):" << a.workFuel << "\n";
        out << "Время прогрева мусоровоза в минутах" << a.warmUpTime << "\n";

        return out;
    }
};

class Population {
private:
    int population;
    float accumulationNorm; 
    float additionalPercentage;
public:
    Population() {
        population = 0;
        accumulationNorm = 0;
        additionalPercentage = 0;
    }

    ~Population(void) {};

    void Input_population() {
        int choice;
        int choice1;

        cout << "Введите число жителей: ";
        cin >> population;

        cout << "(0) Отредактировать норматив накопления твердых коммунальных отходов" << endl;
        cout << "(1) Подтвердить норму накопления твердых коммунальных отходов (0.16051)" << endl;
        cout << "Введите (0) или (1): ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Введите новую норму образования отходов: ";
            cin >> accumulationNorm;
            break;
        case 1:
            accumulationNorm = 0.16051;
            break;
        }

        cout << "(0) Небольшой населенный пункт" << endl;
        cout << "(1) Большой населенный пункт" << endl;
        cout << "Введите (0) или (1): ";
        cin >> choice1;

        switch (choice1) {
        case 0:
            additionalPercentage = 0.3;
            break;
        case 1:
            additionalPercentage = 0.5;
            break;
        }
    }

    int getPopulation() const { return population; }

    float getAccumulationNorm() const { return accumulationNorm; }

    float getAdditionalPercentage() const { return additionalPercentage; }

    friend ostream& operator<<(ostream& out, const Population& a) {
        out << "Число жителей:" << a.population << "\n";
        out << "Норматив накопления твердых коммунальных отходов: " << a.accumulationNorm << "\n";
        out << "Добавочный процент: " << a.additionalPercentage << "\n";

        return out;
    }
};

float recalculation(Truck& a) {
    int choice;
    float benzin = 33.5;
    float diesel = 43;
    float gas = 36.12;
    float fuel_energy;

    cout << "Вы используете: " << a.get_name_fuel() << endl;

    cout << "Для какого вида топлива нужен перерасчет?" << endl;
    cout << "(1) - Бензин" << endl;
    cout << "(2) - Дизель" << endl;
    cout << "(3) - Газ" << endl;

    cin >> choice;
    switch (choice) {
    case 1:
        fuel_energy = a.getWasteTruckConsumption() / 100 * a.get_fuel_energy();
        return (fuel_energy / benzin);
        break;
    case 2:
        fuel_energy = a.getWasteTruckConsumption() / 100 * a.get_fuel_energy();
        return (fuel_energy / diesel);
        break;
    case 3:
        fuel_energy = a.getWasteTruckConsumption() / 100 * a.get_fuel_energy();
        return (fuel_energy / gas);
        break;
    }    
}

int main() {
    system("chcp 1251 > null");
    float RouteLength, workTime, TotalWaste, Emissions, idleConsumption, workConsumption, warmUpConsumption, summa;
    long trips111;

    Truck trc;
    trc.Input_values();

    Population pop;
    pop.Input_population();

    cout << "Укажите протяженность маршрута в километрах: ";
    cin >> RouteLength;

    cout << "Введите время работы оборудования в минутах: ";
    cin >> workTime;

    cout << "\033[2J\033[1;1H";

    float population = pop.getPopulation();
    float accumulationNorm = pop.getAccumulationNorm();
    float additionalPercentage = pop.getAdditionalPercentage();
    float truckCapacity = trc.getTruckCapacity();
    float WasteTruckConsumption = trc.getWasteTruckConsumption();
    float FuelDensity = trc.getFuelDensity();
    float CO2Coefficient = trc.getCO2Coefficient();
    float idleFuel = trc.getIdleFuel();
    float workFuel = trc.getWorkFuel();
    float warmUpTime = trc.getWarmUpTime();

    float waste = (population * accumulationNorm) + (population * accumulationNorm * additionalPercentage);
    cout << "Количество образованных отходов (тонн): " << waste << endl;

    float waste2 = waste * 1000;
    float trips = waste2 / truckCapacity;
    trips111 = round(trips); // Используем std::round для округления
    cout << "Количество маршрутов: " << trips111 << endl;
    TotalWaste = trips * RouteLength;

    Emissions = WasteTruckConsumption * FuelDensity * CO2Coefficient * TotalWaste / 100;
    cout << "CО2 пробег (кг): " << Emissions << endl;

    idleConsumption = idleFuel * (warmUpTime / 60) * FuelDensity;
    workConsumption = workFuel * (workTime / 60) * FuelDensity;
    warmUpConsumption = CO2Coefficient * idleConsumption;
    float workConsumptionTotal = CO2Coefficient * workConsumption;
    summa = warmUpConsumption + workConsumptionTotal + Emissions;

    cout << "Выброс CО2 при прогреве мусоровоза (тонн): " << warmUpConsumption << endl;
    cout << "Выброс CO2 при работе оборудования (тонн): " << workConsumptionTotal << endl;
    cout << "Объем выбросов CO2 суммарно (тонн): " << summa << endl;

    cout << recalculation(trc) << endl;
    return 0;
}



//workuptime плотность топлива 