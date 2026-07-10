from .BattleStrategy import BattleStrategy
from .InvalidCreatureException import InvalidCreatureException
from ex0 import Creature


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, Creature)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidCreatureException(creature.name, "Normal")
        print(creature.attack())
