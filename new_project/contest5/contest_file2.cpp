#include <iostream>
#include <deque>

class Water
{
public:
    int temperature;
    Water(int temperature)
    {
        this->temperature = temperature;
    }
};

class Teapot
{
public:
    int temperature;
    Teapot(Water water)
    {
        this->temperature = water.temperature;
    }

    bool is_boiling()
    {
        if (this->temperature >= 100)
        {
            return true;
        }
        return false;
    }
    void heat_up(int heat)
    {
        this->temperature += heat;
    }
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;

    Water water(temperature);
    Teapot teapot(water);

    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }

    for(auto t : heat) std::cout << t << ' ';
}
