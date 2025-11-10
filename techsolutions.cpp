#include <iostream>
#include <string>
using namespace std;

class employee {
private:
    string name;   
    int id;
    double salary;

    static int employeeCount;
    static const string companyName;

public:
    // Constructor with initializer list
    employee(const string& n, int i, double s)
        : name(n), id(i), salary(s) {
        employeeCount++;
    }

    // Copy Constructor
    employee(const employee& other)
        : name(other.name), id(other.id), salary(other.salary) {
        employeeCount++;
    }

    ~employee() {
        employeeCount--;
    }

    // Const function to display data
    void display() const {
        cout << "Company: " << companyName << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: $" << salary << endl;
        cout << "--------------------------------" << endl;
    }

    // Static function to show total employees
    static void showTotalemployees() {
        cout << "Total employees: " << employeeCount << endl;
    }

    // Update details using 'this' pointer
    void update(const string& newName, double newSalary) {
        this->name = newName;
        this->salary = newSalary;
    }

    // Return a new employee object (promotion)
    employee promote(double increment) {
        employee temp(*this);
        temp.salary += increment;
        return temp;
    }

    // Shallow copy demo (manual, just reference the same data)
    employee shallowCopy() {
        employee temp(*this);
        temp.name = this->name; // For string, still deep copy (safe)
        return temp;
    }
};

// Static members initialization
int employee::employeeCount = 0;
const string employee::companyName = "TechSolutions";

void showemployee(employee e) {
    cout << "\n[Displaying employee Passed to Function]\n";
    e.display();
}

int main() {
    cout << "=== employee Management System: TechSolutions ===\n\n";

    employee* e1 = new employee("Muhammad Abdullah", 1008, 55000);
    employee* e2 = new employee("chaudhary Abdullah", 102, 62000);

    e1->display();
    e2->display();
    employee::showTotalemployees();

    showemployee(*e1);

    employee promoted = e1->promote(5000);
    cout << "\n[After Promotion]\n";
    promoted.display();

    cout << "\n=== Demonstrating Copy Behavior (auto deep copy) ===\n";
    employee copy = *e1;  // Deep copy handled by string
    e1->update("Alice Cooper", 70000);

    cout << "\nAfter modifying original:\n";
    e1->display();
    copy.display();

    delete e1;
    delete e2;

    cout << "\nAfter deleting dynamic objects:\n";
    employee::showTotalemployees();

    return 0;
}
