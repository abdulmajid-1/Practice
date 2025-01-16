#include <iostream>
using namespace std;

class FamilyMember {
public:
    string name;
    int age;
    FamilyMember* firstChild; 
    FamilyMember* nextSibling; 

    // Constructor
    FamilyMember(string name, int age) {
        this->name = name;
        this->age = age;
        this->firstChild = NULL;
        this->nextSibling = NULL;
    }
};

class FamilyTree {
private:
    FamilyMember* root;

public:
    FamilyTree(FamilyMember* root) {
        this->root = root;
    }

    // Add a child to a parent
    void addChild(FamilyMember* parent, FamilyMember* child) {
        if (parent->firstChild == NULL) {
            parent->firstChild = child; // First child
        } else {
            FamilyMember* current = parent->firstChild;
            while (current->nextSibling != NULL)
            {
                current = current->nextSibling; 
            }
            current->nextSibling = child;
        }
    }

    // Find a family member by name
    FamilyMember* findMember(FamilyMember* node, const string& name) {
        if (node == NULL) return NULL;

        if (node->name == name) return node;

        // Check children
        FamilyMember* found = findMember(node->firstChild, name);
        if (found != NULL) 
            return found;

        // Check siblings
        return findMember(node->nextSibling, name);
    }

    // Find children of a specific member
    void findChildren(const string& name) {
        FamilyMember* member = findMember(root, name);
        if (member == NULL) {
            cout << "No person named " << name << " found in the tree." << endl;
            return;
        }

        if (member->firstChild == NULL) {
            cout << name << " has no children." << endl;
            return;
        }

        cout << "Children of " << name << ": ";
        FamilyMember* child = member->firstChild;
        while (child != NULL) {
            cout << child->name << " ";
            child = child->nextSibling;
        }
        cout << endl;
    }

    // Find the oldest member in the tree
    void findOldestMember() {
        FamilyMember* oldest = findOldest(root);
        if (oldest != NULL) {
            cout << "The oldest member is " << oldest->name << " with age " << oldest->age << "." << endl;
        }
    }

private:
    // Helper function to find the oldest member
    FamilyMember* findOldest(FamilyMember* node) {
        if (node == NULL) 
            return NULL;

        FamilyMember* oldest = node;

        // Check children
        FamilyMember* child = findOldest(node->firstChild);
        if (child != NULL && child->age > oldest->age) 
        {
            oldest = child;
        }

        // Check siblings
        FamilyMember* sibling = findOldest(node->nextSibling);
        if (sibling != NULL && sibling->age > oldest->age) 
        {
            oldest = sibling;
        }

        return oldest;
    }
};

int main() 
{
    FamilyMember* grandparent = new FamilyMember("Grandparent", 78);
    FamilyMember* parent1 = new FamilyMember("Parent1", 50);
    FamilyMember* parent2 = new FamilyMember("Parent2", 48);
    FamilyMember* child1 = new FamilyMember("Child1", 20);
    FamilyMember* child2 = new FamilyMember("Child2", 18);
    FamilyMember* child4 = new FamilyMember("Child4",44);

    FamilyTree familyTree(grandparent);
    familyTree.addChild(grandparent, parent1);
    familyTree.addChild(grandparent, parent2);
    familyTree.addChild(parent1, child1);
    familyTree.addChild(parent1, child2);
    

    familyTree.findChildren("Parent1");

    familyTree.findOldestMember();

    // Cleanup
    delete grandparent;
    delete parent1;
    delete parent2;
    delete child1;
    delete child2;

    return 0;
}
