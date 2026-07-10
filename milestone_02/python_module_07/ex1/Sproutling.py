from ex0 import Creature
from .Heal import HealCapability


class Sproutling(Creature, HealCapability):
    def attack(self) -> str:
        return "Sproutling is attacking!"

    def heal(self) -> str:
        return super().heal()
