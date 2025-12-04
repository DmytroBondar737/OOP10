#pragma once
#include <iostream>
using namespace std;

class Triangle {
protected:
    double a, b, c;
public:
    virtual ~Triangle() {}
    virtual void print() const = 0;
    virtual double getMedian(char side) const = 0;
    virtual double getMiddleLine(char side) const = 0;
};

class TriangleByVertices : public Triangle {
private:
    double x1, y1, x2, y2, x3, y3;
    void calcSides();
public:
    TriangleByVertices(double x1, double y1, double x2, double y2, double x3, double y3);
    void print() const override;
    double getMedian(char side) const override;
    double getMiddleLine(char side) const override;
};

class TriangleBySides : public Triangle {
public:
    TriangleBySides(double a, double b, double c);
    void print() const override;
    double getMedian(char side) const override;
    double getMiddleLine(char side) const override;
};

class TriangleByMedians : public Triangle {
private:
    double ma, mb, mc;
    void calcSides();
public:
    TriangleByMedians(double ma, double mb, double mc);
    void print() const override;
    double getMedian(char side) const override;
    double getMiddleLine(char side) const override;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double leg1, double leg2);
    void print() const override;
    double getMedian(char side) const override;
    double getMiddleLine(char side) const override;
    double getInscribed() const;
    double getCircumscribed() const;
};
