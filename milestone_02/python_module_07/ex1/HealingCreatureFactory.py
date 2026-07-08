from ex0 import CreatureFactory
from .Sproutling import Sproutling
from .Bloomelle import Bloomelle

heal_base_data = {
    "name": "Sproutling",
    "type": "Healer",
    "technique": "Heal bomb"
}
heal_evolved_data = {
    "name": "Bloomelle",
    "type": "Bishop",
    "technique": "Mend"
}


class HealingCreatureFactory(CreatureFactory):
    def create_base(self):
        name = heal_base_data["name"]
        type = heal_base_data["type"]
        technique = heal_base_data["technique"]
        return Sproutling(name, type, technique)

    def create_evolved(self):
        name = heal_evolved_data["name"]
        type = heal_evolved_data["type"]
        technique = heal_evolved_data["technique"]
        return Bloomelle(name, type, technique)
