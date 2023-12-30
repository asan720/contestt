
class Cat 
{
public:
bool isAlive;
bool isOpen;

Cat() 
{
isAlive = rand() % 2;
isOpen = false;
}

bool is_alive() 
{
if (isOpen)
{
return isAlive;
}
else
{
return rand() % 2;
}
}
};

class Box 
{
public:
Cat open()
{
Cat cat; 
cat.isOpen = true;
return cat;
}
};
