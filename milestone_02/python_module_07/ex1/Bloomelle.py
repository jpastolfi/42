from ex0.Creature import Creature
from .Heal import HealCapability


class Bloomelle(Creature, HealCapability):
    def attack(self):
        return "Bloomelle is attacking!"

    def heal(self) -> str:
        return super().heal()
