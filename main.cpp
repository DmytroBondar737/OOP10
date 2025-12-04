#include "triangle.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    TriangleByVertices t1(0, 0, 4, 0, 0, 3);
    TriangleBySides t2(3, 4, 5);
    TriangleByMedians t3(4, 5, 6);
    RightTriangle t4(3, 4);

    Triangle* triangles[4] = { &t1, &t2, &t3, &t4 };

    for (int i = 0; i < 4; i++) {
        triangles[i]->print();
        cout << "Median: " << triangles[i]->getMedian('a') << endl;
        cout << "Middle line: " << triangles[i]->getMiddleLine('a') << endl << endl;
    }

    cout << "Inscribed: " << t4.getInscribed() << endl;
    cout << "Circumscribed: " << t4.getCircumscribed() << endl;

    return 0;
}
