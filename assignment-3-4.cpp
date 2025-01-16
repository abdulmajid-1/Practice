#include <iostream>
using namespace std;

class Employee {
public:
    string name;            
    Employee* nextSibling;  
    Employee* firstChild;    

    // Constructor
    Employee(string name) {
        this->name = name;
        this->nextSibling = NULL;
        this->firstChild = NULL;
    }
};

class Organization {
private:
    Employee* ceo;

public:
    // Constructor
    Organization(string ceoName) {
        ceo = new Employee(ceoName);
    }

    Employee* findEmployee(Employee* current, const string& name) {
        if (current == NULL) return NULL;
        if (current->name == name) return current;

        Employee* found = findEmployee(current->firstChild, name);
        if (found) return found;

        return findEmployee(current->nextSibling, name);
    }

    void addEmployee(const string& managerName, const string& employeeName) {
        Employee* manager = findEmployee(ceo, managerName);
        if (!manager) {
            cout << "Manager " << managerName << " not found in the organization." << endl;
            return;
        }

        Employee* newEmployee = new Employee(employeeName);

        if (manager->firstChild == NULL) {
            manager->firstChild = newEmployee; 
        } else {
            Employee* sibling = manager->firstChild;
            while (sibling->nextSibling != NULL) {
                sibling = sibling->nextSibling; 
            }
            sibling->nextSibling = newEmployee; 
        }
    }

    void displaySubordinates(const string& managerName) {
        Employee* manager = findEmployee(ceo, managerName);
        if (!manager) {
            cout << "Manager " << managerName << " not found in the organization." << endl;
            return;
        }

        cout << "Employees under " << managerName << ": ";
        displaySubordinatesHelper(manager->firstChild);
        cout << endl;
    }

    void displaySubordinatesHelper(Employee* current) {
        if (current == NULL) return;

        cout << current->name << " ";
        displaySubordinatesHelper(current->firstChild); 
        displaySubordinatesHelper(current->nextSibling);
    }

    int countEmployees() {
        return countEmployeesHelper(ceo);
    }

    int countEmployeesHelper(Employee* current) 
    {
        if (current == NULL) return 0;

        return 1 + countEmployeesHelper(current->firstChild) + countEmployeesHelper(current->nextSibling);
    }

    ~Organization() {
        deleteHierarchy(ceo);
    }

    void deleteHierarchy(Employee* current) 
    {
        if (current == NULL) return;

        deleteHierarchy(current->firstChild); 
        deleteHierarchy(current->nextSibling);
        delete current;                         
    }
};


int main()
{
    Organization org("CEO");


    org.addEmployee("CEO", "Manager1");
    org.addEmployee("CEO", "Manager2");
    org.addEmployee("Manager1", "Employee1");
    org.addEmployee("Manager1", "Employee2");
    org.addEmployee("Manager2", "Employee3");


    org.displaySubordinates("Manager1");


    cout << "Total number of employees: " << org.countEmployees() << endl;

    return 0;
}
