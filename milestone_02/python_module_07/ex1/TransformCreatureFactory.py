from ex0 import CreatureFactory
from .Shiftling import Shiftling
from .Morphagon import Morphagon

transform_base_data = {
    "name": "Shiftling",
    "type": "Normal",
    "technique": "Mimic"
}
transform_evolved_data = {
    "name": "Morphagon",
    "type": "Copycat",
    "technique": "Mirror"
}


class TransformCreatureFactory(CreatureFactory):
    def create_base(self):
        name = transform_base_data["name"]
        type = transform_base_data["type"]
        technique = transform_base_data["technique"]
        return Shiftling(name, type, technique)

    def create_evolved(self):
        name = transform_evolved_data["name"]
        type = transform_evolved_data["type"]
        technique = transform_evolved_data["technique"]
        return Morphagon(name, type, technique)
