#include <iostream>

using namespace std;

enum ENGINE
{
    jz2,
    G4KD,
    B13,
    LT
};

enum TURBO
{
    NONE,
    turbo,
    twin_turbo
};

enum COLOR
{
    RED,
    BLUE,
    WHITE,
    BLACK,
    ORANGE
};

enum BODY_TYPE
{
    COUPE,
    SEDAN,
    WAGON,
    HATCHBACK
};

enum TRANSMISSION
{
    MANUAL_TRANSMISSION,
    AUTOMATIC_TRANSMISSION
};

class Car
{
    ENGINE engine;
    TURBO turbo;
    COLOR color;
    BODY_TYPE bodyType;
    TRANSMISSION transmission;

    friend class sportCarBuilder;
    friend class lowCostCarBuilder;

public:
    string toString()
    {
        string str = "";

        switch (engine)
        {
        case ENGINE::jz2: str += "jz2"; break;
        case ENGINE::G4KD: str += "G4KD"; break;
        case ENGINE::B13: str += "B13"; break;
        case ENGINE::LT: str += "LT"; break;
        }

        str += ", ";

        switch (turbo)
        {
        case TURBO::NONE: str += "none turbo"; break;
        case TURBO::turbo: str += "turbo"; break;
        case TURBO::twin_turbo: str += "twin_turbo"; break;
        }

        str += ", ";

        switch (color)
        {
        case COLOR::RED: str += "Red"; break;
        case COLOR::BLUE: str += "BLUE"; break;
        case COLOR::WHITE: str += "WHITE"; break;
        case COLOR::BLACK: str += "BLACK"; break;
        case COLOR::ORANGE: str += "ORANGE"; break;
        }

        str += ", ";

        switch (bodyType)
        {
        case BODY_TYPE::COUPE: str += "Coupe"; break;
        case BODY_TYPE::SEDAN: str += "SEDAN"; break;
        case BODY_TYPE::WAGON: str += "WAGON"; break;
        case BODY_TYPE::HATCHBACK: str += "HATCHBACK"; break;
        }

        str += ", ";

        switch (transmission)
        {
        case TRANSMISSION::AUTOMATIC_TRANSMISSION: str += "Automatic transmission"; break;
        case TRANSMISSION::MANUAL_TRANSMISSION: str += "Manual transmission"; break;
        }

        return str;
    }

};

class CarBuilder
{
protected:
    COLOR color;
    BODY_TYPE bodyType;

public:
    virtual void setColor(COLOR color)
    {
        this->color = color;
    };

    virtual void setBodyType(BODY_TYPE bodyType)
    {
        this->bodyType = bodyType;
    };

    virtual Car* build() = 0;
};

class sportCarBuilder : public CarBuilder
{
public:
    Car* build() override
    {
        Car* car = new Car();

        car->engine = ENGINE::jz2;
        car->turbo = TURBO::twin_turbo;
        car->transmission = TRANSMISSION::MANUAL_TRANSMISSION;

        return car;
    }
};

class lowCostCarBuilder : public CarBuilder
{
public:
    Car* build() override
    {
        Car* car = new Car();

        car->engine = ENGINE::G4KD;
        car->turbo = TURBO::NONE;
        car->transmission = TRANSMISSION::AUTOMATIC_TRANSMISSION;

        return car;
    }
};

void director(CarBuilder& builder)
{
    builder.setBodyType(COUPE);
    builder.setColor(BLACK);

    Car* car = builder.build();

    cout << "Car built: " << car->toString() << endl;
}

int main()
{

    sportCarBuilder builder1;
    lowCostCarBuilder builder2;

    director(builder1);
    director(builder2);

}