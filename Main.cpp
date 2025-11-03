#include <iostream>
#include <vector>
#include <algorithm>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

bool comparebyArea(Shape* s1, Shape* s2)
{
    return (s1->Area() < s2->Area());
}

int main()
{
    vector<Shape*> myShape;
    vector<Shape*> deletedShapes; // for undo
    int choice;

    while (true)
    {
        cout << "\n-------------- Geometry Shape Analyzer --------------" << endl;
        cout << "1. Add any Shape" << endl;
        cout << "2. Display All Shapes" << endl;
        cout << "3. Sort Shapes by Area" << endl;
        cout << "4. Search Shape by Perimeter" << endl;
        cout << "5. Delete Last Shape" << endl;
        cout << "6. Undo Last Delete" << endl;
        cout << "7. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int c;
            cout << "1. Circle\n2. Rectangle\n3. Triangle\nChoice: ";
            cin >> c;

            if (c == 1)
            {
                double r;
                cout << "Enter radius: ";
                cin >> r;
                myShape.push_back(new Circle(r));
            }
            else if (c == 2)
            {
                double l, b;
                cout << "Enter length and breadth: ";
                cin >> l >> b;
                myShape.push_back(new Rectangle(l, b));
            }
            else if (c == 3)
            {
                double a, b, c_;
                cout << "Enter sides A, B, C: ";
                cin >> a >> b >> c_;
                myShape.push_back(new Triangle(a, b, c));
            }
            else
                cout << "Invalid shape choice!" << endl;
        }
        else if (choice == 2)
        {
            if (myShape.empty())
                cout << "No shapes available!" << endl;
            else
            {
                for (auto s : myShape)
                {
                    s->displayShape();
                    cout << "Area: " << s->Area() << " | Perimeter: " << s->Perimeter() << endl;
                }
            }
        }
        else if (choice == 3)
        {
            if (myShape.empty())
                cout << "No shapes to sort!" << endl;
            else
            {
                sort(myShape.begin(), myShape.end(), comparebyArea);
                cout << "Shapes sorted by area!" << endl;
            }
        }
        else if (choice == 4)
        {
            if (myShape.empty())
                cout << "No shapes to search!" << endl;
            else
            {
                double p;
                cout << "Enter perimeter to search: ";
                cin >> p;
                bool found = false;

                for (auto s : myShape)
                {
                    if (s->Perimeter() == p)
                    {
                        s->displayShape();
                        cout << "Found with Area: " << s->Area() << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Shape not found!" << endl;
            }
        }
        else if (choice == 5)
        {
            if (myShape.empty())
                cout << "No shape to delete!" << endl;
            else
            {
                Shape* last = myShape.back();
                myShape.pop_back();
                deletedShapes.push_back(last);
                cout << "Last shape deleted!" << endl;
            }
        }
        else if (choice == 6)
        {
            if (deletedShapes.empty())
                cout << "No deleted shapes to undo!" << endl;
            else
            {
                Shape* lastDeleted = deletedShapes.back();
                deletedShapes.pop_back();
                myShape.push_back(lastDeleted);
                cout << "Undo successful — shape restored!" << endl;
            }
        }
        else if (choice == 7)
        {
            for (auto s : myShape)
                delete s;
            for (auto s : deletedShapes)
                delete s;

            cout << "Exiting program. All memory cleared!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
