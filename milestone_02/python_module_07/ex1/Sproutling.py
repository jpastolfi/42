from ex0 import Creature
from .Heal import HealCapability


class Sproutling(Creature, HealCapability):
    def attack(self) -> str:
        return "Sproutling is attacking!"

    def describe(self) -> str:
        return "Hi, I'm a Sproutling!"

    def heal(self) -> str:
        return super().heal()
