// diff components used in circuits
#include <cstdio>

// template use?
class Joint // joint btw any two components
{

};

class Capacitor
{
private:
    float charge;
    float capacitance;
    float potential_diff;

    float pos_x;
    float pos_y;
    bool orientation;

    Joint* positive_terminal;
    Joint* negative_terminal;

    //list::iterator neg_term_itr  // this comes from the component list in Joint to make destroying ez
    //list::iterator pos_term_itr

public:
    void set_pos_terminal(Joint* P)
    {
        positive_terminal = P;
    }

    void set_neg_terminal(Joint* N)
    {
        negative_terminal = N;
    }

    void set_charge(float chrg)
    {
        charge = chrg;
    }

    void set_cap(float cap)
    {
        capacitance = cap;
    }

    Capacitor(float cap, float chrg = 0, float xpos = 0, float ypos = 0, Joint* P = NULL, Joint* N = NULL) // had to import <cstdio> for NULL, could cause prblmn in future
    {
        if (cap == 0) cap = 0.1;

        charge = chrg;
        capacitance = cap;
        potential_diff = charge/capacitance;

        pos_x = xpos;
        pos_y = ypos;

        positive_terminal = P;
        negative_terminal = N;
    }

    Capacitor() : charge(0), capacitance(0.1), potential_diff(0), positive_terminal(NULL), negative_terminal(NULL)
    {}

    ~Capacitor()
    {
        // setting joints to the capacitor as NULL
    }
};

class Inductor
{
private:
    float inductance;

    Joint* terminal_1;
    Joint* terminal_2;

    // list::iterator term_1_itr;
    // list::iterator term_2_itr;

    float pos_x;
    float pos_y;
    bool orientation;

public:
    Inductor(float indc, float xpos, float ypos, Joint* term_1, Joint* term_2)
    {
        inductance = indc;
        pos_x = xpos;
        pos_y = ypos;

        terminal_1 = term_1;
        terminal_2 = term_2;
    }

    Inductor()
    {}

};

class Switch
{
private:
    bool state;

    Joint* terminal_1;
    Joint* terminal_2;

    float pos_x;
    float pos_y;
    bool orientation;

public:
    Switch(bool st, float xpos, float ypos, bool orntn, Joint* term_1, Joint* term_2)
    {
        state = st;
        
        pos_x = xpos;
        pos_y = ypos;
        orientation = orntn;

        terminal_1 = term_1;
        terminal_2 = term_2;
    }
};

class Resistor
{

};