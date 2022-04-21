//Headers:
#include <GUI\Canva.hpp>

Canva::Canva(sf::RenderWindow& windowRef)
{
    this -> renderWindowRef = &windowRef;
}

Canva::~Canva()
{
    unsigned int vectorSize = this -> elements.size();

    for (unsigned int i = 0; i < vectorSize; i++)
    {
        this -> elements.at(i) -> parentCanva = nullptr;
    }
}

bool Canva::linkElement(std::shared_ptr<CanvaElement> elementToAdd)
{
    if (!this-> hasElement(elementToAdd))
    {
        this -> elements.push_back(elementToAdd);
        elementToAdd -> parentCanva = std::shared_ptr<Canva>(this);

        return true;
    }

    return false;
}

bool Canva::unlinkElement(std::shared_ptr<CanvaElement> elementToRemove)
{
    unsigned int vectorSize = this -> elements.size();

    for (unsigned int i = 0; i < vectorSize; i++)
    {
        if (this-> elements.at(i).get() == elementToRemove.get())
        {
            this -> elements.erase(this-> elements.begin() + i);
            elementToRemove -> parentCanva = nullptr;
            
            return true;
        }
    }

    return false;
}

std::shared_ptr<CanvaElement> Canva::getElement(unsigned int index) const
{
    if (index < this -> elements.size())
    {
        return this -> elements.at(index);
    }

    return std::shared_ptr<CanvaElement>(nullptr);
}

bool Canva::hasElement(std::shared_ptr<CanvaElement> elementToSearch) const
{
    unsigned int vectorSize = this -> elements.size();

    for (unsigned int i = 0; i < vectorSize; i++)
    {
        if (this-> elements.at(i).get() == elementToSearch.get())
        {
            return true;
        }
    }

    return false;
}

sf::RenderWindow* Canva::getRenderWindow() const
{
    return this -> renderWindowRef;
}

void Canva::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    unsigned int vectorSize = this -> elements.size();

    for (unsigned int i = 0; i < vectorSize; i++)
    {
        target.draw(*(sf::Sprite*) this -> elements.at(i).get(), states);
    }
}

void Canva::update(sf::Event& event, sf::Clock& deltaTimeClock)
{
    unsigned int vectorSize = this -> elements.size();

    for (unsigned int i = 0; i < vectorSize; i++)
    {
        this -> elements.at(i) -> update(event, deltaTimeClock);
    }
}

void Canva::fixedUpdate(sf::Event& event, float deltaTime)
{
    unsigned int vectorSize = this -> elements.size();

    for (unsigned int i = 0; i < vectorSize; i++)
    {
        this -> elements.at(i) -> fixedUpdate(event, deltaTime);
    }
}
