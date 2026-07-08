from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self, name: str, type: str, technique: str) -> None:
        self.name = name
        self.technique = technique
        self.type = type
        super().__init__()

    @abstractmethod
    def attack(self) -> str:
        return f"{self.name} is attacking!"

    def describe(self) -> str:
        return f"I'm a {self.type} creature called {self.name}"
