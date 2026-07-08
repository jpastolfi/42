from ex0.Creature import Creature
from .Heal import HealCapability


class Bloomelle(Creature, HealCapability):
    def attack(self):
        return "Bloomelle is attacking!"

    def describe(self) -> str:
        return "Hi, I'm a Bloomelle!"

    def heal(self) -> str:
        return super().heal()
