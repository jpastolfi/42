from typing import cast
from .BattleStrategy import BattleStrategy
from .InvalidCreatureException import InvalidCreatureException
from ex0 import Creature
from ex1 import TransformCapability


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidCreatureException(creature.name, "Aggressive")
        transform_creature = cast(TransformCapability, creature)
        print(transform_creature.transform())
        print(creature.attack())
        print(transform_creature.revert())
