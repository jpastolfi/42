from elements import create_fire, create_water
from .elements import create_air, create_earth


def healing_potion() -> str:
    return "Healing potion brewed with {} and {}".format(
        create_earth(), create_air())


def strength_potion() -> str:
    return "Strength potion brewed with {} and {}".format(
        create_fire(), create_water())
