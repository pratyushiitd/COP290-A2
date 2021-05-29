#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
class weapon
{
private:
    int ammo;
    int capacity;
    int firerate;
    time_point<system_clock> start;
    int reloadtime;

public:
    weapon(int ammo, int capacity, int firerate, int reloadtime);
    void fire();
    void reload();
};

weapon::weapon(int ammo, int capacity, int firerate, int reloadtime)
{
    this->ammo = ammo;
    this->capacity = capacity;
    this->firerate = firerate;
    this->reloadtime = reloadtime;
    this->start = high_resolution_clock::now();
}
void weapon::fire()
{
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - this->start).count() / 1000000;
    if (duration < this->reloadtime || this->ammo < 0)
    {
        cout << "Waited for: " << duration << " Time remaining: " << reloadtime - duration << endl;
        return;
    }
    this->ammo--;
    this->start = stop;
    cout << "shoot";
}
int main(int argc, char const *argv[])
{
    weapon gun = weapon(10, 10, 10, 5);
    int a = 0;
    while (true)
    {
        cin >> a;
        if (a == 1)
        {
            gun.fire();
            a = 0;
        }
    }
    return 0;
}
