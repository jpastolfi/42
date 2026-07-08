from .CreatureFactory import CreatureFactory
from .concrete_creatures import Flameling, Pyrodon, Aquabub, Torragon


fire_base_data = {
    "name": "Flameling",
    "type": "Fire",
    "technique": "Ember"
}
fire_evolved_data = {
    "name": "Pyrodon",
    "type": "Magma",
    "technique": "Magma Swm"
}
aqua_base_data = {
    "name": "Aquabub",
    "type": "Water",
    "technique": "Water Gun"
}
aqua_evolved_data = {
    "name": "Torragon",
    "type": "Ice",
    "technique": "Blizzard"
}


class FlameFactory(CreatureFactory):
    def create_base(self) -> Flameling:
        name = fire_base_data["name"]
        type = fire_base_data["type"]
        technique = fire_base_data["technique"]
        return Flameling(name, type, technique)

    def create_evolved(self) -> Pyrodon:
        name = fire_evolved_data["name"]
        type = fire_evolved_data["type"]
        technique = fire_evolved_data["technique"]
        return Pyrodon(name, type, technique)


class AquaFactory(CreatureFactory):
    def create_base(self) -> Aquabub:
        name = aqua_base_data["name"]
        type = aqua_base_data["type"]
        technique = aqua_base_data["technique"]
        return Aquabub(name, type, technique)

    def create_evolved(self) -> Torragon:
        name = aqua_evolved_data["name"]
        type = aqua_evolved_data["type"]
        technique = aqua_evolved_data["technique"]
        return Torragon(name, type, technique)
