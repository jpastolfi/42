from .. import elements, potions
from elements import create_fire


def lead_to_gold() -> str:
    return "Recipe transmuting Lead to Gold: brew {} and {} mixed with {}"
    .format
    (
        elements.create_air(),
        potions.strength_potion(),
        create_fire()
    )