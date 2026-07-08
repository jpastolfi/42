from abc import ABC, abstractmethod


class TransformCapability(ABC):
    def __init__(self):
        self.is_evolved = False
        super().__init__()

    @abstractmethod
    def transform(self) -> str:
        self.is_evolved = True
        return "Evolve!"

    @abstractmethod
    def revert(self) -> str:
        self.is_evolved = False
        return "Revert!"
