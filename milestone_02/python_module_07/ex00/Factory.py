from abc import ABC, abstractmethod
from .Creature import Creature


class CreatureFactory(ABC):
    @abstractmethod
    def create_base(self, name: str, type: str, technique: str) -> Creature:
        ...

    @abstractmethod
    def create_evolved(self, name: str, type: str, technique: str):
        ...
