//
// Created by velocitatem on 9/27/24.
//

#include <string>
#ifndef CELLS_H
#define CELLS_H
#include <nlohmann/json.hpp>


#include "board.h"

class Board;
using namespace std;


class CellularAutomaton {
public:
protected:
    CellularAutomaton() = default;
    static void compute(Board *board); // Make compute a pure virtual function
public:
    virtual ~CellularAutomaton() = default;
};

class DiscreteAutomaton : public CellularAutomaton {
public:
    virtual double get_value() = 0;
    virtual int get_x() = 0;
    virtual int get_y() = 0;
    void set_x(int x);
    void set_y(int y);
    void set_value(double value);
private:
    int x, y;
    double value;
};

class ContinuousAutomaton : public CellularAutomaton {
public:
    static void compute(Board *board); // Pure virtual function for DiscreteAutomaton
};

/// ====== END OF ABSTRACT CLASSES ====== ///


class ParticleLife : public ContinuousAutomaton {
public:
    ParticleLife(int x, int y, string species); //TODO: Color
    // copy
    ParticleLife(const ParticleLife &cell) {
        x = cell.x;
        y = cell.y;
        species = cell.species;
    }
    int get_x();
    int get_y();
    string get_species();
    static Board compute(Board *board);
private:
    int x, y;
    string species;
};


class BasicLife : public DiscreteAutomaton {
public:
    BasicLife(int x, int y, double value);
    int get_x(); int get_y();
    double get_value();
    static void compute(Board *board);
private:
    int x, y;
    double value;
};


class SmithLife : public DiscreteAutomaton {
public:
    SmithLife(int x, int y, double value);
    int get_x(); int get_y();
    double get_value();
    static void compute(Board &board);
private:
    int x, y;
    double value;

};


#endif //CELLS_H
