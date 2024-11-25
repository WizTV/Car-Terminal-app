#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    int naped;
    std::string color;
    std::string model;
    std::string marka;
    double rokProdukcji;
    int przebieg;
    
public:
    // Setters
    void setNaped(int napedData);
    void setColor(std::string colorData);
    void setModel(std::string modelData);
    void setMarka(std::string markaData);
    void setRokProdukcji(double rokProdukcjiData);
    void setPrzebieg(int przebiegData);
    
    // Getters
    int getNaped();
    std::string getColor();
    std::string getModel();
    std::string getMarka();
    double getRokProdukcji();
    int getPrzebieg();
};

#endif
