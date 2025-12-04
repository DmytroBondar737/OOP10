#include "triangle.h"
#include <cmath>

// TriangleByVertices
void TriangleByVertices::calcSides() {
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
}

TriangleByVertices::TriangleByVertices(double x1, double y1, double x2, double y2, double x3, double y3)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
    calcSides();
}

void TriangleByVertices::print() const {
    cout << "Triangle vertices: (" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ") (" << x3 << "," << y3 << ")\n";
}

double TriangleByVertices::getMedian(char side) const {
    if (side == 'a') return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    if (side == 'b') return 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
    return 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
}

double TriangleByVertices::getMiddleLine(char side) const {
    if (side == 'a') return a / 2;
    if (side == 'b') return b / 2;
    return c / 2;
}

// TriangleBySides
TriangleBySides::TriangleBySides(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void TriangleBySides::print() const {
    cout << "Triangle sides: " << a << " " << b << " " << c << "\n";
}

double TriangleBySides::getMedian(char side) const {
    if (side == 'a') return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    if (side == 'b') return 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
    return 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
}

double TriangleBySides::getMiddleLine(char side) const {
    if (side == 'a') return a / 2;
    if (side == 'b') return b / 2;
    return c / 2;
}

// TriangleByMedians
void TriangleByMedians::calcSides() {
    a = (2.0 / 3.0) * sqrt(2 * mb * mb + 2 * mc * mc - ma * ma);
    b = (2.0 / 3.0) * sqrt(2 * ma * ma + 2 * mc * mc - mb * mb);
    c = (2.0 / 3.0) * sqrt(2 * ma * ma + 2 * mb * mb - mc * mc);
}

TriangleByMedians::TriangleByMedians(double ma, double mb, double mc) : ma(ma), mb(mb), mc(mc) {
    calcSides();
}

void TriangleByMedians::print() const {
    cout << "Triangle medians: " << ma << " " << mb << " " << mc << "\n";
}

double TriangleByMedians::getMedian(char side) const {
    if (side == 'a') return ma;
    if (side == 'b') return mb;
    return mc;
}

double TriangleByMedians::getMiddleLine(char side) const {
    if (side == 'a') return a / 2;
    if (side == 'b') return b / 2;
    return c / 2;
}

// RightTriangle
RightTriangle::RightTriangle(double leg1, double leg2) {
    a = leg1;
    b = leg2;
    c = sqrt(leg1 * leg1 + leg2 * leg2);
}

void RightTriangle::print() const {
    cout << "Right triangle: " << a << " " << b << " " << c << "\n";
}

double RightTriangle::getMedian(char side) const {
    if (side == 'a') return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    if (side == 'b') return 0.5 * sqrt(2 * a * a + 2 * c * c - b * b);
    return 0.5 * sqrt(2 * a * a + 2 * b * b - c * c);
}

double RightTriangle::getMiddleLine(char side) const {
    if (side == 'a') return a / 2;
    if (side == 'b') return b / 2;
    return c / 2;
}

double RightTriangle::getInscribed() const {
    return (a + b - c) / 2;
}

double RightTriangle::getCircumscribed() const {
    return c / 2;
}
