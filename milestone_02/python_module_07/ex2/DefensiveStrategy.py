from typing import cast
from .BattleStrategy import BattleStrategy
from .InvalidCreatureException import InvalidCreatureException
from ex0 import Creature
from ex1 import HealCapability


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidCreatureException(creature.name, "Defensive")
        heal_creature = cast(HealCapability, creature)
        print(creature.attack())
        print(heal_creature.heal())
