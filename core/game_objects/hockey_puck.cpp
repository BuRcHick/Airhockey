#include "hockey_puck.hpp"
#include "texture/texture_manager.hpp"
#include "hockey_striker.hpp"

HockeyPuck::HockeyPuck()
    : PhysicObject(), GameObject(TexturesID::HockeyPuck, 0, 0)
{
}

bool HockeyPuck::isHit(const GameObject& object)
{
    bool isHit = false;
    if (TexturesID::HockeyStriker != object.getTexture()) {
        return GameObject::isHit(object);
    }

    HockeyStriker const* striker = dynamic_cast<HockeyStriker const*>(&object);

    if (GameObject::isHit(striker->getTopHitBox()) || GameObject::isHit(striker->getBottomHitBox())) {
        /* TODO: Need to change diraction */
        isHit = true;
    } else {
        isHit = GameObject::isHit(striker->getMiddleHitBox());
    }

    if (isHit) {
        /* TODO: Need to change angle */
    }

    return isHit;
}

void HockeyPuck::handleEvent(Event* event)
{
    /* TODO */
}
