from ex0 import Creature
from .Transform import TransformCapability


class Morphagon(Creature, TransformCapability):
    def attack(self):
        return ("Evolved Morphagon is attacking!"
                if self.is_evolved else "Morphagon is attacking!")

    def describe(self) -> str:
        return "Hi, I'm a Morphagon!"

    def transform(self):
        return super().transform()

    def revert(self):
        return super().revert()
