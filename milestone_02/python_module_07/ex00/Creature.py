from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self, name: str, type: str, technique: str) -> None:
        self.name = name
        self.technique = technique
        self.type = type

    @abstractmethod
    def attack(self):
        ...

    def describe(self) -> str:
        return "I'm a {} creature called {}".format(self.type, self.name)
