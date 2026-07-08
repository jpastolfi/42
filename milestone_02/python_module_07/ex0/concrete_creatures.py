from .Creature import Creature


class Flameling(Creature):
    def attack(self) -> str:
        return f"{self.name} uses {self.technique}"


class Pyrodon(Creature):
    def attack(self) -> str:
        return f"{self.name} uses {self.technique}"


class Aquabub(Creature):
    def attack(self) -> str:
        return f"{self.name} uses {self.technique}"


class Torragon(Creature):
    def attack(self) -> str:
        return f"{self.name} uses {self.technique}"
