from .Creature import Creature


class Flameling(Creature):
    def attack(self) -> str:
        return "{} uses {}".format(self.name, self.technique)


class Pyrodon(Creature):
    def attack(self) -> str:
        return "{} uses {}".format(self.name, self.technique)


class Aquabub(Creature):
    def attack(self) -> str:
        return "{} uses {}".format(self.name, self.technique)


class Torragon(Creature):
    def attack(self) -> str:
        return "{} uses {}".format(self.name, self.technique)
