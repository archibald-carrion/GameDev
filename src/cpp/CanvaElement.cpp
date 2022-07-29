//Headers_
#include <GUI\CanvaElement.hpp>

CanvaElement::CanvaElement() // Constructor.
{
    this -> parentCanva = nullptr;
}

CanvaElement::~CanvaElement() // Destructor.
{
    this -> parentCanva -> unlinkElement(std::shared_ptr<CanvaElement>(this));
}

bool CanvaElement::linkToParent(std::shared_ptr<Canva> parentToLink)
{
    std::shared_ptr<CanvaElement> as_sharedPtr(this);

    if (!parentToLink -> hasElement(as_sharedPtr))
    {
        parentToLink -> elements.push_back(as_sharedPtr);
        this -> parentCanva = parentToLink;

        return true;
    }

    return false;
}

bool CanvaElement::unlinkFromParent()
{
    if (this-> parentCanva != nullptr)
    {
        std::shared_ptr<CanvaElement> as_sharedPtr(this);
        this -> parentCanva -> unlinkElement(as_sharedPtr);
        this -> parentCanva = nullptr;

        return true;
    }

    else
    {
        return false;
    }
}

std::shared_ptr<Canva> CanvaElement::getParent() const
{
    return this -> parentCanva;
}
