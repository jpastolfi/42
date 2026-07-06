from .Factory import CreatureFactory
from .concrete_creatures import Flameling, Pyrodon, Aquabub, Torragon


class FlameFactory(CreatureFactory):
    def create_base(self, name: str, type: str, technique: str) -> Flameling:
        return Flameling(name, type, technique)

    def create_evolved(self, name: str, type: str, technique: str) -> Pyrodon:
        return Pyrodon(name, type, technique)


class AquaFactory(CreatureFactory):
    def create_base(self, name: str, type: str, technique: str) -> Aquabub:
        return Aquabub(name, type, technique)

    def create_evolved(self, name: str, type: str, technique: str) -> Torragon:
        return Torragon(name, type, technique)
