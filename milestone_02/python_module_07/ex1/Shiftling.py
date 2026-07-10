from ex0 import Creature
from .Transform import TransformCapability


class Shiftling(Creature, TransformCapability):
    def attack(self) -> str:
        return ("Evolved Shiftling is attacking!"
                if self.is_evolved else "Shiftling is attacking!")

    def transform(self):
        return super().transform()

    def revert(self):
        return super().revert()
