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
    int getNaped() const;
    std::string getColor() const;
    std::string getModel() const;
    std::string getMarka() const;
    double getRokProdukcji() const;
    int getPrzebieg() const;
};

#endif
